// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// ----- One-shot modifiers & layers -----
//
// This keymap has no tap-hold keys: every modifier and the symbol layer are
// one-shot taps, so the PERMISSIVE_HOLD / TAPPING_TERM / QUICK_TAP_TERM tuning
// that mod-taps need is gone.

// A queued one-shot mod waits this long (ms) for its next keypress before it
// gives up -- generous so you're never rushed between the mod tap and the key.
#define ONESHOT_TIMEOUT 3000

// Tapping a one-shot key this many times in a row locks it on (tap once more to
// release). Single tap = one-shot; double tap = locked. Applies to both OSM and
// OSL, so double-tapping SYM locks the symbol layer and double-tapping Shift
// acts like Caps Lock.
#define ONESHOT_TAP_TOGGLE 2

// ----- Combos -----
//
// Modifiers are fired by two-finger combos on adjacent home-row keys. Those
// pairs (e.g. "ar", "rs", "st") also occur in normal typing, so keep the window
// tight -- both keys must land within this many ms to count as a combo, which
// stops ordinary rolls from misfiring a mod.
#define COMBO_TERM 40
