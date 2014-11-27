<?php
/**
 * @file
 * Hooks provided by Favicon Generator.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Add sub-module fields to admin UI.
 *
 * @return array
 *   A Form API array containing the form elements of the sub-module.
 */
function hook_favicon_generator_admin() {
  return array();
}

/**
 * Create the RFG sub-spec for the platform.
 *
 * @param array $settings
 *   An array of global settting.
 *   Includes color and margin.
 *
 * @return array
 *   A nest array of the settings required by RFG.
 */
function hook_favicon_generator_spec(array $settings) {
  return array(
    'platform' => array(
      'setting1' => 'xxx',
    ),
  );
}

/**
 * @} End of "addtogroup hooks".
 */
