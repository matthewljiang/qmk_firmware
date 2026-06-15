// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Hold-free layout. The original port of my ZSA Moonlander Colemak-DHm layout
// leaned on sustained holds everywhere -- home-row mods plus layer-tap holds on
// the thumbs -- and that constant isometric holding caused hand tension. This
// version removes holding from the base layer entirely:
//
//   * Modifiers are ONE-SHOT (OSM) fired by COMBOS: squeeze a home-row key with
//     the bottom-row key below it (same finger) and the next key is modified.
//     They chain natively (fire Shift, fire Cmd, tap T -> Cmd+Shift+T) with no
//     holding. You CAN hold a combo'd mod if you want (e.g. Shift while tapping
//     arrows to extend a selection), but you never have to.
//   * SYM (symbols) is a ONE-SHOT LAYER (OSL): tap, type one symbol, it exits.
//   * NUM and NAV are TOGGLES (TG): tap to enter, tap again to leave -- good for
//     sustained numpad entry or arrow navigation without holding anything.
//   * Caps Word (CW_TOGG) replaces holding Shift for CONSTANT_NAMES / PascalCase.
//   * ONESHOT_TAP_TOGGLE (config.h) means double-tapping ANY one-shot locks it
//     on: double-tap SYM to lock the symbol layer.
//
// Thumb-light: the thumb cluster is nearly empty. Only THREE thumb keys are
// live; the rest are dead (KC_NO) so there is nothing awkward to reach for:
//   left  middle thumb -> Space        left  inner thumb -> OSL(SYM)  [trigger]
//                                       right inner thumb -> TG(AERO) [trigger]
//   (every other thumb key is unused)
//
// Modifiers live on two-finger home-row COMBOS, keeping the same finger -> mod
// identity as the old home-row mods (pinky Ctrl, ring Alt, middle Cmd, index
// Shift): each mod fires from its finger's home key plus the neighbour rolling
// inward. Shift is the outer pinky+index pinch (the index has no free inward
// neighbour). On BOTH hands so you can mod with the hand the letter isn't on:
//   A+R Ctrl   R+S Alt   S+T Cmd   A+T Shift(pinch)   (left, Colemak)
//   O+I Ctrl   I+E Alt   E+N Cmd   O+N Shift(pinch)   (right, Colemak)
//
// Backspace / Enter moved off the thumbs onto the two inner index keys (the
// center keys between the halves). Caps Word sits on the left pinky bottom.
//
// Layer access:
//   left  pinky row1 -> TG(NAV)        right pinky row1  -> TG(NUM)
//   top-right corner -> TT(MEDIA)      right inner thumb -> TG(AERO)
//
// Other combos (matched by Colemak keycode):
//   W+F = Tab   U+Y = Enter   Q+W = Esc   , + . = Delete   L+U = Backspace
enum custom_layers {
     _QWERTY,
     _COLEMAK,
     _SYM,
     _NAV,
     _NUM,
     _MEDIA,
     _AERO
};

// AeroSpace chords -- the _AERO layer fires the ctrl+alt (and ctrl+alt+shift)
// combos straight from ~/.config/aerospace/aerospace.toml, so AeroSpace needs no
// remap of its own. AeroSpace's key-mapping preset is 'qwerty', so these send
// raw keycodes and AeroSpace reads the QWERTY-position letter/number/symbol --
// independent of whichever base layer (Colemak/QWERTY) is active here.
#define AS_MOD(kc)  LCTL(LALT(kc))         // ctrl + alt + kc        (switch / focus / act)
#define AS_MODS(kc) LCTL(LALT(LSFT(kc)))   // ctrl + alt + shift + kc (move window / variants)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // QWERTY base -- pure letters on the home row (no mod-taps). Modifiers and
  // layers are reached from the one-shot keys around the edges; identical to the
  // Colemak base so muscle memory carries over.
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TT(_MEDIA),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TG(_NAV),KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TG(_NUM),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ENT,        KC_BSPC,       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
              KC_NO,         KC_SPC, OSL(_SYM),              TG(_AERO),   KC_NO,  KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TT(_MEDIA),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TG(_NAV),KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, TG(_NUM),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  KC_ENT,        KC_BSPC,       KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
              KC_NO,         KC_SPC, OSL(_SYM),              TG(_AERO),   KC_NO,  KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // SYM -- tap OSL(SYM) (left inner thumb) for one symbol, then it auto-exits;
  // double-tap to lock it on. Brackets live on the LEFT hand, open next to close
  // (` [ ] < > over ~ { } ( )); the less-common symbols live on the RIGHT hand
  // (_ + | over - = \). Modifiers are not here -- they live on the base-layer
  // home-row combos (see the bottom of this file).
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_GRV,  KC_LBRC, KC_RBRC, KC_LABK, KC_RABK,                            _______, _______, KC_UNDS, KC_PLUS, KC_PIPE, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_TILD, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,                            _______, _______, KC_MINS, KC_EQL,  KC_BSLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // NAV -- tap TG(NAV) (left pinky, row 1) to enter, tap again to leave. Arrows
  // on the right home row, Home/PgDn/PgUp/End above them. The left home row
  // carries one-shot CAGS modifiers (Ctrl/Alt/Cmd/Shift) -- tap a mod then an
  // arrow to jump/select, or hold the mod while tapping arrows to extend a range.
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // NUM -- tap TG(NUM) (right pinky, row 1) to enter, tap again to leave.
  // Calculator-style numpad on the right hand (7 8 9 / 4 5 6 / 1 2 3) with 0 on
  // the right outer thumb. Operators and = live on the SYM layer.
  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // MEDIA -- TT toggle (tap the top-right corner to enter, tap again to leave).
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
  ),

  // AERO -- AeroSpace window-manager control. Tap TG(_AERO) (right inner thumb,
  // mirror of the SYM trigger) to enter, tap again to leave. Every key fires a
  // ctrl+alt(+shift) chord straight from aerospace.toml; nothing here types a
  // letter. Mental split: LEFT hand = workspaces, RIGHT hand = the focused
  // window.
  //
  //   LEFT  -- workspace SWITCH on top, MOVE-window-to-workspace directly below:
  //     row0  1 2 3 4 5            row1  (shift) move win -> 1 2 3 4 5
  //     row2  Z G S | close newwin row3  (shift) move win -> Z G S | resize/service mode
  //   RIGHT -- act on the focused window:
  //     row0  focus prev/next | layout tiles/accordion | fullscreen
  //     row1  MOVE window  left/down/up/right | layout floating   (ctrl+alt+shift+arrows)
  //     row2  FOCUS window left/down/up/right                     (ctrl+alt+arrows, NAV-style home row)
  //     row3  resize - +  | rotate / rotate-rev | cycle padding
  [_AERO] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, AS_MOD(KC_1),  AS_MOD(KC_2),  AS_MOD(KC_3),  AS_MOD(KC_4),  AS_MOD(KC_5),         AS_MODS(KC_TAB), AS_MOD(KC_TAB), AS_MOD(KC_SLSH), AS_MOD(KC_COMM), AS_MOD(KC_F),    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, AS_MODS(KC_1), AS_MODS(KC_2), AS_MODS(KC_3), AS_MODS(KC_4), AS_MODS(KC_5),        _______,         AS_MODS(KC_LEFT), AS_MODS(KC_DOWN), AS_MODS(KC_UP), AS_MODS(KC_RGHT), AS_MODS(KC_SPC),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, AS_MOD(KC_Z),  AS_MOD(KC_G),  AS_MOD(KC_S),  AS_MOD(KC_Q),  AS_MOD(KC_ENT),       _______,         AS_MOD(KC_LEFT),  AS_MOD(KC_DOWN),  AS_MOD(KC_UP),  AS_MOD(KC_RGHT),  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, AS_MODS(KC_Z), AS_MODS(KC_G), AS_MODS(KC_S), AS_MOD(KC_R),  AS_MODS(KC_SCLN), _______,  _______, _______, AS_MOD(KC_MINS), AS_MOD(KC_EQL), AS_MOD(KC_O), AS_MODS(KC_O), AS_MOD(KC_P),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// Utility combos -- ported from the Moonlander, matched by Colemak keycode.
// W F U Y Q , . L are plain keys on both bases, so these fire on Colemak (and
// mostly on QWERTY too). The W+F=Tab and ,+.=Del combos are the only Tab/Delete
// on the board.
const uint16_t PROGMEM combo_tab[]  = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_L, KC_U, COMBO_END};

// One-shot modifier combos -- roll two adjacent home-row keys to fire that
// one-shot mod, on either hand. Finger -> mod follows the old CAGS home-row
// order (pinky Ctrl, ring Alt, middle Cmd, index Shift): each mod = its finger's
// home key + the neighbour toward the centre. Shift is the outer pinky+index
// pinch, since the index has no free inward neighbour. Defined by Colemak
// keycodes.
const uint16_t PROGMEM combo_lctl[] = {KC_A, KC_R, COMBO_END};       // pinky+ring
const uint16_t PROGMEM combo_lalt[] = {KC_R, KC_S, COMBO_END};       // ring+middle
const uint16_t PROGMEM combo_lgui[] = {KC_S, KC_T, COMBO_END};       // middle+index
const uint16_t PROGMEM combo_lsft[] = {KC_A, KC_T, COMBO_END};       // pinky+index pinch
const uint16_t PROGMEM combo_rsft[] = {KC_O, KC_N, COMBO_END};       // pinky+index pinch
const uint16_t PROGMEM combo_rgui[] = {KC_E, KC_N, COMBO_END};       // middle+index
const uint16_t PROGMEM combo_ralt[] = {KC_I, KC_E, COMBO_END};       // ring+middle
const uint16_t PROGMEM combo_rctl[] = {KC_O, KC_I, COMBO_END};       // pinky+ring

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

// Tint the board to match whichever layer is active. NAV and NUM are toggles, so
// the color stays on as a persistent reminder until you tap the toggle off.
layer_state_t layer_state_set_user(layer_state_t state) {
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
        case _MEDIA:
            set_solid_hs(HSV_TEAL);
            break;
        case _AERO:
            set_solid_hs(HSV_PURPLE);
            break;
        default:  // back on a base layer
            apply_base_layer_rgb();
            break;
    }
    return state;
}
