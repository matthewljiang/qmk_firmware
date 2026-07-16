// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
     _COLEMAK,
     _NAV,
     _FN,
     _SHORTCUT // opened by OSL on the right thumb -- edit/system shortcuts
};

enum custom_keycodes {
    MAC_LOCK = SAFE_RANGE,
    BAILOUT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
     BAILOUT,LCA(KC_1),LCA(KC_2),LCA(KC_3),LCA(KC_4),LCA(KC_5),        LCA(KC_6),LCA(KC_7),LCA(KC_8),LCA(KC_9),LCA(KC_0),KC_NO,
     KC_NO,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                     KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_NO,
     KC_ESC, KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                     KC_M,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,
     KC_NO,  KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_ENT, KC_BSPC,KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,KC_NO,
              OSL(_FN), MO(_NAV), KC_SPC,                        OSM(MOD_LSFT), OSL(_SHORTCUT), KC_NO
  ),

  [_NAV] = LAYOUT(
     _______,_______,      _______,      _______,      _______,      _______,                  _______,_______,_______,_______,_______,_______,
     _______,_______,      _______,      _______,      _______,      _______,                  _______,_______,_______,_______,_______,_______,
     _______,OSM(MOD_LCTL),OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LSFT),_______,                  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______,
     _______,_______,      _______,      _______,      _______,      _______,_______,_______,_______,_______,_______,_______,_______,_______,
              _______, _______, _______,   _______, _______, _______
  ),

  [_FN] = LAYOUT(
     KC_F11,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                    KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F12,
     _______, RM_TOGG,KC_VOLD,KC_VOLU,KC_MUTE,_______,                  _______,RM_HUEU,RM_HUED,RM_NEXT,RM_PREV,QK_BOOT,
     MAC_LOCK,KC_MPRV,KC_MSTP,KC_MPLY,KC_MNXT,_______,                  _______,RM_VALU,RM_VALD,RM_SPDU,RM_SPDD,EE_CLR,
     _______, KC_SLEP,KC_WAKE,_______,_______,_______,_______,_______,RM_SATU,RM_SATD,_______,_______,_______,_______,
              _______, _______, _______,   _______, _______, _______
  ),

  // _SHORTCUT -- opened by OSL on the right thumb; left hand fires one shortcut.
  // Edit ops sit under their Colemak-DH legends so they read as mnemonics:
  //   Z/X/C/V = undo / cut / copy / paste     R = redo (Cmd-Shift-Z)
  //   A = select-all   S = save   F = find   G = find-next   W = close (Cmd-W)
  //   T = tmux prefix (C-a).
  // Unused keys fall through to _COLEMAK -- BAILOUT (top-left) stays reachable
  // to escape, at the cost of a slip typing its base letter.
  [_SHORTCUT] = LAYOUT(
     _______,_______,   _______,        _______,     _______,   _______,                  _______,_______,_______,_______,_______,_______,
     _______,_______,   LGUI(KC_W),     LGUI(KC_F),  _______,   _______,                  _______,_______,_______,_______,_______,_______,
     _______,LGUI(KC_A),LSFT(LGUI(KC_Z)),LGUI(KC_S), LCTL(KC_A),LGUI(KC_G),               _______,_______,_______,_______,_______,_______,
     _______,LGUI(KC_Z),LGUI(KC_X),     LGUI(KC_C),  _______,   LGUI(KC_V),_______,_______,_______,_______,_______,_______,_______,_______,
                   _______, _______, _______,                              _______, _______, _______
  ),
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
        case BAILOUT:
            if (record->event.pressed) {
                clear_oneshot_mods();
                clear_oneshot_locked_mods();
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                clear_mods();
                layer_clear();       // drop any toggled/locked layers to base
                caps_word_off();
            }
            return false;
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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NAV:
            set_solid_hs(HSV_GREEN);
            break;
        case _FN:
            set_solid_hs(HSV_TEAL);
            break;
        case _SHORTCUT:
            set_solid_hs(HSV_MAGENTA);   // "shortcut armed"
            break;
        default:
            apply_base_layer_rgb();
            break;
    }
    return state;
}
