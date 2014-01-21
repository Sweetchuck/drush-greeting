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
    'description' => dt('Something helpful description.'),
  );

  return $commands;
}

/**
 * Implements drush_COMMAND().
 */
function drush_greeting() {
  drush_print(dt('Hello DDD Szeged 2014'));
}
