
# [# Excel Tutorial For Beginners in Hindi | Complete Microsoft Excel Tutorial](https://www.youtube.com/watch?v=OX-iyb-21tk&ab_channel=RishabhMishra)

### **Layout Overview**

- **Top Horizontal**:  
    **Tabs**: Top navigation tabs (e.g., File, Home, Insert).  
    **Groups**: Sections inside each tab (e.g., Clipboard, Font, Alignment under Home).
    
- **Bottom Horizontal**:  
    **Sheets**: Displays sheet tabs for navigating between sheets.
    
- **Top Horizontal (Inside Sheets)**:  
    **Columns**: A, B, C, ..., Z, AA, AB, ...  
    **Rows**: Displayed vertically on the left side as 1, 2, 3, ...
    
- **Top Left Corner**:  
    **Selected Cells**: Shows the currently selected cell(s) (e.g., A1, B3).
    
    - For a single cell: `[Column][Row]` (e.g., A1).
    - For multiple cells: Displays as `13R x 9C` (e.g., 13 rows by 9 columns selected).
- **Bottom Right Corner**:  
    **Zoom In/Out**: Adjust the zoom level for the worksheet.
    

---

### **Advanced Features**

#### **Select Multiple Cells**

- **Using Keyboard**:
    - Select a cell, then use **Shift + Arrow Keys** to extend the selection.
- **Using Mouse**:
    - Left-click and drag to select a range of cells.

#### **Automatic Value Extension with Smart Features**

- To auto-fill a sequence along a row or column:
    1. Select the existing sequence.
    2. Drag the **bottom-right dot** of the selection.

**Examples**:

- `1` -> 1, 1, 1, ...
- `5, 3` -> 5, 3, 1, -1, -3, ...
- `A, B, C` -> A, B, C, A, B, C, ...

#### **Format Painter**

- To apply the format of one group of cells to another:
    1. Select the formatted cells.
    2. Go to **Home Tab > Clipboard Group** and click **Format Painter**.
    3. Select the target cells to apply the format.

#### **Change Date Format**

- To change a date like `01-12-2023` to `1-Dec-2024`:
    1. Select the cells containing the dates.
    2. Use the **format dropdown** in the **Number Group** under the **Home Tab**.

---

### **Formula Basics**

#### **Formula Box**

- Click any cell to apply a formula.  
    **Example**:
- `=2+2` will display `4`.

#### **Aggregate Formulas**

1. Select the output cell.
2. Type `=SUM()` or `=AVERAGE()`.
    - Use **TAB** to autocomplete.
3. Select the input cells:
    - **Mouse**: Drag to select.
    - **Keyboard**: Use `Ctrl` or `Shift`.
    - **Range**: Specify as `FUNC(Top-left:Bottom-right)` (e.g., `SUM(C2:C7)` or `SUM(C3:D9)`).
    - **Multiple cells**: Separate by commas (e.g., `=SUM(A1, B2, C3)`).

#### **Combine Text Using Functions**

- To combine first name (A1) and last name (B1) into full name in C1:  
    `=CONCAT(A1, " ", B1)`
    - Drag the **bottom-right dot** to apply the formula to other rows.

#### **Static Values**

- A formula-based cell will update when connected cells change.
- To keep a static value, **copy the cell** and **paste as value**.

https://youtu.be/OX-iyb-21tk?t=1262