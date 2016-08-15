<?php
/**
 * Implements hook_views_data().
 */
function civivolunteer_views_views_data() {
  // for civivolunteer need table
  $data['civicrm_volunteer_need']['table']['group'] = t('civiVolunteer Volunteer Needs');
  $data['civicrm_volunteer_need']['table']['base'] = array(
    'field' => 'id',
    'title' => t('CiviVolunteer Needs'),
    'help' => t("View displays CiviVolunteer Needs."),
  );
  $data['civicrm_volunteer_need']['id'] = array(
    'title' => t('Volunteer Need ID'),
    'help' => t('ID of Volunteer need for civiVolunteer'),
  );
  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function civivolunteer_views_views_data_alter(&$data) {
  civivolunteer_views_views_data();
}
