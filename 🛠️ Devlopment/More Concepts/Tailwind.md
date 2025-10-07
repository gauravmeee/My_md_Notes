

## Tailwind + CSS Variables

##### **Summary**

**Styles in  `global.css`?**
- A **global stylesheet** applied to your entire project.
- Loaded in `app/layout.js` or `RootLayout`.
- Styles defined here apply to **all pages and components** (unless overridden).
- Commonly used for:
    - CSS variables (`--background`, `--yellow`, etc.)
    - Reset styles (`* { margin: 0; }`)
    - Utility overrides (scrollbar, typography)

**Common Problem**
- Variables like `--success-dark` or `--paper-bg` **exist in `:root`** but are **not included in `@theme inline`**.
- Tailwind classes referencing them (`bg-success-dark`) **won’t work**, even if the variable exists in CSS.
- Direct CSS (`var(--success-dark)`) will still work outside Tailwind.

**Solutions**
1. **Keep all Tailwind-used variables in `@theme inline`**.
2. **Map variables in `tailwind.config.js`** under `theme.extend.colors`.
3. **Use `var(--variable)` directly in CSS** if utility classes aren’t needed.
    
**Rule of Thumb**
- Tailwind utility classes only read variables mapped in `@theme inline` or `theme.extend`.
- Any variable in `:root` not mapped cannot be used in Tailwind classes.
- Direct CSS usage always works.

##### **1. Declaring CSS Variables**

- **Base variables** should be declared in `:root` for the default theme:
```css
/* Syntax: `--name: value;` inside a `:root` selector (so it’s globally available) */

:root {
  --background: #ffffff;
  --foreground: #000000;
  --primary: #2563eb;
  --success: #16a34a;
}


/* Variables are reusable across all CSS & Tailwind tokens. */
/* You can override them in `.dark {}` or `.light {}` for theming. */
```

- **Theme-specific overrides**:
```css
.light {
  --background: #ffffff;
  --foreground: #000000;
}

.dark {
  --background: #1a1a1a;
  --foreground: #f8fafc;
}
```

- **Optional system dark mode**:
```css
@media (prefers-color-scheme: dark) {
  :root {
    --background: #1a1a1a;
    --foreground: #f8fafc;
  }
}
```

##### **2. Using Variables Directly (Raw CSS)**

```css
body {
  background-color: var(--background);
  color: var(--foreground);
}
```

But **Tailwind does not understand raw variables** → need to map them.

##### **3. How Tailwind Works with CSS Variables**

- Tailwind **does not automatically read all CSS variables**. ⭐
- Only variables **inside `@theme inline`** or mapped in `tailwind.config.js` are usable in Tailwind utility classes like `bg-primary` or `text-success`.
- Any variable outside these blocks **will not work in Tailwind classes**, though direct CSS (`var(--variable)`) still works.

**`@theme inline` Mapping**
- Tailwind recognizes special token prefixes.  
- We map CSS variables to tokens so they can be used in **class names**.

**Common Token Categories:**
- `--color-*` → usable with `bg-*`, `text-*`, `border-*`
- `--font-*` → usable with `font-*`
- `--radius-*` → usable with `rounded-*`
- `--shadow-*` → usable with `shadow-*`
- `--spacing-*` → usable with `m-*`, `p-*`, `gap-*`
- `--size-*` → usable with `w-*`, `h-*`
- `--opacity-*` → usable with `opacity-*`
- `--z-*` → usable with `z-*`

##### **4. Ways to Use CSS Variables with Tailwind**

**Option 1: `@theme inline` (Simple, recommended)**

- All variables you want to use in Tailwind classes must be **inside `@theme inline`**:
```css
@theme inline {
  --color-background: var(--background);
  --color-foreground: var(--foreground);
  --color-primary: var(--primary);
  --color-success: var(--success);
}
```

- Then you can use classes like:
```html
<div class="bg-background text-foreground">
  Hello World
</div>
```

- **This works because:**
	- `bg-background` → Tailwind looks for `--color-background`
	- `text-foreground` → Tailwind looks for `--color-foreground`


**Option 2: Tailwind Config (`theme.extend`)**

- Map CSS variables in `tailwind.config.js`:
```js
export default {
  theme: {
    extend: {
      colors: {
        primary: 'var(--primary)',
        success: 'var(--success)',
        background: 'var(--background)',
        foreground: 'var(--foreground)',
      },
    },
  },
}
```
- Use Tailwind classes: `bg-primary`, `text-success`.
    

**Option 3: Direct CSS Usage**

- Use raw CSS variables in your own styles:
```css
.btn {
  background-color: var(--primary);
  color: var(--foreground);
}
```
- Tailwind classes are not needed, but you lose utility class flexibility.

