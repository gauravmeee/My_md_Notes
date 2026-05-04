
# Sequential Logic Circuits

#### Latch & Flip Flop

* **Latch** - Basic 1-bit storage element (level-triggered). changes output as long as enable is active
* **Flip-Flop** - Built from latches, 1-bit storage (edge-triggered). changes output only on clock edge
* **Shift Register** - Sequential circuit made from multiple flip-flops connected in series, used to store and shift data bit-by-bit.
* Flip-flops are built **using latches** (typically two latches in master–slave configuration).

**Types of Latch**

**1. SR Latch (Set-Reset)**

* **Inputs:** S (Set), R (Reset)
* **Operation:**
  * `S=1, R=0` → `Q=1` (Set)
  * `S=0, R=1` → `Q=0` (Reset)
  * `S=0, R=0` → `Q` holds value
  * `S=1, R=1` → Invalid state in basic form
* **Diagram:**

```
 S ──┐        ┌── Q
     │        │
    NOR────┐  │
     ▲     │  │
     │    NOR─┘
     │     ▲
     └─────R
```

**2. Gated SR Latch**

* **Inputs:** S, R, Enable (E)
* **Operation:**
  * Works like SR latch but changes output **only when E=1**.
  * E=0 → output holds.
* **Diagram:**

```
 S ─┐AND      ┌── Q
 E ─┘         │
              │
             NOR────┐
              ▲     │
 R ─┐AND      │    NOR─┘
 E ─┘         │     ▲
              └─────┘
```

**3. D Latch (Data / Transparent Latch)**

* **Inputs:** D, Enable (E)
* **Operation:**
  * `E=1` → `Q` follows `D`.
  * `E=0` → `Q` holds previous value.
  * Built from SR latch with gating to avoid invalid state.
* **Diagram:**

```
 D ─┐         ┌── S
    │AND      │
 E ─┘         │
              │
             SR Latch → Q
  D'─┐AND     │
 E ──┘        └── R
```

**4. JK Latch**

* **Inputs:** J, K, Enable (E)
* **Operation:**
  * `J=1, K=0` → Set
  * `J=0, K=1` → Reset
  * `J=0, K=0` → Hold
  * `J=1, K=1` → Toggle
  * Level-sensitive (changes when `E=1`)
* **Diagram (conceptual):**

```
 J, K + E → Logic → SR Latch → Q
```

**5. T Latch (Toggle)**

* **Inputs:** T, Enable (E)
* **Operation:**
  * `T=1, E=1` → Toggle `Q`
  * `T=0 or E=0` → Hold `Q`
  * Often built from JK latch with `J=K=T`.
* **Diagram:**

```
 T + E → XOR with Q → SR/D Latch → Q
```

**Types of Flip-Flop ⭐**

**1. SR Flip-Flop (Set-Reset)**

* **Inputs:** S (Set), R (Reset)
* **Operation:**
  * **`S=1, R=0` → `Q=1` (set)**
  * **`S=0, R=1` → `Q=0` (reset)**
  * **`S=0, R=0` → `Q` holds previous value**
  * **`S=1, R=1` → Invalid (in basic form)**
* **Diagram:**

```
   S ───┐
        │
      ┌─┴─┐
      │   │
      │   ├── Q
      │   │
      └─┬─┘
        │
   R ───┘
```

**2. JK Flip-Flop**

* **Inputs:** J, K
* **Operation:**
  * **J=1, K=0 → Set Q=1**
  * **J=0, K=1 → Reset Q=0**
  * **J=0, K=0 → Q holds**
  * **J=1, K=1 → Q toggles each clock**
* **Advantage:** Just removes **SR** invalid state. ( Rest Same as **SR** )⭐
* **Diagram:**

```
   J ───┐
        │
      ┌─┴─┐
CLK──>│   │── Q
      │   │
   K ─┴───┘
```

**3. D Flip-Flop (Data/Delay)**

* **Input:** D
* **Operation:**
  * **On clock edge, `Q` takes the value of `D`.**
  * **Eliminates ambiguity of SR and JK.**
* **Use:** Data storage and synchronization.
* **Diagram:**

```
   D ─────┐
          │
      ┌───┴───┐
CLK──>│       │── Q
      └───────┘
```

**4. T Flip-Flop (Toggle)**

* **Input:** T
* **Operation:**
  * **`T=0` → `Q` holds value**
  * **`T=1` → `Q` toggles on each clock**
* **Use:** Counters, frequency division.
* **Diagram:**

```
   T ─────┐
          │
      ┌───┴───┐
CLK──>│       │── Q
      └───────┘
```
