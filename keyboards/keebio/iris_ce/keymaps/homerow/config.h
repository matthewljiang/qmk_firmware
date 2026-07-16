#pragma once

// Ported from the Oryx Moonlander source. This keymap uses tap-hold home-row
// mods (MT), so it needs PERMISSIVE_HOLD + a tapping term -- unlike the sibling
// `matthew` keymap, which replaced mod-taps with one-shots/combos.
#define PERMISSIVE_HOLD
#define TAPPING_TERM 200
#define ONESHOT_TAP_TOGGLE 2
#define FLOW_TAP_TERM 150

// Auto Shift: long-press a number or special-symbol key to get its shifted
// form. Alphas are excluded (Shift still capitalizes normally).
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 140  // default 175

// Mouse layer tuning (from the Oryx source).
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 15
