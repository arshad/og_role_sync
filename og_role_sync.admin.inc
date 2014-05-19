<?php

/**
 * @file
 * Admin settings for OG role sync module.
 */

/**
 * Menu callback; OG role sync settings form.
 */
function og_role_sync_admin_settings_form($form, &$form_state) {
  $site_roles = user_roles();
  $og_roles = og_role_sync_get_all_og_roles(TRUE);
  $og_role_sync_settings = variable_get('og_role_sync_settings');

  $form['og_role_sync_settings'] = array(
    '#tree' => TRUE,
  );

  foreach ($site_roles as $site_rid => $site_role) {
    $form['og_role_sync_settings'][$site_role] = array(
      '#type' => 'fieldset',
      '#title' => $site_role,
      '#collapsed' => ($site_rid == 1 || $site_rid == 2),
      '#collapsible' => TRUE,
    );
    $form['og_role_sync_settings'][$site_role][$site_rid] = array(
      '#title' => t('Sync the role %site_role with the following OG roles', array(
        '%site_role' => $site_role,
      )),
      '#type' => 'checkboxes',
      '#options' => $og_roles,
      '#default_value' => !empty($og_role_sync_settings[$site_rid]) ? $og_role_sync_settings[$site_rid] : array(),
    );
  }

  return system_settings_form($form);
}
