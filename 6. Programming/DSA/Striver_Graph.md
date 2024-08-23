| ←→↑↓ | ⬋⬊⬉⬈ | ⟷    | ⇄⇅  |
| ---- | ---- | ---- | --- |
| ○〇   | ˄˅>< | ˄˅>< | ╱╲  |
| ─│   | ✕    | │    |     |
| ✕    | ╲    | ╱    |     |

# [# G-1. Introduction to Graph | Types | Different Conventions Used](https://youtu.be/M3_pLsDdeuU?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)

Graph -> Nodes + Edges

### Types

Undirected Graph
```
〇───〇
│    │   v = 5
〇───〇   E = 6
 ╲  ╱ 
  〇 
Undirected + Cyclic Graph
```

Directed Graph 
```
〇───→〇
│     ↑   V = 5
↓     │   E = 6
〇───→〇
 ╲    ╱
  ⬊ ⬋ 
   〇
Directed + Asyclic Graph => DAG
```

```
〇 : Nodes/Vertices
__ : Undirected Edge (⇄)
─→ : Direted edge
```


**Cyclic Graph** - Contain at least single cycle
```
(1) ───
│      Not cyclic ❌
(2)───  

(1)───(2)
│      │   Cyclic ✅
(3)───(4)

(1)───→(2)
│       ↑  
↓       │   Not cyclic ❌
(3)───→(4)

(1)←──→(2)
│       ↑   Cyclic ✅
↓       │  
(3)───→(4)


cyle: start from a node, and can reach to the node through a path
```

**Path** -  Contain a lot of nodes and each of them are reachable
```
(1)----(2)
        |      12345: Path ✅
        |      12321 : Not path ❌
(4)----(3)     135 : Not path ❌
       ╱
    (5)

- Node shouldn't appear twice in path
- Adjacent Nodes should have edge between them
```

### Degree of Graph

```
Undirected Grpah

(1)----(2)   Degrees(Nodes)
|       |    D(3) = 3
|       |    D(4) = 2
(5)----(3)   D(1) = 2
 ╲      ╱    Degree of Graph = 2*6 = 12
    (4)

Degree (for Undirected Graph) - The no. of edges attach to the node

Property : Total Degree of Graph = 2*E 
```

```
Directed Grpah

(1)───→(2)        Indegree(node)
│       ↑         D(3) = 1
↓       │         Outdegree(node)
(5)───→(3)        D(3) = 2
 ╲     ╱
  ⬊  ⬋ 
   (4)

Degree (for Directed Graph):
Indegree - the no. of incoming edges to the node
Outdegree - the no. of outgoing edges to the node
```

### Edge Weight

```
()---3---()----5---()╲ 
|         |         |  ╲6  
|2        |1        |5  ()
|         |         |  ╱7
()---2----()---1---()╱

If Weight not given - Assume all unity 
```

# [G-2. Graph Representation in C++ | Two Ways to Represent](https://youtu.be/3oI-34aPMWM?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)

### Undirect Graph

Input Graph
```
(1)------(2)
 |        |  ╲ 
 |        |   (5)
 |        |  ╱
(3)------(4)
```

Input example
```
5   6   
2   1
1   3
2   4
3   4
2   5
4   5
```

Interpretation (Undirected Graph)
```
5   6    n=5 m=6
2   1    edge1 : 2--1
1   3    edge1 : 1--3  
2   4    edge1 : 2--4
3   4    edge1 : 3--4
2   5    edge1 : 2--5
4   5    edge1 : 4--5

- Nodes- No. of Node Constant
- Edges - No. of Edges Variable (if we join more two nodes in same graph no. of edges increase)
```

How to store??
Two ways - Matrix and List

Adjacency Matrix
```
adj[n+1][n+1] (if 0 based indexing then adj[n][n])

Mark the edge = 1
arr[2][1]=1 and arr[1][2]=1
arr[1][3]=1 and arr[3][1]=1
arr[2][4]=1 and arr[4][2]=1
arr[3][4]=1 and arr[4][3]=1
arr[2][5]=1 and arr[5][2]=1
arr[4][5]=1 and arr[5][4]=1

      0   1   2   3   4   5
	+---+---+---+---+---+---+
0	| 0 | 0 | 0 | 0 | 0 | 0 |
	+---+---+---+---+---+---+
1	| 0 | 0 | 1 | 1 | 0 | 0 |
	+---+---+---+---+---+---+
2	| 0 | 1 | 0 | 0 | 1 | 1 |
	+---+---+---+---+---+---+
3	| 0 | 1 | 0 | 0 | 1 | 0 |
	+---+---+---+---+---+---+
4	| 0 | 0 | 1 | 1 | 0 | 1 |
	+---+---+---+---+---+---+
5	| 0 | 0 | 1 | 0 | 1 | 0 |
	+---+---+---+---+---+---+

Space : N x N (Costly)
```

Implementation Adjacency matrix
```cpp
int main(){
	 int n, m;
	 cin>>n>>m;
	//graph here
	int adj[n+1][n+1];
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u][v] =1;
		adj[v][u] =1; // only for undirected graph
	}
	return 0;
}
```

Adjacency List
```
List for Each Nodes (In c++, list are vector)
Vector<vector<int>> adj[n+1]
adj[0] -> {}
adj[1] -> {2,3}
adj[2] -> {1,4,5}
adj[3] -> {1,4}
adj[4] -> {3,2,5}
adj[5] -> {2,4}

Space Complexit - 2*E  (Each edges is considered twice)
```

Implementation List
```cpp
int main(){
	 int n, m;
	 cin>>n>>m;
	//List here
	vector<vector<int> adj(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u); // only for undirected graph
	}
	return 0;
}
```

### Directed Graph

For Directed Graph , Implementation is Same,
but keep keep in mind if `(1)--->(2)` than only consider `adj[1][2]` not `adj[2][1]`
```
for matrix only : adj[1][2] =1
for list only : adj[1].push(2)
```

*Note:* We will use Adjacency list in Every Problem  because of better Space complexity

Weighted Graph:
```
(1)--2---(2)
 |        |  ╲6 
 |3       |1  (5)
 |        |  ╱3
(3)---4--(4)

```

```
Adjacency Matrix -  In Place of marking `1`, use the `weight of edge`
    1   2   3   4   5
  +---+---+---+---+---+
1 | 0 | 2 | 3 | 0 | 0 |
  +---+---+---+---+---+
2 | 2 | 0 | 0 | 6 | 1 |
  +---+---+---+---+---+
3 | 3 | 0 | 0 | 4 | 0 |
  +---+---+---+---+---+
4 | 0 | 6 | 4 | 0 | 3 |
  +---+---+---+---+---+
5 | 0 | 1 | 0 | 3 | 0 |
  +---+---+---+---+---+

```

```
Adjacency List - Use pair for to store node .i.e `adj[x].push(node,weight)`

(1)--2---(2)
 |        |  ╲6 
 |3       |1  (5)
 |        |  ╱3
(3)---4--(4)

vector<vector<pair<int, int>>> adj(n + 1);
adj[0] -> {}
adj[1] -> {(2,2), (3,3)}
adj[2] -> {(1,2), (4,1), (5,6)}
adj[3] -> {(1,3),(4,3)}
adj[4] -> {(3,4), (2,1) ,(5,3)}
adj[5] -> {(2,6),(4,3)}
```

# [G-3. Graph Representation in Java | Two Ways to Represent](https://youtu.be/OsNklbh9gYI?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)

For Java So Skipped.

# [G-4. What are Connected Components ?](https://youtu.be/lea-Wl_uWXY?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)

Components of Graph
```
(1)------(2)       (5)          (8)    (10)
|         |        /  \         /
|         |       /    \       /
(3)------(4)    (6)----(7)   (9)

The 4 Can be considered as A Signle Graph ✅ (but not connected)

Because we Can Define it as,
N=10   M=8
 1      2
 1      3
 2      4 
 3      4
 5      6
 .      .
 .      .
  
The Graph have 4 componets
```

Traversal
```
If we Start from Node (1), we could never reach Node (5) to (7)
For any Traversal in Graph we always use a `visited array` Vis[n+1]

        0 1 2 3 4 5 6 7 8 9 10 
Vis = [ 0 0 0 0 0 0 0 0 0 0 0]
```

To Handle any Traversal Algorithm/Function to Handle not connected components use the for loop:
```cpp
for(i=0->10)
	if(!vis[i]) // whenever other component's node appear, pass to function.
		traversal(i); // function to traverse all connected components

```
```                     
                        0 1 2 3 4 5 6 7 8 9 10
traversal(0) -> Vis = [ 0 1 1 1 1 0 0 0 0 0 0]
traversal(5) -> Vis = [ 0 1 1 1 1 1 1 1 0 0 0]
traversal(8) -> Vis = [ 0 1 1 1 1 1 1 1 1 1 0]
traversal(10) -> Vis = [ 0 1 1 1 1 1 1 1 1 1 1]
```