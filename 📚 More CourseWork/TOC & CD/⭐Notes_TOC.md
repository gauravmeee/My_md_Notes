
**Ques:** Total no. of substrings possible for `w = GATE`
```
length:      0      1          2           3          4
substrings:  ϵ    G,A,T,E    GA,AT,TE    GAT,ATE     GATE
no. of subs: 1 +    4     +    3    +      2   +      1   = 4(4+1)/2 + 1
```
`ϵ` = null

Total no. of Substrings Formula : `n(n+1)/2+1` , `n=size of string`
Total no. of Non-trivial (not include `ϵ`) substring : `n(n+1)/2`

**Ques :** Find the no. of prefix and suffix possible in `GATE`, where `|w|=n`
prefix:- { ϵ, G, GA, GAT, GATE} `n+1`
prefix:- { ϵ, E, TE, ATE, GATE} `n+1`

### Automata


```
Grammar                            Language  Automata
------------------------------------------------------------------
Regular Grammar(RG) ->                RL ->  Finite Automata (FA)
Context-Free Grammar(CFG) ->          CFL -> Push-down Automata (PDA)
Context-Sensitive Grammar(CSG) ->     CSL -> Linear Bounded Automata (LBA)
Recursively Enumerable Grammar(REG)-> REL -> Turing Machine (TM)
```

hot -f


Symbol - basic building block
### Regular Language



### Finite Automata

### Context-Free Grammar

### Push-Down Automata