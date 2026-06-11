# Matthew's Iris CE keymap — quick reference

A scannable cheat sheet for what's available. Two base layouts (Colemak + QWERTY),
CAGS home-row mods, and four hold-to-activate layers on the thumbs.

---

## Thumb keys (how you reach everything)

Each inner thumb is a **tap = key / hold = layer** dual-role key.

| Thumb (L→R) | Tap | Hold |
|---|---|---|
| Left outer | Cmd (GUI) | — |
| Left middle | Space | **LOWER** layer |
| Left inner | Enter | **NAV** layer |
| Right inner | Backspace | **SYM** layer |
| Right middle | Space | **RAISE** layer |
| Right outer | Right Alt | — |

Hold LOWER **and** RAISE together → **ADJUST** (tri-layer).

---

## Home-row mods (CAGS)

Hold a home-row key for a modifier; tap it for the letter. Same on both layouts.

| | pinky | ring | middle | index |
|---|---|---|---|---|
| **Left**  (Colemak A R S T) | **Ctrl** | **Alt** | **Cmd** | **Shift** |
| **Right** (Colemak N E I O) | **Shift** | **Cmd** | **Alt** | **Ctrl** |

Tuned for macOS. `TAPPING_TERM` 200 ms, permissive hold on.

---

## Switching base layout

On the **LOWER** layer, bottom-row left:

- `DF(_QWERTY)` and `DF(_COLEMAK)` — set the default base layer (persists).

Board color tells you which is active: **red = QWERTY**, **blue = Colemak**.

---

## NAV layer — navigation + text editing (hold left-inner / Enter)

Board glows **green** while NAV is active.

### Movement (right hand)
```
        ⌥←  PgDn PgUp ⌥→              word-jump + page (top row)
         ←   ↓    ↑    →   Home End   arrows + line ends (home row)
```

### Editing (left hand)
| Key (Colemak) | Action |
|---|---|
| `Q` | delete to line start (Cmd+⌫) |
| `W` | delete previous word (⌥⌫) |
| `F`/`E` pos | delete next word (⌥⌦) |
| `P`/`R` pos | delete to line end (Ctrl+K) |
| `Z` | **undo** (Cmd+Z) |
| `X` | **cut** (Cmd+X) |
| `C` | **copy** (Cmd+C) |
| `V` | **paste** (Cmd+V) |
| `B` | **redo** (Cmd+Shift+Z) |

### Selection
- Left home row keeps the **CAGS mods**, so hold Shift/Cmd/Opt + a right-hand
  movement key to select (e.g. Shift+→ = select char, Opt+Shift+→ = select word).
- **One-shot Shift** on the right `P` key: tap it, then any movement key extends a
  selection — "shift for a whole word." Tap twice to lock Shift on.
- `Cmd+A` select-all on the right `N`/`J` position (bottom row).

### Layer lock (stay in NAV hands-free)
- Hold NAV, tap the **top-left key (Esc position)** → NAV locks on, no thumb needed.
- Tap it again to release. Stays **green** the whole time so you know you're in the
  (destructive) editing mode.

---

## SYM layer — programming symbols (hold right-inner / Backspace)

Board glows **gold**. Brackets stack vertically in columns 2–3.

```
 `  {  }  @  $        %  #  ^  <  >
 ~  (  )  =  +        !  -  _  *  /  ?
 |  [  ]  \  &
```

---

## LOWER layer (hold left-middle / Space)

Board glows **orange**. Number pad on the right, symbols on top, arrows on the left.

- Top row: `~ ! @ # $ %` … `^ & * ( )` + PgUp/PgDn
- Left: arrow cluster (`← ↓ → / ↑`), `[ ]`, `{ } ( )`
- Right: numpad `7 8 9 0 / 4 5 6 / 1 2 3 / 0`, `+ - | `
- Bottom-left: `DF(_QWERTY)` / `DF(_COLEMAK)`, `RM_NEXT`, `EE_CLR`

---

## RAISE layer — F-keys, media, RGB (hold right-middle / Space)

Board glows **teal**.

- **Top row:** F1–F12
- **Media (left):** prev/next track, play/stop, volume up/down, mute
- **RGB controls (right):**

| Control | Key (Colemak) | Code |
|---|---|---|
| Brightness **up** | `O` (home row) | `RM_VALU` |
| Brightness **down** | `/` (bottom row) | `RM_VALD` |
| Hue +/− | `E` / `,` | `RM_HUEU` / `RM_HUED` |
| Saturation +/− | `I` / `.` | `RM_SATU` / `RM_SATD` |
| Toggle RGB on/off | `Q` | `RM_TOGG` |
| Next animation | `Tab` pos | `RM_NEXT` |

Brightness **persists** across layer changes and reboots.

---

## Per-layer colors at a glance

| Layer | Color |
|---|---|
| QWERTY (base) | red |
| Colemak (base) | blue |
| LOWER | orange |
| RAISE | teal |
| NAV (held or locked) | green |
| SYM | gold |

Colors are `*_noeeprom`, so they never overwrite your saved RGB settings.

---

## Build & flash

```sh
qmk compile -kb keebio/iris_ce/rev1 -km matthew
qmk flash   -kb keebio/iris_ce/rev1 -km matthew   # put a half in bootloader first
```

Split board: flash each half separately (`QK_BOOT` is on RAISE, top-right).
