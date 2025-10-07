
Here are **general notes on sharing state and React Context**:

---

### **Sharing State in React**

1. **Local State (`useState`)**
    
    - State defined inside a component.
        
    - Private to that component.
        
    - Example:
        
        ```jsx
        const [count, setCount] = useState(0);
        ```
        
    - Cannot be accessed directly outside the component.
        
2. **Lifting State Up**
    
    - If two components need the same state, move the state up to their **common parent**.
        
    - Pass the state and updater as **props** to children.
        
    - Works well when few components need the state.
        
3. **Prop Drilling Problem**
    
    - Passing props through many layers just to reach a deeply nested component.
        
    - Becomes messy and hard to maintain.
        

---

### **React Context**

1. **Definition**
    
    - A built-in React API for sharing values across the component tree without prop drilling.
        
2. **How It Works**
    
    - `createContext()` → creates a context object.
        
    - `Context.Provider` → wraps components and provides a value.
        
    - `useContext(Context)` → used inside any child to access that value.
        
3. **When to Use**
    
    - When many components at different levels need the same data.
        
    - Examples: authentication, theme, language, user settings, loading state.
        
4. **Advantages**
    
    - Eliminates prop drilling.
        
    - Central place to manage shared data.
        
    - Easy to access from any child.
        
5. **Disadvantages**
    
    - All consumers re-render when context value changes.
        
    - Should not be overused for every small state (can cause performance issues).
        
    - Best for global or app-wide state.
        

---

### **Example**

```jsx
// Create context
const ThemeContext = React.createContext();

// Provide context
function App() {
  return (
    <ThemeContext.Provider value="dark">
      <Child />
    </ThemeContext.Provider>
  );
}

// Consume context
function Child() {
  const theme = useContext(ThemeContext);
  return <div>Theme is {theme}</div>;
}
```

---

### **Summary**

- Use **local state** for component-specific values.
    
- **Lift state up** when siblings need to share it.
    
- Use **Context** when state must be accessible across many components, or siblings without a direct parent-child prop path.
    

---

Do you want me to also add **comparison table: Props vs Lifting vs Context** for clarity?