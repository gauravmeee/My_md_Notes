Notes – **React Context API** (Sharing State Globally)

---

### 1. What is Context?

- Context API allows **sharing state/data across components** without passing props manually at every level.
    
- Useful when multiple components need access to the same data.
    

---

### 2. Steps to Implement Context

**(i) Create Context**

```jsx
import { createContext, useState, useContext } from "react";

const LoadingContext = createContext(); // create context object

export function LoadingProvider({ children }) {
  const [loading, setLoading] = useState(false); // central state
  return (
    <LoadingContext.Provider value={{ loading, setLoading }}>
      {children}
    </LoadingContext.Provider>
  );
}

export function useLoading() {
  return useContext(LoadingContext); // custom hook for easy usage
}
```

**(ii) Wrap Components with Provider**

```jsx
// Page.js
import { LoadingProvider } from "../context/LoadingContext";
import HeroSection from "../components/HeroSection";
import MainSection from "../components/MainSection";

export default function Page() {
  return (
    <LoadingProvider>
      <HeroSection />
      <MainSection />
    </LoadingProvider>
  );
}
```

**(iii) Use Context in Child Components**

```jsx
// MainSection.js
import { useLoading } from "../context/LoadingContext";

export default function MainSection() {
  const { loading, setLoading } = useLoading();
  return (
    <div>
      <p>Main Section (loading: {loading.toString()})</p>
      <button onClick={() => setLoading(!loading)}>Toggle</button>
    </div>
  );
}
```

```jsx
// HeroSection.js
import { useLoading } from "../context/LoadingContext";

export default function HeroSection() {
  const { loading } = useLoading();
  return <p>Hero sees loading: {loading.toString()}</p>;
}
```

---

### 3. How Context Works

- `createContext()` → creates a "box" to hold shared data.
    
- `Provider` → makes data available to all children inside it.
    
- `useContext()` → allows any child to consume that data.
    
- If state updates in Provider, **all components using context automatically re-render** with new value.
    

---

### 4. When to Use Context

- When multiple components need same state/data.
    
- To avoid "prop drilling" (passing props through many layers).
    
- Example: user authentication, theme, global loading state.
    

---

Do you want me to also include a **diagram-style flow explanation** (Provider → Consumer → Re-render) in notes?