// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
     _COLEMAK,
     _NAV,
     _FN
};

enum custom_keycodes {
    MAC_LOCK = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
     KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
     KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_NO,
     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
     KC_NO,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_ENT,        KC_BSPC,    KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
              OSL(_FN),      KC_LGUI, KC_SPC,                  OSM(MOD_LSFT), KC_SPC, OSL(_NAV)
  ),

  [_NAV] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     QK_LLCK, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
     _______, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  ),

  [_FN] = LAYOUT(
     KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
     QK_LLCK, RM_TOGG, KC_VOLD, KC_VOLU, KC_MUTE, _______,                            _______, RM_HUEU, RM_HUED, RM_NEXT, RM_PREV, QK_BOOT,
     MAC_LOCK,KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______,                            _______, RM_VALU, RM_VALD, RM_SPDU, RM_SPDD, EE_CLR,
     _______, KC_SLEP, KC_WAKE, _______, _______, _______, _______,  _______, _______, RM_SATU, RM_SATD, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  )
};

// ===== Combos =================================================================
// Combos live in combos.def (one line each); the X-macro below expands that
// file twice -- once to declare the PROGMEM key arrays, once to build key_combos[].

#define CM(name, out, ...) const uint16_t PROGMEM name[] = {__VA_ARGS__, COMBO_END};
#include "combos.def"
#undef CM

combo_t key_combos[] = {
#define CM(name, out, ...) COMBO(name, out),
#include "combos.def"
#undef CM
};

// ===== Custom keycodes ========================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC_LOCK:
            host_consumer_send(record->event.pressed ? 0x19E : 0);
            return false;
    }
    return true;
}

// ===== RGB indicators =========================================================

static void set_solid_hs(uint8_t hue, uint8_t sat, uint8_t val) {
    (void)val;
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(hue, sat, rgb_matrix_get_val());
}

static void apply_base_layer_rgb(void) {
    set_solid_hs(HSV_BLUE);
}

void keyboard_post_init_user(void) {
    default_layer_set((layer_state_t)1 << _COLEMAK);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    apply_base_layer_rgb();
    return state;
}

bool layer_lock_set_user(layer_state_t locked_layers) {
    if (is_layer_locked(_NAV)) {
        set_solid_hs(HSV_GREEN);
    } else if (is_layer_locked(_FN)) {
        set_solid_hs(HSV_TEAL);
    } else {
        apply_base_layer_rgb();
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_layer_locked(_NAV) || is_layer_locked(_FN)) {
        return state;
    }
    switch (get_highest_layer(state)) {
        case _NAV:
            set_solid_hs(HSV_GREEN);
            break;
        case _FN:
            set_solid_hs(HSV_TEAL);
            break;
        default:
            apply_base_layer_rgb();
            break;
    }
    return state;
}
