
### **Problem 1 (LLM × Google Apps Script)** ✅

**Problem Description:**  
Create a system that sends an automatic reply email based on the input from a Google Form. Use the Gemini API to generate the reply.

**Purpose:**  
Test your skills in integrating Google Apps Script with the free Gemini API.

**Requirements:**

**1. Tools and APIs**

|Tool/API|Details|
|---|---|
|Google Account|Use your personal Google Account. (No school/company org accounts.)|
|Google Apps Script|For backend scripting.|
|Free Gemini API|Any free Gemini model (e.g., gemini-1.5-flash).|

**2. Google Form Specifications**

|Specification|Details|
|---|---|
|Form title|`Form_your_name` (e.g., Form_Gaurav_Meena)|
|Fields|1. Your email (email input) 2. Question (text input)|

**3. Email Sending Specifications**

| Specification       | Details                                               |
| ------------------- | ----------------------------------------------------- |
| LLM API Call        | Use form response to query Gemini API.                |
| Model               | Any Gemini text-generation model.                     |
| Question Scope      | General questions about machine learning.             |
| Reply Email Subject | "Reply for your question"                             |
| Recipient           | Email address entered in the form                     |
| Trigger             | On form submit; email should be sent within 1 minute. |
##### Solution ✅
```js
const GEMINI_API_KEY = 'YOUR_VALID_API_KEY';  // from makersuite.google.com

function onFormSubmit(e) {
  const responses = e.values;
  const email = responses[1];     // Assuming 2nd column is Email
  const question = responses[2];  // Assuming 3rd column is Question

  const reply = getGeminiReply(question);
  GmailApp.sendEmail(email, "Answer to your question", reply);
}

function getGeminiReply(question) {
  const payload = {
    contents: [{ parts: [{ text: question }] }]
  };

  const options = {
    method: 'POST',
    contentType: 'application/json',
    payload: JSON.stringify(payload),
    muteHttpExceptions: true
  };

  const url = 'https://generativelanguage.googleapis.com/v1beta2/models/chat-bison-001:generateContent?key=' + GEMINI_API_KEY;
  const response = UrlFetchApp.fetch(url, options);

  const responseText = response.getContentText();
  Logger.log("Gemini response: " + responseText);

  const data = JSON.parse(responseText);
  return data?.candidates?.[0]?.content?.parts?.[0]?.text || "Sorry, no response.";
}
```


##### Steps to Follow :

1. **Create your Google Form**
    - Title it: `Form_Your_Name`
    - Add these 2 fields:
        1. "Your email" – (Short answer → response should be email)
        2. "Question" – (Paragraph)
            
2. **Link your Form to a Google Sheet**
    - After creating the form, click **“Responses” > “Link to Sheets”**
    - It will create a spreadsheet with the form responses. Make note of the column positions:
        - Timestamp → index `0`
        - Email → index `1`
        - Question → index `2`
            
3. **Open the linked Google Sheet > Extensions > Apps Script**
	- Paste your full code inside the **Apps Script editor** of the linked spreadsheet:
	- In Apps Script, click the clock icon on the left (Triggers).    
	- Add a trigger:
	    - Choose function: `onFormSubmit`
	    - Event type: **"From form" > "On form submit"**

This will call the function every time the form is submitted.

- Replace `'YOUR_VALID_API_KEY'` with your actual Gemini API key from [makersuite.google.com](https://makersuite.google.com/)
---

### **Problem 2 (Laptop Product Lineup Strategy)** ✅

**Overview:**  
You are a product planner at a laptop company in Tokyo. Currently, you sell a base laptop PC model. You plan to add higher-end models by choosing **TWO upgrades** from four available options. The goal is to select the two that give the **highest gross profit**.

**1. Current Model Specs and Selling Price**

| Specification | Value       |
| ------------- | ----------- |
| Memory        | 16 GB       |
| Storage       | 512 GB      |
| CPU Class     | 1           |
| Screen Size   | 14.0 inches |
| Release Year  | 2025        |

- **Original Selling Price**: 111,000 yen
- **Note**: Gross profit = Selling price - Total additional cost
- CPU Class: Higher class = more powerful and expensive
    

**2. Upgrade Options**

|Upgrade Item|Additional Cost (yen)|
|---|---|
|Add 16 GB memory|7,000|
|Add 512 GB storage|5,000|
|Upgrade CPU class by 1 level|15,000|
|Increase screen size to 16 inch|3,000|


**3. Dataset**
- Provided as a CSV with specs and market prices (tax excluded)
- **Download**: [Laptop Dataset CSV (Google Drive)](https://drive.google.com/file/d/1-PT29BP2ru2L9zQNNXK3y-kBZHxfrngn/view?usp=sharing)

**4. Task**
- **Analyze the dataset** to find expected market prices for each upgrade combination.
- **Select the two upgrades** that together give the highest **gross profit**.
- Use **any method** (manual analysis, linear regression, grouping) — dataset usage is **mandatory**.
- Do **not** consider consumption tax in gross profit.
    
    
**Objective:**  
Identify and justify (via code) the **TWO upgrades** that maximize gross profit using dataset-based analysis.

##### Solution ✅`
```python
import pandas as pd

# Load dataset
df = pd.read_csv("laptop_price_dataset.csv")

# Base model specs
base_spec = {
    'Memory': 16,
    'Storage': 512,
    'CPU': 1,
    'Screen Size': 14.0
}

base_price = 111000

# Upgrade options and cost
upgrades = {
    "Add 16 GB memory": {"Memory": 32, "Cost": 7000},
    "Add 512 GB storage": {"Storage": 1024, "Cost": 5000},
    "Upgrade CPU class by 1 level": {"CPU": 2, "Cost": 15000},
    "Increase screen size from 14 to 16 inches": {"Screen Size": 16.0, "Cost": 3000}
}

# Function to compute average price for upgraded model
def get_avg_price(upgrade_name, change):
    filter_cond = (df["Memory"] == base_spec["Memory"]) & \
                  (df["Storage"] == base_spec["Storage"]) & \
                  (df["CPU_class"] == base_spec["CPU_class"]) & \
                  (df["Screen_size"] == base_spec["Screen_size"])

    for feature in change:
        filter_cond &= (df[feature] == change[feature])
    upgraded_df = df[filter_cond]

    if len(upgraded_df) == 0:
        return 0
    return upgraded_df["Price"].mean()

# Try upgrades one-by-one from base spec
results = []
for name, upgrade in upgrades.items():
    modified_spec = base_spec.copy()
    for k in upgrade:
        if k != "Cost":
            modified_spec[k] = upgrade[k]
    cond = (df["Memory"] == modified_spec["Memory"]) & \
           (df["Storage"] == modified_spec["Storage"]) & \
           (df["CPU"] == modified_spec["CPU"]) & \
           (df["Screen Size"] == modified_spec["Screen Size"])
    avg_price = df[cond]["Price"].mean()
    if avg_price > 0:
        profit = (avg_price - base_price) - upgrade["Cost"]
        results.append((name, profit))

# Sort by profit
results.sort(key=lambda x: x[1], reverse=True)
for name, profit in results:
    print(f"{name}: Estimated Profit = {profit:.2f}")

```

##### Steps to Follow :
1. Paste the code in python IDE or Jupyter Notebook.
2. Replace the actual `csv` file name in `df = pd.read_csv("laptop_price_dataset.csv")`
3. Run the program
4. Note the output.

---
### **Problem 3: Handwritten Digit Generation Web App**: ❌


**Goal**
Build a web app where:
- User selects a digit (0–9)
- App generates **5 distinct images** of that digit using **your own trained model**
- Displays those images (in MNIST-like format)

**1. Web Application**

|Requirement|Details|
|---|---|
|Framework|Any (Streamlit, Flask, etc.)|
|Access|Publicly available for at least **2 weeks**|
|Features|① User inputs digit (0–9)② Generate 5 digit images③ Display all 5|
|Hosting|Use services like HuggingFace Spaces, Render, Streamlit Cloud, etc. App can go to sleep but must be revivable|


**2. Model Building & Training**

|Requirement|Details|
|---|---|
|Dataset|MNIST (28×28 grayscale)|
|Framework|PyTorch or TensorFlow|
|Pretrained|❌ **Do NOT use pretrained weights**|
|Model Output|Generates images of digits (NOT classification) — use GAN, VAE, or similar|
|Training Env|Use Google Colab (1×T4 GPU max)|
|Accuracy|Just enough for ChatGPT to recognize images correctly|
|Diversity|Must produce **5 visually different images** (not identical copies)|
|Training File|Submit `.py` or `.ipynb` file with **model, loss function, and training code**|


**3. Submission Checklist**

| Item                                         | Required            |
| -------------------------------------------- | ------------------- |
| Web App Link                                 | ✅ `https://...`     |
| Training Script (with model + loss function) | ✅ `.py` or `.ipynb` |
| Explanation / README                         | ❌ Not required      |
| Dataset                                      | ❌ Don’t submit      |

**Example Stack**
- Model: DCGAN or VAE (to generate digits)
- Framework: Streamlit + `torch` or `tensorflow`
- Deployment: Streamlit Cloud / HuggingFace Spaces
- Output: Grid of 5 generated digit images
