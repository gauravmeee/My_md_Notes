
# Artificial Intelligence

| Topics                   | Subtopics                      |
| ------------------------ | ------------------------------ |
| Scope                    | History and applications       |
| Problem Solving          | State-space, search techniques |
| Knowledge Representation | Predicate logic                |
| Uncertainty & Learning   | Probabilistic reasoning        |
| Neural Networks          | ANN fundamentals               |
| Planning & CSP           | Heuristic planning             |
| Swarm Intelligence       | Algorithms                     |
| Image Processing         | Basics                         |
| NLP                      | Parsing, semantics             |
# Scope of AI

AI (Artificial Intelligence) aims to build intelligent systems that can perform tasks requiring human-like intelligence such as reasoning, learning, perception, and decision-making.

## 1. Major Areas

- **Problem Solving & Search:** Algorithms for exploring possible solutions (e.g., A*, Hill Climbing).
    
- **Knowledge Representation:** Storing and manipulating knowledge using logic, semantic networks, frames, and ontologies.
    
- **Reasoning:** Deductive, inductive, and probabilistic reasoning for inference.
    
- **Learning:** Machine Learning (supervised, unsupervised, reinforcement) for pattern discovery and prediction.
    
- **Perception:** Interpretation of sensory data such as speech, vision, and text.
    
- **Natural Language Processing (NLP):** Understanding and generating human language.
    
- **Robotics:** Integrating AI with sensors and actuators for autonomous action.
    
- **Expert Systems:** Rule-based systems that emulate human expertise in specific domains.
    

## 2. Application Domains

- **Business:** Data analytics, decision support, automation.
    
- **Healthcare:** Diagnosis, medical imaging, drug discovery.
    
- **Finance:** Fraud detection, stock prediction, risk management.
    
- **Transportation:** Autonomous vehicles, traffic optimization.
    
- **Manufacturing:** Predictive maintenance, quality control.
    
- **Defense:** Surveillance, autonomous weapons, strategic planning.
    
- **Education:** Personalized learning, intelligent tutoring systems.
    

## 3. Future Scope

- Integration with IoT, cloud, and big data.
    
- Ethical and explainable AI systems.
    
- General AI (AGI) research for human-level intelligence.
    
- Sustainable and responsible AI development.

---
---

# Problem Solving – State Space Search, Production Systems, Search Space Control

## 1. Problem Solving

Problem solving in AI involves finding a sequence of actions to reach a desired goal from an initial state. Problems are represented as **state space search**.

## 2. State Space Search

- **State:** A representation of a situation.
    
- **Initial State:** Starting condition of the problem.
    
- **Goal State:** Desired condition to achieve.
    
- **Operators:** Actions that transform one state into another.
    
- **State Space:** The set of all possible states reachable from the initial state using operators.
    
- **Search Tree:** Tree formed by exploring possible states.
    

**Example:** 8-Puzzle problem, where each configuration is a state and tile moves are operators.

## 3. Production Systems

A **Production System** is a model of problem solving consisting of:

- **Production Rules:** IF (condition) THEN (action) form.
    
- **Working Memory:** Contains current state or facts.
    
- **Control System:** Chooses and applies applicable rules.
    

**Example:**

```
IF (room_is_dark) THEN (turn_on_light)
IF (light_is_on) THEN (read_book)
```

Execution continues until a goal condition is satisfied.

## 4. Search Space Control

Used to manage the growth of search space and improve efficiency.

**Techniques:**

- **Heuristics:** Estimates cost or distance to goal; guides search (e.g., A*, Best-First Search).
    
- **Pruning:** Eliminates unpromising branches (e.g., Alpha-Beta pruning).
    
- **Constraint Propagation:** Reduces possible states by applying constraints early.
    
- **Backtracking Control:** Returns to previous states when a path fails.
    
- **Rule Ordering:** Prioritizing more promising production rules.
    

Efficient search control minimizes computation and memory usage while ensuring goal achievement.


---
---


# Knowledge Representation – Predicate Logic

## 1. Knowledge Representation

Knowledge representation (KR) is the method used to describe information about the world so that a computer system can reason and make decisions.

## 2. Predicate Logic (First-Order Logic)

Predicate Logic extends propositional logic by including **objects, properties, and relations** among objects. It provides greater expressiveness.

### Components

- **Constants:** Represent specific objects (e.g., `John`, `Delhi`).
    
- **Variables:** Represent arbitrary objects (e.g., `x`, `y`).
    
- **Predicates:** Represent relations or properties (e.g., `Loves(John, Mary)`, `IsHuman(x)`).
    
- **Functions:** Map objects to other objects (e.g., `FatherOf(John)`).
    
- **Quantifiers:**
    
    - **Universal (∀):** “For all” → ∀x Human(x) → Mortal(x)
        
    - **Existential (∃):** “There exists” → ∃x Animal(x) ∧ CanFly(x)
        

### Example

Knowledge: “All humans are mortal. Socrates is a human.”

```
∀x (Human(x) → Mortal(x))
Human(Socrates)
⊢ Mortal(Socrates)
```

## 3. Advantages

- Expresses complex relationships.
    
- Supports inference and reasoning through rules.
    
- Enables formal proofs using logical deduction.
    

## 4. Inference in Predicate Logic

- **Unification:** Matching predicates with variables to apply rules.
    
- **Resolution:** Rule of inference used to derive new facts or detect contradictions.
    

## 5. Applications

- Expert systems
    
- Natural language understanding
    
- Semantic web
    
- Automated reasoning systems

---
---

# Handling Uncertainty and Learning – Non-Monotonic Reasoning

## 1. Need for Handling Uncertainty

In real-world AI systems, knowledge is often **incomplete, inconsistent, or uncertain**. Deterministic logic (True/False) is inadequate; thus probabilistic and approximate reasoning are used.

## 2. Methods to Handle Uncertainty

- **Probabilistic Reasoning:** Uses probability theory to represent belief in outcomes.  
    Example: `P(Rain | Clouds) = 0.8`
    
- **Bayesian Networks:** Graphical models representing probabilistic dependencies among variables.
    
- **Fuzzy Logic:** Deals with degrees of truth (values between 0 and 1).  
    Example: “The temperature is _somewhat hot_.”
    
- **Certainty Factors (CF):** Used in expert systems to express belief strength.  
    Example: CF = 0.7 means 70% confidence in the rule.
    
- **Dempster–Shafer Theory:** Combines evidence from different sources to compute belief and plausibility.
    

## 3. Learning under Uncertainty

AI systems learn patterns even when data is noisy or incomplete using methods like:

- **Probabilistic Learning:** Naive Bayes, Bayesian networks.
    
- **Fuzzy Learning:** Adaptive systems based on fuzzy rules.
    
- **Reinforcement Learning:** Learning optimal actions under uncertain rewards.
    

## 4. Non-Monotonic Reasoning

In **classical logic**, adding new knowledge never invalidates old conclusions — it’s **monotonic**.  
But in real-world reasoning, new facts may **retract** previous conclusions → **Non-Monotonic Reasoning**.

### Example

```
Rule: Birds can fly → Bird(x) → CanFly(x)
Fact: Penguin is a bird → Bird(Penguin)
Exception: Penguin cannot fly → Penguin(x) → ¬CanFly(x)
```

When “Penguin” is introduced, the previous conclusion “Penguin can fly” is withdrawn.

### Types

- **Default Reasoning:** Assume something true by default until contradicted.
    
- **Circumscription:** Minimizes assumptions to represent exceptions.
    
- **Autoepistemic Logic:** Models reasoning about one’s own beliefs.
    

## 5. Applications

- Expert systems with exceptions
    
- Decision-making under uncertainty
    
- Dynamic knowledge bases
    
- Intelligent agents adapting to new information

---
---

# Neural Networks

## 1. Introduction

A Neural Network is a computational model inspired by the human brain, consisting of interconnected nodes (neurons) that process information through weighted connections. It is used for pattern recognition, classification, and learning from data.

## 2. Structure of Neural Network

- **Neuron (Node):** Basic processing unit that computes weighted sum of inputs.
    
- **Weights (w):** Represent strength of connections between neurons.
    
- **Activation Function (f):** Introduces non-linearity to decide neuron output.
    
- **Layers:**
    
    - **Input Layer:** Receives raw data.
        
    - **Hidden Layers:** Extract features through transformations.
        
    - **Output Layer:** Produces final result (e.g., class label).
        

**Neuron Output Formula:**

```
y = f(Σ(wi * xi) + b)
```

where `xi` = input, `wi` = weight, `b` = bias.

## 3. Activation Functions

- **Step Function:** Binary output.
    
- **Sigmoid:** Smooth, used in early networks → `1 / (1 + e^-x)`
    
- **Tanh:** Scaled sigmoid between -1 and 1.
    
- **ReLU:** `max(0, x)` – efficient for deep networks.
    
- **Softmax:** Used in multi-class classification.
    

## 4. Learning Process

- **Feedforward:** Input data moves from input to output layer.
    
- **Error Calculation:** Compare predicted and actual outputs.
    
- **Backpropagation:** Adjust weights to minimize error using gradient descent.
    
- **Training:** Repeated iteration until convergence.
    

## 5. Types of Neural Networks

- **Single-Layer Perceptron:** One layer; handles linearly separable problems.
    
- **Multi-Layer Perceptron (MLP):** Multiple hidden layers; learns complex patterns.
    
- **Convolutional Neural Network (CNN):** For image and spatial data.
    
- **Recurrent Neural Network (RNN):** For sequential data like speech, text, time series.
    
- **Radial Basis Function Network (RBFN):** Uses radial basis functions for activation.
    

## 6. Applications

- Image and speech recognition
    
- Natural language processing
    
- Medical diagnosis
    
- Fraud detection
    
- Autonomous systems
    

## 7. Advantages and Limitations

**Advantages:** Learns from examples, handles complex data, adaptable.  
**Limitations:** Requires large data, computationally expensive, less interpretable.


---
---

# Planning and Constraint Satisfaction

## 1. Planning

Planning in AI is the process of generating a sequence of actions that leads from an initial state to a desired goal state efficiently.

### Components of a Planning System

- **Initial State:** Starting condition.
    
- **Goal State:** Desired final condition.
    
- **Operators (Actions):** Define how to move between states.
    
- **Plan:** Ordered sequence of actions to achieve the goal.
    

### Types of Planning

- **Classical Planning:** Assumes deterministic and fully known environment (e.g., STRIPS).
    
- **Hierarchical Planning (HTN):** Decomposes complex tasks into simpler sub-tasks.
    
- **Conditional Planning:** Handles uncertainty using conditional branches.
    
- **Continuous/Reactive Planning:** Used in dynamic environments (e.g., robotics).
    

### Planning Techniques

- **State Space Search:** Forward or backward search through possible states.
    
- **Plan Space Search:** Searches through partially ordered plans.
    
- **Heuristic Planning:** Uses heuristics to guide search efficiently (e.g., A*).
    
- **GraphPlan:** Constructs planning graphs and extracts valid plans.
    

---

## 2. Constraint Satisfaction Problems (CSP)

A **CSP** involves finding values for a set of variables that satisfy a set of constraints.

### Components

- **Variables:** X = {X₁, X₂, …, Xn}
    
- **Domains:** D = {D₁, D₂, …, Dn}, possible values for each variable.
    
- **Constraints:** Rules restricting combinations of variable values.
    

**Example:**  
Coloring map regions with 3 colors so that adjacent regions have different colors.

### Solving CSPs

- **Backtracking Search:** Tries variable assignments one by one and backtracks when constraints fail.
    
- **Forward Checking:** Eliminates inconsistent values from future variable domains.
    
- **Constraint Propagation:** Narrows down domains using constraints (e.g., Arc Consistency).
    
- **Heuristics:**
    
    - **MRV (Minimum Remaining Values):** Choose variable with fewest legal values.
        
    - **Degree Heuristic:** Choose variable involved in most constraints.
        

### Applications

- Scheduling
    
- Resource allocation
    
- Map coloring
    
- Timetabling
    
- Puzzle solving (e.g., Sudoku)

---
---

# Swarm Intelligence

## 1. Introduction

Swarm Intelligence (SI) is a subfield of Artificial Intelligence inspired by the **collective behavior of social organisms** such as ants, bees, birds, and fish. It focuses on distributed problem-solving using simple agents that interact locally without centralized control.

## 2. Characteristics

- **Decentralization:** No central authority; agents act independently.
    
- **Self-organization:** Order emerges through local interactions.
    
- **Adaptivity:** System adjusts to changes in the environment.
    
- **Scalability:** Works efficiently with increasing number of agents.
    
- **Robustness:** Failure of few agents does not affect the system.
    

## 3. Main Swarm Intelligence Algorithms

### a) Ant Colony Optimization (ACO)

- Inspired by the **foraging behavior of ants**.
    
- Ants deposit **pheromones** on paths; stronger pheromone trails attract more ants.
    
- Used to find optimal paths in graphs.  
    **Applications:** Traveling Salesman Problem, routing, scheduling.
    

### b) Particle Swarm Optimization (PSO)

- Inspired by **flocking behavior of birds or fish schooling**.
    
- Each particle represents a potential solution and moves in the search space according to its velocity, best position, and group best.  
    **Applications:** Function optimization, neural network training.
    

### c) Artificial Bee Colony (ABC)

- Based on the **foraging behavior of honey bees**.
    
- Includes employed, onlooker, and scout bees to explore and exploit search space.  
    **Applications:** Optimization and clustering problems.
    

### d) Firefly Algorithm

- Inspired by the **flashing behavior of fireflies**.
    
- Fireflies are attracted to brighter individuals; brightness relates to solution quality.
    

## 4. Applications

- Optimization and scheduling
    
- Routing in communication networks
    
- Control of multi-robot systems
    
- Feature selection and clustering
    
- Image segmentation
    

## 5. Advantages and Limitations

**Advantages:** Simple, flexible, parallelizable, fault-tolerant.  
**Limitations:** May converge slowly, risk of local optima, parameter tuning required.



---
---


# Image Processing

## 1. Introduction

Image Processing is a field of AI and computer vision concerned with performing operations on digital images to enhance them or extract meaningful information. It forms the foundation of pattern recognition, object detection, and visual understanding.

## 2. Stages of Image Processing

1. **Image Acquisition:** Capturing image through sensors or cameras.
    
2. **Preprocessing:** Removing noise, adjusting brightness/contrast, resizing.
    
3. **Segmentation:** Dividing the image into meaningful regions or objects.
    
4. **Feature Extraction:** Identifying edges, shapes, textures, or color features.
    
5. **Recognition/Interpretation:** Classifying or identifying objects using AI models.
    

## 3. Types of Image Processing

- **Analog Image Processing:** Done on physical images (pre-digital).
    
- **Digital Image Processing:** Manipulation of digital images using algorithms.
    

## 4. Common Image Processing Techniques

- **Filtering:** Enhances or suppresses image details (e.g., Gaussian, median filters).
    
- **Edge Detection:** Identifies object boundaries (e.g., Sobel, Canny, Prewitt).
    
- **Morphological Operations:** Shape-based operations (dilation, erosion).
    
- **Histogram Equalization:** Improves contrast by redistributing pixel intensity.
    
- **Thresholding:** Separates objects from the background.
    
- **Fourier Transform:** Converts image to frequency domain for analysis.
    
- **Convolution:** Core operation in CNNs for feature extraction.
    

## 5. Tools and Techniques in AI-based Image Processing

- **Convolutional Neural Networks (CNNs):** Automatically learn image features for classification or detection.
    
- **Deep Learning Frameworks:** TensorFlow, PyTorch, OpenCV.
    
- **Transfer Learning:** Using pre-trained models like VGG, ResNet for new tasks.
    

## 6. Applications

- Medical imaging (MRI, CT-scan analysis)
    
- Face and object recognition
    
- Autonomous vehicles (lane and obstacle detection)
    
- Satellite and aerial image analysis
    
- Document scanning and OCR
    
- Industrial inspection and robotics
    

## 7. Advantages and Challenges

**Advantages:** High accuracy, automation, data-driven insights.  
**Challenges:** High computational cost, need for large datasets, sensitivity to lighting and noise.


---
---

# Natural Language Processing (NLP)

## 1. Introduction

Natural Language Processing is a branch of AI that enables computers to understand, interpret, and generate human language in a meaningful way. It combines **linguistics, computer science, and machine learning**.

## 2. Levels of NLP

1. **Phonology:** Study of sounds in language.
    
2. **Morphology:** Structure of words (roots, prefixes, suffixes).
    
3. **Syntax:** Grammar and sentence structure.
    
4. **Semantics:** Meaning of words and sentences.
    
5. **Pragmatics:** Context-based interpretation.
    
6. **Discourse:** Relation between sentences for coherence.
    

## 3. NLP Tasks

- **Tokenization:** Splitting text into words or sentences.
    
- **Stop-word Removal:** Removing common words (e.g., is, the, and).
    
- **Stemming/Lemmatization:** Reducing words to their root form.
    
- **Part-of-Speech Tagging:** Identifying nouns, verbs, adjectives, etc.
    
- **Named Entity Recognition (NER):** Identifying names, places, dates, etc.
    
- **Parsing:** Analyzing grammatical structure.
    
- **Word Sense Disambiguation:** Determining correct meaning of words in context.
    

## 4. NLP Techniques

- **Rule-Based Systems:** Use of linguistic rules for parsing and translation.
    
- **Statistical NLP:** Uses probabilistic models (e.g., Hidden Markov Models).
    
- **Neural NLP:** Deep learning methods using embeddings and transformers.
    

## 5. Important Models and Concepts

- **Bag of Words (BoW):** Represents text as word frequency counts.
    
- **TF-IDF:** Measures importance of words across documents.
    
- **Word Embeddings:** Word2Vec, GloVe – capture semantic meaning.
    
- **Recurrent Neural Networks (RNNs):** Handle sequential data.
    
- **Transformers:** Use attention mechanisms for parallel processing (e.g., BERT, GPT).
    

## 6. Applications

- Machine Translation (Google Translate)
    
- Sentiment Analysis
    
- Chatbots and Virtual Assistants
    
- Speech Recognition and Generation
    
- Text Summarization
    
- Information Retrieval (Search Engines)
    

## 7. Challenges

- Ambiguity and context understanding
    
- Sarcasm and idiomatic expressions
    
- Multilingual processing
    
- Data bias and ethical concerns