# Matthew's Iris CE keymap — quick reference

A **hold-free, thumb-light** layout. The original port of my ZSA Moonlander
Colemak-DHm layout leaned on sustained holds everywhere — home-row mods plus
layer-tap holds on the thumbs — and that constant holding caused hand tension.
This version removes holding from the base layer entirely (modifiers and the
symbol layer are **one-shot taps**, the heavy layers are **toggles**) **and**
empties the thumb cluster down to three keys: Space, the SYM trigger, and the
AERO trigger. Modifiers moved onto **home-row combos**.

Two base layouts (Colemak + QWERTY), five reachable layers, and combos.

---

## The big idea: tap, don't hold

| Mechanism | Used for | How it works |
|---|---|---|
| **Mod combo** → one-shot mod | Ctrl / Alt / Cmd / Shift | Roll two adjacent home-row keys (two fingers). The **next** key is modified; they chain. |
| **One-shot layer** (`OSL`) | SYM (symbols) | Tap the trigger, type one symbol, it auto-exits. |
| **Toggle** (`TG`) | NUM, NAV | Tap to enter, tap again to leave — for sustained sessions. |
| **Toggle** (`TT`) | MEDIA | Tap to enter, tap again to leave. |
| **Caps Word** (`CW_TOGG`) | CONSTANT / PascalCase | Tap once, type a word, auto-releases. Replaces holding Shift. |

> **Double-tap to lock.** `ONESHOT_TAP_TOGGLE` is on, so double-tapping the SYM
> trigger locks the symbol layer for a burst of symbols. Tap once more to release.

> **Holding is always optional.** You *can* hold a mod combo when it helps
> (e.g. Shift while tapping arrows to extend a selection) — you just never
> *have* to.

---

## Thumb keys

The cluster is nearly empty — only three keys are live. Everything else moved to
combos or off-thumb keys.

| | outer | middle | inner |
|---|---|---|---|
| **Left**  | — | Space | SYM **(trigger)** |
| **Right** | — | — | AERO **(trigger)** |

Backspace and Enter moved off the thumbs onto the two **inner index keys** (the
center keys between the halves): Enter (left center), Backspace (right center).

---

## Modifiers — home-row combos (one-shot)

Roll **two adjacent home-row keys** (two fingers) to fire that one-shot mod.
Finger → mod keeps the old CAGS home-row identity — each mod fires from its
finger's home key plus the neighbour toward the centre. **Shift** is the outer
pinky+index pinch, since the index has no free inward neighbour. They're on
**both hands** so you can mod with the hand the letter isn't on:

| finger | mod | left combo (Colemak) | right combo (Colemak) |
|---|---|---|---|
| pinky  | **Ctrl**  | `A` + `R` | `O` + `I` |
| ring   | **Alt**   | `R` + `S` | `I` + `E` |
| middle | **Cmd**   | `S` + `T` | `E` + `N` |
| index  | **Shift** | `A` + `T` (pinch) | `O` + `N` (pinch) |

Fire the combo, then tap the letter — they chain in any order. `Cmd+C` = roll
`E`+`N` (right Cmd), tap `C`. `Cmd+Shift+T` = right Cmd, left Shift, `T`. No
holding, no thumbs. (You *can* hold a combo to keep the mod down, e.g. Shift +
arrows to select a range.)

**Caps Word** (left pinky bottom) covers whole-word capitalization. The NAV layer
also carries the CAGS mods on its left home row for select-while-navigating.

> Combos are tuned for **Colemak** (the keycodes form adjacent home-row pairs
> there). On QWERTY they land on different keys.

---

## Layer access

| Layer | Reach it by | What's on it |
|---|---|---|
| **SYM** | tap the trigger (left inner thumb) | all symbols (brackets left, extras right) |
| **NUM** | tap `TG` (right pinky, row 1) | numpad (right hand) |
| **NAV** | tap `TG` (left pinky, row 1) | arrows + Home/End/PgUp/PgDn (right hand) + CAGS mods (left hand) |
| **MEDIA** | tap `TT` (top-right corner) | media transport + RGB |
| **AERO** | tap `TG` (right inner thumb) | AeroSpace WM control (workspaces left, windows right) |

Board color shows the active layer (see below); NAV/NUM/AERO stay lit until toggled off.

---

## Combos

Tuned for Colemak. Two kinds:

**Mods** (see the table above): `A+R` `R+S` `S+T` `A+T` on the left, `O+I` `I+E`
`E+N` `O+N` on the right.

**Utility** — the only Tab/Delete on the board:

| Combo | Output |
|---|---|
| `W` + `F` | Tab |
| `U` + `Y` | Enter |
| `Q` + `W` | Esc |
| `,` + `.` | Delete |
| `L` + `U` | Backspace |

`COMBO_TERM` is 40 ms. The mod pairs are now adjacent home-row letters, which
*do* get rolled in normal typing (`ar`, `rs`, `st`…), so this tight window is
what keeps those rolls from firing a mod — both keys must land within 40 ms.
Bump it **down** if you get misfires while typing, **up** if the mods feel hard
to trigger.

---

## SYM layer — symbols (tap the trigger, left inner thumb)

One layer, both hands. Bracket pairs on the **left** (open next to close), the
less-common symbols on the **right**:

```
left hand        right hand
` [ ] < >          _ + |      (upper row)
~ { } ( )          - = \      (home row)
```

Tap the trigger, type one symbol, it exits. Double-tap the trigger to lock the
layer for a run of symbols. (Modifiers are not here — they're home-row combos.)

---

## NAV layer — navigation (tap `TG`, left pinky)

```
Home PgDn PgUp End     (right upper row)
 ←    ↓    ↑    →       (right home row)
```

Left home row carries one-shot **Ctrl / Alt / Cmd / Shift**. Tap a mod then an
arrow to jump/select by word/line; hold the mod while tapping to extend a range.
Tap `TG(NAV)` again to leave.

---

## NUM layer — numpad (tap `TG`, right pinky)

Right hand, calculator layout; `0` on the right outer thumb. Operators and `=`
live on the SYM layer.

```
7 8 9
4 5 6
1 2 3
 0        (right outer thumb)
```

Tap `TG(NUM)` again to leave.

---

## MEDIA layer — media + RGB (`TT`, top-right corner)

- **Left:** volume down/up/mute, media prev/stop/play/next, system sleep/wake.
- **Left bottom row:** `DF(_QWERTY)` / `DF(_COLEMAK)` base switches.
- **Right:** RGB hue/sat/val ±, animation next/prev, speed ±, toggle.
- **Corners:** `QK_BOOT` (top-right) and `EE_CLR` (right pinky) for reflashing.

---

## AERO layer — AeroSpace WM (tap `TG`, right inner thumb)

Drives the [AeroSpace](https://github.com/nikitabobko/AeroSpace) tiling WM by
firing its shortcuts directly — every key sends the `ctrl+alt` (or
`ctrl+alt+shift`) chord straight from `~/.config/aerospace/aerospace.toml`, so
AeroSpace needs no config of its own. Toggle on, juggle windows, toggle off.

> Keys send raw keycodes and AeroSpace reads them through its `qwerty`
> key-mapping preset, so the layer works the same whether the base is Colemak or
> QWERTY. If you re-bind something in `aerospace.toml`, update the matching key
> here (the chords are `#define`d as `AS_MOD` / `AS_MODS` at the top of
> `keymap.c`).

**Mental split: left hand = workspaces, right hand = the focused window.**

**Left — workspaces** (switch on top, *move the window there* directly below):

```
WS 1   WS 2  WS 3  WS 4  WS 5         (switch to workspace 1-5)
Mv→1   Mv→2  Mv→3  Mv→4  Mv→5         (move window to workspace 1-5)

WS Z   WS G  WS S   Close   New-win   (Z=Zoom, G=Gmail, S=Slack; close; new Ghostty)
Mv→Z   Mv→G  Mv→S   Resize-mode  Service-mode
```

**Right — the focused window:**

```
Focus-prev  Focus-next  Tiles  Accordion  Fullscreen      (upper row)
Move ←  Move ↓  Move ↑  Move →   Floating                 (move window — ctrl+alt+shift+arrows)
Focus ←  Focus ↓  Focus ↑  Focus →                        (focus window — same home-row spots as NAV's arrows)
Resize −  Resize +   Rotate   Rotate-rev   Pad-cycle       (bottom row)
```

Tap `TG(AERO)` again (right inner thumb) to leave.

---

## Switching base layout

On **MEDIA**, bottom-row left: `DF(_QWERTY)` / `DF(_COLEMAK)` (persists at
runtime, but a reset always boots **Colemak**). Board color shows which is
active: **red = QWERTY**, **blue = Colemak**.

---

## Per-layer colors

| Layer | Color |
|---|---|
| QWERTY (base) | red |
| Colemak (base) | blue |
| NAV (toggled on) | green |
| SYM (active) | gold |
| NUM (toggled on) | orange |
| MEDIA | teal |
| AERO (toggled on) | purple |

Colors are `*_noeeprom`, so they never overwrite your saved RGB settings.

---

## Tuning

No tap-hold keys, so no `TAPPING_TERM` / `PERMISSIVE_HOLD` tuning. Instead:

- `ONESHOT_TIMEOUT 3000` — a queued one-shot mod waits 3 s for its next key.
- `ONESHOT_TAP_TOGGLE 2` — double-tap any one-shot to lock it on.

---

## Build & flash

```sh
qmk compile -kb keebio/iris_ce/rev1 -km matthew
qmk flash   -kb keebio/iris_ce/rev1 -km matthew   # put a half in bootloader first
```

Split board: flash each half separately (`QK_BOOT` is on MEDIA, top-right).
