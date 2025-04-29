
### Preprocess an image using `pip`, `OpenCV`, and `pytesseract` before performing OCR for better accuracy, and then extract specific information from it?

**1. Install Required Libraries**
```bash
pip install opencv-python pytesseract numpy
```

**2. Preprocessing the Image**
Here are common preprocessing steps to improve OCR accuracy:
- **Grayscale Conversion**: Improves contrast for better text recognition.
- **Noise Removal**: Reduces pixel noise using Gaussian or Median blur
- **Thresholding**: Binarizes the image (black text on white background).
- **Dilation & Erosion**: Enhances or thins characters for better recognition.
- **Resize & Denoise**: Adjusts image size for better OCR readability.
    
**Sample Code: **
```python
import cv2
import pytesseract
import re

# Load image
image = cv2.imread("invoice.jpg")

# Preprocessing steps
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  # Grayscale
blur = cv2.GaussianBlur(gray, (5, 5), 0)        # Remove noise
thresh = cv2.threshold(blur, 150, 255, cv2.THRESH_BINARY)[1]  # Thresholding

# OCR Extraction
text = pytesseract.image_to_string(thresh)

# Display processed image
cv2.imshow("Processed Image", thresh)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Print extracted text
print("Extracted Text:\n", text)

# Extracting specific data
patterns = {
    "date": r'\b(?:\d{1,2}[-/]\d{1,2}[-/]\d{2,4}|\d{4}[-/]\d{1,2}[-/]\d{1,2})\b',
    "price": r'₹?\$?\s?\d{1,3}(?:,\d{3})*(?:\.\d{2})?',
    "product": r'([A-Za-z0-9\s\-,.]+)\s+(?:x\s?\d+)?\s?₹?\$?\d{1,3}(?:,\d{3})*(?:\.\d{2})?',
    "invoice_no": r'\b(?:Invoice|Bill)\s?(?:No\.?|#)?\s?(\w+)\b'
}

# Extract data from text
extracted = {key: re.findall(pattern, text) for key, pattern in patterns.items()}

# Display results
for key, values in extracted.items():
    print(f"{key.capitalize()}: {values}")
```

---

### Extract specific information like Date, Price, Product, and Invoice Number from the OCR-extracted text

To extract data like **Date, Price, Product, etc.** from your bills and invoices using Python regex, here’s how you can do it:

---

### ✅ **Common Regex Patterns**

1. **Date**:
- Matches formats like `12/03/2024`, `2024-03-12`, `03-12-24`
```python
r'\b(?:\d{1,2}[-/]\d{1,2}[-/]\d{2,4}|\d{4}[-/]\d{1,2}[-/]\d{1,2})\b'
```

2. **Price (with or without currency)**:
- Matches `₹1,200.50`, `$250`, `4000.99`
```python
r'₹?\$?\s?\d{1,3}(?:,\d{3})*(?:\.\d{2})?'
```

3. **Product Names** (based on typical patterns):
- Matches `Product XYZ x2 ₹1500`
```python
r'([A-Za-z0-9\s\-,.]+)\s+(?:x\s?\d+)?\s?₹?\$?\d{1,3}(?:,\d{3})*(?:\.\d{2})?'
```

4. **Invoice/Bill Number**:
- Matches `Invoice No. 123456`
```python
r'\b(?:Invoice|Bill)\s?(?:No\.?|#)?\s?(\w+)\b'
```

**Sample Code :**
```python
import re

# Sample OCR text
text = """
Invoice No: 12345  
Date: 12/03/2024  
Product: Laptop x1 ₹45,000  
Product: Mouse x2 ₹1,200  
Total: ₹46,200  
"""

# Patterns
patterns = {
    "date": r'\b(?:\d{1,2}[-/]\d{1,2}[-/]\d{2,4}|\d{4}[-/]\d{1,2}[-/]\d{1,2})\b',
    "price": r'₹?\$?\s?\d{1,3}(?:,\d{3})*(?:\.\d{2})?',
    "product": r'([A-Za-z0-9\s\-,.]+)\s+(?:x\s?\d+)?\s?₹?\$?\d{1,3}(?:,\d{3})*(?:\.\d{2})?',
    "invoice_no": r'\b(?:Invoice|Bill)\s?(?:No\.?|#)?\s?(\w+)\b'
}

# Extracting data
extracted = {key: re.findall(pattern, text) for key, pattern in patterns.items()}

# Display result
for key, values in extracted.items():
    print(f"{key.capitalize()}: {values}")
```
