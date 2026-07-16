#pragma once

// Ported from the Oryx Moonlander source. This keymap uses tap-hold home-row
// mods (MT), so it needs PERMISSIVE_HOLD + a tapping term -- unlike the sibling
// `matthew` keymap, which replaced mod-taps with one-shots/combos.
#define PERMISSIVE_HOLD
#define TAPPING_TERM 200

// Mouse layer tuning (from the Oryx source).
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 15
