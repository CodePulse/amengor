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
  if ($view->name == '_smilee_modal' && $view->current_display == 'block_recently_viewed') {
    // Prevent duplicate products being displayed under latest products
    $query->add_field('node', 'title', 'node_title', array('function' => 'groupby'));
    $query->distinct=TRUE;
  }
  if ($view->name == '_smilee_shop_block' && $view->current_display == 'page_2' || $view->current_display == 'page_1' || $view->current_display == 'page_4' || $view->current_display == 'page_categories_grid') {
    // Prevent duplicate products being displayed under latest products
    $query->add_field('node', 'title', 'node_title', array('function' => 'groupby'));
    $query->distinct=TRUE;
  }
  if ($view->name == '_smilee_product' && $view->current_display == 'block_upsell_products' || $view->current_display == 'block_recent_products_sg') {
    // Prevent duplicate products being displayed under latest products
    $query->add_field('node', 'title', 'node_title', array('function' => 'groupby'));
    $query->distinct=TRUE;
  }
}