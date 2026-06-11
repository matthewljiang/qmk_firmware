// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
     _QWERTY,
     _COLEMAK,
     _LOWER,
     _RAISE,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                               KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LT(_LOWER,KC_HOME),  LT(_RAISE,KC_END), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LT(_WM,KC_SPC), KC_ENT, LT(_SYM,KC_BSPC), LT(_NAV,KC_SPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ), // _QWERTY thumbs: LT(_WM, KC_LGUI) replaces plain LGUI on the left outer

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  COLE_A,  COLE_R,  COLE_S,  COLE_T,  KC_G,                               KC_M,    COLE_N,  COLE_E,  COLE_I,  COLE_O,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    LT(_LOWER,KC_HOME),  LT(_RAISE,KC_END), KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LT(_WM,KC_SPC), KC_ENT, LT(_SYM,KC_BSPC), LT(_NAV,KC_SPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_UP,   _______, QK_BOOT, _______,                            KC_PSLS, KC_P7,   KC_P8,   KC_P9,   _______, KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                            KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, EE_CLR,  DF(_QWERTY), DF(_COLEMAK), _______, _______, _______,    _______, KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_TOGG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RM_HUEU, RM_SATU, RM_VALU, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, EE_CLR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Nav layer -- hold left thumb (Enter). Vim HJKL arrows live on the right-hand
  // home row; the left-hand home row keeps the CAGS mods so you can Shift/Cmd/Opt
  // + arrow to select. Word-jump (Opt+arrow) and PgUp/PgDn sit above the arrows.
  //
  // Editing additions (macOS):
  //   Left top row : delete to line-start (Cmd+Bksp), delete word back/fwd
  //                  (Opt+Bksp / Opt+Del), delete to line-end (Ctrl+K).
  //   Left bottom  : Cmd+Z/X/C/V undo/cut/copy/paste on the real Z X C V keys,
  //                  redo (Cmd+Shift+Z) on B.
  //   Right top    : OSM(Shift) -- tap it, then any movement key (arrow,
  //                  word-jump, Home/End) extends a selection ("shift a word").
  //   Right bottom : Cmd+A select-all.
  //
  // Window resize (above the right-hand arrows): Alt+- shrinks, Alt+= grows,
  // matching the window manager's resize shortcuts.
  //
  // Layer lock: tap QK_LLCK (top-left / Esc position) while NAV is held to keep
  // it on hands-free; tap it again to release. The board glows green while NAV
  // is locked so you can't forget you're in the (destructive) editing mode.
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_LLCK, _______,     _______,     _______,    _______,     _______,            _______,    A(KC_MINS), A(KC_EQL), _______, _______,        _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_BSPC),  A(KC_BSPC),  A(KC_DEL),  C(KC_K),     _______,            A(KC_LEFT), KC_PGDN, KC_PGUP, A(KC_RGHT), OSM(MOD_LSFT),  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCTL,     KC_LALT,     KC_LGUI,    KC_LSFT,     _______,            KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT,    KC_HOME,        KC_END,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_Z),     G(KC_X),     G(KC_C),    G(KC_V),     SGUI(KC_Z), _______,  _______, G(KC_A),   _______, _______,    _______,        _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Symbol layer -- hold right-inner thumb (Backspace). Frequency-optimized for
  // TypeScript + Lua/LazyVim. Bracket pairs mirror across the hands (open on the
  // left, close on the right) on the home row: ( ) on the index fingers, { } on
  // the middle, < > on the ring. = and | sit on the index reaches; the [ ] pair
  // stacks on the top row directly above ( ). Arithmetic ( + - * ) mirrors on the
  // top row; the bottom index fingers hold the two logic keys (! left, & right).
  // Colon, semicolon, slash, and question mark are left to the base layer, where
  // each is already a tap (or shift) away.
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_ASTR, KC_PLUS, KC_LBRC, _______,                            _______, KC_RBRC, KC_MINS, _______, KC_AT,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LABK, KC_LCBR, KC_LPRN, KC_EQL,                             KC_PIPE, KC_RPRN, KC_RCBR, KC_RABK, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PERC, KC_BSLS, KC_UNDS, KC_EXLM, KC_DLR,  _______,          _______, KC_GRV,  KC_AMPR, _______, KC_CIRC, KC_TILD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Window-manager layer -- hold left-outer thumb (Cmd) or lock it on. The layer
  // synthesizes the Ctrl+Alt(+Shift) chords AeroSpace already listens for, so a
  // single tap drives the window manager instead of a four-key chord. AeroSpace
  // config is untouched; other input devices keep working as before.
  //
  // Right hand = window focus/move (mirrors NAV's arrow placement):
  //   focus (Ctrl+Alt+arrow)        on the home row  H J K L  = ← ↓ ↑ →
  //   move  (Ctrl+Alt+Shift+arrow)  directly above   Y U I O  = ← ↓ ↑ →
  //   resize -/+ (Ctrl+Alt+ -/= )   right home pinky  ; '
  //   workspace back-and-forth       P  ·  fullscreen  Del
  //
  // Left hand = workspaces + actions:
  //   switch  workspace 1-5 (Ctrl+Alt+n)         number row  1 2 3 4 5
  //   move-to workspace 1-5 (Ctrl+Alt+Shift+n)   row below   Q W E R T
  //   lettered workspaces on their own keys:  Z = Zoom, S = Slack, G = Gmail
  //   A = new terminal · D = float/tile toggle
  //   X = close · C = rotate · V = cycle padding · B = tiles/horiz-vert toggle
  //
  // QK_LLCK (top-left / Esc position): lock the layer on hands-free; tap again to
  // release. Board glows purple while WM is active or locked.
  [_WM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_LLCK, C(A(KC_1)),    C(A(KC_2)),    C(A(KC_3)),    C(A(KC_4)),    C(A(KC_5)),            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, C(A(S(KC_1))), C(A(S(KC_2))), C(A(S(KC_3))), C(A(S(KC_4))), C(A(S(KC_5))),        C(A(S(KC_LEFT))), C(A(S(KC_DOWN))), C(A(S(KC_UP))), C(A(S(KC_RGHT))), C(A(KC_TAB)), C(A(KC_F)),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, C(A(KC_ENT)),  C(A(KC_S)),    C(A(S(KC_SPC))), _______,     C(A(KC_G)),           C(A(KC_LEFT)),    C(A(KC_DOWN)),    C(A(KC_UP)),    C(A(KC_RGHT)),    C(A(KC_MINS)), C(A(KC_EQL)),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, C(A(KC_Z)),    C(A(KC_Q)),    C(A(KC_O)),    C(A(KC_P)),    C(A(KC_SLSH)), _______,  _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
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
// warning; restore the base-layer color when it unlocks.
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

// Tint the board to match whichever momentary layer is active. Locked NAV keeps
// its green indicator (handled above), so bail out early when it's locked.
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_layer_locked(_NAV) || is_layer_locked(_WM)) {
        return state;
    }
    switch (get_highest_layer(state)) {
        case _LOWER:
            set_solid_hs(HSV_ORANGE);
            break;
        case _RAISE:
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
