<?php
/**
 * @file
 * recherche_des_certificats.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function recherche_des_certificats_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_certificats:certificats
  $menu_links['main-menu_certificats:certificats'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'certificats',
    'router_path' => 'certificats',
    'link_title' => 'Certificats',
    'options' => array(
      'identifier' => 'main-menu_certificats:certificats',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Certificats');


  return $menu_links;
}
