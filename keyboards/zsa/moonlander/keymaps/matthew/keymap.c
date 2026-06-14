// Copyright 2024 Matthew Jiang
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Moonlander adaptation of my Iris CE keymap. Mirrors the Iris design as closely
// as the hardware allows: Colemak Mod-DH + QWERTY bases, CAGS home-row mods, a
// SpaceFn-style thumb cluster, and FN / NAV / SYM / WM layers with text-editing
// keys, layer lock, and per-layer RGB.
//
// Mapping notes (Moonlander has more keys than the Iris):
//   - The Iris's six main columns per hand map 1:1 onto the Moonlander's outer
//     six columns (x0-x5 left, x11-x16 right).
//   - The Iris reaches _FN by holding inner bottom-row keys. Here those
//     LT(_FN, Home/End) keys live on the Moonlander's extra inner-index column
//     on the home row (left x6, right x10), tapped for Home/End as on the Iris.
//   - The Iris thumbs are placed on the Moonlander's most comfortable thumb
//     positions rather than its far lower arc. Each hand's primary lands on the
//     big red key, the next on the small key directly below it:
//       big red : WM/Tab (left)        | NAV/Space (right, primary)
//       below   : Enter  (left)        | SYM/Bksp  (right)
//       arc     : LGUI   (left)        | RALT      (right)
//     The outer arc key on each side, the extra inner column on rows 0/1, and
//     the extra bottom row are left KC_NO on base / transparent elsewhere.

#include QMK_KEYBOARD_H

enum custom_layers {
     _QWERTY,
     _COLEMAK,
     _FN,
     _NAV,
     _SYM,
     _WM
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

// Thumb / inner-index layer-taps (tap = key / hold = layer).
#define FN_HOME   LT(_FN,  KC_HOME)
#define FN_END    LT(_FN,  KC_END)
#define WM_TAB    LT(_WM,  KC_TAB)
#define SYM_BSPC  LT(_SYM, KC_BSPC)
#define NAV_SPC   LT(_NAV, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,             KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_NO,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,             KC_NO,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    FN_HOME,           FN_END,  KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,           WM_TAB,            NAV_SPC,          KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                        KC_ENT,  KC_LGUI, KC_NO,             KC_RALT, SYM_BSPC, KC_NO
  ),

  [_COLEMAK] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,             KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_NO,             KC_NO,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
    KC_ESC,  COLE_A,  COLE_R,  COLE_S,  COLE_T,  KC_G,    FN_HOME,           FN_END,  KC_M,    COLE_N,  COLE_E,  COLE_I,  COLE_O,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,           WM_TAB,            NAV_SPC,          KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                        KC_ENT,  KC_LGUI, KC_NO,             KC_RALT, SYM_BSPC, KC_NO
  ),

  // Function / numpad / system layer -- hold either inner-index key (the
  // LT(_FN,...) tucked beside G/H on the home row). Merges the old LOWER/RAISE:
  //   Number row : F1-F12.
  //   Right hand : numpad 7 8 9 / 4 5 6 / 1 2 3, 0 on the right thumb, and the
  //                / * - + . operators in the inner/outer columns.
  //   Left hand  : media transport + volume, RGB hue/sat/val (UP on the upper
  //                row, DOWN on the bottom row).
  //   System     : QK_BOOT / EE_CLR on the right, DF(_QWERTY)/DF(_COLEMAK) on
  //                the left bottom row. Glows teal.
  [_FN] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,           KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_NEXT, KC_VOLU, KC_TRNS,           KC_TRNS, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, QK_BOOT,
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_MSTP, KC_VOLD, KC_TRNS,           KC_TRNS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, EE_CLR,
    RM_HUED, RM_SATD, RM_VALD, DF(_QWERTY), DF(_COLEMAK), KC_TRNS,                    KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,           KC_P0,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Nav layer -- hold left thumb (Enter). Vim HJKL arrows on the right home row;
  // the left home row keeps the CAGS mods for Shift/Cmd/Opt + arrow selections.
  //   Top-left QK_LLCK : tap while Nav is held to lock it on hands-free.
  //   Left top row     : del to line-start (Cmd+Bksp), del word back/fwd
  //                      (Opt+Bksp / Opt+Del), del to line-end (Ctrl+K).
  //   Left bottom      : Cmd+Z/X/C/V undo/cut/copy/paste, redo (Cmd+Shift+Z) on B.
  //   Right top        : OSM(Shift) -- tap then a movement key to extend a select.
  //   Right bottom     : Cmd+A select-all.
  //   Window resize    : Alt+- / Alt+= above the right-hand arrows. Glows green.
  [_NAV] = LAYOUT(
    QK_LLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, A(KC_MINS), A(KC_EQL), KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, G(KC_BSPC), A(KC_BSPC), A(KC_DEL), C(KC_K), KC_TRNS, KC_TRNS,   KC_TRNS, A(KC_LEFT), KC_PGDN, KC_PGUP, A(KC_RGHT), OSM(MOD_LSFT), KC_DEL,
    KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS,           KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
    KC_TRNS, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), SGUI(KC_Z),                          G(KC_A), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,           KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Symbol layer -- hold right-inner thumb (Backspace). Left upper row mirrors
  // the shifted number row (! @ # $ %). Bracket pairs sit open-next-to-close,
  // balanced across hands: [ ] ( ) left, { } < > right. Right upper row carries
  // = + - * | ; bottom rows hold ` \ _ (left) and & ^ ~ (right). Sentence
  // punctuation keeps its , . / and ; ' columns. Glows gold.
  [_SYM] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,           KC_TRNS, KC_TRNS, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_PIPE,
    KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TRNS,           KC_TRNS, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_SCLN, KC_QUOT,
    KC_TRNS, KC_GRV,  KC_BSLS, KC_UNDS, KC_TRNS, KC_TRNS,                             KC_AMPR, KC_CIRC, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,           KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Window-manager layer -- hold left-middle thumb (WM/Tab) or lock it on. Each
  // key synthesizes the Ctrl+Alt(+Shift) chord AeroSpace already listens for.
  //   Right hand : focus (Ctrl+Alt+arrow) on the home row H J K L; move
  //                (Ctrl+Alt+Shift+arrow) on the row above; resize -/+ on the
  //                right home pinky; workspace back-and-forth + fullscreen.
  //   Left hand  : switch workspace 1-5 (number row), move-to workspace 1-5
  //                (row below), lettered actions on the bottom row.
  //   QK_LLCK    : top-left, locks the layer on. Glows purple.
  [_WM] = LAYOUT(
    QK_LLCK, C(A(KC_1)), C(A(KC_2)), C(A(KC_3)), C(A(KC_4)), C(A(KC_5)), KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, C(A(S(KC_1))), C(A(S(KC_2))), C(A(S(KC_3))), C(A(S(KC_4))), C(A(S(KC_5))), KC_TRNS,  KC_TRNS, C(A(S(KC_LEFT))), C(A(S(KC_DOWN))), C(A(S(KC_UP))), C(A(S(KC_RGHT))), C(A(KC_TAB)), C(A(KC_F)),
    KC_TRNS, C(A(KC_ENT)), C(A(KC_S)), C(A(S(KC_SPC))), KC_TRNS, C(A(KC_G)), KC_TRNS, KC_TRNS, C(A(KC_LEFT)), C(A(KC_DOWN)), C(A(KC_UP)), C(A(KC_RGHT)), C(A(KC_MINS)), C(A(KC_EQL)),
    KC_TRNS, C(A(KC_Z)), C(A(KC_Q)), C(A(KC_O)), C(A(KC_P)), C(A(KC_SLSH)),                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,           KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
  ),
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

// Boot into Colemak every time the board is plugged in. The DF(_QWERTY) /
// DF(_COLEMAK) keys still switch layouts at runtime, but the choice is not
// persisted -- a reset always comes back up on Colemak.
void keyboard_post_init_user(void) {
    default_layer_set((layer_state_t)1 << _COLEMAK);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    apply_base_layer_rgb();
    return state;
}

// While the NAV layer is locked, glow green as a "you're in editing mode"
// warning; WM locked glows purple; otherwise restore the base-layer color.
bool layer_lock_set_user(layer_state_t locked_layers) {
    if (is_layer_locked(_NAV)) {
        set_solid_hs(HSV_GREEN);
    } else if (is_layer_locked(_WM)) {
        set_solid_hs(HSV_PURPLE);
    } else {
        apply_base_layer_rgb();
    }
    return true;
}

// Tint the board to match whichever momentary layer is active. Locked NAV/WM
// keep their indicators (handled above), so bail out early when locked.
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_layer_locked(_NAV) || is_layer_locked(_WM)) {
        return state;
    }
    switch (get_highest_layer(state)) {
        case _FN:
            set_solid_hs(HSV_TEAL);
            break;
        case _NAV:
            set_solid_hs(HSV_GREEN);
            break;
        case _SYM:
            set_solid_hs(HSV_GOLD);
            break;
        case _WM:
            set_solid_hs(HSV_PURPLE);
            break;
        default:  // back on a base layer
            apply_base_layer_rgb();
            break;
    }
    return state;
}
