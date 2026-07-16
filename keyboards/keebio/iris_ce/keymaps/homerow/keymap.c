// Faithful port of the Oryx Moonlander "colemak" keymap to the Iris CE.
// Colemak-DH + home-row mods (MT).
// Source: ~/Documents/zsa_moonlander_reva_ArgWe_7v0JOY_colemak_source
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
     KC_NO,  LCA(KC_1),         LCA(KC_2),         LCA(KC_3),         LCA(KC_4),         LCA(KC_5),                LCA(KC_6),LCA(KC_7),         LCA(KC_8),         LCA(KC_9),         LCA(KC_0),         KC_NO,
     KC_NO , KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                     KC_J,     KC_L,              KC_U,              KC_Y,              KC_SCLN,           KC_NO,
     KC_ESC, MT(MOD_LCTL,KC_A), MT(MOD_LALT,KC_R), MT(MOD_LGUI,KC_S), MT(MOD_LSFT,KC_T), KC_G,                     KC_M,     MT(MOD_RSFT,KC_N), MT(MOD_RGUI,KC_E), MT(MOD_RALT,KC_I), MT(MOD_RCTL,KC_O), KC_QUOT,
     KC_NO,  KC_Z,              KC_X,              KC_C,              KC_D,              KC_V, KC_NO,     KC_BSPC, KC_K,     KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_NO,
                                MO(_MEDIA),             MO(_NAV),          LT(_SYM,KC_SPC),                      OSM(MOD_LSFT), MO(_SYM), KC_NO
  ),

  // Top row: numbers (plain, so Auto Shift gives !@#$%^&*() on a long press).
  // Home row: same home-row mods as _BASE, but taps are editing keys --
  //   left  Esc/Tab/Bspc (Ctrl/Alt/Gui), right Del/Space/Enter (Ctrl/Alt/Gui),
  //   both index fingers stay Shift (hold only).
  // Bottom row: [ ] ` - = \ auto-shift to { } ~ _ + |.
  [_SYM] = LAYOUT(
     KC_NO  ,KC_NO  ,             KC_NO  ,            KC_NO  ,             KC_NO  ,            KC_NO  ,                  KC_NO  ,KC_NO ,             KC_NO  ,            KC_NO  ,             KC_NO  ,            KC_NO  ,
     KC_NO  , KC_1,               KC_2,               KC_3,                KC_4,               KC_5,                     KC_6,   KC_7,               KC_8,               KC_9,                KC_0,               KC_NO  ,
     TO(_BASE),MT(MOD_LCTL,KC_ESC),MT(MOD_LALT,KC_TAB),MT(MOD_LGUI,KC_BSPC),MOD_LSFT, KC_NO,                    KC_NO,   MOD_RSFT, MT(MOD_RGUI,KC_ENT),MT(MOD_LALT,KC_SPC), MT(MOD_RCTL,KC_DEL),KC_NO  ,
     KC_NO  ,KC_NO  ,             KC_GRV ,            KC_LBRC,             KC_RBRC,            KC_NO  ,KC_NO  ,KC_NO  ,  KC_NO,  KC_MINS,            KC_EQL ,             KC_BSLS,            KC_NO,              KC_NO  ,
     _______,_______,_______,_______,_______,_______
  ),

  [_NAV] = LAYOUT(
     KC_NO  ,KC_NO  ,           KC_NO  ,           KC_NO  ,           KC_NO  ,           KC_NO  ,                  KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
     KC_NO  ,KC_NO  ,           KC_NO  ,           KC_NO  ,           KC_NO  ,           KC_NO  ,                  KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
     TO(_BASE),OSM(MOD_LCTL),    OSM(MOD_LALT),     OSM(MOD_LGUI),     OSM(MOD_LSFT),    KC_NO  ,                  KC_LEFT,KC_DOWN, KC_UP,  KC_RGHT,KC_NO  ,KC_NO  ,
     KC_NO  ,KC_NO  ,           KC_NO  ,           KC_NO  ,           KC_NO  ,           KC_NO  ,KC_NO  ,KC_NO  ,  KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,
     _______,_______,_______,_______,_______,_______
  ),

  [_MEDIA] = LAYOUT(
     KC_NO  ,  KC_NO  ,   KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                            KC_NO  ,       KC_NO  ,   KC_NO  ,       KC_NO  ,   KC_NO  ,       QK_BOOT,
     KC_NO  ,  KC_NO  ,   KC_NO  , RM_VALD, RM_VALU, KC_NO  ,                            MS_WHLL,       MS_BTN1,   MS_UP,         MS_BTN2,   MS_WHLU,       KC_NO  ,
     TO(_BASE),KC_MSTP,   KC_MPLY, KC_VOLD, KC_VOLU, KC_NO  ,                            MS_WHLR,       MS_LEFT,   MS_DOWN,       MS_RGHT,   MS_WHLD,       KC_NO  ,
     KC_NO  ,  KC_NO  ,   KC_NO  , KC_NO  , KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,            KC_NO  ,       KC_NO  ,   KC_NO  ,       KC_NO  ,   KC_NO  ,       KC_NO  ,
     _______,_______,_______,_______,_______,_______
  ),
};

// ===== Combos (ported 1:1 from the Oryx source) ==============================
const uint16_t PROGMEM combo_tab[]  = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM combo_ent[]  = { KC_COMM, KC_DOT, COMBO_END };
const uint16_t PROGMEM combo_bspc[]  = { KC_H, KC_COMM, COMBO_END };

combo_t key_combos[] = {
    COMBO(combo_tab,  KC_TAB),
    COMBO(combo_ent,  KC_ENT),
    COMBO(combo_bspc, KC_BSPC),
};

// ===== Tap-hold tuning ========================================================
// SpaceFn (LT on the left thumb) is the highest-frequency key, so a fast
// space->letter roll must NOT misfire into _SYM. Disable permissive hold for it
// (keep it on for the home-row mods) and give it a slightly longer hold term.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LT(_SYM, KC_SPC)) return false;
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LT(_SYM, KC_SPC)) return 220;
    return TAPPING_TERM;
}

// ===== RGB layer indicators ===================================================
// Solid per-layer color so the active layer is obvious. Brightness is preserved
// via rgb_matrix_get_val(), so Bri-/Bri+ (RM_VALD/RM_VALU) still work.
// Colors match the sibling `matthew` keymap: base=blue, nav=green, sym=teal.
static void set_solid_hs(uint8_t hue, uint8_t sat, uint8_t val) {
    (void)val;
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(hue, sat, rgb_matrix_get_val());
}

void keyboard_post_init_user(void) {
    set_solid_hs(HSV_BLUE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SYM:   set_solid_hs(HSV_TEAL);    break;
        case _NAV:   set_solid_hs(HSV_GREEN);   break;
        case _MEDIA: set_solid_hs(HSV_MAGENTA); break;
        default:     set_solid_hs(HSV_BLUE);    break;
    }
    return state;
}
