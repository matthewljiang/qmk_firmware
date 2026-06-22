// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Iris CE adaptation of my latest ZSA Moonlander Colemak-DHm layout (the Oryx
// "combo-heavy / reduced-footprint" design). The base layer carries letters and
// almost nothing else -- numbers, symbols, brackets, Tab/Enter/Esc/Backspace
// and the layer launcher are all COMBOS, so the physical key count stays tiny.
//
// Modifiers (the new scheme -- NOT the old home-row-pair mod combos):
//   * Ctrl  -- OSM on BOTH outer pinky columns, home row   (left + right)
//   * Alt   -- OSM on BOTH outer pinky columns, bottom row  (left + right)
//   * Shift -- OSM on the right thumb
//   * Cmd   -- plain GUI hold on the left thumb (held for Cmd+Tab / Cmd+click)
// They are one-shot (OSM): tap a mod, then the next key is modified; they chain
// (Shift then Cmd then T -> Cmd+Shift+T) and can be held if you prefer. Double-
// tapping any one-shot locks it on (ONESHOT_TAP_TOGGLE in config.h).
//
// Numbers -- VERTICAL same-finger combos (top row + home row of one finger):
//   Q+A 1   W+R 2   F+S 3   P+T 4   B+G 5      (left, Colemak)
//   J+M 6   L+N 7   U+E 8   Y+I 9   '+O 0      (right, Colemak)
// The number row is also populated as a convenience (the Iris has the row), but
// the combos mean you rarely leave the home block.
//
// Symbols -- horizontal home-row combos:
//   A+R `    N+E -    E+I =    I+O \           (shifted: ~ _ + |)
//
// Brackets -- horizontal bottom-row combos, open-next-to-close across the hands:
//   Z+X <   X+C {   C+D [   D+V (             (left, opening)
//   K+H )   H+, ]   ,+. }   .+/ >             (right, closing)
//
// Utility combos (matched by Colemak keycode):
//   W+F Tab   U+Y Enter   Q+W Esc   L+U Backspace
//
// Layer launcher:
//   A+R+S+T (all four left home keys) -> OSL(_FN)   [system / media / F-keys]
//   N+E+I   (right home row)          -> TG(_WORD)  [programming-word combos]
//   R+S+T   (left home, no pinky)     -> TG(_WORK)  [sales-tax domain combos]
//   right thumb -> OSL(_NAV)                        [arrows / navigation]
//   _FN -> TG(_AERO)                                [AeroSpace window manager]
//
// Thumb-light cluster (3 keys + 1 inner-index per hand):
//   left  : OSL(_FN)  Cmd   Space        | inner-index: Enter
//   right : Space     Shift OSL(_NAV)     | inner-index: Backspace

#include QMK_KEYBOARD_H

enum custom_layers {
     _COLEMAK,
     _QWERTY,
     _NAV,
     _FN,
     _AERO,
     _WORD,   // programming words, combo-driven (N+E+I)
     _WORK    // sales-tax / domain words, combo-driven (R+S+T)
};

enum custom_keycodes {
    MAC_LOCK = SAFE_RANGE,   // consumer "Lock" (macOS lock screen)

    // _WORD layer (programming flavour) -- each types a common code token. They
    // are NOT on individual keys; they fire from two-key COMBOS that only work
    // while _WORD is active (see combo_should_trigger). Every one of these must
    // stay AFTER MAC_LOCK in this enum -- the gate uses `keycode > MAC_LOCK` to
    // recognise a word keycode. Combo pairs are listed next to each below.
    W_RETURN,     // R+E
    W_FUNCTION,   // F+N
    W_IMPORT,     // I+M
    W_EXPORT,     // E+X
    W_INCLUDE,    // I+N
    W_INTERFACE,  // I+F
    W_CONST,      // C+O
    W_STRUCT,     // S+T
    W_STRING,     // S+G
    W_PUBLIC,     // P+B
    W_PRIVATE,    // P+R
    W_POINTER,    // P+O
    W_PARAMS,     // P+A
    W_VARIABLE,   // V+R
    W_DEFINE,     // D+E
    W_DEFAULT,    // D+F
    W_DELETE,     // D+L
    W_DOCUMENT,   // D+O
    W_OBJECT,     // O+B
    W_BOOLEAN,    // B+L
    W_LENGTH,     // L+G
    W_VALUE,      // V+A
    W_RESULT,     // R+S
    W_REQUEST,    // R+Q
    W_RESPONSE,   // R+N
    W_CONTINUE,   // C+N
    W_CONTEXT,    // C+X
    W_CALLBACK,   // C+B
    W_UPDATE,     // U+P
    W_MESSAGE,    // M+E
    W_SWITCH,     // S+W

    // _WORK layer (sales-tax / tax-software domain words) -- fired by two-key
    // COMBOS that only work while _WORK is active (like the W_* set). Keep
    // WK_JURISDICTION first and WK_REFUND last (the gate/handlers range-check).
    WK_JURISDICTION, WK_TAXABILITY, WK_EXEMPT, WK_COMPLIANCE, WK_REGISTRATION,
    WK_CERTIFICATE, WK_THRESHOLD, WK_TRANSACTION, WK_LIABILITY, WK_REMITTANCE,
    WK_NEXUS, WK_SURCHARGE, WK_MARKETPLACE, WK_FACILITATOR, WK_CALCULATION,
    WK_DESTINATION, WK_SOURCING, WK_MUNICIPALITY, WK_LOCALITY, WK_DISTRICT,
    WK_REGION, WK_COUNTRY, WK_ADDRESS, WK_INVOICE, WK_CUSTOMER, WK_REFUND,
};

// AeroSpace chords -- the _AERO layer fires the ctrl+alt (and ctrl+alt+shift)
// combos straight from ~/.config/aerospace/aerospace.toml. AeroSpace's preset is
// 'qwerty', so these send raw keycodes and AeroSpace reads the QWERTY-position
// letter/number regardless of which base layer is active here.
#define AS_MOD(kc)  LCTL(LALT(kc))         // ctrl + alt + kc        (switch / focus / act)
#define AS_MODS(kc) LCTL(LALT(LSFT(kc)))   // ctrl + alt + shift + kc (move window / variants)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // COLEMAK base (boot default). Letters only on the home block; mods on the
  // pinky columns + thumbs; everything else is a combo. Glows blue.
  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM(MOD_LCTL),KC_A,KC_R,   KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    OSM(MOD_RCTL),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM(MOD_LALT),KC_Z,KC_X,   KC_C,    KC_D,    KC_V,    KC_ENT,        KC_BSPC,    KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RALT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
              OSL(_FN),      KC_LGUI, KC_SPC,                  KC_SPC, OSM(MOD_LSFT), OSL(_NAV)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // QWERTY alt-base (DF switch on _FN). Same mods/thumbs as Colemak, but because
  // the number/symbol/bracket combos are defined by Colemak key POSITIONS they
  // mostly won't fire here -- so this layer keeps a real number row and stays
  // self-sufficient as a plain-QWERTY fallback. Glows red.
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CW_TOGG, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM(MOD_LCTL),KC_A,KC_S,   KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, OSM(MOD_RCTL),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM(MOD_LALT),KC_Z,KC_X,   KC_C,    KC_V,    KC_B,    KC_ENT,        KC_BSPC,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RALT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
              OSL(_FN),      KC_LGUI, KC_SPC,                  KC_SPC, OSM(MOD_LSFT), OSL(_NAV)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // NAV -- tap OSL(_NAV) (right thumb) for a one-shot move, or double-tap to lock
  // it on (QK_LLCK top-left also locks). Arrows on the right home row, Home/PgDn/
  // PgUp/End above them. The left home row carries one-shot CAGS mods so you can
  // tap a mod then an arrow to jump/select, or hold the mod while arrowing to
  // extend a range. Glows green.
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_LLCK, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // FN -- the launcher / system layer. Reach it with the A+R+S+T home-row combo
  // (one-shot) or hold it via the left thumb OSL; QK_LLCK locks it on. Carries
  // F1-F12 on the number row, media transport + volume on the left, RGB matrix
  // controls on the right, QK_BOOT / EE_CLR for flashing, DF() base switches,
  // MAC_LOCK, and TG(_AERO) to enter the window-manager layer. Glows teal.
  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_LLCK, RM_TOGG, KC_VOLD, KC_VOLU, KC_MUTE, _______,                            _______, RM_HUEU, RM_HUED, RM_NEXT, RM_PREV, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     MAC_LOCK,KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______,                            TG(_AERO),RM_VALU,RM_VALD, RM_SPDU, RM_SPDD, EE_CLR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_SLEP, KC_WAKE, DF(_QWERTY), DF(_COLEMAK), _______, _______,  _______, _______, RM_SATU, RM_SATD, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // AERO -- AeroSpace window-manager control (carried over from my previous Iris
  // keymap; not in the Oryx export). Tap TG(_AERO) on _FN to enter, tap again to
  // leave. Every key fires a ctrl+alt(+shift) chord; nothing types a letter.
  // LEFT hand = workspaces, RIGHT hand = the focused window. Glows purple.
  //   LEFT  row1  switch ws 1-5     row2  Z G S | close newwin   row3  (shift) move-to-ws Z G S | resize/service
  //   RIGHT row1  focus prev/next | layout | fullscreen   row2  FOCUS l/d/u/r   row3  move/resize/rotate
  [_AERO] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, AS_MOD(KC_1),  AS_MOD(KC_2),  AS_MOD(KC_3),  AS_MOD(KC_4),  AS_MOD(KC_5),         AS_MODS(KC_TAB), AS_MOD(KC_TAB), AS_MOD(KC_SLSH), AS_MOD(KC_COMM), AS_MOD(KC_F),    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, AS_MODS(KC_1), AS_MODS(KC_2), AS_MODS(KC_3), AS_MODS(KC_4), AS_MODS(KC_5),        AS_MODS(KC_LEFT), AS_MODS(KC_DOWN), AS_MODS(KC_UP), AS_MODS(KC_RGHT), AS_MODS(KC_SPC), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, AS_MOD(KC_Z),  AS_MOD(KC_G),  AS_MOD(KC_S),  AS_MOD(KC_Q),  AS_MOD(KC_ENT),       AS_MOD(KC_LEFT),  AS_MOD(KC_DOWN),  AS_MOD(KC_UP),  AS_MOD(KC_RGHT),  AS_MOD(KC_P),   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, AS_MODS(KC_Z), AS_MODS(KC_G), AS_MODS(KC_S), AS_MOD(KC_R),  AS_MODS(KC_SCLN),_______, _______, _______, AS_MOD(KC_MINS), AS_MOD(KC_EQL), AS_MOD(KC_O), AS_MODS(KC_O), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // WORD -- a programming word-expansion layer. Fire N+E+I (right home row) to
  // toggle it on, then roll a two-key COMBO to type a code token (R+E return,
  // F+N function, S+T struct, ...). The combos only fire while this layer is
  // active (combo_should_trigger), and firing one auto-exits back to base. The
  // layer itself is transparent -- it is purely a "mode flag" that the word
  // combos gate on; the combos read the Colemak letters underneath. Tap N+E+I
  // again to leave without typing anything. Glows magenta. See the combo block
  // and process_record_user() below for the full word list.
  [_WORD] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  ),

  // WORK -- sales-tax / tax-software domain words, combo-driven like _WORD. Tap
  // R+S+T (left home row) to toggle on, then roll a two-key COMBO to type the
  // word (J+U jurisdiction, R+E remittance, E+X exempt, ...); firing one auto-
  // exits. The layer is transparent -- just a mode flag the work combos gate on.
  // Tap R+S+T again to leave without typing. Glows gold. See the combo block.
  [_WORK] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  )
};

// ===== Combos =================================================================
// The whole point of this layout. All defined by Colemak keycode/position, so
// they fire on the Colemak base (and not on QWERTY, which keeps its own keys).

// --- Utility ---
const uint16_t PROGMEM combo_tab[]  = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_L, KC_U, COMBO_END};

// --- Layer launcher: all four left home keys -> one-shot FN ---
const uint16_t PROGMEM combo_fn[]   = {KC_A, KC_R, KC_S, KC_T, COMBO_END};

// --- Word layers: N+E+I (right home) toggles _WORD (programming words); R+S+T
//     (left home) toggles _WORK (sales-tax domain words). Both combo-driven.
//     R+S+T is the A+R+S+T launcher minus the pinky -- add A to reach _FN. ---
const uint16_t PROGMEM combo_word[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_work[] = {KC_R, KC_S, KC_T, COMBO_END};

// --- Numbers: vertical same-finger pairs (top row + home row) ---
const uint16_t PROGMEM combo_1[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM combo_0[] = {KC_QUOT, KC_O, COMBO_END};

// --- Symbols: horizontal home-row pairs (Shift these for ~ _ + |) ---
const uint16_t PROGMEM combo_grv[]  = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM combo_mins[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo_eql[]  = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_bsls[] = {KC_I, KC_O, COMBO_END};

// --- Brackets: horizontal bottom-row pairs, open (left) next to close (right) ---
const uint16_t PROGMEM combo_labk[] = {KC_Z, KC_X, COMBO_END};      // <
const uint16_t PROGMEM combo_lcbr[] = {KC_X, KC_C, COMBO_END};      // {
const uint16_t PROGMEM combo_lbrc[] = {KC_C, KC_D, COMBO_END};      // [
const uint16_t PROGMEM combo_lprn[] = {KC_D, KC_V, COMBO_END};      // (
const uint16_t PROGMEM combo_rprn[] = {KC_K, KC_H, COMBO_END};      // )
const uint16_t PROGMEM combo_rbrc[] = {KC_H, KC_COMM, COMBO_END};   // ]
const uint16_t PROGMEM combo_rcbr[] = {KC_COMM, KC_DOT, COMBO_END}; // }
const uint16_t PROGMEM combo_rabk[] = {KC_DOT, KC_SLSH, COMBO_END}; // >

// --- Programming words (active ONLY on _WORD, see combo_should_trigger). Each
//     reads the Colemak letters under the keys; the pair is shown after each. ---
const uint16_t PROGMEM cw_return[]    = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM cw_function[]  = {KC_F, KC_N, COMBO_END};
const uint16_t PROGMEM cw_import[]    = {KC_I, KC_M, COMBO_END};
const uint16_t PROGMEM cw_export[]    = {KC_E, KC_X, COMBO_END};
const uint16_t PROGMEM cw_include[]   = {KC_I, KC_N, COMBO_END};
const uint16_t PROGMEM cw_interface[] = {KC_I, KC_F, COMBO_END};
const uint16_t PROGMEM cw_const[]     = {KC_C, KC_O, COMBO_END};
const uint16_t PROGMEM cw_struct[]    = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM cw_string[]    = {KC_S, KC_G, COMBO_END};
const uint16_t PROGMEM cw_public[]    = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM cw_private[]   = {KC_P, KC_R, COMBO_END};
const uint16_t PROGMEM cw_pointer[]   = {KC_P, KC_O, COMBO_END};
const uint16_t PROGMEM cw_params[]    = {KC_P, KC_A, COMBO_END};
const uint16_t PROGMEM cw_variable[]  = {KC_V, KC_R, COMBO_END};
const uint16_t PROGMEM cw_define[]    = {KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM cw_default[]   = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cw_delete[]    = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM cw_document[]  = {KC_D, KC_O, COMBO_END};
const uint16_t PROGMEM cw_object[]    = {KC_O, KC_B, COMBO_END};
const uint16_t PROGMEM cw_boolean[]   = {KC_B, KC_L, COMBO_END};
const uint16_t PROGMEM cw_length[]    = {KC_L, KC_G, COMBO_END};
const uint16_t PROGMEM cw_value[]     = {KC_V, KC_A, COMBO_END};
const uint16_t PROGMEM cw_result[]    = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM cw_request[]   = {KC_R, KC_Q, COMBO_END};
const uint16_t PROGMEM cw_response[]  = {KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM cw_continue[]  = {KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM cw_context[]   = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM cw_callback[]  = {KC_C, KC_B, COMBO_END};
const uint16_t PROGMEM cw_update[]    = {KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM cw_message[]   = {KC_M, KC_E, COMBO_END};
const uint16_t PROGMEM cw_switch[]    = {KC_S, KC_W, COMBO_END};

// --- Sales-tax / domain words (active ONLY on _WORK, see combo_should_trigger).
//     Mostly the word's first two letters; pair shown after each. ---
const uint16_t PROGMEM cwk_jurisdiction[] = {KC_J, KC_U, COMBO_END};  // ju
const uint16_t PROGMEM cwk_taxability[]   = {KC_T, KC_A, COMBO_END};  // ta
const uint16_t PROGMEM cwk_exempt[]       = {KC_E, KC_X, COMBO_END};  // ex
const uint16_t PROGMEM cwk_compliance[]   = {KC_C, KC_O, COMBO_END};  // co
const uint16_t PROGMEM cwk_registration[] = {KC_R, KC_G, COMBO_END};  // reg
const uint16_t PROGMEM cwk_certificate[]  = {KC_C, KC_E, COMBO_END};  // ce
const uint16_t PROGMEM cwk_threshold[]    = {KC_T, KC_H, COMBO_END};  // th
const uint16_t PROGMEM cwk_transaction[]  = {KC_T, KC_R, COMBO_END};  // tr
const uint16_t PROGMEM cwk_liability[]    = {KC_L, KC_I, COMBO_END};  // li
const uint16_t PROGMEM cwk_remittance[]   = {KC_R, KC_E, COMBO_END};  // re
const uint16_t PROGMEM cwk_nexus[]        = {KC_N, KC_X, COMBO_END};  // ne(x)
const uint16_t PROGMEM cwk_surcharge[]    = {KC_S, KC_U, COMBO_END};  // su
const uint16_t PROGMEM cwk_marketplace[]  = {KC_M, KC_A, COMBO_END};  // ma
const uint16_t PROGMEM cwk_facilitator[]  = {KC_F, KC_A, COMBO_END};  // fa
const uint16_t PROGMEM cwk_calculation[]  = {KC_C, KC_A, COMBO_END};  // ca
const uint16_t PROGMEM cwk_destination[]  = {KC_D, KC_E, COMBO_END};  // de
const uint16_t PROGMEM cwk_sourcing[]     = {KC_S, KC_O, COMBO_END};  // so
const uint16_t PROGMEM cwk_municipality[] = {KC_M, KC_U, COMBO_END};  // mu
const uint16_t PROGMEM cwk_locality[]     = {KC_L, KC_O, COMBO_END};  // lo
const uint16_t PROGMEM cwk_district[]     = {KC_D, KC_I, COMBO_END};  // di
const uint16_t PROGMEM cwk_region[]       = {KC_R, KC_N, COMBO_END};  // reg(n)
const uint16_t PROGMEM cwk_country[]      = {KC_C, KC_N, COMBO_END};  // c(n)
const uint16_t PROGMEM cwk_address[]      = {KC_A, KC_D, COMBO_END};  // ad
const uint16_t PROGMEM cwk_invoice[]      = {KC_I, KC_N, COMBO_END};  // in
const uint16_t PROGMEM cwk_customer[]     = {KC_C, KC_U, COMBO_END};  // cu
const uint16_t PROGMEM cwk_refund[]       = {KC_R, KC_F, COMBO_END};  // re(f)

combo_t key_combos[] = {
    COMBO(combo_tab,  KC_TAB),
    COMBO(combo_ent,  KC_ENT),
    COMBO(combo_esc,  KC_ESC),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_fn,   OSL(_FN)),
    COMBO(combo_word, TG(_WORD)),
    COMBO(combo_work, TG(_WORK)),
    COMBO(combo_1, KC_1),
    COMBO(combo_2, KC_2),
    COMBO(combo_3, KC_3),
    COMBO(combo_4, KC_4),
    COMBO(combo_5, KC_5),
    COMBO(combo_6, KC_6),
    COMBO(combo_7, KC_7),
    COMBO(combo_8, KC_8),
    COMBO(combo_9, KC_9),
    COMBO(combo_0, KC_0),
    COMBO(combo_grv,  KC_GRV),
    COMBO(combo_mins, KC_MINS),
    COMBO(combo_eql,  KC_EQL),
    COMBO(combo_bsls, KC_BSLS),
    COMBO(combo_labk, KC_LABK),
    COMBO(combo_lcbr, KC_LCBR),
    COMBO(combo_lbrc, KC_LBRC),
    COMBO(combo_lprn, KC_LPRN),
    COMBO(combo_rprn, KC_RPRN),
    COMBO(combo_rbrc, KC_RBRC),
    COMBO(combo_rcbr, KC_RCBR),
    COMBO(combo_rabk, KC_RABK),
    // Programming words -- gated to _WORD by combo_should_trigger().
    COMBO(cw_return,    W_RETURN),
    COMBO(cw_function,  W_FUNCTION),
    COMBO(cw_import,    W_IMPORT),
    COMBO(cw_export,    W_EXPORT),
    COMBO(cw_include,   W_INCLUDE),
    COMBO(cw_interface, W_INTERFACE),
    COMBO(cw_const,     W_CONST),
    COMBO(cw_struct,    W_STRUCT),
    COMBO(cw_string,    W_STRING),
    COMBO(cw_public,    W_PUBLIC),
    COMBO(cw_private,   W_PRIVATE),
    COMBO(cw_pointer,   W_POINTER),
    COMBO(cw_params,    W_PARAMS),
    COMBO(cw_variable,  W_VARIABLE),
    COMBO(cw_define,    W_DEFINE),
    COMBO(cw_default,   W_DEFAULT),
    COMBO(cw_delete,    W_DELETE),
    COMBO(cw_document,  W_DOCUMENT),
    COMBO(cw_object,    W_OBJECT),
    COMBO(cw_boolean,   W_BOOLEAN),
    COMBO(cw_length,    W_LENGTH),
    COMBO(cw_value,     W_VALUE),
    COMBO(cw_result,    W_RESULT),
    COMBO(cw_request,   W_REQUEST),
    COMBO(cw_response,  W_RESPONSE),
    COMBO(cw_continue,  W_CONTINUE),
    COMBO(cw_context,   W_CONTEXT),
    COMBO(cw_callback,  W_CALLBACK),
    COMBO(cw_update,    W_UPDATE),
    COMBO(cw_message,   W_MESSAGE),
    COMBO(cw_switch,    W_SWITCH),
    // Sales-tax / domain words -- gated to _WORK by combo_should_trigger().
    COMBO(cwk_jurisdiction, WK_JURISDICTION),
    COMBO(cwk_taxability,   WK_TAXABILITY),
    COMBO(cwk_exempt,       WK_EXEMPT),
    COMBO(cwk_compliance,   WK_COMPLIANCE),
    COMBO(cwk_registration, WK_REGISTRATION),
    COMBO(cwk_certificate,  WK_CERTIFICATE),
    COMBO(cwk_threshold,    WK_THRESHOLD),
    COMBO(cwk_transaction,  WK_TRANSACTION),
    COMBO(cwk_liability,    WK_LIABILITY),
    COMBO(cwk_remittance,   WK_REMITTANCE),
    COMBO(cwk_nexus,        WK_NEXUS),
    COMBO(cwk_surcharge,    WK_SURCHARGE),
    COMBO(cwk_marketplace,  WK_MARKETPLACE),
    COMBO(cwk_facilitator,  WK_FACILITATOR),
    COMBO(cwk_calculation,  WK_CALCULATION),
    COMBO(cwk_destination,  WK_DESTINATION),
    COMBO(cwk_sourcing,     WK_SOURCING),
    COMBO(cwk_municipality, WK_MUNICIPALITY),
    COMBO(cwk_locality,     WK_LOCALITY),
    COMBO(cwk_district,     WK_DISTRICT),
    COMBO(cwk_region,       WK_REGION),
    COMBO(cwk_country,      WK_COUNTRY),
    COMBO(cwk_address,      WK_ADDRESS),
    COMBO(cwk_invoice,      WK_INVOICE),
    COMBO(cwk_customer,     WK_CUSTOMER),
    COMBO(cwk_refund,       WK_REFUND),
};

// Gate combos by layer. The 30+ programming-word combos (keycode > MAC_LOCK)
// only fire while _WORD is active; every other combo (numbers, symbols,
// brackets, launcher) is suppressed on _WORD so it doesn't clash with a word
// roll. The N+E+I activation (TG(_WORD)) always fires, so it can toggle _WORD
// off again too.
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // NOTE: gate on combo->keycode (the combo's OUTPUT), not `keycode` -- that
    // argument is the individual pressed key, not the combo result.
    uint16_t kc = combo->keycode;
    if (kc == TG(_WORD) || kc == TG(_WORK)) {
        return true;   // N+E+I / R+S+T activations -- always (so they can toggle off too)
    }
    if (kc >= W_RETURN && kc <= W_SWITCH) {
        return layer_state_is(_WORD);   // programming-word combos: only on _WORD
    }
    if (kc >= WK_JURISDICTION && kc <= WK_REFUND) {
        return layer_state_is(_WORK);   // domain-word combos: only on _WORK
    }
    // Everything else (numbers, symbols, brackets, FN launcher): suppress while
    // in either word layer so a roll never clashes with word entry.
    return !(layer_state_is(_WORD) || layer_state_is(_WORK));
}

// ===== Custom keycodes ========================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC_LOCK:
            // Consumer "Local Machine Browser Lock" -> macOS lock screen.
            host_consumer_send(record->event.pressed ? 0x19E : 0);
            return false;
    }

    // _WORD programming words: every W_* keycode comes from a combo that only
    // fires on _WORD. Type the token (no trailing space, so you can append
    // ()/;/<> etc.) and auto-exit the layer so one roll = one word.
    if (keycode >= W_RETURN && keycode <= W_SWITCH) {
        if (record->event.pressed) {
            layer_off(_WORD);
            switch (keycode) {
                case W_RETURN:     SEND_STRING("return");     break;
                case W_FUNCTION:   SEND_STRING("function");   break;
                case W_IMPORT:     SEND_STRING("import");     break;
                case W_EXPORT:     SEND_STRING("export");     break;
                case W_INCLUDE:    SEND_STRING("include");    break;
                case W_INTERFACE:  SEND_STRING("interface");  break;
                case W_CONST:      SEND_STRING("const");      break;
                case W_STRUCT:     SEND_STRING("struct");     break;
                case W_STRING:     SEND_STRING("string");     break;
                case W_PUBLIC:     SEND_STRING("public");     break;
                case W_PRIVATE:    SEND_STRING("private");    break;
                case W_POINTER:    SEND_STRING("pointer");    break;
                case W_PARAMS:     SEND_STRING("params");     break;
                case W_VARIABLE:   SEND_STRING("variable");   break;
                case W_DEFINE:     SEND_STRING("define");     break;
                case W_DEFAULT:    SEND_STRING("default");    break;
                case W_DELETE:     SEND_STRING("delete");     break;
                case W_DOCUMENT:   SEND_STRING("document");   break;
                case W_OBJECT:     SEND_STRING("object");     break;
                case W_BOOLEAN:    SEND_STRING("boolean");    break;
                case W_LENGTH:     SEND_STRING("length");     break;
                case W_VALUE:      SEND_STRING("value");      break;
                case W_RESULT:     SEND_STRING("result");     break;
                case W_REQUEST:    SEND_STRING("request");    break;
                case W_RESPONSE:   SEND_STRING("response");   break;
                case W_CONTINUE:   SEND_STRING("continue");   break;
                case W_CONTEXT:    SEND_STRING("context");    break;
                case W_CALLBACK:   SEND_STRING("callback");   break;
                case W_UPDATE:     SEND_STRING("update");     break;
                case W_MESSAGE:    SEND_STRING("message");    break;
                case W_SWITCH:     SEND_STRING("switch");     break;
            }
        }
        return false;
    }

    // _WORK domain words: combo-driven sales-tax vocabulary; type the word and
    // auto-exit (one roll = one word). No trailing space.
    if (keycode >= WK_JURISDICTION && keycode <= WK_REFUND) {
        if (record->event.pressed) {
            layer_off(_WORK);
            switch (keycode) {
                case WK_JURISDICTION: SEND_STRING("jurisdiction"); break;
                case WK_TAXABILITY:   SEND_STRING("taxability");   break;
                case WK_EXEMPT:       SEND_STRING("exempt");       break;
                case WK_COMPLIANCE:   SEND_STRING("compliance");   break;
                case WK_REGISTRATION: SEND_STRING("registration"); break;
                case WK_CERTIFICATE:  SEND_STRING("certificate");  break;
                case WK_THRESHOLD:    SEND_STRING("threshold");    break;
                case WK_TRANSACTION:  SEND_STRING("transaction");  break;
                case WK_LIABILITY:    SEND_STRING("liability");    break;
                case WK_REMITTANCE:   SEND_STRING("remittance");   break;
                case WK_NEXUS:        SEND_STRING("nexus");        break;
                case WK_SURCHARGE:    SEND_STRING("surcharge");    break;
                case WK_MARKETPLACE:  SEND_STRING("marketplace");  break;
                case WK_FACILITATOR:  SEND_STRING("facilitator");  break;
                case WK_CALCULATION:  SEND_STRING("calculation");  break;
                case WK_DESTINATION:  SEND_STRING("destination");  break;
                case WK_SOURCING:     SEND_STRING("sourcing");     break;
                case WK_MUNICIPALITY: SEND_STRING("municipality"); break;
                case WK_LOCALITY:     SEND_STRING("locality");     break;
                case WK_DISTRICT:     SEND_STRING("district");     break;
                case WK_REGION:       SEND_STRING("region");       break;
                case WK_COUNTRY:      SEND_STRING("country");      break;
                case WK_ADDRESS:      SEND_STRING("address");      break;
                case WK_INVOICE:      SEND_STRING("invoice");      break;
                case WK_CUSTOMER:     SEND_STRING("customer");     break;
                case WK_REFUND:       SEND_STRING("refund");       break;
            }
        }
        return false;
    }
    return true;
}

// ===== RGB indicators =========================================================

// Set a solid color from an HSV_* macro while KEEPING the current brightness.
// The macro's value component is intentionally ignored and replaced with
// rgb_matrix_get_val(), so RM_VALU/RM_VALD adjustments survive layer changes.
static void set_solid_hs(uint8_t hue, uint8_t sat, uint8_t val) {
    (void)val;  // discard the macro's full-brightness value
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(hue, sat, rgb_matrix_get_val());
}

// Paint the solid RGB color for the active base layer:
//   _COLEMAK -> blue   _QWERTY -> red
static void apply_base_layer_rgb(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            set_solid_hs(HSV_RED);
            break;
        case _COLEMAK:
        default:
            set_solid_hs(HSV_BLUE);
            break;
    }
}

// Boot into Colemak every time the board is plugged in. The DF() keys on _FN
// still switch layouts at runtime, but the choice is not persisted -- a reset
// always comes back up on Colemak.
void keyboard_post_init_user(void) {
    default_layer_set((layer_state_t)1 << _COLEMAK);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    apply_base_layer_rgb();
    return state;
}

// While NAV or FN is LOCKED (via QK_LLCK), keep its color on as a persistent
// "you're in this mode" reminder; otherwise restore the base-layer color.
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

// Tint the board to match whichever momentary layer is active. A locked NAV/FN
// keeps its indicator (handled above), so bail out early when locked.
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
        case _AERO:
            set_solid_hs(HSV_PURPLE);
            break;
        case _WORD:
            set_solid_hs(HSV_MAGENTA);
            break;
        case _WORK:
            set_solid_hs(HSV_GOLD);
            break;
        default:  // back on a base layer
            apply_base_layer_rgb();
            break;
    }
    return state;
}
