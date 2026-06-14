# Matthew's Iris CE keymap — quick reference

Ported from my ZSA Moonlander Colemak-DHm layout (Oryx `aOMg7/m5XPwj`). The
Moonlander's gaming QWERTY layer is dropped; this board keeps its own QWERTY
base. There is no window-manager layer (the Moonlander didn't have one).

Two base layouts (Colemak + QWERTY), CAGS home-row mods, four hold-to-reach
layers, and four combos.

---

## Reaching the layers

| Hold | Layer | What's on it |
|---|---|---|
| **Left Space** (left-mid thumb) | **NAV** | arrows + Home/End/PgUp/PgDn (right hand) |
| **D** (left index, lower row) | **NUM** | numpad (right hand) |
| **X** while in NUM | **SYM2** | `_ + \| - = \` (right hand) |
| **H** (right index, lower row) | **SYM** | bracket pairs (left hand) |
| **left-outer thumb** (`TT`, tap) | **MEDIA** | media transport + RGB |

`TT(MEDIA)` is a toggle: tap to enter, tap again to leave (or hold for momentary).

> On the QWERTY base the NUM/SYM holds sit on the same physical keys (left-index
> lower / right-index lower), so the muscle memory carries across both layouts.

---

## Thumb keys

| | outer | middle | inner |
|---|---|---|---|
| **Left**  | `TT` MEDIA | Space / **NAV** (hold) | Enter |
| **Right** | Backspace | Space | Right Alt |

---

## Combos

Matched by keycode (so they fire on the Colemak base, where these are all plain
keys). On the QWERTY base only `W+F`=Tab is affected — `F` is a home-row mod-tap
there — the other three work on both.

| Combo | Output |
|---|---|
| `W` + `F` | Tab |
| `U` + `Y` | Enter |
| `X` + `C` | Esc |
| `,` + `.` | Delete |

---

## Home-row mods (CAGS)

Hold a home-row key for a modifier; tap for the letter. Same on both layouts.

| | pinky | ring | middle | index |
|---|---|---|---|---|
| **Left**  (Colemak A R S T) | **Ctrl** | **Alt** | **Cmd** | **Shift** |
| **Right** (Colemak N E I O) | **Shift** | **Cmd** | **Alt** | **Ctrl** |

Tuned for macOS. `TAPPING_TERM` 200 ms, permissive hold on, `QUICK_TAP_TERM` 120 ms.

---

## SYM layer — brackets (hold right-index `H`)

Bracket pairs on the **left** hand, open next to close:

```
` [ ] < >      (upper row: Q W F P B positions)
~ { } ( )      (home row:  A R S T G positions)
```

Tap the **top-left key (Esc position)** to lock SYM hands-free; tap again to release.

---

## SYM2 layer — extra symbols (hold `D`, then `X`)

Nested under NUM, on the **right** hand:

```
_ + |          (upper row)
- = \          (home row)
```

---

## NAV layer — navigation (hold left Space)

Right hand:

```
Home PgDn PgUp End     (upper row)
 ←    ↓    ↑    →       (home row)
```

The left home row stays transparent, so the CAGS mods pass through — hold
Shift/Cmd/Opt + an arrow to select. Tap the **top-left key (Esc)** to lock NAV;
tap again to release.

---

## NUM layer — numpad (hold `D`)

Right hand, calculator layout:

```
7 8 9
4 5 6
1 2 3
 0        (right inner thumb)
```

Left hand: **Left Shift** (for shifted digits) and **SYM2** access on `X`.

---

## MEDIA layer — media + RGB (`TT`, left-outer thumb)

- **Left:** volume down/up/mute, media prev/stop/play/next, system sleep/wake.
- **Left bottom row:** `DF(_QWERTY)` / `DF(_COLEMAK)` base switches.
- **Right:** RGB hue/sat/val ±, animation next/prev, speed ±, toggle.
- **Corners:** `QK_BOOT` (top-right) and `EE_CLR` (right pinky) for reflashing.

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
| NAV (held or locked) | green |
| SYM (held or locked) | gold |
| NUM | orange |
| SYM2 | purple |
| MEDIA | teal |

Colors are `*_noeeprom`, so they never overwrite your saved RGB settings.

---

## Build & flash

```sh
qmk compile -kb keebio/iris_ce/rev1 -km matthew
qmk flash   -kb keebio/iris_ce/rev1 -km matthew   # put a half in bootloader first
```

Split board: flash each half separately (`QK_BOOT` is on MEDIA, top-right).
