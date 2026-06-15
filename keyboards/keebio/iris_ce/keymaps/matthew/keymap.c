// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Ported from the ZSA Moonlander Colemak-DHm layout (Oryx hash aOMg7/m5XPwj).
// The Moonlander's gaming QWERTY layer is intentionally dropped; this board
// keeps its own QWERTY base instead. The Moonlander has no window-manager
// layer, so that is dropped too.
//
// Layer access -- all on the thumb cluster (tap = the legend, hold = the layer):
//   hold left Space  -> NUM    (numpad on the right hand)
//   hold Enter       -> NAV    (arrows / home-end / page on the right hand)
//   hold right Space -> SYM    (bracket pairs on the left hand)
//   hold Backspace   -> SYM2   (_ + | - = \  on the right hand)
//     hold X in NUM  -> SYM2   (also reachable nested, like Moonlander MO(5))
//   tap left-outer   -> MEDIA  (TT toggle: media transport + RGB)
//
// Combos (defined by keycode, so they fire on the Colemak base; on QWERTY the
// W+F=Tab and L+U=Backspace combos won't fire because F and L are home-row
// mod-taps there):
//   W+F = Tab   U+Y = Enter   Q+W = Esc   , + . = Delete   L+U = Backspace
enum custom_layers {
     _QWERTY,
     _COLEMAK,
     _SYM,
     _NAV,
     _NUM,
     _SYM2,
     _MEDIA
};

// Home row mods (CAGS: Ctrl, Alt, GUI/Cmd, Shift) -- tuned for macOS
// QWERTY home row: A S D F | J K L ;
#define HOME_A    LCTL_T(KC_A)
#define HOME_S    LALT_T(KC_S)
#define HOME_D    LGUI_T(KC_D)
#define HOME_F    LSFT_T(KC_F)

#define HOME_J    RSFT_T(KC_J)
#define HOME_K    RGUI_T(KC_K)
#define HOME_L    LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// Same CAGS scheme for the Colemak home row: A R S T | N E I O
#define COLE_A    LCTL_T(KC_A)
#define COLE_R    LALT_T(KC_R)
#define COLE_S    LGUI_T(KC_S)
#define COLE_T    LSFT_T(KC_T)

#define COLE_N    RSFT_T(KC_N)
#define COLE_E    RGUI_T(KC_E)
#define COLE_I    LALT_T(KC_I)
#define COLE_O    RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // QWERTY base -- layers are reached from the thumb cluster (see the header
  // comment), identical to the Colemak base, so muscle memory carries over.
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                               KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,  KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                       TT(_MEDIA), LT(_NUM,KC_SPC), LT(_NAV,KC_ENT),   LT(_SYM2,KC_BSPC), LT(_SYM,KC_SPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  COLE_A,  COLE_R,  COLE_S,  COLE_T,  KC_G,                               KC_M,    COLE_N,  COLE_E,  COLE_I,  COLE_O,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_TAB,  KC_DEL,  KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                       TT(_MEDIA), LT(_NUM,KC_SPC), LT(_NAV,KC_ENT),   LT(_SYM2,KC_BSPC), LT(_SYM,KC_SPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // SYM -- hold right Space. Bracket pairs live on the LEFT hand, open next
  // to close: ` [ ] < > on the upper row, ~ { } ( ) on the home row. Tap the
  // top-left key (Esc position) to lock the layer hands-free; tap again to release.
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_LLCK, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_GRV,  KC_LBRC, KC_RBRC, KC_LABK, KC_RABK,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_TILD, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // NAV -- hold Enter. Arrows on the right home row, Home/PgDn/PgUp/End
  // above them. The left home row carries dedicated CAGS modifiers
  // (Ctrl/Alt/Cmd/Shift) for Shift/Cmd/Opt + arrow selection. Tap the top-left
  // key (Esc) to lock the layer; tap again to release.
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_LLCK, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // NUM -- hold left Space. Calculator-style numpad on the right hand (7 8 9 /
  // 4 5 6 / 1 2 3) with 0 on the right outer thumb (the base-layer RAlt key).
  // The left hand carries a Left Shift (for shifted digits) and MO(_SYM2) for
  // the nested symbol layer.
  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LSFT, MO(_SYM2), _______, _______, _______, _______,  _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // SYM2 -- hold Backspace (right thumb), or nested under NUM (hold left Space,
  // then hold X). The less-common symbols on the right hand: _ + | on the upper
  // row, - = \ on the home row.
  [_SYM2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UNDS, KC_PLUS, KC_PIPE, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_MINS, KC_EQL,  KC_BSLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // MEDIA -- TT toggle (tap the left-outer thumb to enter, tap again to leave).
  // Left hand: media transport + volume, with DF(_QWERTY)/DF(_COLEMAK) base
  // switches on the bottom row. Right hand: RGB controls. QK_BOOT and EE_CLR
  // sit in the top-right / right-pinky corners for reflashing.
  [_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                            _______, RM_HUEU, RM_HUED, RM_NEXT, RM_PREV, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______,                            _______, RM_VALU, RM_VALD, _______, RM_TOGG, EE_CLR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_SLEP, KC_WAKE, DF(_QWERTY), DF(_COLEMAK), _______, _______,  _______, _______, RM_SATU, RM_SATD, RM_SPDU, RM_SPDD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// Combos -- ported from the Moonlander. Matched by keycode, so they fire on the
// Colemak base where W F U Y Q , . are all plain keys. On the QWERTY base the
// W+F=Tab and L+U=Backspace combos will not fire (F and L are home-row mod-taps
// there); the other three work on both bases.
const uint16_t PROGMEM combo_tab[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_L, KC_U, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_ent, KC_ENT),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_bspc, KC_BSPC),
};

// Set a solid color from an HSV_* macro while KEEPING the current brightness.
// The macro's value component is intentionally ignored and replaced with
// rgb_matrix_get_val(), so RM_VALU/RM_VALD adjustments survive layer changes.
static void set_solid_hs(uint8_t hue, uint8_t sat, uint8_t val) {
    (void)val;  // discard the macro's full-brightness value
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(hue, sat, rgb_matrix_get_val());
}

// Paint the solid RGB color for the active base layer:
//   _QWERTY  -> red
//   _COLEMAK -> blue
static void apply_base_layer_rgb(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            set_solid_hs(HSV_BLUE);
            break;
        case _QWERTY:
            set_solid_hs(HSV_RED);
            break;
    }
}

// Boot into Colemak every time the board is plugged in. The DF() keys on MEDIA
// still switch layouts at runtime, but the choice is not persisted -- a reset
// always comes back up on Colemak.
void keyboard_post_init_user(void) {
    default_layer_set((layer_state_t)1 << _COLEMAK);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    apply_base_layer_rgb();
    return state;
}

// While NAV or SYM is locked, hold its indicator color so you can't forget the
// layer is on; restore the base-layer color when it unlocks.
bool layer_lock_set_user(layer_state_t locked_layers) {
    if (is_layer_locked(_NAV)) {
        set_solid_hs(HSV_GREEN);
    } else if (is_layer_locked(_SYM)) {
        set_solid_hs(HSV_GOLD);
    } else {
        apply_base_layer_rgb();
    }
    return true;
}

// Tint the board to match whichever momentary layer is active. Locked NAV/SYM
// keep their indicators (handled above), so bail out early when locked.
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_layer_locked(_NAV) || is_layer_locked(_SYM)) {
        return state;
    }
    switch (get_highest_layer(state)) {
        case _SYM:
            set_solid_hs(HSV_GOLD);
            break;
        case _NAV:
            set_solid_hs(HSV_GREEN);
            break;
        case _NUM:
            set_solid_hs(HSV_ORANGE);
            break;
        case _SYM2:
            set_solid_hs(HSV_PURPLE);
            break;
        case _MEDIA:
            set_solid_hs(HSV_TEAL);
            break;
        default:  // back on a base layer
            apply_base_layer_rgb();
            break;
    }
    return state;
}
