
# Computer Graphics

|     | Topics                    | Subtopics                     |
| --- | ------------------------- | ----------------------------- |
| 1   | Display Devices           | CRT, LCD, LED                 |
| 2   | Output Primitives         | Line, Circle, Polygon drawing |
| 3   | Geometric Modeling        | 2D/3D transformations         |
| 4   | Viewing                   | 2D and 3D projections         |
| 5   | Visible Surface Detection | Z-buffer, Painter’s algorithm |
# 1. Display Devices

**Definition:**  
Display devices are output units used to present visual information to the user in text, graphics, or images form.

## 1. **Cathode Ray Tube (CRT)**

- Uses electron beams to excite phosphor dots on the screen.
    
- Components: Electron gun, focusing & deflection system, phosphor-coated screen.
    
- Types:
    
    - **Raster Scan:** Refreshes entire screen line by line (used in TVs, monitors).
        
    - **Random Scan:** Draws only lines/curves (used in vector displays, oscilloscopes).
        
- Advantages: High resolution, good color.
    
- Disadvantages: Bulky, high power consumption, limited portability.
    

## 2. **Liquid Crystal Display (LCD)**

- Uses liquid crystals that modulate light between polarizers.
    
- Each pixel controlled by an electric field.
    
- Types:
    
    - **Passive Matrix LCD** – slower response, cheaper.
        
    - **Active Matrix (TFT LCD)** – faster, better color and contrast.
        
- Advantages: Thin, lightweight, low power.
    
- Disadvantages: Limited viewing angles, slower refresh rates.
    

## 3. **Light Emitting Diode (LED)**

- Array of LEDs used as light source (backlight or direct emission).
    
- Better brightness, contrast, and energy efficiency than LCD.
    
- Variants: Edge-lit and full-array LED displays.
    

## 4. **Plasma Display Panel (PDP)**

- Uses small gas cells containing neon/xenon plasma that emit UV light to excite phosphors.
    
- Advantages: Wide viewing angle, high brightness.
    
- Disadvantages: Heavy, high power use, image burn-in.
    

## 5. **Organic LED (OLED)**

- Uses organic compounds that emit light when current passes.
    
- Self-emissive (no backlight needed).
    
- Advantages: Excellent contrast, thin, flexible, energy efficient.
    
- Disadvantages: Shorter lifespan, expensive manufacturing.
    

## 6. **Digital Light Processing (DLP)**

- Uses micromirrors on a semiconductor chip to reflect light.
    
- Common in projectors.
    
- Advantages: High contrast, good color accuracy.
    
- Disadvantages: Rainbow effect, complex optics.
    

## 7. **Touch Screen Displays**

- Detect user input via touch sensors.
    
- Technologies: Resistive, Capacitive, Infrared, Surface Acoustic Wave (SAW).
    
- Used in smartphones, ATMs, kiosks.
    

**Summary Table:**

|Type|Technology|Key Feature|Example Use|
|---|---|---|---|
|CRT|Electron beam|High resolution|Old monitors|
|LCD|Liquid crystals|Thin, low power|Laptops|
|LED|LED backlight|Bright, efficient|TVs|
|PDP|Gas discharge|Large screens|Plasma TVs|
|OLED|Organic emitters|Flexible, high contrast|Smartphones|
|DLP|Micromirrors|Projection|Projectors|
|Touch Screen|Sensor-based|Interactive input|ATMs|

---
---

# 2. Output Primitives

**Definition:**  
Output primitives are basic graphic elements used to construct complex images. They define how objects are represented on a display device.

## 1. **Point**

- Smallest visible unit on the display.
    
- Represented by pixel coordinates (x, y).
    
- To plot a point:
    
    ```
    putpixel(x, y, color);
    ```
    
- Transformation: Translation, Scaling, Rotation can be applied to points.
    

## 2. **Line**

- Connects two points (x1, y1) and (x2, y2).
    
- Line attributes: type (solid/dashed), color, thickness.
    
- Algorithms for line generation:
    
    - **Digital Differential Analyzer (DDA)**
        
    - **Bresenham’s Line Algorithm**
        
- Equation of a line: y = mx + c
    

## 3. **Circle**

- Set of points at a fixed distance (radius) from a center (xc, yc).
    
- Equation: (x – xc)² + (y – yc)² = r²
    
- Circle drawing algorithms:
    
    - Midpoint Circle Algorithm
        
    - Bresenham’s Circle Algorithm
        

## 4. **Ellipse**

- Equation: (x²/a²) + (y²/b²) = 1  
    where a = semi-major axis, b = semi-minor axis.
    
- Algorithm: Midpoint Ellipse Algorithm.
    

## 5. **Polygon**

- Closed figure made of connected line segments.
    
- Specified by vertices (x1, y1), (x2, y2), ..., (xn, yn).
    
- Types: Convex and Concave.
    
- Polygon filling algorithms:
    
    - Boundary-fill algorithm
        
    - Flood-fill algorithm
        
    - Scan-line fill algorithm
        

## 6. **Character and Text**

- Display of alphanumeric characters.
    
- Represented by stroke (vector) or bitmap.
    
- Attributes: font, size, color, orientation.
    

## 7. **Attributes of Output Primitives**

- **Line Attributes:** type, width, color.
    
- **Curve Attributes:** thickness, pattern.
    
- **Color Attributes:** RGB or indexed color.
    
- **Area-fill Attributes:** pattern, color, hatch.
    
- **Character Attributes:** font, size, spacing, style.
    

**Summary Table:**

|Primitive|Basic Element|Example Algorithm|
|---|---|---|
|Point|Pixel|—|
|Line|2 endpoints|DDA, Bresenham|
|Circle|Center & Radius|Midpoint, Bresenham|
|Ellipse|Major/Minor Axes|Midpoint|
|Polygon|Set of vertices|Scan-line, Flood-fill|
|Text|Characters|Bitmap/Stroke representation|


---
---

# 3. Geometric Modelling

**Definition:**  
Geometric modelling is the mathematical representation of objects’ shapes and structures used for computer graphics and CAD applications. It defines how a 2D or 3D object is described and displayed.

## 1. **Types of Geometric Models**

### (a) **Wireframe Model**

- Represents object using points, lines, and curves.
    
- Shows edges and vertices only.
    
- Advantages: Simple, low storage, fast rendering.
    
- Disadvantages: Ambiguous, lacks surface & volume information.
    

### (b) **Surface Model**

- Describes surfaces (not volume) of objects using polygons or curved patches.
    
- Common formats: Polygon meshes, Bézier or B-spline surfaces.
    
- Advantages: Realistic appearance, used in visualization.
    
- Disadvantages: No interior details, complex shading.
    

### (c) **Solid Model**

- Represents complete 3D volume of an object.
    
- Defines both exterior and interior properties.
    
- Techniques:
    
    - **Constructive Solid Geometry (CSG):** Combines primitives (cube, sphere, cylinder, etc.) using Boolean operations (Union, Intersection, Difference).
        
    - **Boundary Representation (B-Rep):** Describes object by its faces, edges, and vertices.
        
- Advantages: Complete and unambiguous.
    
- Disadvantages: Requires large storage and computation.
    

## 2. **Geometric Transformation**

Used to modify object’s position, orientation, and size.  
Types:

- **Translation** – shifting by (tx, ty, tz).
    
- **Scaling** – resizing by factors (sx, sy, sz).
    
- **Rotation** – turning about an axis.
    
- **Reflection** – mirror about axis/plane.
    
- **Shearing** – slanting object shape.
    

## 3. **Representation Schemes**

- **Parametric Representation:** Curve defined by parameters (e.g., Bézier, B-spline).
    
- **Implicit Representation:** Equation form (e.g., x² + y² + z² – r² = 0).
    
- **Explicit Representation:** y = f(x) type equations.
    

## 4. **Common 3D Geometric Primitives**

- Cube, Cylinder, Sphere, Cone, Torus, Pyramid, etc.
    
- These can be combined to form complex objects using Boolean operations.
    

**Summary Table:**

|Model Type|Description|Example|Information Provided|
|---|---|---|---|
|Wireframe|Lines & vertices|3D skeleton|Shape only|
|Surface|Faces & curves|Mesh model|Surface only|
|Solid|Volume representation|CSG, B-Rep|Full geometry|


---
---

# 4. Two-Dimensional Viewing and 3-D Concepts

## 1. **Two-Dimensional Viewing**

**Definition:**  
2D viewing defines how a part of a 2D world (world coordinate system) is displayed on a device (screen coordinate system).

### (a) **Window and Viewport Concepts**

- **Window:** Portion of the world to be displayed. (world coordinates)
    
- **Viewport:** Area on the display device where window content is mapped. (device coordinates)
    
- Mapping ensures window fits into viewport.
    

**Mapping Equation:**

```
xv = xvmin + (xw - xwmin) * (xvmax - xvmin) / (xwmax - xwmin)
yv = yvmin + (yw - ywmin) * (yvmax - yvmin) / (ywmax - ywmin)
```

### (b) **Clipping**

- Process of selecting visible portions of an image within a window.
    
- **Types:**
    
    - Point Clipping
        
    - Line Clipping (Algorithms: Cohen–Sutherland, Liang–Barsky)
        
    - Polygon Clipping (Sutherland–Hodgman)
        
    - Text Clipping
        
- **Purpose:** Remove objects outside the display region.
    

### (c) **Coordinate Systems**

- **World Coordinate System (WCS):** Defined by user.
    
- **Device Coordinate System (DCS):** Actual display coordinates.
    
- **Normalized Device Coordinates (NDC):** Range 0–1 for mapping portability.
    

---

## 2. **3-D Concepts**

**Definition:**  
3D graphics extends 2D by adding depth (z-axis) for realistic modeling and visualization.

### (a) **3D Coordinate Systems**

- **Right-Handed System:** +z comes out of screen.
    
- **Left-Handed System:** +z goes into screen.
    
- Coordinates: (x, y, z).
    

### (b) **3D Transformations**

Used to manipulate 3D objects.

- **Translation:** Move by (tx, ty, tz)
    
- **Scaling:** Scale by (sx, sy, sz)
    
- **Rotation:** About x, y, or z axis
    
- **Reflection:** About coordinate planes
    
- **Shearing:** Slant shape
    

### (c) **Projections**

Convert 3D objects into 2D view for display.

- **Parallel Projection:** Projection lines parallel.
    
    - _Orthographic:_ Projectors perpendicular to view plane.
        
    - _Oblique:_ Projectors at an angle.
        
- **Perspective Projection:** Projectors converge to a point (gives depth).
    
    - Types: One-point, two-point, three-point perspective.
        

### (d) **3D Viewing Pipeline**

Steps to convert 3D scene to 2D display:

1. Modeling Transformations
    
2. Viewing Transformations
    
3. Clipping
    
4. Projection
    
5. Viewport Transformation
    

**Summary Table:**

|Concept|Purpose|Key Algorithms/Methods|
|---|---|---|
|Window-Viewport|Map world to device|Mapping equations|
|Clipping|Remove outside objects|Cohen–Sutherland, Liang–Barsky|
|3D Transformations|Modify object geometry|Translation, Rotation, Scaling|
|Projection|Convert 3D → 2D|Parallel, Perspective|


---
---


# 5. Visible Surface Detection Methods

**Definition:**  
Visible Surface Detection (Hidden Surface Removal) determines which surfaces or parts of a 3D object are visible to the viewer and which are hidden behind others.

## 1. **Classification**

- **Object-Space Methods:** Compare objects and surfaces in 3D space to decide visibility (e.g., Back-Face Detection).
    
- **Image-Space Methods:** Determine visibility for each pixel on the projection plane (e.g., Z-Buffer).
    

---

## 2. **Object-Space Methods**

### (a) **Back-Face Detection**

- Simple method based on surface orientation.
    
- For a polygon with normal vector **N = (A, B, C)** and view direction **V**,  
    if **N · V > 0**, face is **back face** → not visible.
    
- Works for convex solid objects only.
    
- Fast and used for initial elimination.
    

### (b) **Depth-Sort (Painter’s Algorithm)**

- Surfaces sorted by depth (z-value).
    
- Paint from farthest to nearest → nearer surfaces overwrite farther ones.
    
- Problems: Overlapping or intersecting surfaces.
    

---

## 3. **Image-Space Methods**

### (a) **Z-Buffer (Depth Buffer) Algorithm**

- For each pixel, stores smallest depth (z) value.
    
- Steps:
    
    1. Initialize depth buffer with ∞ and frame buffer with background color.
        
    2. For each polygon, compute z for every pixel.
        
    3. If z < z-buffer(x, y), update pixel color and depth.
        
- Advantages: Simple, hardware-supported.
    
- Disadvantages: High memory use.
    

### (b) **Scan-Line Algorithm**

- Processes one scan line at a time.
    
- For each line, determine visible polygon segments using depth comparison.
    
- More efficient than pixel-by-pixel methods.
    

### (c) **A-Buffer Algorithm**

- Extension of Z-buffer supporting transparency and anti-aliasing.
    
- Stores intensity and depth for multiple surfaces per pixel.
    

---

## 4. **Other Methods**

### (a) **Ray Casting / Ray Tracing**

- For each pixel, cast a ray from eye through the view plane into the scene.
    
- The nearest intersected surface determines visible pixel.
    
- Produces realistic images with shadows and reflections but computationally expensive.
    

### (b) **Binary Space Partitioning (BSP) Tree**

- Divides scene recursively into front and back subspaces using planes.
    
- Used for efficient visibility determination in complex scenes.
    

---

## 5. **Comparison Table**

|Method|Type|Technique|Advantages|Disadvantages|
|---|---|---|---|---|
|Back-Face|Object-space|Normal–view test|Fast|Only for solid objects|
|Depth-Sort|Object-space|Sort by z-depth|Simple|Overlap issues|
|Z-Buffer|Image-space|Depth buffer|Easy, hardware support|High memory|
|Scan-Line|Image-space|Line-by-line|Efficient|Complex to implement|
|A-Buffer|Image-space|Extended Z-buffer|Handles transparency|Memory heavy|
|Ray Tracing|Image-space|Ray intersection|High realism|Very slow|
|BSP Tree|Hybrid|Space partitioning|Efficient for scenes|Complex setup|



