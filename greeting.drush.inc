<?php

/**
 * @file
 * My first Drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function greeting_drush_command() {
  $commands = array();

  $commands['docs-greeting'] = array(
    'description' => dt('Greetings'),
    'hidden' => TRUE,
    'topic' => TRUE,
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'callback' => 'drush_print_file',
    'callback arguments' => array(__DIR__ . '/README.md'),
  );

  $commands['greeting'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'description' => dt('Some helpful description.'),
    'required-arguments' => FALSE,
    'arguments' => array(
      'greeting' => dt('Kind of greeting.'),
    ),
    'options' => array(
      'subject' => array(
        'description' => dt("The person's name"),
        'example-value' => dt('World'),
        'required' => FALSE,
        'hidden' => FALSE,
      ),
    ),
  );

  $commands['greeting-list'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'description' => dt('Some helpful description.'),
    'engines' => array(
      'outputformat' => array(
        'default' => 'table',
        'field-labels' => array(
          'name' => dt('Name'),
          'label' => dt('Label'),
        ),
      ),
    ),
  );

  return $commands;
}

/**
 * Implements drush_COMMAND_validate().
 */
function drush_greeting_validate($greeting = NULL) {
  $greetings = greeting_info_greeting();
  if ($greeting !== NULL && !isset($greetings[$greeting])) {
    drush_set_error('greeting_unknown_greeting', dt('Unknown greeting.'));
  }

  $subject = drush_get_option('subject', 'DDD Szeged 2014');
  if (!trim($subject)) {
    drush_set_error('greeting_empty_subject', dt('The subject can not be empty.'));
  }
}

/**
 * Implements drush_COMMAND().
 */
function drush_greeting($greeting = NULL) {
  $greetings = greeting_info_greeting();
  $subject = drush_get_option('subject', 'DDD Szeged 2014');

  if (!$greeting) {
    $greeting = drush_choice(_greeting_greeting_options());
    if (!$greeting) {
      return drush_user_abort();
    }
  }
  
  return dt('@greeting @subject', array(
    '@greeting' => $greetings[$greeting]['label'],
    '@subject' => $subject,
  ));
}

/**
 * Implements drush_COMMAND().
 */
function drush_greeting_list() {
  $sure = drush_confirm(dt('Are you sure you want to see the list of greetings?'));
  if (!$sure) {
    return drush_user_abort();
  }

  return greeting_info_greeting();
}

/**
 * Return all greeting definitions.
 *
 * @return array
 *   An array of greeting definitions.
 */
function greeting_info_greeting() {
  return array(
    'hello' => array(
      'name' => 'hello',
      'label' => dt('Hello'),
    ),
    'good_morning' => array(
      'name' => 'good_morning',
      'label' => dt('Good morning'),
    ),
  );
}

/**
 * Option list from greeting names and labels.
 *
 * @return array
 *   Key value pairs of greeting names and labels.
 */
function _greeting_greeting_options() {
  $options = array();

  foreach (greeting_info_greeting() as $greeting) {
    $options[$greeting['name']] = $greeting['label'];
  }

  return $options;
}
