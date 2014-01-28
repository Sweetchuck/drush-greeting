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
    'arguments' => array(
      'greeting' => dt('Kind of greeting.'),
    ),
  );

  return $commands;
}

/**
 * Implements drush_COMMAND().
 */
function drush_greeting($greeting) {
  drush_print(dt('@greeting DDD Szeged 2014', array(
    '@greeting' => $greeting,
  )));
}
