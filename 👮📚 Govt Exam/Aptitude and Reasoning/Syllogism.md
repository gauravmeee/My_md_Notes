
### Inference Rules

All →  
- All A are B ⟹ (if domain non-empty) Some A are B.  (All => Some ✅)
- All A are B ⟹ No A are non-B.  
- All A are B does **not** ⟹ Some B are A. ( All => Some ❌ why? )

Some →  
- Some A are B does **not** ⟹ All A are B.  
- Some A are B ⟹ It’s consistent with Many/Few/Most depending on proportion.  
- Some A are B ⟹ ¬(No A are B).

None →  
- No A are B ⟺ All A are non-B.  
- No A are B ⟹ Not(Some A are B).  
- None is stronger than “few” or “some” (it forbids).

Few →  
- “Few A are B” is vague; formalize as “>0 and << total A”.  
- Few A are B ⟹ Some A are B and ¬Most A are B and ¬All A are B.

Most →  
- Most A are B ⟹ Some A are B.  
- Most A are B ⟹ Usually ¬All A are B (but could be All if interpreted permissively).  
- Most A are B ⟹ Probability(A is B) > 0.5 among A.

Exact / Numeric →  
- Exactly k A are B gives precise inferences (e.g., Exactly 1 A is B ⟹ Some A are B and if k=1 then that A is unique).

At-least / At-most →  
- At least n A are B ⟹ Some A are B if n≥1.  
- At most n A are B ⟹ ¬(At least n+1 A are B).

Contradictories & Contraries →  
- Contradictories: “All A are B” vs “Some A are not B” (cannot both be true, cannot both be false). 
- Contraries: “All A are B” vs “No A are B” (can’t both be true but can both be false).

Existential import caveat →  
- Traditional syllogisms assume categories non-empty so All A are B implies Some A are B; modern predicate logic does not assume that (All A B true when no A exist).

Quick heuristic rules for reasoning →  
- If quantifier asserts universality (All/No) derive negated particulars accordingly;  
- If particular (Some/Few/Many/Most) never derive universals;  
- Numeric quantifiers beat vague ones (use numbers to resolve ambiguity);  
- When in doubt, translate into predicate logic and check existential assumptions.

Examples →  
- All cats are mammals ⟹ Some cats are mammals (assuming cats exist).  
- Some dogs are friendly ⟹ cannot infer All dogs are friendly.  
- No reptiles are warm-blooded ⟹ All reptiles are non-warm-blooded.

More patterns you want formatted similarly?