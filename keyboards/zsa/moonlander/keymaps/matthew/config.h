// Copyright 2024 Matthew Jiang
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
