<?php
/**
 * @file
 * gsb_courses.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function gsb_courses_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gsb_course_importer';
  $feeds_importer->config = array(
    'name' => 'GSB Course Importer',
    'description' => 'Imports course information from explorecourses.stanford.edu',
    'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
      'request_timeout' => NULL,
    ),
    ),
    'parser' => array(
    'plugin_key' => 'FeedsXPathParserXML',
    'config' => array(
      'sources' => array(
      'xpathparser:0' => 'concat(administrativeInformation/courseId,"-",subject,"-",code,"-",year)',
      'xpathparser:1' => 'title',
      'xpathparser:2' => 'code',
      'xpathparser:3' => 'subject',
      'xpathparser:4' => 'administrativeInformation/courseId',
      'xpathparser:5' => 'description',
      'xpathparser:6' => 'year',
      'xpathparser:7' => 'concat(subject,code)',
      ),
      'rawXML' => array(
      'xpathparser:0' => 0,
      'xpathparser:1' => 0,
      'xpathparser:2' => 0,
      'xpathparser:3' => 0,
      'xpathparser:4' => 0,
      'xpathparser:5' => 0,
      'xpathparser:6' => 0,
      'xpathparser:7' => 0,
      ),
      'context' => '//courses/course',
      'exp' => array(
      'errors' => 0,
      'debug' => array(
        'context' => 0,
        'xpathparser:0' => 0,
        'xpathparser:1' => 0,
        'xpathparser:2' => 0,
        'xpathparser:3' => 0,
        'xpathparser:4' => 0,
        'xpathparser:5' => 0,
        'xpathparser:6' => 0,
        'xpathparser:7' => 0,
      ),
      ),
      'allow_override' => 1,
    ),
    ),
    'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'expire' => '-1',
      'author' => 0,
      'mappings' => array(
      0 => array(
        'source' => 'xpathparser:0',
        'target' => 'guid',
        'unique' => 1,
      ),
      1 => array(
        'source' => 'xpathparser:1',
        'target' => 'title',
        'unique' => FALSE,
      ),
      2 => array(
        'source' => 'xpathparser:2',
        'target' => 'field_gsb_course_code',
        'unique' => FALSE,
      ),
      3 => array(
        'source' => 'xpathparser:3',
        'target' => 'field_gsb_course_subject',
        'unique' => FALSE,
      ),
      4 => array(
        'source' => 'xpathparser:4',
        'target' => 'field_gsb_course_course_id',
        'unique' => FALSE,
      ),
      5 => array(
        'source' => 'xpathparser:5',
        'target' => 'field_gsb_course_description',
        'unique' => FALSE,
      ),
      6 => array(
        'source' => 'xpathparser:6',
        'target' => 'field_gsb_course_year',
        'unique' => FALSE,
      ),
      7 => array(
        'source' => 'xpathparser:7',
        'target' => 'field_gsb_course_ec_link:url',
        'unique' => FALSE,
      ),
      ),
      'update_existing' => '2',
      'input_format' => 'filtered_html',
      'bundle' => 'gsb_course',
      'authorize' => TRUE,
      'skip_hash_check' => FALSE,
    ),
    ),
    'content_type' => 'gsb_course_importer',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gsb_course_section_importer';
  $feeds_importer->config = array(
    'name' => 'GSB Course Section Importer',
    'description' => 'Imports course sections from explorecourses.stanford.edu',
    'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
      'request_timeout' => NULL,
    ),
    ),
    'parser' => array(
    'plugin_key' => 'FeedsXPathParserXML',
    'config' => array(
      'sources' => array(
      'xpathparser:0' => 'classId',
      'xpathparser:1' => 'concat(subject,"-",classId)',
      'xpathparser:2' => 'term',
      'xpathparser:3' => 'subject',
      'xpathparser:4' => 'code',
      'xpathparser:5' => 'courseId',
      'xpathparser:6' => 'schedules/schedule/instructors/instructor/name',
      'xpathparser:7' => 'schedules/schedule/instructors/instructor/firstName',
      'xpathparser:8' => 'schedules/schedule/instructors/instructor/lastName',
      'xpathparser:9' => 'schedules/schedule/instructors/instructor/sunet',
      ),
      'rawXML' => array(
      'xpathparser:0' => 0,
      'xpathparser:1' => 0,
      'xpathparser:2' => 0,
      'xpathparser:3' => 0,
      'xpathparser:4' => 0,
      'xpathparser:5' => 0,
      'xpathparser:6' => 0,
      'xpathparser:7' => 0,
      'xpathparser:8' => 0,
      'xpathparser:9' => 0,
      ),
      'context' => '//courses/course/sections/section',
      'exp' => array(
      'errors' => 0,
      'debug' => array(
        'context' => 0,
        'xpathparser:0' => 0,
        'xpathparser:1' => 0,
        'xpathparser:2' => 0,
        'xpathparser:3' => 0,
        'xpathparser:4' => 0,
        'xpathparser:5' => 0,
        'xpathparser:6' => 0,
        'xpathparser:7' => 0,
        'xpathparser:8' => 0,
        'xpathparser:9' => 0,
      ),
      ),
      'allow_override' => 1,
    ),
    ),
    'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'expire' => '-1',
      'author' => 0,
      'mappings' => array(
      0 => array(
        'source' => 'xpathparser:0',
        'target' => 'guid',
        'unique' => 1,
      ),
      1 => array(
        'source' => 'xpathparser:1',
        'target' => 'title',
        'unique' => FALSE,
      ),
      2 => array(
        'source' => 'xpathparser:2',
        'target' => 'field_gsb_course_sec_term',
        'unique' => FALSE,
      ),
      3 => array(
        'source' => 'xpathparser:3',
        'target' => 'field_gsb_course_sec_subject',
        'unique' => FALSE,
      ),
      4 => array(
        'source' => 'xpathparser:4',
        'target' => 'field_gsb_course_sec_code',
        'unique' => FALSE,
      ),
      5 => array(
        'source' => 'xpathparser:5',
        'target' => 'field_gsb_course_sec_course_id',
        'unique' => FALSE,
      ),
      6 => array(
        'source' => 'xpathparser:6',
        'target' => 'field_gsb_course_sec_ins',
        'unique' => FALSE,
      ),      
      7 => array(
        'source' => 'xpathparser:7',
        'target' => 'field_gsb_course_sec_ins_first_n',
        'unique' => FALSE,
      ),
      8 => array(
        'source' => 'xpathparser:8',
        'target' => 'field_gsb_course_sec_ins_last_n',
        'unique' => FALSE,
      ),
      9 => array(
        'source' => 'xpathparser:9',
        'target' => 'field_gsb_course_sec_ins_sunet',
        'unique' => FALSE,
      ),
      ),
      'update_existing' => '2',
      'input_format' => 'plain_text',
      'bundle' => 'gsb_course_section',
      'authorize' => TRUE,
      'skip_hash_check' => FALSE,
    ),
    ),
    'content_type' => 'gsb_course_section_importer',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );

  $export['gsb_course_section_importer'] = $feeds_importer;

  return $export;
}
