
# RAG

## Retrieval-Augmented Generation (RAG)

##### **1. Definition**

- RAG = **hybrid framework** combining **retrieval** (information from external knowledge base) and **generation** (LLM/decoder).
- Goal: produce **factually accurate, context-rich answers**.
- Two main modules:
    1. **Retriever** → finds relevant documents/passages.
    2. **Generator** → generates final answer conditioned on retrieved docs.

##### **2. Why RAG**

- LLMs have limited **parametric memory** (forget or hallucinate).
- RAG adds **non-parametric memory** (external KB).
- Benefits:
    - Up-to-date knowledge.
    - Domain-specific accuracy.
    - Reduces hallucination.
    - Smaller model + large corpus ≈ performance of huge models.

##### **3. RAG Architecture**

**a) Retriever**
- Input: query.
- Output: top-k relevant passages.
- Types:
    - **Sparse retrievers** → BM25, TF-IDF.
    - **Dense retrievers** → DPR, Contriever, ColBERT (use embeddings).
    - **Hybrid retrievers** → combine sparse + dense.

**b) Generator**

- Input: (query + retrieved docs).
- Output: natural language answer.
- Models: BART, T5, GPT, LLaMA, etc.
- Generation modes:
    - **Fusion-in-Decoder (FiD)** → generator attends separately to each doc.
    - **Concatenation** → all docs concatenated as context.

##### **4. RAG Workflow**

1. **Query encoding**.
2. **Retrieve top-k documents**.
3. **Combine with query** → context.
4. **Generator produces answer**.
5. (Optional) **Re-ranking or filtering** of docs before generation.

##### **5. Variants of RAG**

- **RAG-Sequence**: generate answer conditioned on single retrieved doc at each decoding step.
- **RAG-Token**: each token generation considers different retrieved docs → more dynamic.
- **FiD (Fusion-in-Decoder)**: processes multiple docs independently before fusion.
- **Atlas**: large-scale RAG with stronger retrievers + generator.

##### **6. Fine-Tuning in RAG**

- **Retriever Fine-Tuning**: contrastive learning on (query, pos, neg docs).
- **Generator Fine-Tuning**: supervised on (query + docs → gold answer).
- **End-to-End Fine-Tuning**: joint retriever + generator training.
- **PEFT Methods (LoRA, Adapters, Prefix Tuning)** used for efficiency.

##### **7. Evaluation Metrics**

**a) Retriever**
- Recall@k, Precision@k, nDCG, MRR.

**b) Generator**
- BLEU, ROUGE, METEOR, BERTScore.
- Factuality & Faithfulness evaluation.

**c) End-to-End**
- Human evaluation (accuracy, hallucination rate, relevance).

##### **8. Applications**
- **Search + QA**: customer support, chatbots.
- **Domain assistants**: legal, medical, finance.
- **Enterprise Knowledge Base QA**.
- **Education**: personalized tutoring.
- **Coding assistants** (retrieval from docs + code gen).

##### **9. Challenges**
- **Retriever errors** → irrelevant docs retrieved.
- **Generator hallucination** even with good docs.
- **Latency** (retrieval + generation pipeline is slow).
- **Data scarcity** for fine-tuning.
- **Scalability** of retriever with very large corpora.

##### **10. Improvements & Best Practices**
- Use **hybrid retrievers** (sparse + dense).
- Add **re-ranking step** with cross-encoders.
- Use **knowledge distillation** for efficiency.
- Apply **parameter-efficient fine-tuning (LoRA, adapters)**.
- Feedback loops for **active retriever re-training**. 
- Maintain **up-to-date external knowledge base**.

## RAG – Software & Use Cases

##### **1. Vector Stores (Retrieval Layer)**

Used to store embeddings (vector representations of text) and perform similarity search.

- **FAISS**
    - Lightweight library by Facebook AI
    - Runs locally, fast nearest-neighbor search
    - **Use case:** Research, prototyping, small–medium datasets
        
- **Milvus**
    - Distributed vector database
    - Highly scalable, supports billions of vectors
    - **Use case:** Enterprise-scale search, recommendation engines
        
- **Weaviate**
    - Vector DB with semantic + keyword search
    - Schema-based, supports hybrid queries
    - **Use case:** Product search, semantic search over structured/unstructured data
        
- **Pinecone**
    - Managed cloud vector database (SaaS)
    - High reliability, auto-scaling
    - **Use case:** Customer support chatbots, enterprise RAG systems
        
- **Chroma**
    - Simple, open-source, Python-first vector DB
    - Easy to use, minimal setup
    - **Use case:** Personal knowledge base, quick prototypes


##### **2. Embedding Models (Text → Vectors)**

Convert text/documents into dense vector representations.

- **OpenAI Embeddings**
    
    - High-quality embeddings (e.g., `text-embedding-ada-002`)    
    - Cloud-only
    - **Use case:** General-purpose semantic search, question answering
        
- **SentenceTransformers (Hugging Face)**
    
    - Local embeddings with pretrained transformer models
    - Supports fine-tuning for domain-specific needs
    - **Use case:** Offline/private RAG, sensitive data domains (health, finance)

##### **3. Language Models (Generation Layer)**

Generate final answers by combining query + retrieved documents.

- **OpenAI GPT (3.5/4)**
    - API-based, best for high-quality general use        
    - **Use case:** QA bots, summarization, customer support

- **LLaMA, Mistral, Falcon** (open-source)
    - Run locally or on private servers
    - Can be fine-tuned with LoRA/adapters        
    - **Use case:** Domain-specific assistants, cost-sensitive or private deployments

##### **4. Frameworks (Integration Layer)**

Orchestration tools to connect retrieval with generation.

- **LangChain**
    - Most popular framework for RAG pipelines
    - Provides chains, agents, memory, and tool integration
    - **Use case:** Multi-step agents, chatbot apps, document QA
        
- **LlamaIndex (GPT Index)**
    - Specializes in connecting LLMs with structured/unstructured data
    - Strong support for large-document ingestion
    - **Use case:** Knowledge-base Q&A, long-document summarization
        
- **Haystack**
    - Modular NLP/RAG framework from deepset
    - Flexible: supports multiple vector DBs and LLMs
    - **Use case:** Enterprise search engines, production RAG pipelines

##### **5. Typical RAG Workflow**

1. Documents → **embedding model** → stored in **vector store**
2. Query → embedded → retrieve top-k relevant docs
3. Retrieved docs + query → passed to **LLM**
4. **LLM generates** grounded answer using context
    

##### **Summary Mapping Table**

|Layer|Software/Tools|Best Use Case|
|---|---|---|
|Vector Store|FAISS|Local research/prototypes|
||Milvus|Large-scale enterprise search|
||Weaviate|Product/semantic search|
||Pinecone|SaaS, customer support|
||Chroma|Lightweight prototypes|
|Embeddings|OpenAI Embeddings|General-purpose semantic search|
||SentenceTransformers (HF)|Offline, domain-specific embeddings|
|LLM|OpenAI GPT|General chatbot, QA|
||LLaMA, Mistral, Falcon|Private, domain-tuned LLMs|
|Frameworks|LangChain|Chatbots, multi-step agents|
||LlamaIndex|Long-doc understanding, KBs|
||Haystack|Enterprise search pipelines|
