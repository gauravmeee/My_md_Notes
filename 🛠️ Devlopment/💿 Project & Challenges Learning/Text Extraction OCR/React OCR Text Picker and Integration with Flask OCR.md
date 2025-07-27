
### Create a React Frontend to Upload an Image, Send it to the Backend, and Display the Detected Text with Clickable Areas**


### 🛠️ **Tech Stack**
- **Frontend:** React (Vite), TailwindCSS, and Axios for sending images.
- **Backend:** Flask with OpenCV and OCR (Tesseract).
- **Functionality:**
    
    1. Upload image.
    2. Send image to the backend.        
    3. Backend detects text with bounding boxes (x, y, w, h).
    4. React displays the image with clickable bounding boxes.
    5. Clicking on a bounding box shows the corresponding text in input fields.

### ⚙️ **1. Backend (Flask)**

➡️ **Install Required Libraries**
```bash
pip install flask opencv-python numpy pillow pytesseract
```

➡️ **Backend Code:**
```python
from flask import Flask, request, jsonify
from flask_cors import CORS
import cv2
import numpy as np
import pytesseract

app = Flask(__name__)
CORS(app)

@app.route('/upload', methods=['POST'])
def upload_image():
    file = request.files['image']
    image = np.frombuffer(file.read(), np.uint8)
    img = cv2.imdecode(image, cv2.IMREAD_COLOR)

    # Preprocessing
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5, 5), 0)
    thresh = cv2.threshold(blur, 150, 255, cv2.THRESH_BINARY)[1]

    # OCR with bounding boxes
    boxes = pytesseract.image_to_data(thresh, output_type=pytesseract.Output.DICT)
    
    data = []
    for i in range(len(boxes['text'])):
        x, y, w, h = boxes['left'][i], boxes['top'][i], boxes['width'][i], boxes['height'][i]
        text = boxes['text'][i].strip()
        if text:  # Skip empty boxes
            data.append({'x': x, 'y': y, 'w': w, 'h': h, 'text': text})

    return jsonify(data)

if __name__ == '__main__':
    app.run(debug=True, port=5000)
```


### 📄 **3. React Component: `App.jsx`**

```javascript
import { useState, useRef } from "react";
import axios from "axios";

const App = () => {
  const [image, setImage] = useState(null);
  const [boxes, setBoxes] = useState([]);
  const [selectedText, setSelectedText] = useState("");
  const canvasRef = useRef(null);

  // Upload image handler
  const handleImageChange = (e) => {
    const file = e.target.files[0];
    if (file) {
      setImage(URL.createObjectURL(file));
      const formData = new FormData();
      formData.append("image", file);

      // Send to backend
      axios.post("http://localhost:5000/upload", formData)
        .then((res) => setBoxes(res.data))
        .catch((err) => console.error(err));
    }
  };

  // Click handler to select text
  const handleCanvasClick = (e) => {
    if (!canvasRef.current) return;

    const canvas = canvasRef.current;
    const rect = canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    // Find the clicked bounding box
    const clickedBox = boxes.find((box) =>
      x >= box.x && x <= box.x + box.w &&
      y >= box.y && y <= box.y + box.h
    );

    if (clickedBox) {
      setSelectedText(clickedBox.text);
    }
  };

  return (
    <div className="p-8">
      <h1 className="text-2xl font-bold mb-4">Text Picker from Image</h1>

      {/* Image Upload */}
      <input type="file" onChange={handleImageChange} className="mb-4" />

      <div className="flex gap-4">
        {/* Display Image and Bounding Boxes */}
        <div className="relative border rounded shadow-lg">
          {image && (
            <div className="relative">
              <img
                src={image}
                alt="Uploaded"
                className="w-full max-w-md"
                onClick={handleCanvasClick}
                ref={canvasRef}
              />
              {boxes.map((box, index) => (
                <div
                  key={index}
                  className="absolute border border-red-500"
                  style={{
                    left: `${box.x}px`,
                    top: `${box.y}px`,
                    width: `${box.w}px`,
                    height: `${box.h}px`,
                    background: "rgba(255, 0, 0, 0.3)",
                  }}
                />
              ))}
            </div>
          )}
        </div>

        {/* Display Selected Text */}
        <div className="flex flex-col">
          <label className="font-medium">Selected Text:</label>
          <input
            type="text"
            value={selectedText}
            readOnly
            className="border p-2 rounded w-72"
          />
        </div>
      </div>
    </div>
  );
};

export default App;
```

### 🛠️ **5. How It Works**

1. The **frontend** allows the user to upload an image.
2. The image is sent to the **Flask backend**.
3. Flask uses **OpenCV** and `pytesseract` to detect the text along with bounding box coordinates.
4. The backend sends the extracted text data with coordinates `(x, y, w, h)` back to the frontend.
5. React displays the image with clickable bounding boxes.
6. When the user clicks on a bounding box, the corresponding text appears in the text field.    
