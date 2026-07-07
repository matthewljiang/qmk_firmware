// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// ----- One-shot modifiers & layers -----
//
// Every modifier and the FN/NAV layer access are one-shot (OSM / OSL) or
// combos -- there are no tap-hold (mod-tap / layer-tap) keys, so the
// PERMISSIVE_HOLD / TAPPING_TERM tuning that those need is unnecessary.

// A queued one-shot waits this long (ms) for its next keypress before giving up
// -- generous so you're never rushed between the mod/layer tap and the key.
#define ONESHOT_TIMEOUT 1500

// Tapping a one-shot this many times in a row locks it on (tap once more to
// release). Single tap = one-shot; double tap = locked. Applies to OSM and OSL,
// so double-tapping NAV locks the nav layer and double-tapping Shift acts like
// Caps Lock.
#define ONESHOT_TAP_TOGGLE 2

// ----- Combos -----
//
// This layout leans heavily on combos: numbers, symbols, brackets, Tab/Enter/
// Esc/Backspace and the FN launcher are all two- to four-key combos on adjacent
// keys. Some of those pairs also occur in fast typing rolls, so keep the window
// tight -- all keys of a combo must land within this many ms to count, which
// stops ordinary rolls (and the A+R grave vs. A+R+S+T launcher overlap) from
// misfiring.
#define COMBO_TERM 40
