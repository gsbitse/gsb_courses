<?php
/**
 * @file
 * gsb_courses.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gsb_courses_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function gsb_courses_node_info() {
  $items = array(
    'gsb_course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('An academic course'),
      'has_title' => '1',
      'title_label' => t('Course Title'),
      'help' => '',
    ),
    'gsb_course_importer' => array(
      'name' => t('Course Importer'),
      'base' => 'node_content',
      'description' => t('This is a meta content type to which you can attach GSB Course Importer feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This is a "meta" content type for importing course feeds from http://explorecourses.stanford.edu.'),
    ),
    'gsb_course_section' => array(
      'name' => t('Course Section'),
      'base' => 'node_content',
      'description' => t(' A <em>section</em> is an instance of a course, and includes instructor, academic quarter, date and time information, and so forth.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'gsb_course_section_importer' => array(
      'name' => t('Course Section Importer'),
      'base' => 'node_content',
      'description' => t('This is a meta content type to which you can attach GSB Course Section Importer feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This is a "meta" content type for importing course section feeds from http://explorecourses.stanford.edu.'),
    ),
  );
  return $items;
}
