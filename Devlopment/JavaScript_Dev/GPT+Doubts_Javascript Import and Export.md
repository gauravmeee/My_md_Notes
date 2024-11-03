

# Require vs Import

In JavaScript, `import` and `require` are both used to include and use modules, but they are used in different contexts and have different syntax and features. Here’s a comparison:

### `require`

- **Context**: CommonJS
- **Used in**: Node.js (primarily)
- **Syntax**:
  ```javascript
  const module = require('module-name');
  ```
- **Features**:
  - **Synchronous Loading**: Modules are loaded synchronously. This is suitable for server-side code where modules are typically loaded from the filesystem.
  - **Dynamic Loading**: You can use `require` inside functions or conditionally.
  - **No static analysis**: Since `require` is a function call, the imports cannot be analyzed at compile time for optimizations.

### `import`

- **Context**: ES Modules (ESM)
- **Used in**: Modern JavaScript environments including browsers and Node.js (with `.mjs` extension or `type: module` in `package.json`)
- **Syntax**:
  ```javascript
  import { something } from 'module-name';
  import * as module from 'module-name';
  import defaultExport from 'module-name';
  ```
- **Features**:
  - **Asynchronous Loading**: Modules can be loaded asynchronously using `import()`, which returns a promise.
  - **Static Analysis**: `import` statements are static and can be analyzed at compile time. This allows for tree-shaking, which removes unused code during bundling.
  - **Top-Level Only**: `import` statements must be at the top level of the module and cannot be used conditionally or inside functions.

# Default Export vs Named Export

In JavaScript ES Modules, `default export` and `named export` are two ways to export code from a module. They serve different purposes and have different syntaxes. Here's a breakdown of each:

### Default Export

- **Purpose**: Allows you to export a single value or entity from a module.
- **Syntax**:
  ```javascript
  // module.js
  export default function myFunction() {
    // function body
  }
  
  // or exporting an object
  export default {
    key: 'value'
  };
  ```
- **Importing**:
  ```javascript
  // Importing the default export
  import myFunction from './module';
  ```

  ```javascript
  // Importing default export with a different name
  import anyName from './module';
  ```

- **Characteristics**:
  - **Single Default Export**: Each module can have only one default export.
  - **Import Name**: The name used when importing the default export can be chosen freely (it does not have to match the name used in the module).

### Named Export

- **Purpose**: Allows you to export multiple values or entities from a module.
- **Syntax**:
  ```javascript
  // module.js
  export function myFunction() {
    // function body
  }

  export const myValue = 42;
  
  // or export all together
  const anotherValue = 'hello';
  export { anotherValue };
  ```

- **Importing**:
  ```javascript
  // Importing named exports
  import { myFunction, myValue } from './module';
  ```

  ```javascript
  // Importing with alias
  import { myFunction as func, myValue as value } from './module';
  ```

- **Characteristics**:
  - **Multiple Named Exports**: You can have multiple named exports per module.
  - **Import Name**: The names used when importing must match the names exported (unless you use an alias).

### Comparison

- **Default Export**:
  - Suitable for exporting a single main entity or value from a module.
  - Importing does not require the exact name, making it flexible.

- **Named Export**:
  - Suitable for exporting multiple entities from a module.
  - Importing requires exact names or allows for aliasing.
