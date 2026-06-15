// Copyright 2024 Matthew Jiang
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Moonlander adaptation of my Iris CE keymap. Synced to the Iris hold-free
// philosophy: home-row mods removed, modifiers now fired by one-shot combos on
// adjacent home-row pairs (same CAGS finger identity -- pinky Ctrl, ring Alt,
// middle Cmd, index Shift):
//   A+R Ctrl   R+S Alt   S+T Cmd   A+T Shift   (left, Colemak)
//   O+I Ctrl   I+E Alt   E+N Cmd   O+N Shift   (right, Colemak)
//
// Layer access (held, Moonlander thumb cluster and inner-index column):
//   big red left  : WM/Tab (hold)       big red right : NAV/Space (hold)
//   below left    : Enter               below right   : SYM/Bksp (hold)
//   inner-index   : FN/Home (hold)      inner-index   : FN/End (hold)
//
// Other combos (matched by Colemak keycode):
//   W+F = Tab   U+Y = Enter   Q+W = Esc   , + . = Delete   L+U = Backspace

#include QMK_KEYBOARD_H

enum custom_layers {
     _QWERTY,
     _COLEMAK,
     _FN,
     _NAV,
     _SYM,
     _WM
};

// AeroSpace chords (same macros as the Iris _AERO layer).
#define AS_MOD(kc)  LCTL(LALT(kc))         // ctrl + alt + kc
#define AS_MODS(kc) LCTL(LALT(LSFT(kc)))   // ctrl + alt + shift + kc

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
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    FN_HOME,           FN_END,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,           WM_TAB,            NAV_SPC,          KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                        KC_ENT,  KC_LGUI, KC_NO,             KC_RALT, SYM_BSPC, KC_NO
  ),

  [_COLEMAK] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,             KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_NO,             KC_NO,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    FN_HOME,           FN_END,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
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
    KC_TRNS, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), KC_TRNS, KC_TRNS,   KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
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

  // Window-manager / AeroSpace layer -- hold left-middle thumb (WM/Tab) or lock
  // it on with QK_LLCK. Fires ctrl+alt(+shift) chords from aerospace.toml
  // directly (AeroSpace preset 'qwerty', so keycodes are QWERTY-position).
  //
  //   LEFT  -- workspaces:
  //     num row  switch to workspace 1-5          (ctrl+alt+1..5)
  //     row 1    move window to workspace 1-5     (ctrl+alt+shift+1..5)
  //     home row Z G S Q | close / new-win        (ctrl+alt+Z/G/S/Q/Enter)
  //     bottom   (shift variants) Z G S | resize/service mode
  //   RIGHT -- focused window:
  //     num row  focus prev/next | layout tiles/accordion | fullscreen
  //     row 1    MOVE window left/down/up/right | layout floating
  //     home row FOCUS window left/down/up/right  (ctrl+alt+arrows)
  //     bottom   resize -/+ | rotate | cycle padding | fullscreen-zoom
  [_WM] = LAYOUT(
    QK_LLCK, AS_MOD(KC_1),  AS_MOD(KC_2),  AS_MOD(KC_3),  AS_MOD(KC_4),  AS_MOD(KC_5),  KC_TRNS,   KC_TRNS, AS_MODS(KC_TAB), AS_MOD(KC_TAB), AS_MOD(KC_SLSH), AS_MOD(KC_COMM), AS_MOD(KC_F),    KC_TRNS,
    KC_TRNS, AS_MODS(KC_1), AS_MODS(KC_2), AS_MODS(KC_3), AS_MODS(KC_4), AS_MODS(KC_5), KC_TRNS,   KC_TRNS, KC_TRNS,         AS_MODS(KC_LEFT), AS_MODS(KC_DOWN), AS_MODS(KC_UP), AS_MODS(KC_RGHT), AS_MODS(KC_SPC),
    KC_TRNS, AS_MOD(KC_Z),  AS_MOD(KC_G),  AS_MOD(KC_S),  AS_MOD(KC_Q),  AS_MOD(KC_ENT), KC_TRNS,  KC_TRNS, KC_TRNS,         AS_MOD(KC_LEFT),  AS_MOD(KC_DOWN),  AS_MOD(KC_UP),  AS_MOD(KC_RGHT),  KC_TRNS,
    KC_TRNS, AS_MODS(KC_Z), AS_MODS(KC_G), AS_MODS(KC_S), AS_MOD(KC_R),  AS_MODS(KC_SCLN),                  KC_TRNS, AS_MOD(KC_MINS), AS_MOD(KC_EQL), AS_MOD(KC_O), AS_MODS(KC_O), AS_MOD(KC_P),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,           KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

// Utility combos -- matched by Colemak keycode (fire on the Colemak base;
// on QWERTY the W+F and L+U combos won't fire because F/L are at different
// physical positions). W+F=Tab and ,+.=Del are the only Tab/Delete on base.
const uint16_t PROGMEM combo_tab[]  = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_L, KC_U, COMBO_END};

// One-shot modifier combos -- roll two adjacent home-row keys for that mod.
// Finger -> mod follows CAGS order (pinky Ctrl, ring Alt, middle Cmd, index
// Shift). Shift is the pinky+index pinch (index has no free inward neighbour).
// Defined by Colemak keycodes (A R S T left | N E I O right).
const uint16_t PROGMEM combo_lctl[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM combo_lalt[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM combo_lgui[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_lsft[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM combo_rsft[] = {KC_O, KC_N, COMBO_END};
const uint16_t PROGMEM combo_rgui[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM combo_ralt[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM combo_rctl[] = {KC_O, KC_I, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_tab,  KC_TAB),
    COMBO(combo_ent,  KC_ENT),
    COMBO(combo_esc,  KC_ESC),
    COMBO(combo_del,  KC_DEL),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_lctl, OSM(MOD_LCTL)),
    COMBO(combo_lalt, OSM(MOD_LALT)),
    COMBO(combo_lgui, OSM(MOD_LGUI)),
    COMBO(combo_lsft, OSM(MOD_LSFT)),
    COMBO(combo_rsft, OSM(MOD_RSFT)),
    COMBO(combo_rgui, OSM(MOD_RGUI)),
    COMBO(combo_ralt, OSM(MOD_RALT)),
    COMBO(combo_rctl, OSM(MOD_RCTL)),
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
