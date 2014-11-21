/**
 * @file
 *
 * Favicon generator color picker function
 */

(function($) {
  Drupal.behaviors.favicon_generator = {
    attach: function(context) {
      $('.colorpicker').farbtastic('#edit-favicon-generator-color');
    }
  };
})(jQuery);
