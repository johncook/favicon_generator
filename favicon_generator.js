/**
 * @file
 *
 * Favicon generator color picker function.
 */

(function($) {
  Drupal.behaviors.favicon_generator = {
    attach: function(context, settings) {
      // Attach color wheel behaviour.
      $('.favicon_generator_colorpicker').farbtastic('#edit-favicon-generator-color');

      // Attach onClick event for swatches.
      $('.form-item-favicon-generator-color .color-preset:not(.favicon-generator-color-preset-processed)')
      .addClass('favicon-generator-color-preset-processed')
      .click(function() {
        var color = $(this).css('background-color');

        var rgb2hex = (function(rgb) {
          if (rgb.search("rgb") == -1)
            return rgb;
          else {
            rgb = rgb.match(/^rgb\((\d+),\s*(\d+),\s*(\d+)\)$/);
            function hex(x) {
              return ("0" + parseInt(x).toString(16)).slice(-2);
            }
            return ("#" + hex(rgb[1]) + hex(rgb[2]) + hex(rgb[3]));
          }
        });

        color = rgb2hex(color);
        $.farbtastic('.favicon_generator_colorpicker').setColor(color);
      });
    }
  };
})(jQuery);
