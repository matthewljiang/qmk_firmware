// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// ----- Home row mods (tap-hold) tuning -----

// How long a key must be held before it registers as a modifier.
#define TAPPING_TERM 200

// Resolve a mod-tap as "hold" when another key is pressed and released within
// the tapping term. Greatly improves rolling typing with home row mods.
#define PERMISSIVE_HOLD

// Within this window after a tap, holding the same key repeats the tap instead
// of acting as a modifier -- allows tap-then-hold auto-repeat while still
// keeping home row mods responsive.
#define QUICK_TAP_TERM 120

// ----- Tri-layer layer indices -----
// Base layers (_QWERTY = 0, _COLEMAK = 1) sit below the momentary layers, so
// LOWER/RAISE/ADJUST are shifted up by one from QMK's defaults (1/2/3).
#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4
