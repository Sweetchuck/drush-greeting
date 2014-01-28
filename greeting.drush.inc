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
  );

  return $commands;
}
