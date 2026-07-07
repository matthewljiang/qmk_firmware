# Matthew's Iris CE keymap — quick reference

A **combo-first** Colemak-DHm layout. The base layer is letters plus a little
punctuation; **numbers, brackets, most symbols, and Tab/Enter/Backspace are
combos**, so the hands barely leave the home block. Three layers: **Colemak**
(base), **NAV**, **FN**.

> **Double-tap to lock.** `ONESHOT_TAP_TOGGLE 2` is on, so double-tapping any
> one-shot (a mod, or NAV/FN) locks it on. Tap once more to release.

---

## Base layer

- **Letters:** Colemak-DHm.
- **Punctuation on keys:** `;` `'` `,` `.` `/`, and `Esc` (left home).
- **Top row:** a **panic/clear** key far left (clears stuck mods, one-shots, and
  layers), then `Ctrl+Alt+1`…`Ctrl+Alt+0` app-switch chords across the number
  row (for AeroSpace / app switching — *not* plain digits).
- **Thumbs:** `OSL(FN)` · **Cmd** · **Space**  |  **Shift** · `OSL(NAV)` · –

---

## Modifiers — one-shot (OSM)

Tap a mod, the **next** key is modified; they chain (`Shift` then `Cmd` then `T`
→ `Cmd+Shift+T`) and can be held.

| Mod | Where |
|---|---|
| **Cmd**   | left thumb |
| **Shift** | right thumb |
| **Ctrl / Alt / Cmd / Shift** | **NAV** layer, left home row (`A R S T`) — this is where Ctrl/Alt live |

---

## Numbers — vertical combos (top row + home row)

| | pinky | ring | middle | index | inner |
|---|---|---|---|---|---|
| **Left**  | `Q+A` = **1** | `W+R` = **2** | `F+S` = **3** | `P+T` = **4** | `B+G` = **5** |
| **Right** | `'+O` = **0** | `Y+I` = **9** | `U+E` = **8** | `L+N` = **7** | `J+M` = **6** |

There is **no number row or number layer** — digits come only from these combos.

---

## Brackets — horizontal top-row combos

Open brackets on the left hand, close brackets on the right:

| Left | | Right | |
|---|---|---|---|
| `Q` + `W` | `<` | `J` + `L` | `)` |
| `W` + `F` | `{` | `L` + `U` | `]` |
| `F` + `P` | `[` | `U` + `Y` | `}` |
| `P` + `B` | `(` | `Y` + `;` | `>` |

---

## Symbols — home-row combos

| Combo | Output | Shifted |
|---|---|---|
| `A` + `R` | `` ` `` | `~` |
| `G` + `M` | `+` | |
| `N` + `E` | `-` | `_` |
| `E` + `I` | `=` | |
| `I` + `O` | `\` | `\|` |

Everything else (`! @ # $ % ^ & *`, `:`, `"`, `?`, etc.) is **Shift + a number
combo** or **Shift + a key** (e.g. `Shift`+`/` = `?`, `Shift`+`;` = `:`).

---

## Utility combos (bottom row)

| Combo | Output |
|---|---|
| `X` + `C` | Tab |
| `,` + `.` | Enter |
| `H` + `,` | Backspace |

`Esc` is a real key (left home row). The `A+R+S+T` combo launches the FN layer.

> `COMBO_TERM` is **40 ms** — tight enough that normal rolls don't misfire and
> the `A+R` (grave) vs. `A+R+S+T` (launcher) overlap resolves cleanly. Bump down
> for fewer misfires, up if combos feel hard to trigger.

---

## Layers

| Layer | Reach it by | What's on it | Color |
|---|---|---|---|
| **Colemak** (base) | boot default | letters + combos | blue |
| **NAV** | `OSL(NAV)` (right thumb) | arrows on right home (`M N E I` = ← ↓ ↑ →); one-shot Ctrl/Alt/Cmd/Shift on left home | green |
| **FN** | `A+R+S+T` combo, or `OSL(FN)` (left thumb) | F1–F12, media, volume, RGB, sleep/wake, `QK_BOOT`, `EE_CLR`, `MAC_LOCK` | teal |

---

## Tuning (`config.h`)

No tap-hold keys, so no `TAPPING_TERM` / `PERMISSIVE_HOLD`. Instead:

- `ONESHOT_TIMEOUT 1500` — a queued one-shot waits 1.5 s for its next key.
- `ONESHOT_TAP_TOGGLE 2` — double-tap any one-shot to lock it on.
- `COMBO_TERM 40` — combo window.

---

## Build & flash

```sh
qmk compile -kb keebio/iris_ce/rev1 -km matthew
```

UF2-drive flashing is broken on this Mac, so flash with **picotool** (put a half
in bootloader first via `QK_BOOT` on FN, or the PCB reset button):

```sh
until picotool info >/dev/null 2>&1; do :; done
picotool load -x keebio_iris_ce_rev1_matthew.uf2
```

Split board: flash each half separately.

---

## Diagram

`matthew.svg` is generated from `matthew.yaml`:

```sh
uvx --from keymap-drawer keymap draw matthew.yaml > matthew.svg
```

Hand-edit the YAML when the keymap changes — don't re-parse from `keymap.c`.
