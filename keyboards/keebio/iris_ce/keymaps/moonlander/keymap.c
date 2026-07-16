// Faithful port of the Oryx Moonlander "colemak" keymap to the Iris CE.
// Source: ~/Documents/zsa_moonlander_reva_ArgWe_nlym6K_colemak_source
//
// The Moonlander has an extra inner thumb column and two thumb rows the Iris CE
// lacks. Mapping: Moonlander alpha columns -> the Iris' 6 columns (the extra
// inner column, all-transparent on every layer, is dropped); Moonlander's two
// thumb rows collapse onto the Iris' 2 inner keys + 6 thumb keys.
// ponytail: dropped Oryx's 72-LED ledmap + rawhid RGB block -- it's Moonlander-
// specific and won't compile on the Iris. Add per-layer RGB later if wanted.

#include QMK_KEYBOARD_H

enum custom_layers {
    _BASE,    // Colemak-DH + home-row mods   (Moonlander layer 0)
    _SYM,     // brackets / numbers / symbols (layer 1)
    _NAV,     // one-shot mods + arrows       (layer 2)
    _MEDIA,   // media + mouse                (layer 3)
    _GAME,    // QWERTY gaming, TO-toggled    (layer 4)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
     KC_NO,  LCA(KC_1),         LCA(KC_2),         LCA(KC_3),         LCA(KC_4),         LCA(KC_5),                LCA(KC_6),LCA(KC_7),         LCA(KC_8),         LCA(KC_9),         LCA(KC_0),         KC_NO,
     KC_GRV, KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                     KC_J,     KC_L,              KC_U,              KC_Y,              KC_SCLN,           KC_BSLS,
     KC_ESC, MT(MOD_LCTL,KC_A), MT(MOD_LALT,KC_R), MT(MOD_LGUI,KC_S), MT(MOD_LSFT,KC_T), KC_G,                     KC_M,     MT(MOD_RSFT,KC_N), MT(MOD_RGUI,KC_E), MT(MOD_RALT,KC_I), MT(MOD_RCTL,KC_O), KC_QUOT,
     KC_NO,  KC_Z,              KC_X,              KC_C,              KC_D,              KC_V, TO(_GAME), MO(_NAV), KC_K,     KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_NO,
                                MO(_MEDIA),        MO(_SYM),          KC_SPC,                              OSM(MOD_LSFT), KC_NO, KC_NO
  ),

  [_SYM] = LAYOUT(
     _______,_______,           _______,           _______,           _______,           _______,                  _______,_______,           _______,           _______,           _______,           _______,
     _______,KC_LABK,           KC_LCBR,           KC_LBRC,           KC_LPRN,           _______,                  _______,KC_RPRN,           KC_RBRC,           KC_RCBR,           KC_RABK,           _______,
     _______,MT(MOD_LCTL,KC_1), MT(MOD_LALT,KC_2), MT(MOD_LGUI,KC_3), MT(MOD_LSFT,KC_4), KC_5,                     KC_6,   MT(MOD_RSFT,KC_7), MT(MOD_RGUI,KC_8), MT(MOD_LALT,KC_9), MT(MOD_RCTL,KC_0), _______,
     _______,KC_MINS,           KC_EQL,            _______,           _______,           _______,_______,_______,  _______,_______,           _______,           _______,           _______,           _______,
                                _______,           _______,           _______,                              _______, _______, _______
  ),

  [_NAV] = LAYOUT(
     _______,_______,           _______,           _______,           _______,           _______,                  _______,_______, _______,_______,_______,_______,
     _______,_______,           _______,           _______,           _______,           _______,                  _______,_______, _______,_______,_______,_______,
     _______,OSM(MOD_LCTL),     OSM(MOD_LALT),     OSM(MOD_LGUI),     OSM(MOD_LSFT),     _______,                  KC_LEFT,KC_DOWN, KC_UP,  KC_RGHT,_______,_______,
     _______,_______,           _______,           _______,           _______,           _______,_______,_______,  _______,_______, _______,_______,_______,_______,
                                _______,           _______,           _______,                              _______, _______, _______
  ),

  [_MEDIA] = LAYOUT(
     _______,_______,   _______, _______, _______, _______,                            _______,       _______,   _______,       _______,   _______,       QK_BOOT,
     _______,_______,   _______, _______, _______, _______,                            MS_WHLL,       MS_BTN1,   MS_UP,         MS_BTN2,   MS_WHLU,       _______,
     _______,KC_MSTP,   KC_MPLY, KC_VOLD, KC_VOLU, _______,                            MS_WHLR,       MS_LEFT,   MS_DOWN,       MS_RGHT,   MS_WHLD,       _______,
     _______,_______,   _______, _______, _______, _______,_______,_______,            _______,       _______,   _______,       _______,   _______,       _______,
                        _______, _______, _______,                              _______, _______, _______
  ),

  [_GAME] = LAYOUT(
     KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                            _______,_______,_______,_______,_______,_______,
     KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                            _______,_______,_______,_______,_______,_______,
     KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                            _______,_______,_______,_______,_______,_______,
     KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  TO(_BASE),_______,        _______,_______,_______,_______,_______,_______,
                     _______,KC_LALT,KC_SPC,                          _______, _______, _______
  ),
};

// ===== Combos (ported 1:1 from the Oryx source) ==============================
const uint16_t PROGMEM combo_tab[]  = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM combo_bspc[] = { KC_H, KC_COMM, COMBO_END };
const uint16_t PROGMEM combo_ent[]  = { KC_COMM, KC_DOT, COMBO_END };

combo_t key_combos[] = {
    COMBO(combo_tab,  KC_TAB),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_ent,  KC_ENT),
};
