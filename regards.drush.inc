<?php

/**
 * @file
 * My regards.
 */

/**
 * Implements hook_greeting_info().
 */
function regards_greeting_info() {
  return array(
    'good_evening' => array(
      'label' => dt('Good evening'),
    ),
  );
}

/**
 * Implements hook_greeting_info_alter().
 */
function regards_greeting_info_alter(&$info) {
  if (isset($info['hello'])) {
    $info['hello']['label'] = dt('HelloBello');
  }
}
