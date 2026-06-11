# Matthew's Iris CE keymap — quick reference

A scannable cheat sheet for what's available. Two base layouts (Colemak + QWERTY),
CAGS home-row mods, and five hold-to-activate layers on the thumbs.

---

## Thumb keys (how you reach everything)

Each inner thumb is a **tap = key / hold = layer** dual-role key.

| Thumb (L→R) | Tap | Hold |
|---|---|---|
| Left outer | Cmd (GUI) | **WM** layer |
| Left middle | Space | **LOWER** layer |
| Left inner | Enter | **NAV** layer |
| Right inner | Backspace | **SYM** layer |
| Right middle | Space | **RAISE** layer |
| Right outer | Right Alt | — |

> Holding the left-outer thumb now activates the **WM** (window-manager) layer, so
> that thumb no longer gives you *hold*-Cmd. Use home-row Cmd (D / Colemak S) for
> Cmd+click and friends.

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
            ⌥- ⌥=                     window shrink / grow (top row, above ↓↑)
        ⌥←  PgDn PgUp ⌥→              word-jump + page (top row)
         ←   ↓    ↑    →   Home End   arrows + line ends (home row)
```

`⌥-` / `⌥=` resize the focused window (Alt+minus / Alt+equals).

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

## WM layer — AeroSpace window manager (hold left-outer / Cmd)

Board glows **purple**. The layer holds **Ctrl+Alt** (and Shift where noted) for
you, so each AeroSpace op is a single tap instead of a four-key chord. AeroSpace's
config is unchanged — the keyboard just sends the chords it already listens for.

### Right hand — focus & move (arrows mirror NAV)
```
move    (⌃⌥⇧+arrow)   Y  U  I  O          ← ↓ ↑ →   move window
focus   (⌃⌥+arrow)    H  J  K  L          ← ↓ ↑ →   focus window
resize  (⌃⌥ -/=)              ;  '        shrink / grow
extras  (top row)                P  Del   workspace back-and-forth · fullscreen
```

### Left hand — workspaces & actions
| Key (Colemak pos) | Action |
|---|---|
| `1`–`5` (number row) | switch to workspace 1–5 (⌃⌥n) |
| `Q W E R T` (row below) | move window to workspace 1–5 (⌃⌥⇧n) |
| `Z` | workspace **Z**oom · `S` workspace **S**lack · `G` workspace **G**mail |
| `A` | new terminal (⌃⌥↵) |
| `D` | toggle floating/tiling (⌃⌥⇧space) |
| `X` | close window · `C` rotate · `V` cycle side padding · `B` tiles ⇄ accordion toggle |

### Layer lock (hands-free)
- Hold WM, tap the **top-left key (Esc position)** → WM locks on, no thumb needed.
- Tap it again to release. Stays **purple** the whole time.

> Not yet mapped (still reachable via the raw ⌃⌥ chords): accordion-only toggle,
> service mode, and move-workspace-to-monitor. Easy to add to the layer later.

---

## SYM layer — programming symbols (hold right-inner / Backspace)

Board glows **gold**. Frequency-tuned for TypeScript + Lua/LazyVim. Bracket pairs
**mirror across the hands** — open on the left, close on the mirrored finger of the
right — on the home row.

```
 #  *  +  [  ·        ·  ]  -  ·  @
 ·  <  {  (  =        |  )  }  >  ·
 %  \  _  !  $        `  &  ·  ^  ~
   pnk rng mid idx       idx mid rng pnk
```

| Position | Symbols |
|---|---|
| Home, index | `(` `)` — most-typed pair, alternating-hand roll |
| Home, middle | `{` `}` |
| Home, ring | `<` `>` — generics |
| Home, index-reach | `=` (left) · `\|` (right, TS unions) |
| Top, index | `[` `]` — stacked above `( )` |
| Top row | `+ - *` arithmetic · `#` `@` |
| Bottom, index | `!` (left) · `&` (right) — the two logic keys |
| Bottom, index-reach | `$` (left) · `` ` `` (right) — template-literal chars |
| Bottom row | `% \ _ ^ ~` |

> `:` `;` `/` `?` are **not** on SYM — each is a plain tap (or shift) on the base
> layer, so duplicating them here was wasted real estate.

---

## LOWER layer (hold left-middle / Space)

Board glows **orange**. A clean calculator-style number pad on the right, arrows on
the left. All the symbol clutter that used to live here now has **one home on SYM** —
LOWER keeps only the keypad operators (`/ * - + .`) that belong with a numpad.

- Right: numpad `7 8 9 / 4 5 6 / 1 2 3`, `0` on the thumb, with `/ * - +` down the
  inner column and `.` by the `3`. PgUp/PgDn on the outer column.
- Left: arrow cluster (`← ↓ → / ↑`), `Del`, `QK_BOOT`.
- Bottom-left: `DF(_QWERTY)` / `DF(_COLEMAK)`, `RM_NEXT`, `EE_CLR`.

> The keypad `+ - * /` here output the same characters as SYM's; they're kept only
> because a numpad without operators is painful. Every other symbol lives on SYM.

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
| WM (held or locked) | purple |

Colors are `*_noeeprom`, so they never overwrite your saved RGB settings.

---

## Build & flash

```sh
qmk compile -kb keebio/iris_ce/rev1 -km matthew
qmk flash   -kb keebio/iris_ce/rev1 -km matthew   # put a half in bootloader first
```

Split board: flash each half separately (`QK_BOOT` is on RAISE, top-right).
