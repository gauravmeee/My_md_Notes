---
description: Made By Me 💚
icon: dot
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# CommonJS vs ES Modules in JS

[![enter image description here](https://i.sstatic.net/O7XuF.png)](https://i.sstatic.net/O7XuF.png)

**Apart from that,**

You **can't** selectively load only the pieces you need with `require` but with `import`, you can selectively load only the pieces you need, which can save memory.

Loading is **synchronous**(step by step) for `require` on the other hand `import` can be asynchronous(without waiting for previous import) so it _can perform a little better than_ `require`.

***

**`.cjs` (CommonJS):**

* Explicitly marks a file as CommonJS, regardless of the `package.json` configuration.
* Useful when working with both module systems in the same project.

**`.mjs` (ES Modules):**

* Explicitly marks a file as an ES module, regardless of the `package.json` configuration.
* Avoids ambiguity when no `package.json` is present or when the file is standalone.

Study Middleware by `piyush garg`. He said middleware are like plugins
