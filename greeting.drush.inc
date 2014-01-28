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

  $commands['greeting'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'description' => dt('Some helpful description.'),
    'required-arguments' => TRUE,
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

  return $commands;
}

/**
 * Implements drush_COMMAND_validate().
 */
function drush_greeting_validate($greeting) {
  if (!trim($greeting)) {
    drush_set_error('greeting_empty_greeting', dt('The greeting can not be empty.'));
  }

  $subject = drush_get_option('subject', 'DDD Szeged 2014');
  if (!trim($subject)) {
    drush_set_error('greeting_empty_subject', dt('The subject can not be empty.'));
  }
}

/**
 * Implements drush_COMMAND().
 */
function drush_greeting($greeting) {
  $subject = drush_get_option('subject', 'DDD Szeged 2014');
  drush_print(dt('@greeting @subject', array(
    '@greeting' => $greeting,
    '@subject' => $subject,
  )));
}
