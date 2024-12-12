
![[Pasted image 20241128174109.png]]


![[Pasted image 20241128173957.png]]


![[Pasted image 20241128173923.png]]


![[Pasted image 20241128174317.png]]


![[Pasted image 20241128174451.png]]

---
# 2

![[Pasted image 20241128181341.png]]
- Faster then DDA, not uses real arithmetic(like floating point operations) , only involves integer
- More accurate and efficient then DDA
- Can plot circles and other curves with a higher accuracy


![[Pasted image 20241128183038.png]]
**Flood fill**  : faster, efficient and less overhead due to no additional check for boundary color for each pixel
- Flood Fill is used in areas like paint applications to fill uniform regions.
- Boundary Fill is used in graphical applications where filling within a defined boundary is necessary.

⭐
![[Pasted image 20241128183738.png]]
Methods : Stroke method, bitmap method (or Dotmatrix), Starburst method
![[Pasted image 20241128184724.png]]
Character A: 0011 0000 0011 1100 1110 0001


![[Pasted image 20241128204237.png]]

![[Pasted image 20241128185414.png]]
![[Pasted image 20241128192432.png]]
p = (x,y)
Scanline :
```sh
y=20 : p1 p2
y=19 : p3 p4 p5 p6
y=18 : p7 p8 p9 p10
y=17  : p11 p12 p13(E)
y=11 : (p14 p15(D) p16)
y=  5 :  (p17(H) p18)
y=3  :  (p19 p20)

# y=2 : (p21(G) p22(F)) -> lots of point --- skip it for now
```
Intersecting vertices  E D H
- both the edges are on same(both left or right) side vertex = E, D -> consider twice in the alternate pair
- both edges lies opposite(one left one right) side of vertex = H -> consider as one point
```sh
Updated:
y=20 : (p1 p2)
y=19 : (p3 p4) (p5 p6)
y=18 : (p7 p8) (p9 p10)
y=17  : (p11 p12) (p13 p13)
y=11 : (p14 p15) (p15 p16)
y=  5 :  (p17 p18)
y=3  :  (p19 p20)
y=2 : (p21 p22)
```
Distnct Edge List : cutted by
```sh
AH : p1 and AB : p2
BC : p5 and CD : p6
DE : p15 and EF : p16
HG : p19 and EF(X)
GF : many points

Edgelist = [AH AB BC CD DE EF HG GF]
```
Filling = scan line : line cuted by it (called active edge)
```
y20 : AH AB
y19 : AH AB BC CD
........
```
Coherence Property
- It mean Relating property of one scene to another part of scene
- Here it is used for lines property (ex slope(m)), and used it to find other values by relating
- Ex: 
	- AH is cutted going to cutted by many scan line, y20, y19, y18......
	- slope of AH = $y_{end}-y_{start}/x_{end}-x_{start}$  
	- Similarly taking any two point on line (not necessary start or end) can give same  slope 
	- so m = $y_{next}-y_{prev}/x_{next}-x_{prev}$   
	- so $y_{next}-y_{prev}=-1$  (because  $y_{prev}$  to $y_{next}$   -> one step down) 
	- (let prev =$k$ and next =$k+1$)
	- $m = -1/(x_{K+1}-x_1)$  -> $x_{K+1}-x_1 = -1/m$ -> $x_{k+1} = x_k - 1/m$
	- So for Line AH, we can Calculate it's next x point, for next scan line using$x_{k+1} = x_k - 1/m$


---
# 3

![[Pasted image 20241128201552.png]]

**Composite Transformation** in computer graphics is the combination of multiple transformations (translation, scaling, rotation, etc.) into a single transformation matrix to avoid applying them individually.

Note: - Combine transformations into a composite matrix in **reverse order** of intended application, since transformations are applied **right-to-left** in matrix multiplication.
ex:
- To **translate**, then **rotate**, and finally **scale**:  
    Composite matrix = S⋅R⋅T


![[Pasted image 20241128203116.png]]


![[Pasted image 20241128203707.png]]

---
# 4

![[Pasted image 20241128222134.png]]

Three types
1. All or None String clipping
2. All or None character Clipping
3. Bitmap character clipping


⭐
![[Pasted image 20241129021252.png]]
![[Pasted image 20241129022027.png]]
4 rules, to define intersection


⭐
![[Pasted image 20241129022100.png]]


![[Pasted image 20241129022545.png]]


![[Pasted image 20241129023139.png]]


### 1st order and 2nd order Geometric Continuity
![[Pasted image 20241129023518.png]]
![[Pasted image 20241129023602.png]]


⭐⭐⭐
![[Pasted image 20241129024256.png]] 
![[Pasted image 20241129024726.png]]
![[Pasted image 20241129033355.png]]
![[Pasted image 20241129033448.png]]


![[Pasted image 20241129092154.png]]
![[Pasted image 20241129092133.png]]
for cubic degree 3, points 4 (0 1 2 3)
![[Pasted image 20241129092543.png]]
![[Pasted image 20241129093332.png]]
![[Pasted image 20241129093614.png]]
![[Pasted image 20241129093651.png]]
![[Pasted image 20241129093714.png]]


![[Pasted image 20241129093933.png]]
![[Pasted image 20241129100259.png]]
![[Pasted image 20241129100408.png]]
![[Pasted image 20241129100318.png]]

Bezier : B-spline
approximate spline curve : approximate spline curve
Degree fix (no of point -1) : Can specify degree 
Global control point : local control point

- A Bezier curve exhibits **global control**, meaning **any change in a control point affects the entire curve**. (because the blending functions (Bernstein polynomials) depend on all control points simultaneously.)
- A B-Spline curve exhibits **local control**, meaning **changing a control point only affects a portion of the curve**. (- This is due to the properties of the basis functions, which are non-zero over only a limited span of the curve, determined by the **knot vector** and the **degree of the curve**.)

⭐
![[Pasted image 20241129100833.png]]

---

# 5
![[Pasted image 20241129101417.png]]


![[Pasted image 20241129101754.png]]
![[Pasted image 20241129102156.png]]


![[Pasted image 20241129102329.png]]


Cabinet = 1:1/2 45 degree
Caviler = 1:1 63.4 degree
![[Pasted image 20241129101933.png]]

---

# 6

![[Pasted image 20241129103005.png]]
![[Pasted image 20241129103121.png]]
![[Pasted image 20241129103139.png]]


![[Pasted image 20241129103237.png]]
![[Pasted image 20241129103400.png]]



![[Pasted image 20241129103456.png]]
![[Pasted image 20241129103545.png]]



![[Pasted image 20241129103610.png]]
![[Pasted image 20241129103704.png]]
![[Pasted image 20241129103744.png]]


![[Pasted image 20241129103918.png]]


![[Pasted image 20241129104003.png]]
![[Pasted image 20241129104013.png]]


![[Pasted image 20241129104101.png]]

---
---


# Not much Important

![[Pasted image 20241128174346.png]]

![[Pasted image 20241128175230.png]]
![[Pasted image 20241128204257.png]]


**a) Affine Transformation**

An **Affine Transformation** in computer graphics is a linear mapping method that preserves points, straight lines, and planes. It allows transformations such as translation, scaling, rotation, shearing, and reflection while maintaining the relative geometry (e.g., parallel lines remain parallel).

Mathematical Representation:

- In matrix form: 
- $\begin{bmatrix} x' \\ y' \\ 1 \end{bmatrix} = \begin{bmatrix} a & b & tx \\ c & d & ty \\ 0 & 0 & 1 \end{bmatrix} \cdot \begin{bmatrix} x \\ y \\ 1 \end{bmatrix}$
- Here:
    - a,b,c,da, b, c, d: Transformation coefficients.
    - tx,tytx, ty: Translation values.

Key Properties:

1. **Preservation**: Retains collinearity and ratios of distances.
2. **Combination**: Multiple affine transformations can be combined into a single matrix.
3. **Examples**: Translation, rotation, scaling, shearing.

**b) Fill Styles**

**Fill Styles** in computer graphics refer to the patterns, colors, or textures used to fill a shape or area. They define how the interior of a graphical object is rendered.

Types of Fill Styles:

1. **Solid Fill**:
    - Fills the area with a single, uniform color.
    - Example: Filling a rectangle with red.
2. **Pattern Fill**:
    - Fills the area with a repeating pattern or texture (e.g., stripes, dots).
    - Common in creating stylized or decorative shapes.
3. **Gradient Fill**:
    - Creates a smooth transition between colors.
    - Types: Linear gradient (color changes along a straight line) or radial gradient (color changes outward from a center point).
4. **Hatch Fill**:
    - Fills the area with predefined hatch patterns (e.g., diagonal lines, crosshatch).
5. **Bitmap Fill**:
    - Uses a bitmap image as the fill pattern.

 Applications:

- **Solid Fill**: Basic shapes or background.
- **Gradient Fill**: Adds depth or realism.
- **Pattern Fill**: Decorative designs.
- **Bitmap Fill**: Complex textures (e.g., wood grain).

Comparison:

|**Aspect**|**Solid Fill**|**Pattern/Gradient Fill**|
|---|---|---|
|**Complexity**|Low|Medium to High|
|**Performance**|Faster|Slower (requires more processing).|
|**Visual Appeal**|Simple|More detailed and realistic.|

---

# 3