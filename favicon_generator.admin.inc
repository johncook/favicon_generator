<?php

/**
 * @file
 * Contains admin UI.
 *
 * @author JohnCook
 */

/**
 * Implements hook_settings().
 */
function favicon_generator_settings() {
  $form = array();

  $form['#attached']['js'] = array(
    'misc/farbtastic/farbtastic.js',
    drupal_get_path('module', 'favicon_generator') . '/favicon_generator.js',
  );
  $form['#attached']['css'] = array(
    'misc/farbtastic/farbtastic.css',
    drupal_get_path('module', 'favicon_generator') . '/favicon_generator.css',
  );

  // Background Color.
  $form['favicon_generator_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Background Color'),
    '#default_value' => variable_get('favicon_generator_color', '#00aba9'),
    '#description' => '<div class="favicon_generator_colorpicker"></div>',
    '#size' => 7,
    '#maxlength' => 7,
  );
  // Add presets.
  $colors = array(
    '00aba9' => t('Teal'),
    '2d89ef' => t('Blue'),
    'da532c' => t('Dark Orange'),
    '00a300' => t('Green'),
    '2b5797' => t('Dark Blue'),
    'b91d47' => t('Dark Red'),
    'ffc40d' => t('Yellow'),
    '603cba' => t('Dark Purple'),
    '9f00a7' => t('Light Purple'),
  );
  $form['favicon_generator_color']['#description'] .= '<div class="color-presets">';
  foreach ($colors as $hex => $name) {
    $form['favicon_generator_color']['#description'] .=
      '<div class="color-preset" style="background-color: #' . $hex . ';" >' . $name . '<br/>#' . $hex . '</div>';
  }
  $form['favicon_generator_color']['#description'] .= '</ div>';

  // Margin.
  $form['favicon_generator_margin'] = array(
    '#type' => 'select',
    '#title' => t('Margin size (for a 57x57 icon)'),
    '#options' => array(
      0 => t('0px'),
      1 => t('1px'),
      2 => t('2px'),
      3 => t('3px'),
      4 => t('4px'),
      5 => t('5px'),
      6 => t('6px'),
      7 => t('7px'),
      8 => t('8px'),
      9 => t('9px'),
      10 => t('10px'),
      11 => t('11px'),
      12 => t('12px'),
      13 => t('13px'),
      14 => t('14px'),
      15 => t('15px'),
    ),
    '#default_value' => variable_get('favicon_generator_margin', 4),
  );

  // IO Picture Aspect.
  // 57x57px.
  $form['favicon_generator_ios'] = array(
    '#type' => 'select',
    '#title' => t('IOS Style'),
    '#options' => array(
      'transparent' => t('Transparent Background'),
      'colored' => t('Colored Background'),
    ),
    '#default_value' => variable_get('favicon_generator_ios', 'colored'),
  );

  // Windows Picture Aspect.
  // 50x50 icon on 101x101 tile.
  $form['favicon_generator_windows'] = array(
    '#type' => 'select',
    '#title' => t('Windows 8 Style'),
    '#options' => array(
      'colored' => t('Use the icon as is'),
      'white' => t('Turn the icon into a white silhouette'),
    ),
    '#default_value' => variable_get('favicon_generator_windows', 'colored'),
  );

  // Firefox Picture Aspect.
  $form['favicon_generator_ff'] = array(
    '#type' => 'select',
    '#title' => 'Firefox OS Style',
    '#options' => array(
      'circle' => t('Circle'),
      'rsquare' => t('Rounded Square'),
      'square' => t('Square'),
    ),
    '#default_value' => variable_get('favicon_generator_ff', 'circle'),
  );
  $form['favicon_generator_ff_incircle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Keep picture in circle'),
    '#description' => t('If checked, the icon is cropped in order to fit the circle. Else, the icon may extend beyond the circle.'),
    '#default_value' => variable_get('favicon_generator_ff_incircle', 1),
    '#states' => array(
      'visible' => array(
        ':input[name="favicon_generator_ff"]' => array('value' => 'circle'),
      ),
    ),
  );

  // Android Picture Aspect.
  $form['favicon_generator_android'] = array(
    '#type' => 'select',
    '#title' => 'Android Style',
    '#options' => array(
      'transparent' => t('Transparent Background'),
      'colored' => t('Colored Background'),
      'shadow' => t('Add Shadow'),
    ),
    '#default_value' => variable_get('favicon_generator_android', 'shadow'),
  );

  $form['favicon_generator_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to icon files'),
    '#field_prefix' => t('public://'),
    '#default_value' => variable_get('favicon_generator_path', ''),
  );

  return system_settings_form($form);
}
