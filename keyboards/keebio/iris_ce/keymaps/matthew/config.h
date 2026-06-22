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
#define ONESHOT_TIMEOUT 3000

// Tapping a one-shot this many times in a row locks it on (tap once more to
// release). Single tap = one-shot; double tap = locked. Applies to OSM and OSL,
// so double-tapping NAV locks the nav layer and double-tapping Shift acts like
// Caps Lock.
#define ONESHOT_TAP_TOGGLE 2

// ----- Layer lock (QK_LLCK) -----
//
// A locked layer (NAV / FN) auto-releases after this many ms of inactivity, so
// you can't get stranded on a layer if you walk away mid-edit.
#define LAYER_LOCK_IDLE_TIMEOUT 5000

// ----- Combos -----
//
// This layout leans heavily on combos: numbers, symbols, brackets, Tab/Enter/
// Esc/Backspace and the FN launcher are all two- to four-key combos on adjacent
// keys. Some of those pairs also occur in fast typing rolls, so keep the window
// tight -- all keys of a combo must land within this many ms to count, which
// stops ordinary rolls (and the A+R grave vs. A+R+S+T launcher overlap) from
// misfiring.
#define COMBO_TERM 40

// Enable the combo_should_trigger() hook (keymap.c) so the programming-word
// combos can be gated to the _WORD layer and the base combos suppressed there.
#define COMBO_SHOULD_TRIGGER
