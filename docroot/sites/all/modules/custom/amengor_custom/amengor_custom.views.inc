<?php

/**
 * Implements hook_views_query_alter().
 */
function amengor_custom_views_query_alter(&$view, &$query) {
  if ($view->name == '_smilee_product' && $view->current_display == 'block_latest_products') {
    // Prevent duplicate products being displayed under latest products
    $query->add_field('node', 'title', 'node_title', array('function' => 'groupby'));
    $query->distinct=TRUE;
  }
}