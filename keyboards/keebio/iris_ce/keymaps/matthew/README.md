# Matthew's Iris CE keymap — quick reference

A **combo-first, reduced-footprint** Colemak-DHm layout, ported from my latest
ZSA Moonlander (Oryx) design. The base layer carries **letters and almost
nothing else** — numbers, symbols, brackets, Tab/Enter/Esc/Backspace and the
layer launcher are all **combos**, so the physical key count stays tiny and the
hands barely leave the home block.

Two base layouts (Colemak + QWERTY), five extra layers (NAV, FN, WORD, WORK,
AERO), and a lot of combos.

---

## The big idea: letters on keys, everything else on combos

| You want | You press |
|---|---|
| a **letter** | the key |
| a **number** | a vertical same-finger combo (top + home row) |
| a **symbol / bracket** | a horizontal combo on the home or bottom row |
| **Tab / Enter / Esc / Backspace** | a two-key utility combo |
| a **modifier** | a one-shot key on a pinky column or thumb |
| a **layer** | the `A+R+S+T` launcher combo, or a thumb |

> **Double-tap to lock.** `ONESHOT_TAP_TOGGLE` is on, so double-tapping any
> one-shot (a mod, or NAV/FN) locks it on. Tap once more to release. `QK_LLCK`
> also locks the current layer (auto-releases after 5 s idle).

---

## Modifiers — one-shot, on the edges (the new scheme)

Modifiers are **one-shot (OSM)**: tap a mod, the **next** key is modified; they
chain (`Shift` then `Cmd` then `T` → `Cmd+Shift+T`) and can be held if you like.

| Mod | Where |
|---|---|
| **Ctrl**  | outer pinky column, **home** row — *both* hands |
| **Alt**   | outer pinky column, **bottom** row — *both* hands |
| **Shift** | right thumb |
| **Cmd**   | left thumb (a plain GUI hold — for `Cmd+Tab` / `Cmd+click`) |

> This replaces the old home-row *mod combos*. Those home-row pairs are now
> numbers and symbols (see below); modifiers moved to the pinky columns + thumbs.

**Caps Word** (`CW_TOGG`, left pinky, top row) covers whole-word capitalization.
The **NAV** layer also carries one-shot CAGS mods on its left home row for
select-while-navigating.

---

## Numbers — vertical same-finger combos

Squeeze a finger's **top-row + home-row** key together:

| | pinky | ring | middle | index | inner |
|---|---|---|---|---|---|
| **Left**  | `Q+A` = **1** | `W+R` = **2** | `F+S` = **3** | `P+T` = **4** | `B+G` = **5** |
| **Right** | `'+O` = **0** | `Y+I` = **9** | `U+E` = **8** | `L+N` = **7** | `J+M` = **6** |

The number row (`1`–`0`) is also populated as a backup, but the combos mean you
rarely reach for it.

---

## Symbols & brackets — horizontal combos

**Home row** (Shift them for `~ _ + |`):

| Combo | Output |
|---|---|
| `A` + `R` | `` ` `` |
| `N` + `E` | `-` |
| `E` + `I` | `=` |
| `I` + `O` | `\` |

**Bottom row** — open brackets march across the left hand, close brackets across
the right:

| Left | | Right | |
|---|---|---|---|
| `Z` + `X` | `<` | `K` + `H` | `)` |
| `X` + `C` | `{` | `H` + `,` | `]` |
| `C` + `D` | `[` | `,` + `.` | `}` |
| `D` + `V` | `(` | `.` + `/` | `>` |

Everything else (`! @ # $ % ^ & *`, `:`, `"`, `?`, `+`, `_`, `~`, `|`) comes from
**Shift + the combo above** or Shift + a number.

---

## Utility combos

| Combo | Output |
|---|---|
| `W` + `F` | Tab |
| `U` + `Y` | Enter |
| `Q` + `W` | Esc |
| `L` + `U` | Backspace |

> All combos are tuned for **Colemak** positions, so they fire on the Colemak
> base and *not* on QWERTY (which keeps its own number row and keys instead).
> `COMBO_TERM` is **40 ms** — tight enough that normal rolls don't misfire, and
> that the `A+R` (grave) vs. `A+R+S+T` (launcher) overlap resolves cleanly.
> Bump it down if you get misfires, up if combos feel hard to trigger.

---

## Thumb cluster

| | outer | middle | inner | inner-index (center) |
|---|---|---|---|---|
| **Left**  | `OSL(FN)` | **Cmd** | **Space** | **Enter** |
| **Right** | `OSL(NAV)` | **Shift** | **Space** | **Backspace** |

Enter/Backspace also exist as combos (`U+Y` / `L+U`); the center keys are a
convenient duplicate.

---

## Layers

| Layer | Reach it by | What's on it | Color |
|---|---|---|---|
| **Colemak** (base) | boot default | letters + combos | blue |
| **QWERTY** (base) | `DF` on FN | plain QWERTY + real number row | red |
| **NAV** | `OSL(NAV)` (right outer thumb) | arrows + Home/PgDn/PgUp/End; CAGS mods on left home | green |
| **FN** | `A+R+S+T` combo, or `OSL(FN)` (left outer thumb) | F1–F12, media, volume, RGB, system, base switch, AeroSpace toggle | teal |
| **WORD** | `N+E+I` combo (right home row) | programming-word combos (two-key rolls) | magenta |
| **WORK** | `R+S+T` combo (left home row) | sales-tax domain-word combos (two-key rolls) | gold |
| **AERO** | `TG(AERO)` on FN | AeroSpace WM control | purple |

`QK_LLCK` (top-left on NAV and FN) locks the layer; NAV/FN stay lit while locked.

---

## NAV layer

```
Home PgDn PgUp End     (right upper row)
 ←    ↓    ↑    →       (right home row)
```

Left home row carries one-shot **Ctrl / Alt / Cmd / Shift** — tap a mod then an
arrow to jump/select, or hold the mod while arrowing to extend a range. Tap
`OSL(NAV)` for one move, double-tap (or `QK_LLCK`) to lock for a nav session.

---

## FN layer

- **Number row:** `F1`–`F12`.
- **Left:** RGB toggle, volume down/up/mute, media prev/stop/play/next, sleep/wake.
- **Right:** RGB hue/sat/val ±, animation next/prev, speed ±.
- **Base switches:** `DF(_QWERTY)` / `DF(_COLEMAK)` (bottom-row left).
- **System:** `QK_BOOT` (right, top), `EE_CLR` (right pinky), `MAC_LOCK` (left).
- **AeroSpace:** `TG(_AERO)` to enter the window-manager layer.
- `QK_LLCK` to lock FN on.

---

## WORD layer — programming-word combos (`N+E+I` combo)

Squeeze **`N` + `E` + `I`** (the right home row) to toggle the word layer on,
then **roll a two-key combo** to type a code token. Firing one **auto-exits**
back to base, so one roll = one word. Tap `N+E+I` again to leave without typing.

This is the part you asked about — **layer-scoped combos**. The word combos are
gated by `combo_should_trigger()` so they fire *only* while `_WORD` is active;
on the base layers the same rolls do nothing special, and your numbers/symbols/
brackets combos are in turn suppressed while you're in word mode. The layer
itself is transparent — it's just a "mode flag" the word combos read.

Each combo is two letters from the word (mostly first letter + a salient one):

| Combo | Word | Combo | Word | Combo | Word |
|---|---|---|---|---|---|
| `R`+`E` | return    | `P`+`B` | public   | `D`+`O` | document |
| `F`+`N` | function  | `P`+`R` | private  | `O`+`B` | object   |
| `I`+`M` | import    | `P`+`O` | pointer  | `B`+`L` | boolean  |
| `E`+`X` | export    | `P`+`A` | params   | `L`+`G` | length   |
| `I`+`N` | include   | `V`+`R` | variable | `V`+`A` | value    |
| `I`+`F` | interface | `D`+`E` | define   | `R`+`S` | result   |
| `C`+`O` | const     | `D`+`F` | default  | `R`+`Q` | request  |
| `S`+`T` | struct    | `D`+`L` | delete   | `R`+`N` | response |
| `S`+`G` | string    | `C`+`N` | continue | `U`+`P` | update   |
| `S`+`W` | switch    | `C`+`X` | context  | `M`+`E` | message  |
|         |           | `C`+`B` | callback |         |          |

Tokens type with **no trailing space**, so you can append `()`, `;`, `<>`, etc.
right after. Adding more is two lines: a `cw_*` combo + a `W_*` `SEND_STRING`
case in `keymap.c` (no key needed — they're pure combos). Combos avoid
same-finger pairs, so every roll is comfortable.

> The `N+E+I` activation overlaps the base `N+E` (`-`) / `E+I` (`=`) combos;
> pressing all three within `COMBO_TERM` toggles the layer. Word picks are
> common cross-language keywords/identifiers — swap freely for your stack
> (e.g. `typedef`, `namespace`, `iterator`, `println`, `unsigned`).

---

## WORK layer — sales-tax domain combos (`R+S+T` combo)

Squeeze **`R` + `S` + `T`** (the left home row, no pinky) to toggle the domain
layer, then **roll a two-key combo** to type a sales-tax / tax-software term.
Firing one **auto-exits**; tap `R+S+T` again to leave without typing. Same
combo-driven, layer-gated mechanism as the programming layer.

> `R+S+T` is the `A+R+S+T` FN launcher **minus the pinky** — three home keys →
> work words, add your pinky (`A`) → FN. QMK resolves the nesting by longest
> match, so press exactly three for WORK, four for FN.

Each combo is mostly the word's **first two letters**:

| Combo | Word | Combo | Word | Combo | Word |
|---|---|---|---|---|---|
| `J`+`U` | jurisdiction | `R`+`E` | remittance  | `S`+`O` | sourcing     |
| `T`+`A` | taxability   | `N`+`X` | nexus       | `M`+`U` | municipality |
| `E`+`X` | exempt       | `S`+`U` | surcharge   | `L`+`O` | locality     |
| `C`+`O` | compliance   | `M`+`A` | marketplace | `D`+`I` | district     |
| `R`+`G` | registration | `F`+`A` | facilitator | `R`+`N` | region       |
| `C`+`E` | certificate  | `C`+`A` | calculation | `C`+`N` | country      |
| `T`+`H` | threshold    | `D`+`E` | destination | `A`+`D` | address      |
| `T`+`R` | transaction  | `I`+`N` | invoice     | `C`+`U` | customer     |
| `L`+`I` | liability    | `R`+`F` | refund      |         |              |

Words type with **no trailing space** (so you can add `-ion`, `s`, `al`, etc.).
The programming (`N+E+I`) and domain (`R+S+T`) combos live on separate gated
layers, so they reuse the same pairs without clashing (e.g. `C+O` = const in
WORD, compliance in WORK; `R+E` = return vs remittance). Easy to retune — each
word is a `cwk_*` combo + a `WK_*` `SEND_STRING` case in `keymap.c`. Obvious
additions for your stack: `exemption`, `taxable`, `remitting`, `province`,
`territory`, `penalty`, `accrual`, `audit`, `filing`, `origin`.

---

## AERO layer — AeroSpace WM (`TG(AERO)` on FN)

Drives the [AeroSpace](https://github.com/nikitabobko/AeroSpace) tiling WM by
firing its shortcuts directly — every key sends the `ctrl+alt` (or
`ctrl+alt+shift`) chord straight from `~/.config/aerospace/aerospace.toml`, so
AeroSpace needs no config of its own. **Left hand = workspaces, right hand = the
focused window.** Keys send raw keycodes read through AeroSpace's `qwerty`
preset, so the layer works the same on either base. The chords are `#define`d as
`AS_MOD` / `AS_MODS` at the top of `keymap.c`.

> Carried over from my previous Iris keymap — it is **not** in the current Oryx
> export. Delete the `_AERO` layer (and its `TG(_AERO)` on FN) if you don't use it.

---

## Switching base layout

On **FN**, bottom-row left: `DF(_QWERTY)` / `DF(_COLEMAK)`. Persists at runtime,
but a reset always boots **Colemak**. Board color shows which is active:
**red = QWERTY**, **blue = Colemak**.

---

## Tuning

No tap-hold keys, so no `TAPPING_TERM` / `PERMISSIVE_HOLD`. Instead:

- `ONESHOT_TIMEOUT 3000` — a queued one-shot waits 3 s for its next key.
- `ONESHOT_TAP_TOGGLE 2` — double-tap any one-shot to lock it on.
- `LAYER_LOCK_IDLE_TIMEOUT 5000` — a locked layer releases after 5 s idle.
- `COMBO_TERM 40` — combo window.

---

## Build & flash

```sh
qmk compile -kb keebio/iris_ce/rev1 -km matthew
qmk flash   -kb keebio/iris_ce/rev1 -km matthew   # put a half in bootloader first
```

Split board: flash each half separately (`QK_BOOT` is on FN, right side).
