<?php

/**
 * @file
 * Theme and preprocess functions for pages.
 */

/**
 * Implements template_preprocess_page().
 */
function {{machine_name}}_preprocess_page(&$vars) {
  $base_path = $GLOBALS['base_path'];

  // Add a grid definitions for '.main-content' regions.
  if (!empty($vars['page']['sidebar'])) {
    $vars['page']['content']['#wrapper_classes'][] = 'col-md-8 col-md-push-4';
    $vars['page']['sidebar']['#wrapper_classes'][] = 'col-md-4 col-md-pull-8';
  }
  else {
    $vars['page']['content']['#wrapper_classes'][] = 'col-md-12';
  }

  // Add grid def for footer blocks.
  foreach (element_children($vars['page']['footer']) as $name) {
    $vars['page']['footer'][$name]['#wrapper_classes'][] =  'col-md-4';
  }

  // No container on pages using SiteNow Paragraphs which have no menu block.
  if (isset($vars['node']) && empty($vars['page']['sidebar'])) {
    if ($vars['node']->type == 'page') {
      $vars['container'] = FALSE;
    }
  }
}

/**
 * Implements template_process_page().
 */
function {{machine_name}}_process_page(&$vars) {
  $vars['content-classes'][] = 'main-content';

  // If there is no container set OR it's set to true.
  if (!isset($vars['container']) || $vars['container'] == TRUE) {
    // Add a container to '.main-content'.
    $vars['content-classes'][] = 'container-smooth';
  }

  if (isset($vars['$content-classes'])) {
    // Add classes for the main_wrapper.
    $vars['content_classes'] = implode(' ', $vars['content-classes']);
  }
}
