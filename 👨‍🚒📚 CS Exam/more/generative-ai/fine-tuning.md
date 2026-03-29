---
description: Fine Tuning
icon: list-check
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# Fine Tuning

## Fine-Tuning

##### **1. Definition**

- Fine-tuning = **adapting a pre-trained model** to a **specific task or dataset** by continuing training.
- Leverages **knowledge already learned** during pre-training → faster, efficient, smaller datasets required.

##### **2. Purpose**

- Improve **task-specific performance**.
- Reduce **training cost** compared to training from scratch.
- Enable **domain adaptation** (e.g., medical, legal, finance).

##### **3. Pre-requisites**

- Pre-trained model (BERT, GPT, T5, etc.)
- Task-specific labeled dataset
- Compatible **loss function** (e.g., cross-entropy for classification)

##### **4. Types of Fine-Tuning**

**a) Full Fine-Tuning**

- All model parameters updated.
- Pros: maximum performance.
- Cons: computationally expensive, prone to overfitting, high storage.

**b) Parameter-Efficient Fine-Tuning (PEFT)**

- Only a **small subset of parameters** updated.
- Methods:
  1. **LoRA (Low-Rank Adaptation)** → insert trainable low-rank matrices into transformer layers.
  2. **Adapters** → small feed-forward layers added between transformer blocks.
  3. **Prefix Tuning** → learn task-specific prefix embeddings fed into attention layers.
- Pros: memory & compute efficient, prevents catastrophic forgetting.

**c) Task-Specific Fine-Tuning**

- Adapts model to one **specific task** (QA, summarization, classification).
- Can be full or PEFT.

##### **5. Fine-Tuning Process**

1. **Data Preparation**
   - Clean, labeled, balanced dataset.
   - Split into training, validation, test sets.
2. **Model Selection**
   - Choose pre-trained model suitable for task.
3. **Adaptation**
   - Modify input/output layers if necessary (e.g., classifier head for classification).
4. **Training**
   - Use appropriate **learning rate** (often lower than pre-training).
   - Optimizer: AdamW or variants.
   - Loss: task-dependent (cross-entropy, MSE, etc.)
5. **Evaluation**
   - Metrics: task-dependent
     - Classification → Accuracy, F1, Precision, Recall
     - Generation → BLEU, ROUGE, METEOR
     - Retrieval → Recall@k, MRR

##### **6. Advantages**

- Faster than training from scratch.
- Requires smaller datasets.
- Can adapt large general models to **domain-specific tasks**.
- Works with large LLMs using PEFT methods.

##### **7. Challenges**

- Overfitting with small datasets.
- Catastrophic forgetting of pre-trained knowledge.
- Requires careful **learning rate & batch size tuning**.
- May still need **data augmentation** for low-resource domains.

##### **8. Best Practices**

- Use **lower learning rates** for pre-trained layers, higher for new layers.
- Freeze some layers if data is small.
- Prefer **PEFT** for large LLMs to save GPU/memory.
- Monitor validation loss to prevent overfitting.
- Combine with **regularization** (dropout, weight decay).

---

## Fine-Tuning in RAG

##### **1. What is Fine-Tuning**

- Fine-tuning = adapting a **pre-trained model** to a **specific domain/task** using additional training data.
- In **RAG**, fine-tuning improves:
  - **Retriever** (better document recall)
  - **Generator** (better response style/accuracy)
  - End-to-end RAG pipeline (retrieval + generation jointly).

##### **2. Why Fine-Tuning in RAG**

- Pre-trained retrievers may not work well on **domain-specific corpus** (e.g., legal, medical, finance).
- LLMs may generate **hallucinations** or irrelevant answers.
- Fine-tuning ensures:
  - Domain adaptation
  - Higher precision in retrieval
  - More faithful generation

##### **3. Levels of Fine-Tuning**

**a) Retriever Fine-Tuning**

- Uses **contrastive learning**:
  - Positive pairs → (query, relevant doc)
  - Negative pairs → (query, irrelevant doc)
- Optimizes embedding space → similar items closer.
- Methods:
  - DPR (Dense Passage Retrieval) fine-tuning
  - ColBERT, Contriever

**b) Generator Fine-Tuning**

- Train LLM on (retrieved context + query → target answer).
- Types:
  - **Supervised Fine-Tuning (SFT)** → on QA pairs.
  - **Instruction Fine-Tuning** → align with prompt styles.
  - **Preference Optimization (RLHF, DPO)** → better answer quality.

**c) End-to-End RAG Fine-Tuning**

- Joint optimization of retriever and generator.
- Feedback loop: retrieval improves generation, generation guides retriever.
- Requires large compute + carefully curated data.

##### **4. Fine-Tuning Approaches**

**a) Full Fine-Tuning**

- Update **all model parameters**.
- High accuracy but very costly.

**b) Parameter-Efficient Fine-Tuning (PEFT)**

- Freeze most weights, update small modules.
- Methods:
  - **LoRA (Low-Rank Adaptation)**
  - **Prefix Tuning**
  - **Adapters**
- Efficient and scalable.

##### **5. Data Preparation**

- High-quality **domain-specific QA pairs** or **retrieval relevance labels**.
- Dataset types:
  - **Retriever training** → triplets (query, positive doc, negative doc).
  - **Generator training** → (query + retrieved docs → gold answer).
- Ensure **cleaning, deduplication, balanced coverage**.

##### **6. Evaluation of Fine-Tuning**

**a) Retriever Metrics**

- Recall@k, MRR (Mean Reciprocal Rank), nDCG.

**b) Generator Metrics**

- BLEU, ROUGE, METEOR, BERTScore.
- Faithfulness & factuality tests.

**c) End-to-End RAG**

- Human evaluation on **relevance, accuracy, hallucination rate**.

##### **7. Challenges**

- Data scarcity (domain QA pairs hard to obtain).
- Catastrophic forgetting (losing general knowledge).
- Costly computation (GPU/TPU resources).
- Alignment issues (retriever pulls irrelevant docs, generator hallucinates).

##### **8. Best Practices**

- Start with **PEFT methods** (LoRA) before full fine-tuning.
- Use **in-domain embeddings** for retriever.
- Perform **knowledge distillation** (smaller model learns from larger).
- Evaluate iteratively (retriever and generator separately before joint tuning).
- Hybrid approach: **prompt engineering + fine-tuning**.

##### **9. Alternatives to Fine-Tuning**

- Prompt engineering (zero/few-shot).
- Retrieval customization (re-ranking, hybrid search).
- External memory augmentation.

---

## Fine-Tuning in General vs Fine-Tuning in RAG

##### **Fine-Tuning in General**

- Adapting a **pretrained model** (like BERT, GPT, T5) to a **specific dataset/task**.
- Examples: text classification, summarization, translation.
- You fine-tune either **full model** or with **PEFT (LoRA, Adapters, Prefix tuning)**.
- Output: model specialized for that task.

##### **Fine-Tuning in RAG**

- RAG has **two components** (retriever + generator). Fine-tuning can target one or both:
  1. **Retriever Fine-Tuning**
     - Optimizes embeddings so relevant docs are closer to queries.
     - Uses contrastive learning on (query, positive doc, negative doc).
  2. **Generator Fine-Tuning**
     - Adapts LLM to generate answers using retrieved docs.
     - Trained on (query + retrieved docs → gold answer).
  3. **End-to-End Fine-Tuning**
     - Jointly optimizes retriever + generator in one loop.

##### **Key Difference**

- **Normal Fine-Tuning**
  - adapting _one model_ (BERT, GPT) to a task.
  - i.e. task adaptation of pretrained models.
- **RAG Fine-Tuning**
  - adapting _multiple modules (retriever + generator)_, sometimes jointly, to improve end-to-end retrieval + answer generation.
  - i.e. specialized: retriever, generator, or both, to reduce hallucination, improve retrieval quality, and adapt to domain-specific QA.

---

## Parameter-Efficient Fine-Tuning (PEFT)

##### **1. Definition**

- PEFT = **fine-tuning only a small subset of parameters** in a pre-trained model while keeping most weights frozen.
- Goal: **adapt large models efficiently** in terms of memory, compute, and data.
- Essential for **LLMs** like GPT, LLaMA, T5, BERT.

##### **2. Motivation**

- Large models (billions of parameters) → full fine-tuning is **expensive**.
- PEFT allows **task adaptation** without updating all weights.
- Preserves **pre-trained knowledge**, prevents catastrophic forgetting.
- Works well with **small datasets**.

##### **3. Core PEFT Methods**

**a) LoRA (Low-Rank Adaptation)**

- Inserts **low-rank trainable matrices** into transformer layers.
- Original weights frozen; only low-rank matrices updated.
- Steps:
  1. Weight update ΔW ≈ A × B (low-rank)
  2. Forward pass: W + ΔW
  3. Backprop updates only A, B
- Pros: memory-efficient, good for domain/task-specific adaptation.

**b) Prefix Tuning**

- Prepends **task-specific learnable embeddings** to key/query in attention layers.
- Frozen original model.
- Pros: extremely efficient, works in **few-shot scenarios**.

**c) Adapters**

- Small **feed-forward layers** inserted between transformer blocks.
- Only adapter layers trained; main model frozen.
- Pros: modular, easy to switch tasks by changing adapters.

**d) Prompt Tuning**

- Learn **task-specific prompts** for frozen LLM input.
- Pros: very low parameter count, suitable for few-shot or zero-shot.

**e) T-Few (Task-Few)**

- Built for **few-shot multi-task adaptation**.
- Combines **PEFT methods (like prefix tuning)** with **meta-learning**.
- Learns **task-agnostic knowledge** to generalize across unseen tasks with few examples.
- Pros: extremely **data-efficient**, generalizes better than task-specific PEFT.

##### 4. Advantages of PEFT

- Reduces **trainable parameters** → faster, lower memory.
- Preserves pre-trained knowledge.
- Scalable for **multiple tasks** → swap adapters/prefixes.
- Works with **small datasets / few-shot learning**.
- Avoids catastrophic forgetting.

##### 5. Limitations

- Slightly lower performance than full fine-tuning in some tasks.
- Placement of adapters/prefixes affects results.
- Hyperparameter tuning required (rank in LoRA, prefix length).
- T-Few may need meta-task pretraining to work well.

##### 6. Workflow

1. **Select pre-trained model** (GPT, LLaMA, BERT, T5).
2. **Choose PEFT method** (LoRA, Adapters, Prefix, T-Few).
3. **Insert PEFT modules** in transformer layers.
4. **Prepare task dataset** (small data works).
5. **Train only PEFT parameters** (small learning rate).
6. **Evaluate** using task-specific metrics.

##### **7. Applications**

- QA, summarization, classification, RAG pipelines.
- Multi-task adaptation with shared model (swap adapters or prefixes).
- Low-resource domains or few-shot learning.
- Enterprise: chatbots, domain-specific assistants.

##### **8. Comparison of PEFT Methods**

| Method            | Trainable Params   | Data Requirement     | Use Case             | Notes                                       |
| ----------------- | ------------------ | -------------------- | -------------------- | ------------------------------------------- |
| **LoRA**          | Low-rank matrices  | Moderate             | Task-specific        | Efficient for large LLMs                    |
| **Prefix Tuning** | Prefix embeddings  | Few-shot             | Few-shot tasks       | Very memory efficient                       |
| **Adapters**      | Small FF layers    | Moderate             | Multi-task           | Modular, can swap for tasks                 |
| **Prompt Tuning** | Input prompts      | Few-shot / zero-shot | Minimal tuning       | Extremely light-weight                      |
| **T-Few**         | Prefix/meta params | Very few             | Multi-task, few-shot | Meta-learning + PEFT, strong generalization |

---
