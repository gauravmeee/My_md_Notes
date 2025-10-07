
### Notes – **Hooks & Custom Hooks in React**

---

### 1. What is a Hook?

- A **Hook** is a special function in React that lets you “hook into” React features (state, lifecycle, context, etc.) inside functional components.
    
- Examples of built-in hooks:
    
    - `useState` → manage state
        
    - `useEffect` → run side effects
        
    - `useContext` → use context
        
    - `useRef`, `useMemo`, `useCallback`, etc.
        

Rules of hooks:

1. Only call hooks at the **top level** of a function component (not inside loops, conditions).
    
2. Only call hooks inside **React functions** (components or custom hooks).
    

---

### 2. What is a Custom Hook?

- A **custom hook** is just a normal JavaScript function that uses one or more React hooks.
    
- It helps **reuse logic** between components.
    
- Naming convention: must start with `use` (e.g., `useLoading`, `useFetch`).
    

---

### 3. How to Create a Custom Hook

**Example: Custom Hook for window width**

```jsx
import { useState, useEffect } from "react";

function useWindowWidth() {
  const [width, setWidth] = useState(window.innerWidth);

  useEffect(() => {
    const handleResize = () => setWidth(window.innerWidth);
    window.addEventListener("resize", handleResize);

    return () => window.removeEventListener("resize", handleResize);
  }, []);

  return width; // return state
}

export default useWindowWidth;
```

**Use in component:**

```jsx
import useWindowWidth from "./hooks/useWindowWidth";

export default function MyComponent() {
  const width = useWindowWidth(); // use custom hook
  return <p>Window width: {width}px</p>;
}
```

---

**Example: Custom Hook for fetching data**

```jsx
import { useState, useEffect } from "react";

function useFetch(url) {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    fetch(url)
      .then(res => res.json())
      .then(json => {
        setData(json);
        setLoading(false);
      });
  }, [url]);

  return { data, loading };
}

export default useFetch;
```

**Use in component:**

```jsx
import useFetch from "./hooks/useFetch";

export default function Users() {
  const { data, loading } = useFetch("https://jsonplaceholder.typicode.com/users");

  if (loading) return <p>Loading...</p>;
  return (
    <ul>
      {data.map(user => <li key={user.id}>{user.name}</li>)}
    </ul>
  );
}
```

---

### 4. Why Custom Hooks?

- **Reusability** → same logic used in multiple components.
    
- **Cleaner Code** → keeps components small and focused on UI.
    
- **Abstraction** → separates logic from presentation.
    

---

Do you want me to make **short comparison notes: built-in hooks vs custom hooks** also?


---
---
If you name a custom hook **something else (not starting with `use`)**, React will not treat it as a Hook.

### What happens if not starting with `use`

- **React lint rules** (`eslint-plugin-react-hooks`) won’t check it → you might accidentally break Hook rules (like calling inside loops/conditions).
    
- React DevTools also won’t show it properly as a Hook.
    
- It will still run as a normal function, but you lose **all benefits of hook safety**.
    

### Example (wrong way)

```jsx
function fetchData(url) {   // ❌ not starting with "use"
  const [data, setData] = useState(null);  // may still work, but unsafe
  // ...
}
```

### Correct way

```jsx
function useFetchData(url) {  // ✅ starts with "use"
  const [data, setData] = useState(null);
  // ...
}
```

**Conclusion:**

- Always start custom hooks with **`use`**.
    
- This is not just naming style → React relies on it to enforce **Rules of Hooks** and tooling support.
    

Do you want me to also explain **how React internally knows it’s a hook because of `use` prefix`**?