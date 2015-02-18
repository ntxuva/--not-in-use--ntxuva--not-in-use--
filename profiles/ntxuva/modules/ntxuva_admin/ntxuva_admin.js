/**
 * @file ntxuva_admin.js
 *
 * Provides some more leaflet layers to check reports
 */

(function ($) {
  Drupal.behaviors.ntxuvaAdmin = {

    attach: function (context, settings) {
      // Disable User notify
      $('#edit-field-notify-user .form-checkbox').attr('checked', false);
    }
  };
})(jQuery);

