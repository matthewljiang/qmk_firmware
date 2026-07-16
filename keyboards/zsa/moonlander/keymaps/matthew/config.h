// Copyright 2024 Matthew Jiang
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// ----- Tap-hold tuning (for LT() thumb / inner-index keys) -----
//
// Home-row mods are gone -- modifiers are fired by combos now. These settings
// only apply to the remaining layer-tap keys (WM_TAB, NAV_SPC, SYM_BSPC,
// FN_HOME, FN_END) which are on thumbs or the comfortable inner-index column.

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 120

// ----- One-shot modifiers & layers -----

// A queued one-shot mod waits this long (ms) for its next keypress before
// giving up -- generous so you're never rushed.
#define ONESHOT_TIMEOUT 3000

// Tapping a one-shot key this many times locks it on (tap once more to
// release). Single tap = one-shot; double tap = locked. Applies to both
// OSM and OSL.
#define ONESHOT_TAP_TOGGLE 2

// ----- Combos -----
//
// Modifiers fire from two-finger adjacent home-row rolls. Keep the window
// tight so normal typing rolls don't misfire a mod.
#define COMBO_TERM 40

// ----- Leader -----
//
// QK_LEAD sits on the right thumb (was KC_RALT). Sequences are two-/three-key,
// namespaced by first key (T tmux, A aerospace). PER_KEY_TIMING resets the timer
// on every key, so the window applies per keypress -- abandoned sequences time
// out without rushing you mid-sequence.
#define LEADER_TIMEOUT 200
#define LEADER_PER_KEY_TIMING
