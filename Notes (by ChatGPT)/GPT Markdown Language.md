# Markdown Notes

[Markdown Documentation](https://www.markdownguide.org/getting-started/)

## What is Markdown?
Markdown is a lightweight markup language with plain text formatting syntax. Its design allows it to be converted to many output formats, but the original tool by the same name only supports HTML. Markdown is often used to format readme files, for writing messages in online discussion forums, and to create rich text using a plain text editor.

## Basic Syntax

### Headings
Use the `#` symbol followed by a space to create headings. The number of `#` symbols indicates the heading level.

```markdown
# Heading 1
## Heading 2
### Heading 3
#### Heading 4
##### Heading 5
###### Heading 6
```

### Bold and Italic
- To make text **bold**, wrap it with `**` or `__`.
- To make text *italic*, wrap it with `*` or `_`.

```markdown
**This is bold text**
__This is also bold text__

*This is italic text*
_This is also italic text_
```

### Lists
#### Unordered Lists
Use `-`, `*`, or `+` followed by a space to create unordered lists.

```markdown
- Item 1
- Item 2
  - Subitem 1
  - Subitem 2
* Item 3
+ Item 4
```

#### Ordered Lists
Use numbers followed by a period to create ordered lists.

```markdown
1. First item
2. Second item
   1. Subitem 1
   2. Subitem 2
3. Third item
```

### Links
To create a link, wrap the link text in brackets `[ ]`, and then wrap the URL in parentheses `( )`.

```markdown
[OpenAI](https://www.openai.com)
```

### Images
To add an image, use an exclamation mark `!` followed by alt text in brackets `[ ]`, and the path or URL to the image in parentheses `( )`.

```markdown
![OpenAI Logo](https://www.openai.com/logo.png)
```

### Reference
Internal Links to Go to a Specific Section of Page 

Internal Link
```markdown
# Table of Contents

- [Introduction](#introduction)
- [Target Section](#target-section)
- [Conclusion](#conclusion)

## Introduction

Welcome to the document!

## Target Section

This is the target section you linked to.

## Conclusion

Thanks for reading!
```
note: make sure the Section is not Single Hash`#` , otherwise it will reference to this current docs.

or 

```markdown
# Table of Contents

- [Overview of JavaScript](#overview-of-javascript)
- [Another Section](#another-section)

<a id="overview-of-javascript"></a>

### Overview of JavaScript

This section provides an overview of JavaScript.

<a id="another-section"></a>

### Another Section

This is another section to demonstrate internal linking.

```

External Link Written somewhere
```markdown
[Link Text][reference]

[reference]: http://example.com "Optional Title"

```
### Blockquotes
Use `>` to create blockquotes.

```markdown
> This is a blockquote.
> It can span multiple lines.
```

### Code
To format inline code, wrap it with backticks `` ` ``.

```markdown
Here is some inline code: `code`.
```

To create a code block, use three backticks \`\`\` \`\`\` , or indent the code with four spaces.

\`\`\`
```
This is a code block.
It can span multiple lines.
```
\`\`\`

### Horizontal Rules
Use three or more dashes `---`, asterisks `***`, or underscores `___` to create a horizontal rule.

```markdown
---
***
___
```

### Tables
To create tables, use pipes `|` and dashes `-` to separate columns and headers.

```markdown
| Header 1 | Header 2 | Header 3 |
| -------- | -------- | -------- |
| Row 1    | Data     | Data     |
| Row 2    | Data     | Data     |
```

### Sub<sub>script</sub>  &  Super<sup>script</sup>
SubScript : `log<sub>2</sub>N` : log<sub>2</sub>N

SuperScript : `2<sup>n</sup>` : 2<sup>n</sup>

### Next line
On Input side hit `enter` to write in new line, its for `markdown` inut readability\
to Show the text in next line , use `\` at the end of line and then press `enter`

### to Underline 
use HTML `<ins>` tag
```
<ins> This is Underlined </ins>
```

### Center
use HTML `<center> </center>` tag
```
<center> My Notess </center>
```

## Obsedian Markdown Features

### Highlight
`==`
### Line Break
`---`

### [Plugin for Features:](https://github.com/Benature/obsidian-underline)
- `<center>text</center>`: cmd/ctrl+Shift+C
- `[[<u>Underline</u>]]` : cntrl + u
- `[[#heading]]`: ctrl+#
- `[[#^block]]`: ctrl+^