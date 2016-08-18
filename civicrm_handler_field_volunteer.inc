<?php
/**
 * @file
 * Add a table of contributions from related contacts.
 *
 * Copyright (C) 2013-15, AGH Strategies, LLC <info@aghstrategies.com>
 * Licensed under the GNU Affero Public License 3.0 (see LICENSE.txt)
 */
/**
 * Field Handler for volunteer project contacts modeled off of the field handler for activity contact field in CiviCRM 4.7
 */
class civicrm_handler_field_volunteer extends civicrm_handler_field {
  static $_recordType;
  function construct() {
    parent::construct();
    if (!self::$_recordType) {
      if (!civicrm_initialize()) {
        return;
      }
      try {
        $option = civicrm_api3('VolunteerProjectContact', 'getoptions', array(
          'field' => "relationship_type_id",
          'context' => "get",
        ));
        self::$_recordType = $option['values'];
      }
      catch (CiviCRM_API3_Exception $e) {
        watchdog('civivolunteer_views', 'API error finding volunter project contact relationship types: %error', array('error' => $e->getMessage));
      }
    }
  }
  function option_definition() {
    $options = parent::option_definition();
    $options['relationship_type'] = array('default' => 0);
    return $options;
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $relTypes = array(0 => 'Any');
    foreach (self::$_recordType as $id => $type) {
      $relTypes[$id] = $type;
    }
    $form['relationship_type'] = array(
      '#type' => 'radios',
      '#title' => 'Project/contact relationship type',
      '#options' => $relTypes,
      '#description' => t('Record type to be displayed for this field'),
      '#default_value' => $this->options['relationship_type'],
      '#fieldset' => 'relationship_type_choices',
    );
  }
  /**
   * Called to link activity contact with civicrm_contact in a query.
   */
  function query() {
    // Figure out what base table
    $table_data        = views_fetch_data($this->definition['base']);
    $base_field        = empty($this->definition['base field']) ? $table_data['table']['base']['field'] : $this->definition['base field'];
    $this->table_alias = $this->query->add_table($this->table, $this->relationship);
    // Make sure the join to civicrm_contact form the civicrm_activity_contact table
    // Otherwise the displayed field will always be the same as the base table's record
    if ($this->table == 'civicrm_volunteer_project_contact' && isset($this->view->query->table_queue[$this->table_alias]['join']->field)) {
      $this->view->query->table_queue[$this->table_alias]['join']->field = $this->definition['relationship field'];
    }
    $def = $this->definition;
    $leftField         = $this->definition['base'] == 'civicrm_volunteer_project_contact' ? $this->field : $this->definition['other_field'];
    $def['table']      = $this->definition['base'];
    $def['field']      = $this->definition['base field'];
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = $leftField;
    if (!empty($this->options['required'])) {
      $def['type'] = 'INNER';
    }
    if (!empty($def['join_handler']) && class_exists($def['join_handler'])) {
      $join = new $def['join_handler'];
    }
    else {
      $join = new views_join();
    }
    $join->definition = $def;
    $join->construct();
    $join->adjusted = TRUE;
    // Add a join condition to the on clause to narrow down the relationship type shown
    if (isset($this->options['relationship_type']) && $this->options['relationship_type']) {
      $this->query->table_queue[$this->table_alias]['join']->extra[] = array(
        'value' => $this->options['relationship_type'],
        'numeric' => TRUE,
        'field' => 'relationship_type_id',
        'operator' => '=',
      );
    }
    // use a short alias for this:
    $alias = $def['table'] . '_' . $this->table;
    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);
  }
}
