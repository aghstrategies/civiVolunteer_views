<?php
/**
 * Implements hook_views_data().
 */
function civivolunteer_views_views_data() {
  // for civivolunteer need table
  $data['civicrm_volunteer_need']['table']['group'] = t('civiVolunteer - Volunteer Needs');
  $data['civicrm_volunteer_need']['table']['base'] = array(
    'field' => 'id',
    'title' => t('CiviVolunteer Needs'),
    'help' => t("View displays CiviVolunteer Needs."),
  );
  $data['civicrm_volunteer_need']['id'] = array(
    'title' => t('Volunteer Need ID'),
    'help' => t('ID of Volunteer need for civiVolunteer'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['civicrm_volunteer_need']['start_time'] = array(
    'title' => t('Start Time'),
    'help' => t('The Volunteer need start time'),
    'field' => array(
      'handler' => 'civicrm_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'civicrm_handler_filter_datetime',
      'is date' => TRUE,
    ),
    'sort' => array(
      'handler' => 'civicrm_handler_sort_date',
    ),
  );
  $data['civicrm_volunteer_need']['end_time'] = array(
    'title' => t('End Time'),
    'help' => t('The Volunteer need end time'),
    'field' => array(
      'handler' => 'civicrm_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'civicrm_handler_filter_datetime',
      'is date' => TRUE,
    ),
    'sort' => array(
      'handler' => 'civicrm_handler_sort_date',
    ),
  );
  $data['civicrm_volunteer_need']['duration'] = array(
    'title' => t('Duration'),
    'help' => t('Length in minutes of this Volunteer time slot'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['civicrm_volunteer_need']['is_flexible'] = array(
    'title' => t('Is flexible?'),
    'help' => t('Is the volunteer need time flexible?'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['civicrm_volunteer_need']['quantity'] = array(
    'title' => t('Quantity'),
    'help' => t('Number of volunteers required for this need'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['civicrm_volunteer_need']['is_active'] = array(
    'title' => t('Is active?'),
    'help' => t('Is the volunteer need active?'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // TODO: make FK to option value not just number
  $data['civicrm_volunteer_need']['visibility_id'] = array(
    'title' => t('Visibility ID'),
    'help' => t('who sees this need'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // TODO: make FK to option value not just number
  $data['civicrm_volunteer_need']['role_id'] = array(
    'title' => t('Role ID'),
    'help' => t('Role of Need'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  //This makes needs fields available on project views
  // $data['civicrm_volunteer_need']['table']['join'] = array(
  //   'civicrm_volunteer_project' => array(
  //     'left_field' => 'id',
  //     'field' => 'project_id',
  //   ),
  // );
  $data['civicrm_volunteer_project_contact']['table']['join'] = array(
    'civicrm_volunteer_project' => array(
      'left_field' => 'id',
      'field' => 'project_id',
    ),
  );
  // $data['civicrm_contact']['table']['join'] = array(
  //   'civicrm_volunteer_project_contact' => array(
  //     'left_field' => 'contact_id',
  //     'field' => 'id',
  //   ),
  // );
  $data['civicrm_volunteer_project']['table']['join'] = array(
    'civicrm_volunteer_project_contact' => array(
      'left_field' => 'project_id',
      'field' => 'id',
    ),
  );
  //  Trying hops
  // $data['civicrm_volunteer_project']['table']['join']['civicrm_contact'] = array(
  //   'left_table' => 'civicrm_volunteer_project_contact',
  //   'left_field' => 'project_id',
  //   'field' => 'id',
  // );
  // $data['civicrm_volunteer_project_contact']['table']['join']['civicrm_contact'] = array(
  //   'left_field' => 'id',
  //   'field' => 'contact_id',
  // );

  // for civivolunteer project table
  $data['civicrm_volunteer_project']['table']['group'] = t('civiVolunteer - Volunteer Projects');
  $data['civicrm_volunteer_project']['table']['base'] = array(
    'field' => 'id',
    'title' => t('CiviVolunteer Projects'),
    'help' => t("View displays CiviVolunteer Projects."),
  );
  // $data['civicrm_volunteer_project']['table']['join'] = array(
  // // Index this array by the table name to which this table refers.
  // // 'left_field' is the primary key in the referenced table.
  // // 'field' is the foreign key in this table.
  //   'civicrm_volunteer_need' => array(
  //     'left_field' => 'id',
  //     'field' => 'need_id',
  //   ),
  // );
  // NOTE: Fields for volunteer Projects table that we are skipping for now: entity_table entity_id,  loc_block_id, campaign_id
  $data['civicrm_volunteer_project']['id'] = array(
    'title' => t('Volunteer Project ID'),
    'help' => t('ID of Volunteer Project for civiVolunteer'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['civicrm_volunteer_project']['title'] = array(
    'title' => t('Title'),
    'help' => t('Title of the Volunteer Project'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['civicrm_volunteer_project']['description'] = array(
    'title' => t('Description'),
    'help' => t('Description of the Volunteer Project'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['civicrm_volunteer_project']['is_active'] = array(
    'title' => t('Is active?'),
    'help' => t('Is the volunteer project active?'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // TODO for civivolunteer project contact table
  $data['civicrm_volunteer_project_contact']['table']['group'] = t('CiviVolunteer Volunteer Project Contacts');
  $data['civicrm_volunteer_project_contact']['table']['base'] = array(
    'field' => 'id',
    'title' => t('CiviVolunteer Project Contacts'),
    'help' => t("View displays CiviVolunteer Project Contacts."),
  );
  $data['civicrm_volunteer_project_contact']['id'] = array(
    'title' => t('Volunteer Project Contact Row ID'),
    'help' => t('ID of Volunteer Project Contact row for civiVolunteer'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // $data['civicrm_volunteer_project_contact']['contact_id'] = array(
  //   'title' => t('Volunteer Project Contact ID'),
  //   'help' => t('ID of Volunteer Project Contact for civiVolunteer'),
  //   'field' => array(
  //     'handler' => 'views_handler_field_numeric',
  //     'click sortable' => TRUE,
  //   ),
  //   'argument' => array(
  //     'handler' => 'views_handler_argument_numeric',
  //     'numeric' => TRUE,
  //   ),
  //   'filter' => array(
  //     'handler' => 'views_handler_filter_numeric',
  //     'allow empty' => TRUE,
  //   ),
  //   'sort' => array(
  //     'handler' => 'views_handler_sort',
  //   ),
  // );
  $data['civicrm_volunteer_project_contact']['contact_id'] = array(
    'title' => t('Volunteer Project Contact ID'),
    'real field' => 'contact_id',
    'help' => t('The contact related to the volunteer project.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'civicrm_contact',
      'base field' => 'id',
      'handler' => 'civicrm_handler_field_activity',
      'label' => t('CiviCRM Volunteer Project Contact ID'),
      'relationship table' => 'civicrm_volunteer_project',
      'relationship field' => 'project_id',
      'other_field' => 'contact_id',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
  );
  $data['civicrm_volunteer_project_contact']['project_id'] = array(
    'title' => t('Volunteer Project ID'),
    'real field' => 'project_id',
    'help' => t('The project related to the volunteer project.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'civicrm_volunteer_project',
      'base field' => 'id',
      'handler' => 'civicrm_handler_field_activity',
      'label' => t('CiviCRM Volunteer Project ID'),
      'relationship table' => 'civicrm_contact',
      'relationship field' => 'contact_id',
      'other_field' => 'project_id',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
  );
  // $data['civicrm_volunteer_project_contact']['project_id'] = array(
  //   'title' => t('Volunteer Project ID'),
  //   'help' => t('ID of Volunteer Project for civiVolunteer'),
  //   'field' => array(
  //     'handler' => 'views_handler_field_numeric',
  //     'click sortable' => TRUE,
  //   ),
  //   'argument' => array(
  //     'handler' => 'views_handler_argument_numeric',
  //     'numeric' => TRUE,
  //   ),
  //   'filter' => array(
  //     'handler' => 'views_handler_filter_numeric',
  //     'allow empty' => TRUE,
  //   ),
  //   'sort' => array(
  //     'handler' => 'views_handler_sort',
  //   ),
  // );
  // //NOTE: fields for project contacts: id, project_id, contact_id, relationship_type_id
  $data['civicrm_volunteer_project_contact']['relationship_type_id'] = array(
    'title' => t('Volunteer Project Contact Relationship Type ID'),
    'help' => t('Relationship type for contact for civiVolunteer'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function civivolunteer_views_views_data_alter(&$data) {
  civivolunteer_views_views_data();

}
