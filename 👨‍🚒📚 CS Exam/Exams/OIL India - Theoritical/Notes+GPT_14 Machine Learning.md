
# Machine Learning

| Topics                    | Subtopics                   |
| ------------------------- | --------------------------- |
| Introduction              | Basics and applications     |
| Supervised & Unsupervised | Regression, clustering      |
| Ensemble & Probabilistic  | Random forests, Naïve Bayes |
| Reinforcement Learning    | Q-learning                  |
| Genetic Algorithms        | Evolutionary methods        |
| Deep Learning             | Neural networks, CNN, RNN   |
# Introduction to Machine Learning

**Definition:**  
Machine Learning (ML) is a subset of Artificial Intelligence that enables systems to automatically learn patterns from data and improve performance on a task without explicit programming.

**Key Idea:**  
ML algorithms use data to build models that can make predictions, classifications, or decisions.

**Types of Learning:**

1. **Supervised Learning:**
    
    - Model learns from labeled data (input-output pairs).
        
    - Tasks: Regression (predict continuous values), Classification (predict discrete labels).
        
    - Examples: Linear Regression, Decision Tree, SVM, Neural Networks.
        
2. **Unsupervised Learning:**
    
    - Model learns from unlabeled data, finds hidden structures or patterns.
        
    - Tasks: Clustering, Dimensionality Reduction.
        
    - Examples: K-Means, Hierarchical Clustering, PCA.
        
3. **Semi-Supervised Learning:**
    
    - Uses both labeled and unlabeled data to improve learning accuracy.
        
4. **Reinforcement Learning:**
    
    - Agent learns by interacting with an environment and receiving feedback (rewards/penalties).
        
    - Examples: Q-Learning, Deep Q-Networks.
        

**ML Workflow:**

1. Data Collection
    
2. Data Preprocessing (cleaning, normalization, feature extraction)
    
3. Model Selection
    
4. Training
    
5. Evaluation (accuracy, precision, recall, etc.)
    
6. Deployment & Maintenance
    

**Applications:**  
Spam detection, Fraud detection, Recommendation systems, Image recognition, Speech processing, Predictive analytics.

**Challenges:**  
Data quality, Overfitting, Underfitting, Model interpretability, Scalability, Ethical issues.


---
---

# Supervised and Unsupervised Learning, Ensemble and Probabilistic

**Supervised Learning:**  
Model learns from labeled data to map inputs (X) to outputs (Y).

- **Goal:** Predict output for unseen input.
    
- **Types:**
    
    1. **Regression:** Predict continuous values (e.g., House Price Prediction).
        
        - Algorithms: Linear Regression, Ridge, Lasso.
            
    2. **Classification:** Predict discrete labels (e.g., Spam/Not Spam).
        
        - Algorithms: Logistic Regression, Decision Tree, Random Forest, SVM, KNN, Naive Bayes.
            
- **Evaluation Metrics:** Accuracy, Precision, Recall, F1-score, RMSE.
    

**Unsupervised Learning:**  
Model learns patterns from unlabeled data.

- **Goal:** Discover structure or relationships.
    
- **Types:**
    
    1. **Clustering:** Group similar data (K-Means, DBSCAN, Hierarchical).
        
    2. **Dimensionality Reduction:** Reduce features while retaining variance (PCA, t-SNE).
        
    3. **Association:** Find item relationships (Apriori, FP-Growth).
        

**Ensemble Learning:**  
Combines multiple models to improve performance, reduce variance and bias.

- **Types:**
    
    1. **Bagging:** Multiple models trained on random subsets → aggregate predictions.
        
        - Example: Random Forest.
            
    2. **Boosting:** Sequential training where each model corrects errors of the previous one.
        
        - Examples: AdaBoost, Gradient Boosting, XGBoost, LightGBM.
            
    3. **Stacking:** Combines predictions of multiple base learners using a meta-model.
        

**Probabilistic Learning:**  
Models that incorporate probability theory to handle uncertainty.

- **Concept:** Learn probability distribution ( P(Y|X) ).
    
- **Algorithms:**
    
    - Naive Bayes (Bayesian classification with independence assumption).
        
    - Hidden Markov Models (HMM) for sequential data.
        
    - Bayesian Networks (graphical models of dependencies).
        
- **Advantages:** Explainable, handles uncertainty, interpretable confidence estimates.

---
---

# Learning, Reinforcement Learning and Evaluating Hypotheses

**Learning in ML:**  
Learning is the process of improving model performance through experience (data).

- **Goal:** Find a mapping function ( f: X \rightarrow Y ) that generalizes well on unseen data.
    
- **Learning Methods:**
    
    - **Inductive Learning:** Infers general rules from specific examples.
        
    - **Deductive Learning:** Uses known rules to derive conclusions.
        
    - **Transductive Learning:** Predicts specific outputs from given training instances without learning a general rule.
        

**Reinforcement Learning (RL):**  
Learning through interaction with an environment to achieve a goal.

- **Elements:**
    
    - **Agent:** Learner or decision maker.
        
    - **Environment:** System the agent interacts with.
        
    - **State (S):** Current situation.
        
    - **Action (A):** Possible moves by the agent.
        
    - **Reward (R):** Feedback signal for each action.
        
- **Goal:** Learn an optimal policy ( \pi^* ) that maximizes cumulative reward.
    
- **Approaches:**
    
    1. **Model-Free:** Learns directly from experience.
        
        - _Value-Based:_ Q-Learning, SARSA.
            
        - _Policy-Based:_ REINFORCE.
            
    2. **Model-Based:** Learns a model of environment transition probabilities.
        
- **Applications:** Robotics, Game playing (AlphaGo), Resource management, Autonomous driving.
    

**Evaluating Hypotheses:**  
Used to assess the performance of learned models.

- **Hypothesis (h):** Candidate model generated by learning algorithm.
    
- **Error Types:**
    
    - **Training Error:** Error on training data.
        
    - **Test Error:** Error on unseen data.
        
- **Overfitting:** Model fits training data too well but fails to generalize.
    
- **Underfitting:** Model too simple to capture underlying patterns.
    
- **Evaluation Metrics:** Accuracy, Precision, Recall, F1-score, ROC-AUC, Mean Squared Error.
    
- **Validation Techniques:**
    
    - Hold-out validation.
        
    - k-Fold Cross Validation.
        
    - Leave-One-Out Cross Validation.
        
- **Statistical Evaluation:**
    
    - Hypothesis testing (t-test, chi-square).
        
    - Confidence intervals to compare models.
---
---


# Genetic Algorithms

**Definition:**  
Genetic Algorithms (GAs) are optimization techniques inspired by the process of natural selection and genetics. They are used to find approximate solutions to complex search and optimization problems.

**Key Concepts:**

- **Population:** A set of possible solutions (chromosomes).
    
- **Chromosome:** Representation of a candidate solution (often a binary string).
    
- **Gene:** A single unit of information within a chromosome.
    
- **Fitness Function:** Evaluates how good a solution is.
    
- **Selection:** Chooses the best individuals for reproduction based on fitness.
    
- **Crossover (Recombination):** Combines parts of two parent chromosomes to produce offspring.
    
- **Mutation:** Randomly alters genes to introduce variation.
    

**Algorithm Steps:**

1. Initialize a population of N random chromosomes.
    
2. Evaluate fitness of each chromosome.
    
3. Select parents based on fitness (e.g., Roulette Wheel, Tournament Selection).
    
4. Apply Crossover to generate offspring.
    
5. Apply Mutation with low probability to maintain diversity.
    
6. Form a new population and repeat until stopping criteria (max generations or target fitness).
    

**Advantages:**

- Works well for nonlinear, non-differentiable, and complex optimization problems.
    
- Can escape local minima due to stochastic nature.
    

**Disadvantages:**

- Computationally expensive.
    
- Parameter tuning (population size, mutation rate) is difficult.
    

**Applications:**  
Feature selection, Scheduling, Neural network optimization, Path planning, Game strategy optimization.


---
---

# Deep Learning Techniques

**Definition:**  
Deep Learning (DL) is a subset of Machine Learning that uses multi-layered neural networks to automatically learn hierarchical feature representations from data.

**Key Concept:**  
DL models learn complex patterns by composing multiple layers of nonlinear transformations.

**Basic Structure (Artificial Neural Network):**

- **Input Layer:** Receives features from data.
    
- **Hidden Layers:** Perform nonlinear transformations using activation functions.
    
- **Output Layer:** Produces final prediction or classification.
    

**Common Activation Functions:**

- Sigmoid ( f(x) = \frac{1}{1+e^{-x}} )
    
- Tanh ( f(x) = \frac{e^x - e^{-x}}{e^x + e^{-x}} )
    
- ReLU ( f(x) = \max(0,x) )
    
- Softmax (for multi-class classification).
    

**Popular Deep Learning Architectures:**

1. **Feedforward Neural Network (FNN):** Simple layered network where data flows in one direction.
    
2. **Convolutional Neural Network (CNN):** Extracts spatial features, mainly for image and video data.
    
    - Layers: Convolution, Pooling, Fully Connected.
        
    - Examples: LeNet, AlexNet, VGG, ResNet.
        
3. **Recurrent Neural Network (RNN):** Handles sequential/time-series data.
    
    - Variants: LSTM, GRU (solve vanishing gradient problem).
        
4. **Autoencoders:** Unsupervised networks for dimensionality reduction and feature learning.
    
5. **Generative Adversarial Networks (GANs):** Two networks (Generator and Discriminator) trained adversarially to generate realistic data.
    
6. **Transformers:** Sequence models using attention mechanisms (e.g., BERT, GPT).
    

**Training Process:**

- Forward propagation → Compute output.
    
- Loss calculation → Measure error (e.g., Cross-Entropy, MSE).
    
- Backpropagation → Update weights using gradients.
    
- Optimizers: SGD, Adam, RMSProp.
    

**Advantages:**

- Automatic feature extraction.
    
- High performance on large and complex datasets.
    

**Disadvantages:**

- Requires large data and computation.
    
- Hard to interpret and tune.
    

**Applications:**  
Image recognition, NLP, Speech processing, Autonomous driving, Recommendation systems.