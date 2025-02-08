
### **Access JSON Object in JavaScript**

```js
// Access the whole JSON response object
let jsonResponse = {
  "data": {
    "events": {
      "ongoing_events": [ ... ]
    }
  }
};

// Access the 'data' object
let contests = jsonResponse["data"];

// Access the 'events' object inside 'data'
contests = jsonResponse["data"]["events"];

// Access the 'ongoing_events' array inside 'events'
contests = jsonResponse["data"]["events"]["ongoing_events"];
```

---

### **Access JSON Object in Python**

```python
# Access the whole JSON response object
jsonResponse = {
    "data": {
        "events": {
            "ongoing_events": [ ... ]
        }
    }
}

# Access the 'data' dictionary
contests = jsonResponse["data"]

# Access the 'events' dictionary inside 'data'
contests = jsonResponse["data"]["events"]

# Access the 'ongoing_events' list inside 'events'
contests = jsonResponse["data"]["events"]["ongoing_events"]
```
