
Great that you already know JavaScript 👍 — TypeScript (and **TSX**, which is TypeScript + JSX for React) will feel familiar, just _stricter and safer_.

Below are **practical notes** focused on what you’ll actually see in a TSX project, especially React.

---

# TypeScript Notes for JavaScript Developers (TSX-focused)

## 1. Why TypeScript?

- TypeScript = JavaScript + **types**
    
- Errors caught **before runtime**
    
- Better autocomplete & refactoring
    
- Makes large React projects safer
    

---

## 2. Basic Type Annotations

### Variables

```ts
let name: string = "Alex";
let age: number = 18;
let isLoggedIn: boolean = true;
```

Type inference (preferred):

```ts
let score = 100; // inferred as number
```

---

## 3. Arrays

```ts
let numbers: number[] = [1, 2, 3];
let names: string[] = ["a", "b"];

let mixed: (string | number)[] = [1, "two"];
```

---

## 4. Objects

```ts
const user: {
  name: string;
  age: number;
} = {
  name: "Sam",
  age: 20,
};
```

Usually done with **types or interfaces** (see below).

---

## 5. Functions

### Basic

```ts
function add(a: number, b: number): number {
  return a + b;
}
```

### Arrow function

```ts
const multiply = (a: number, b: number): number => a * b;
```

### Void (no return)

```ts
const log = (msg: string): void => {
  console.log(msg);
};
```

---

## 6. `type` vs `interface` (Very Important)

### `type`

```ts
type User = {
  name: string;
  age: number;
};
```

### `interface`

```ts
interface User {
  name: string;
  age: number;
}
```

✅ **Rule of thumb**

- Use `interface` for **props & objects**
    
- Use `type` for **unions, primitives, functions**
    

---

## 7. Union Types (`|`)

```ts
let id: number | string;

id = 1;
id = "abc";
```

Very common in React props.

---

## 8. Optional Properties (`?`)

```ts
interface User {
  name: string;
  age?: number; // optional
}
```

---

## 9. Type Aliases for Functions

```ts
type AddFn = (a: number, b: number) => number;

const add: AddFn = (a, b) => a + b;
```

---

## 10. Enums (Sometimes Seen)

```ts
enum Status {
  Loading,
  Success,
  Error,
}
```

Usage:

```ts
let currentStatus: Status = Status.Loading;
```

---

## 11. Any (Avoid If Possible)

```ts
let value: any;
```

❌ No type safety  
Use only when unavoidable.

---

## 12. Unknown (Safer than `any`)

```ts
let value: unknown;

if (typeof value === "string") {
  console.log(value.toUpperCase());
}
```

---

## 13. Type Assertions

When _you_ know the type:

```ts
const input = document.getElementById("name") as HTMLInputElement;
console.log(input.value);
```

---

## 14. TSX / React Basics

### Functional Component

```tsx
const App: React.FC = () => {
  return <div>Hello</div>;
};
```

or (preferred modern way):

```tsx
function App() {
  return <div>Hello</div>;
}
```

---

## 15. Props in TSX

### Using interface

```tsx
interface Props {
  title: string;
  count?: number;
}

function Header({ title, count }: Props) {
  return (
    <h1>
      {title} {count}
    </h1>
  );
}
```

---

## 16. useState

```tsx
const [count, setCount] = useState<number>(0);
```

With union:

```tsx
const [user, setUser] = useState<User | null>(null);
```

---

## 17. useEffect

```tsx
useEffect(() => {
  console.log("mounted");
}, []);
```

(No special typing usually needed)

---

## 18. Event Handling

```tsx
const handleClick = (e: React.MouseEvent<HTMLButtonElement>) => {
  console.log(e.target);
};
```

Input change:

```tsx
const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
  setValue(e.target.value);
};
```

---

## 19. Children Prop

```tsx
interface Props {
  children: React.ReactNode;
}

function Layout({ children }: Props) {
  return <div>{children}</div>;
}
```

---

## 20. Common Errors You’ll See

### ❌ Object possibly null

```ts
user.name // error
```

✅ Fix:

```ts
user?.name
```

---

### ❌ Type 'string' is not assignable to type 'number'

Means exactly what it says 😄  
Fix by correcting types.

---

## 21. Useful TS Utility Types

```ts
Partial<User>    // all optional
Required<User>   // all required
Pick<User, "name">
Omit<User, "age">
```

---

## 22. When You’re Confused

Ask:

1. What is the **type** expected?
    
2. Is it **nullable**?
    
3. Is it a **union**?
    
4. Should this be optional?
    

---

## 23. Best Practices

✅ Let TS infer types  
✅ Avoid `any`  
✅ Use interfaces for props  
✅ Read error messages carefully  
❌ Don’t over-type everything

---

If you want, I can:

- Convert **JS React code → TSX**
    
- Explain **TS errors you’re seeing**
    
- Make a **cheat sheet PDF**
    
- Explain **advanced TS (generics, utility types)**
    

Just tell me 👍