### ✅ **Screen Features and Requirements**

1. **Multi-step form navigation**:
    
    - Step indicators: `Start`, `Select Actions`, `Link AWS/AZK`, `Fetch`.
        
    - You are building the **Select Actions** step.
        
    - "Back" and "Next" buttons for navigation.
        
2. **Cost-Saving Actions Section**:
    
    - Multiple action categories with checkboxes:
        
        - **Start-Stop Resources**: EC2, RDS, Light Sail, Amazon Neptune.
            
        - **Pause-Resume Resources**: Redshift Clusters, Aurora Serverless V2.
            
        - **Resource Cleanup**: Terminate EC2, Delete EBS volumes, Delete EBS snapshot, Delete RDS snapshot.
            
    - Group checkboxes with proper labeling.
        
3. **JAM Policy Section**:
    
    - Displayed in a scrollable container.
        
    - A **copy icon** next to it for copying the content.
        

---

### 🔥 **Key Requirements**

- **State management:**
    
    - Use React with a state management library like Redux, Zustand, or Context API.
        
    - Store selected actions and manage form step navigation state.
        
- **Theme & Styling:**
    
    - Add a modern theme with consistent colors, padding, and fonts.
        
    - Use Tailwind CSS or styled-components for faster styling.
        
- **Responsive design:**
    
    - Ensure the page is mobile-friendly.
        
    - The JAM policy section should have a scrollable container.
        

---

### 💡 **Improvements You Can Suggest**

1. **Better UX for checkbox selection**:
    
    - Add `Select All` or `Deselect All` options for each category.
        
2. **Tooltips or descriptions**:
    
    - Add hover tooltips on the actions to describe what each one does.
        
3. **Progress indicator**:
    
    - Add a visual indicator (e.g., a progress bar) showing the current step.
        
4. **Validation & Error Handling:**
    
    - Ensure that at least one checkbox is selected before moving to the next step.
        

---

### 📌 **Submission Requirements**

1. **GitHub link**: Host your code in a public repo.
    
2. **Deployed app link**: Deploy it using services like Vercel, Netlify, or Render.
    
3. **Deadline:** Submit before **March 30th, 6:02 PM**.
    

---

### 🚀 **Tools You Can Use for Efficiency**

- **State management:** Redux Toolkit, Zustand.
    
- **Styling:** Tailwind CSS, shadcn/ui.
    
- **Deployment:** Vercel, Netlify.
    
- **Code quality:** Prettier, ESLint.
    

---

✅ Let me know if you have any doubts or need help with the implementation! 🚀

4o

##### You said:

Simply explain me what the app will do?? or the requirement are not clear

###### ChatGPT said:

The app is part of a **multi-step form** for setting up a cloud account.

In **Step 2** (the part you need to build):

1. The user will **select cost-saving actions** they want to perform on their cloud resources.
    
2. The selected actions include:
    
    - **Start/Stop** resources (e.g., EC2, RDS).
        
    - **Pause/Resume** resources (e.g., Redshift clusters).
        
    - **Cleanup** resources (e.g., delete EBS volumes or snapshots).
        
3. There is a **JAM Policy section** with some text:
    
    - It is scrollable.
        
    - Includes a **copy icon** to copy the content.
        
4. Navigation:
    
    - Users can go back to the previous step or proceed to the next step using **Back** and **Next** buttons.
        

✅ Your job is to:

- Build this step with **state management** (to store the selected actions).
    
- Add **styling** and make it responsive.
    
- Deploy the app and submit the code link + live app link.
    

4o

##### You said:

I not have much knolwedge aboutthese policies, cloud form, cost-saving action. explain in genral term what I need to create

###### ChatGPT said:

No worries! Here’s a **simple explanation** of what you need to build:

You are creating a **web page** where the user:

1. **Selects multiple actions** by ticking checkboxes.
    
2. These actions are grouped into categories (like starting, pausing, or deleting resources).
    
3. There is a **scrollable text box** (JAM Policy section) with some content and a **copy button** to quickly copy the text.
    
4. The page has **Back** and **Next** buttons for navigation.
    

---

### 💡 **Think of it like this:**

Imagine you are creating a form where users select **tasks to manage their services**, such as:

- **Starting or stopping services**
    
- **Pausing or resuming services**
    
- **Cleaning up old or unused services**
    

The **JAM Policy section** is just a text box with information that the user might want to copy.

✅ You don’t need to know cloud policies—just focus on building a form with:

- **Checkboxes**
    
- **Text box with scroll + copy button**
    
- **Back/Next buttons**
    
- Store the selected actions in **state**.
    

Let me know if you need help with the technical part! 🚀