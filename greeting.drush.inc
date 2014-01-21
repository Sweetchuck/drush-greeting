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
 * Implements drush_COMMAND_init().
 */
//function drush_greeting_init() {}

/**
 * Implements drush_COMMAND_pre_validate().
 */
//function drush_greeting_pre_validate() {}

/**
 * Implements drush_COMMAND_validate().
 */
//function drush_greeting_validate() {}

//drush_hook_pre_COMMAND

/**
 * Implements drush_COMMAND().
 */
function drush_greeting() {
}

//drush_hook_post_COMMAND
