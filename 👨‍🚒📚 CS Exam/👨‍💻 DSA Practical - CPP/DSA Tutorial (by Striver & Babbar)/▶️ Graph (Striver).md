---
description: From Striver's Tutorial ▶️
layout:
  width: wide
  title:
    visible: false
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: true
  metadata:
    visible: true
  tags:
    visible: true
---

# ▶️ Graph (Striver)

## **Data Structure: Graph**

***

#### Content

**1. Learning:**

| \[\[#^G1]] | Graph and Types                          | Concept   | ✅  | A2Z🟢    |
| ---------- | ---------------------------------------- | --------- | -- | -------- |
| \[\[#^G2]] | Graph Representation - C++               | Concept   | ✅  | A2Z🟢    |
| \[\[#^G3]] | Graph Representation - Java              | Concept   | ❌  | A2Z🟢    |
| \[\[#^G4]] | Connected Components - Logic Explanation | Problem   | ✅  | A2Z🔴    |
| \[\[#^G5]] | BFS                                      | Algorithm | ✅⭐ | A2Z🟠SDE |
| \[\[#^G6]] | DFS                                      | Algorithm | ✅⭐ | A2Z🔴SDE |

**2. Problems on BFS/DFS**

| \[\[#^G7]]  | Number of Provinces - Connected Components   | Problem   |     | A2Z🟠    |
| ----------- | -------------------------------------------- | --------- | --- | -------- |
| \[\[#^G8]]  | Number of Islands - Connected Components     | Problem   |     | 🔴SDE    |
| \[\[#^G9]]  | Flood Fill Algorithm                         | Algorithm | ✅⭐  | A2Z🔴    |
| \[\[#^G10]] | Rotten Oranges                               | Problem   |     | A2Z🟠    |
| \[\[#^G11]] | Cycle Detection in Undirected Graph - BFS    | Algorithm | ✅⭐  | A2Z🔴SDE |
| \[\[#^G12]] | Cycle Detection in Undirected Graph - DFS    | Algorithm | ✅⭐  | A2Z🔴SDE |
| \[\[#^G13]] | 0/1 Matrix - BFS Problem                     | Problem   |     | A2Z🟠    |
| \[\[#^G14]] | Surrounded Regions - DFS                     | Problem   |     | A2Z🔴    |
| \[\[#^G15]] | Number of Enclaves - Flood Fill              | Problem   |     | A2Z🔴    |
| \[\[#^G16]] | Number of Distinct Islands - DFS             | Problem   |     | A2Z🔴    |
| \[\[#^G17]] | Bipartite Graph - BFS                        | Concept   | 🔃⭐ | 🟠SDE    |
| \[\[#^G18]] | Bipartite Graph - DFS                        | Concept   | 🔃⭐ | A2Z🟠SDE |
| \[\[#^G19]] | Detect cycle in a directed graph using - DFS | Algorithm | 🔃⭐ | A2Z🔴    |
| \[\[#^G20]] | Find Eventual Safe States - DFS              | Algorithm |     |          |

**3. Topo Sort Problem**

| \[\[#^G21]] | Topological Sort - DFS                                     | Algorithm | ✅⭐ | A2Z🔴SDE |
| ----------- | ---------------------------------------------------------- | --------- | -- | -------- |
| \[\[#^G22]] | Kahn's Algorithm - Topological Sort - BFS                  | Algorithm | ✅⭐ | A2Z🔴SDE |
| \[\[#^G23]] | Cycle Detection in Directed Graph - Kahn's Algorithm - BFS | Algorithm | ⭐  | A2Z🔴    |
| \[\[#^G24]] | Course Schedule I and II                                   | Problem   |    | A2Z🔴    |
| \[\[#^G25]] | Find Eventual Safe States - BFS - Topological Sort         | Algorithm |    | A2Z🔴    |
| \[\[#^G26]] | Alien Dictionary - Topological Sort                        | Problem   |    | A2Z🔴    |

**4. Shortest Path Algorithm and Problems**

| \[\[#^G27]] | Shortest Path in DAG - Topological Sort | Concept   | 🔃⭐ | A2Z🔴    |
| ----------- | --------------------------------------- | --------- | --- | -------- |
| \[\[#^G28]] | Shortest Path in UG with unit wieghts   | Concept   | 🔃⭐ | A2Z🔴    |
| \[\[#^G29]] | Word Ladder -1                          | Problem   |     | A2Z🔴    |
| \[\[#^G30]] | Word Ladder - 2                         | Problem   |     | A2Z🔴    |
| \[\[#^G35]] | Djisktra's Algorithm                    | Algorithm | ⭐   | A2Z🔴SDE |
| \[\[#^G41]] | Bellman Ford Algorithm                  | Algorithm | ⭐   | A2Z🔴SDE |
| \[\[#^G41]] | Floyd Warshal Algorithm                 |           |     |          |
|             | More....                                |           |     |          |

> Named Algorithms

* Kahn's Algorithm
* Djisktra's Algorithm
* Bellman Ford Algorithm
* Floyd Warshal Algorithm

***

#### Traversal `BFS()`/`DFS()` in Connected vs Disconnected Graph

**1. For connected graph:**

* If graph is connected and `x` can reach every node

```cpp
// Start from root
BFS(x); // or DFS(x)
```

**2. For disconnected graph:**

* If graph is disconnected or `x` can't reach all nodes

```cpp
for (int i = 0; i < V; i++) {
    // loop ensures visiting all components
    if (!vis[i]) BFS(i); // or DFS(i)
}
```

**Note:**

* Generally, `x` is taken as `0`.
* Before solving a question, always check if the graph is connected from node `0`. If it’s not, ensure to use a `for` loop to visit all components in the graph.

***

***

## [# G-1. Introduction to Graph | Types | Different Conventions Used](https://youtu.be/M3_pLsDdeuU?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) ^G1

Graph -> Nodes + Edges

#### Types

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

**Path** - Contain a lot of nodes and each of them are reachable

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

#### Degree of Graph

```
Undirected Grpah

(1)----(2)   Degrees(Nodes)
|       |    D(3) = 3
|       |    D(4) = 2
(5)----(3)   D(1) = 2
 ╲     ╱     Degree of Graph = 2*6 = 12
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

#### Edge Weight

```
()---3---()----5---()╲  6 
|         |         |  ╲  
|2        |1        |5  ()
|         |         |  ╱ 
()---2----()---1---()╱  7 

If Weight not given - Assume all unity 
```

## [G-2. Graph Representation in C++ | Two Ways to Represent](https://youtu.be/3oI-34aPMWM?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) ^G2

#### Undirect Graph

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
---------------------
2   1    edge1 : 2--1
1   3    edge1 : 1--3  
2   4    edge1 : 2--4
3   4    edge1 : 3--4
2   5    edge1 : 2--5
4   5    edge1 : 4--5

- Nodes - No. of Node Constant
- Edges - No. of Edges Variable (if we join more two nodes in same graph no. of edges increase)
```

**Store `edges[]` list i.e. Graph efficiently** ⭐

1. Adjacency Matrix `adj[][]`
2. Adjacency List `adj[]`

#### _Adjacency Matrix:_

```sh
adj[n+1][n+1] (if 0 based indexing then adj[n][n])

Mark the edge = 1
adj[2][1]=1 # and adj[1][2]=1  (if undirected)
adj[1][3]=1 # and adj[3][1]=1         ,,
adj[2][4]=1 # and adj[4][2]=1         ,,
adj[3][4]=1 # and adj[4][3]=1         ,,
adj[2][5]=1 # and adj[5][2]=1         ,,
adj[4][5]=1 # and adj[5][4]=1         ,,

      0   1   2   3   4   5
	┌-----------------------┐
0	| 0 | 0 | 0 | 0 | 0 | 0 |
	|---+---+---+---+---+---|
1	| 0 | 0 | 1 | 1 | 0 | 0 |
	|---+---+---+---+---+---|
2	| 0 | 1 | 0 | 0 | 1 | 1 |
	|---+---+---+---+---+---|
3	| 0 | 1 | 0 | 0 | 1 | 0 |
	|---+---+---+---+---+---|
4	| 0 | 0 | 1 | 1 | 0 | 1 |
	|---+---+---+---+---+---|
5	| 0 | 0 | 1 | 0 | 1 | 0 |
	└-----------------------┘

Space : N x N (Costly)
```

**Implementation of Adjacency Matrix in C++**

```cpp
// Implementation Adjacency matrix
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

#### _Adjacency List:_

```sh
List for Each Nodes (In c++, list are vector)
Vector<vector<int>> adj(n+1)
adj[0] -> {}
adj[1] -> {2,3}
adj[2] -> {1,4,5}
adj[3] -> {1,4}
adj[4] -> {3,2,5}
adj[5] -> {2,4}

Space Complexity - 2*E  (Each edges is considered twice)
```

**Implementation of Adjacency List in C++**

```cpp
// Implementation of Adjacency List
int main(){
	 int n, m;
	 cin>>n>>m;
	//List here
	vector<vector<int>> adj(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u); // only for undirected graph
	}
	return 0;
}
```

#### Directed Graph

For Directed Graph , Implementation is Same, but keep in mind if `(1)--->(2)` than only consider `adj[1][2]` not `adj[2][1]`

```
for matrix only : adj[1][2] =1
for list only : adj[1].push(2)
```

> _Note:_ We will use Adjacency list in Every Problem because of better Space complexity

**Weighted Graph:**

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
adj[3] -> {(1,3), (4,3)}
adj[4] -> {(3,4), (2,1), (5,3)}
adj[5] -> {(2,6), (4,3)}
```

## [G-3. Graph Representation in Java | Two Ways to Represent](https://youtu.be/OsNklbh9gYI?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) ^G3

> For Java So Skipped.

## [G-4. What are Connected Components ?](https://youtu.be/lea-Wl_uWXY?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) ^G4

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

⭐ Always use the for loop in any traversal. so that our traversing not end, on disconnected components i.e. when have multiple components.

_Note:_ To Handle any Traversal Algorithm/Function to Handle not connected components use the

for loop:

```cpp
for(i=0->10)
	if(!vis[i]) // whenever other component's node appear, pass to function.
		traversal(i); // function to traverse all connected components

```

```
                        0 1 2 3 4 5 6 7 8 9 10
traversal(0)  -> Vis = [ 0 1 1 1 1 0 0 0 0 0 0]
traversal(5)  -> Vis = [ 0 1 1 1 1 1 1 1 0 0 0]
traversal(8)  -> Vis = [ 0 1 1 1 1 1 1 1 1 1 0]
traversal(10) -> Vis = [ 0 1 1 1 1 1 1 1 1 1 1]
```

## [G-5. Breadth-First Search (BFS) | C++ and Java | Traversal Technique in Graphs](https://youtu.be/-tgVpUgsQ5k?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) ^G5

BFS -> Breadth First Search BFS -> Traversal Technique BFS -> Level wise Traversal

```scss
N = 8
if Starting Node -> (1)

		  (1)         ----> level 0
		/      \
	 (2)       (6)    ----> level 1
	/   \     /   \
 (3)    (4)  (7)  (8) ----> level 2
		  \  /
		   (5)        ----> level 3


Print :   1  2 6   3 4 7 8  5
Level :  _0_ _1_   ___2___  _3_
```

_Note:_ In any Level, Order doesn't matter, you can choose any nodes in any order within a level, basically its depend on the order of neighbour nodes in adjacency list for the node, Just make sure, the order of levels should be maintained. ex:

```scss
1 62 4538 5 -> ✔️  order of level is maintained, and order within level is ignored
1 4538 62 5 -> X    level 2 is printed befor level 1
```

Same graph if starting node is (6)

```scss
N = 8
if Starting Node -> (6)

						  (1) <- level1
						/      \
		level2 ->    (2)       (6) <- level0
					/   \     /   \
	   level3 -> (3)    (4)  (7)  (8) <- level1
				level3 ⬈  \  / ⬉level1
						   (5)
				            ⬉level2

Print :   6  1 8 7   2 5  4 3
Level :  _0_ __1__   _2_  _3_
```

_Note :_ We can reach to a `Node` in more than one way from starting, and the distance/level may be different, So we always count the way that is shorter to the Node. So we make a `visited array` to prevent traversing it more than one time from different path

```scss

Node 5 : level 3 ✔️
6 -> 7 -> 5

Node 5 : level 4  X (it should be counted in earlier level)
6 -> 1 -> 2 -> 4 -> 5
```

### BFS Implementation Approach

Let the graph

```scss
                    (1)
                  /      \
               (2)         (6)
             /    \       /   \
            (3)   (4)    (7)   (9)
                 /    \
               (5) __ (8) 
```

```
Ajacency List:
1 -> {2, 6}
2 -> {1, 3 ,4}
3 -> {2}
4 -> {2, 5 ,8}
5 -> {4, 8}
6 -> {1,7,9}
7 -> {6}
8 -> {4 ,5}
9 -> {6}
```

**Initial Configuration**

1. In Queue : Push Starting Node i.e. `1`
2. Visited Array : Mark the Pushed nodes as `1` i.e. `vis[1]=1`

```
Queue :
|   |
| 1 |
|___|

visited array (n+1) :
[ 0  1  0  0  0  0  0  0  0  0 ]  -> marked starting node as '1'
  0  1  2  3  4  5  6  7  8  9

printed : 
```

**Loop till Queue is Empty**

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=1` that are not visited yet i.e. `2, 6`
2. Visited Array : Mark the Pushed nodes as `1` i.e. `vis[2]=1 , vis[6]=1`
3. Print(or Store) and Pop `queue.front` i.e. `1`

```
Queue :
| 6 | <- push 6
| 2 | <- push 2
| x --> pop 1
|___|

visited array (n+1) :
[ 0  1  1  0  0  0  1  0  0  0 ]  -> mark vis[2] & vis[6] as `1`
  0  1  2  3  4  5  6  7  8  9

printed : 1 <- print popped node
```

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=2` that are not visited yet i.e. `3, 4`
2. Visited Array : Mark the Pushed nodes as `1` i.e. `arr[3]=1, arr[4]=1`
3. Print and Pop `queue.front` i.e. `2`

```
Queue :
| 4 | <- push 4
| 3 | <- push 3
| 6 |
| x --> pop 2
|___|

visited array (n+1) :
[ 0  1  1  1  1  0  1  0  0  0 ]  -> mark vis[3] & vis[4] as `1`
  0  1  2  3  4  5  6  7  8  9

printed : 1 2 <- print popped node
```

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=6` that are not visited yet i.e. `7, 9`
2. Visited Array : Mark the Pushed nodes as `1` i.e. `arr[7]=1, arr[9]=1`
3. Print and pop `queue.front` i.e. `6`

```
Queue :
| 9 | <- push 9
| 7 | <- push 7
| 4 |
| 3 |
| x --> pop 6
|___|

visited array (n+1) :
[ 0  1  1  1  1  0  1  1  0  1 ]  -> mark vis[7] & vis[9] as `1`
  0  1  2  3  4  5  6  7  8  9

printed : 1 2 6 <- print popped node
```

1. All neighbours of `3` are visited ✔️
2. Print and pop `queue.front` i.e. `3`

```
Queue :

| 9 |
| 7 |
| 4 |
| x --> pop 3
|___|

printed : 1 2 6 3 <- print popped node
```

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=4` that are not visited yet i.e. `5`
2. Visited Array : Mark the Pushed nodes as `1` i.e. `arr[5]=1`
3. Print and pop `queue.front` i.e. `4`

```
Queue :
| 5 | <- push 5
| 9 |
| 7 |
| x --> pop 4
|___|

visited array (n+1) :
[ 0  0  1  1  1  1  1  1  0  1 ]  -> mark vis[5] as `1`
  0  1  2  3  4  5  6  7  8  9

printed : 1 2 6 3 4 <- print popped node
```

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=7` that are not visited yet i.e. `8`
2. Visited Array : Mark the Pushed nodes as `1` i.e. `arr[8]=1`
3. Print and pop `queue.front` i.e. `7`

```
Queue :
| 8 | <- push 8
| 5 |
| 9 |
| x --> pop 7
|___|

visited array (n+1) :
[ 0  0  1  1  1  1  1  1  1  1 ]  -> mark vis[8] as `1`
  0  1  2  3  4  5  6  7  8  9      All Nodes Visited ✔️

printed : 1 2 6 3 4 7 <- print popped node
```

1. All neighbours of `9` are visited ✔️
2. Print and pop `queue.front` i.e. `9`

```
Queue :
| 8 |
| 5 |
| x --> pop 9
|___|

printed : 1 2 6 3 4 7 9 <- print popped node
```

1. All neighbours of `5` are visited ✔️
2. Print and pop `queue.front` i.e. `5`

```
Queue :
| 8 |
| x --> pop 5
|___|

printed : 1 2 6 3 4 7 9 5 <- print popped node
```

1. All neighbours of `8` are visited ✔️
2. Print and pop `queue.front` i.e. `8`

```
Queue :
|   |
| x --> pop 8
|___|

printed : 1 2 6 3 4 7 9 5 8<- print popped node
```

Queue Empty ✅ -> Terminate -> All Not Visited

**BFS Traversal Algorithm**

```sh
1. Create vis[] array and initialize to 0.
2. Push starting node 0 into queue and mark as visited # q.push(0) -> vis[0]=1
3. While queue not empty:
    a. Pop node from queue and add to bfs list. # q.pop() -> list.insert(node)
    b. For each adjacent node:
    #--------------------------------------------
        i. If not visited: # !vis[adj] ⭐
            - Mark visited. # vis[adj]=1
            - Push neighbor into queue. # q.push(adj)
    #--------------------------------------------
4. Return bfs list.
```

#### _BFS Traversal | C++ Code (0-based Indexing)_

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        queue<int> q;
        // push the initial starting node 
        vis[0] = 1; 
        q.push(0); 
        vector<int> bfs; 
        // iterate till the queue is empty 
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};
// Return BFS Traversal Order
```

_**Note:**_ Code for both Directed and Undirected Graph is Same, Because whether it is directed or undirected, one can't go from node B to A, if it already gone through A to B because of visited array

Extra Function (To make adjacent array)

```
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

main Function

```
int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
```

_Note :_ We used Array of Vector here for Adjacency List

**Time Complexity TC:`O(V+2E)`**

`while(!q.empty())` -> run for each nodes : `n` `for(auto it : adj[node])` -> run for all adjacent node i.e. degree of nodes (But only not visited satisfy if condition) -> (node1\*degree of node 1) + (node2\*degree of node 2) + . . . .

Total Time complexity = n + total degree -> n:V, total degree:2E = V + 2E

**Space Complexity SC`:O(3n)`**

n -> BFS( ans ) List n-> Queue n -> Visited Node List

## [G-6. Depth-First Search (DFS) | C++ and Java | Traversal Technique in Graphs](https://youtu.be/Qzf1a--rhp8) ^G6

```
              (2)----(5)
             /          \
           (1)           (7)
             \          /
              (3)----(6)
              /
            (4)
```

```
adj List

1 -> {2,3}
2 -> {1, 5}
3 -> {1, 4, 6}
4 -> {3}
5 -> {2, 7}
6 -> {3, 7}
7 -> {5, 6}
```

```
✅ -> Already Visited

dfs(1)
1 -> {2, 3}
      ^

           (1)
```

```
dfs(2)
2 -> {1✅, 5}
            ^  -> dfs(5)

              (2)
             /
           (1)
```

```
dfs(5)
5 -> {2✅, 7}
            ^ -> dfs(7)

              (2)----(5)
             /  
           (1)          
```

```
dfs(7)
7 -> {5✅, 6}
           ^ -> dfs(6)

              (2)----(5)
             /          \
           (1)          (7)  

```

```
dfs(6)
6 -> {3, 7✅}
      ^ -> dfs(3)

              (2)----(5)
             /          \
           (1)          (7)  
                        /
                      (6) 
```

```
dfs(3)
3 -> {1✅, 4, 6✅}
            ^ -> dfs(4)

              (2)----(5)
             /          \
           (1)          (7)  
             \          /
              (3)----(6) 
```

```
dfs(4)
4 -> {3✅}

              (2)----(5)
             /          \
           (1)          (7)  
             \          /
              (3)----(6) 
              /
            (4) 


Done, All Node Visited.
```

**BFS Traversal Algorithm**

```sh
1. Create vis[] array and initialize to 0.
2. Start DFS from node 0:
    a. Mark node as visited. # vis[node]=1
    b. Add node to dfs list. # list.insert(node)
    c. For each neighbor of node:
    #----------------------------------------------
        i. If not visited: # if !vis[adj] ⭐
            - Recursively call DFS for neighbor. # DFS(adj)
    #-----------------------------------------------
3. Return dfs list.

```

#### _DFS Traversal | C++ Code (0-based Indexing)_

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};
// Return DFS Traversal Order
```

_Note:_ Code for both Directed and Undirected Graph is Same, Because whether it is directed or undirected, one can't go from node B to A, if it already gone through A to B because of visited array. Function to Make adjacent node

```
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

main function

```

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
```

**Time Complexity TC:`O(V+2E)` (Undirected Graph) for directed graph its depend on number of edges**

`if(!vis[it])` -> For every node Calling the dfs() function once : `n` `for(auto it : adj[node])` -> run for all adjacent node i.e. degree of nodes (But only not visited satisfy if condition) -> (node1\*degree of node 1) + (node2\*degree of node 2) + . . . .

Total Time complexity = n + total degree -> n:V, total degree:2E = V + 2E

**Space Complexity SC`:O(3n)`**

n -> DFS( ans ) List n-> Recursion Stack (Worst case) n -> Visited Node List

***

> Problems

## [G-7. Number of Provinces | C++ | Java | Connected Components](https://youtu.be/ACzkVtewUYA) ^G7

## [G-8. Number of Islands | Number of Connected Components in Matrix | C++ | Java](https://youtu.be/muncqlKJrH0) ^G8

## [G-9. Flood Fill Algorithm | C++ | Java](https://youtu.be/C-2_uSRli8o) ^G9

For a Source, Traverse its, Upper, Lower, Left and Right Cells.

```
                 (row+1, col)
                      ↑                 
                      |
(row, col-1)  ←--   (row, col)  --→ (row, col+1)
                      |
                      ↓
                  (row+1, col)
```

\=

**Flood Fill - DFS Algorithm**

```sh
1. Create ans[][] = image[][]. # to store output
2. Store iniColor = image[sr][sc].
3. Define delRow[] = {-1, 0, +1, 0}, delCol[] = {0, +1, 0, -1}. 
4. Call DFS(sr, sc):
    a. Set ans[row][col] = newColor.
    b. For 4 neighbours (nrow, ncol):
        - If valid (in bounds), same iniColor, and ans[nrow][ncol] != newColor:
            -> Call DFS(nrow, ncol).
5. Return ans[][] as final image.
```

#### Flood Fill - DFS Algorithm C++ Code\*

**Version 1:**

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
     int iniColor) {
        // color with new color
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
        return ans; 
    }
};
```

**Version 2:** (My ⭐)

```cpp
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        if(old==color) return image;
        image[sr][sc]=color;
        
        // Down Cell Color
        if(sr+1<image.size() and image[sr+1][sc]==old){

            floodFill(image, sr+1, sc, color);
        }
        // Upper Cell color
        if(sr-1>=0 and image[sr-1][sc]==old){
            floodFill(image, sr-1, sc, color);
        }
        // Right cell Color
        if(sc+1<image[0].size() and image[sr][sc+1]==old){
            floodFill(image, sr, sc+1, color);
        }
        // Left Cell color
        if(sc-1 >=0 and image[sr][sc-1]==old){
            floodFill(image, sr, sc-1, color);
        }
        return image;
    }
```

**Time Complexity:** **O(N × M)**

* (`N` no. of rows & `M` no. of cols)
* In the **worst case**, all `N×M` pixels are visited once (if all have the same color).
* Each pixel is processed only **once** due to the color check (`== oldColor` and updated after visit). Space Complexity:
* **O(N × M)** → in recursive DFS, due to **function call stack** (worst case, all pixels in path).
* Or **O(1)** if system supports tail-call optimization (rare in C++).

TC : `O(N × M)` SC : `O(N x M)`

1. **Version 1 (with `ans` copy):**
   * **Does not modify the original image directly**\
     Useful when the problem requires **returning a new image** without changing the input.
   * **More flexible:**\
     You can compare `image` (original) and `ans` (result) to handle visited/unvisited clearly.
2. **Version 2 (my simple version):**
   * **More concise and readable**
   * **Modifies the original `image` directly**
   * Works fine when **in-place update** is allowed\
     (Most Leetcode problems **do allow** this, so this is preferred in contests/interviews)

## [G-10. Rotten Oranges | C++ | Java](https://youtu.be/yf3oUhkvqA0) ^G10

***

## [G-11. Detect a Cycle in an Undirected Graph using BFS | C++ | Java](https://youtu.be/BPlrALf1LDU) ^G11

Here, In Place of `queue<node>`, we will keep track of the the previous node from which it come i.e. Parent Node. `queue<node, parent>`

For a Node, If it's one or more adjacent node are already visited. There are two cases

1. If the visited Node is its Parent node. than it is obvious it should be visited.
2. But if the visited node is not parent that's mean, the visited node is traversed From a different Path and so make a cycle.

Let Consider the graph

```
✅ -> Already visited
(node, parent)

              (2)----(5)
             /          \
           (1)           (7)
             \          /
              (3)----(6)
              /
            (4)
```

```
(1, -1) -> {2, 3}
            ^  ^ add in queue and mark it as visited

          Level 0

           (1)

```

```
(2, 1) -> {1✅, 5}
                 ^ -> add in queue and mark it as visited
                 
(3, 1) -> {1✅, 4, 6}
                 ^  add in queue and mark it as visited

             Level 1
             
              (2)
             / 
           1 
             \  
              (3)
```

```
(4, 3) -> {3✅}

(5, 2) -> {2✅, 7}
                 ^ -> add in queue and mark it as visited
                 
(6, 3) -> {3✅, 7✅}
                 ^ -> It is not parent but already visited 
                     So its mean, it is visited already from different path

Cycle Detected 💫

                   Level 2

               2 ----(5)
             /          \
            1            (7)
             \     
               3 ----(6)
                 \
                   (4)
```

```
(7, 5) - {5✅}
(7 ,6) - {6✅}
                         Level 3

               2 ---- 5 
             /          \
            1            (7)
             \          /
               3 ---- 6 
                 \
                   4 
```

**Cycle Detection in Undirected Graph- BFS Algorithm**

```sh
1. Create vis[] array and initialize to 0.
2. For each unvisited node:
    a. Start BFS with (node, parent = -1).
    b. Mark node as visited and push into queue.# q.push(node) -> list.insert(node)
    c. While queue not empty:
        i. Pop (node, parent) from queue.
        ii. For each neighbor:
            - If not visited:
                * Mark visited and push (neighbor, node) into queue.
            #---------------------------------------------------------
            - Else if visited and not parent: # vis[adj] & adj!= parent⭐
                * Cycle detected, return true.
            #----------------------------------------------------------
3. If no cycle found after all traversals, return false.
```

#### _Detect Cycle in using BFS | C++ Code:_

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
  bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        // -> this for loop will take care of disconnected components
        for(int i = 0;i<V;i++) { 
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};
```

_Note :_ Whenever there is Problem Related to Multiple Components, Don't forget to use

```
for(int i = 0;i<V;i++) { 
            if(!vis[i]) {
                // BFS or DFS 
            }
        }
```

**Time Complexity TC:`O(V+2E) + O(n)`**

`for(int i = 0;i<V;i++)` -> n Note TC will not equal `O(V+2E) * O(n)`. For loop will only called the `detect()` function whenever it is not visited. and hence for loop will only contribute to `o(n)` addtion of time complexity

**Space Complexity SC`:O(4n)`**

n -> BFS( ans ) List 2n-> Queue n -> Visited Node List

## [G-12. Detect a Cycle in an Undirected Graph using DFS | C++ | Java](https://youtu.be/zQ3zgFypzX4) ^G12

Similarly Like Detection in undirected graph using bfs, we will return cycle as true if a node is already visited but not parent

```
              (2)----(5)
             /          \
           (1)           (7)
             \          /
              (3)----(6)
              /
            (7)
```

```
adj List

1 -> {2,3}
2 -> {1, 5}
3 -> {4, 1, 6}
4 -> {3}
5 -> {2, 7}
6 -> {3, 7}
7 -> {5, 6}
```

DFS to detect cycle

```
dfs(node, parent)

dfs(1,-1) 
   \   ⤣ true
  dfs(2,1)
     \    ⤣ true
     dfs(5,2)
       \   ⤣ true
       dfs(7,5)
          \   ⤣ true
         dfs(6,7)
            \    ⤣ true
            dfs(3,6)
          ⤤ /    \  ⤣ true
        dfs(4,3)   dfs(1,3)  
                    1 previously visited -> cycle 💫         
     
```

**Cycle Detection in Undirected Graph- DFS Algorithm**

```sh
1. Create vis[] array and initialize to 0.
2. For each unvisited node:
    a. Start DFS with (node, parent = -1).
    b. Mark node as visited. # vis[node]=1
    c. For each neighbor:
        i. If not visited, recursively call DFS.
        #---------------------------------------------
        ii. Else If visited and not parent # vis[adj] & adj!= parent⭐
                * Cycle detected, return true.
		 #----------------------------------------------

3. If no cycle found after all traversals, return false.
```

#### _Detect Cycle using DFS | C++ Code:_

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
};
```

_Note :_ For loop will take care of disconnected components

**Time Complexity TC:`O(V+2E) + O(n)`**

`for(int i = 0;i<V;i++)` -> n Note TC will not equal `O(V+2E) * O(n)`. For loop will only called the `detect()` function whenever it is not visited. and hence for loop will only contribute to `o(n)` addtion of time complexity i.e. TC:`O(V+2E) + O(n)`

**Space Complexity SC`:O(3n)`**

n -> BFS( ans ) List n-> Queue n -> Visited Node List

***

## [G-13. Distance of nearest cell having 1 | 0/1 Matrix | C++ | Java](https://youtu.be/edXdVwkYHF8) ^G13

## [G-14. Surrounded Regions | Replace O's with X's | C++ | Java](https://youtu.be/BtdgAys4yMk) ^G14

## [G-15. Number of Enclaves | Multi-source BFS | C++ | Java](https://youtu.be/rxKcepXQgU4) ^G15

***

## [G-17. Bipartite Graph | BFS | C++ | Java](https://youtu.be/-vu34sct1g8) ^G17

## [G-18. Bipartite Graph | DFS | C++ | Java](https://youtu.be/KG5YFfR0j8A) ^G18

**Bipartite Graph Check - DFS Algorithm**

```sh
1. Initialize color[] array to -1. # Not colored
2. For each unvisited node:
    a. If color[node] == -1:
        -> Call DFS(node, 0)
3. In DFS(node, col):
    a. Set color[node] = col
    b. For each adjacent node it:
        - If color[it] == -1:
            -> Call DFS(it, !col)
            -> If returns false, return false
        - Else if color[it] == col:
            -> Return false
    c. Return true
4. If all components return true, graph is bipartite.

```

#### _Bipartite Graph Check - DFS C++ Code_

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    // for connected components
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) 
	                return false; 
	        }
	    }
	    return true; 
	}
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

## [G-19. Detect cycle in a directed graph using DFS | Java | C++](https://youtu.be/9twcmtQj4DU) ^G19

**Cycle Detection in Directed Graph - DFS**

```sh
1. Create vis[] and pathVis[] arrays, initialize to 0. # visited and path visited
2. For each unvisited node:
    a. Mark the node as visited # vis[node] = 1
    b. Mark the node as part of the current DFS path # pathVis[node] = 1
    c. For each adjacent node:
        i. If  not visited, recursively call DFS.
        #---------------------------------------------
        ii. Else If part of the current DFS path # vis[adj] and pathVis[adj] ⭐
	        * return true (cycle detected).
    d. After traversing all neighbors, backtrack by setting # pathVis[node] = 0.
    #----------------------------------------------------------------------
3. If no cycle found after all traversals, return false.
```

## [G-20. Find Eventual Safe States - DFS](https://youtu.be/uRbJ1OF9aYM) ^G20

## [G-21. Topological Sort Algorithm | DFS](https://youtu.be/Dhqe8qxS4kc) ^G21

**Topological Sorting** -> Linear ordering of Vertices such that there is an edge between `u` & `v` , `u` appears before `v` in the ordering

Let Consider the Adjacency List

```
0 ->
1 ->
2 -> {3}
3 -> {1}
4 -> {0,1}
5 -> {0,2}
```

Graph will be like

```
   (5)         (4)
    |   ⬊    ⬋  |
    |     (0)    |
    ⬇            ⬇
   (2) ➡ (3) ➡ (1)
```

* Let Consider the Ordering `5 4 0 2 3 1`

```
for the above list [5 4 0 2 3 1]

 u   &   v 
 ↓       ↓
 5  ->  0  : 5 appear before 0. 5_0___ ✅ 
 4  ->  0  : 4 appear before 0. _40___ ✅
 5  ->  2  : 5 appear before 2. 5__2__ ✅
 4  ->  1  : 4 appear before 1. _4___1 ✅
 2  ->  3  : 2 appear before 3. ___23_ ✅
 3  ->  1  : 3 appear before 1. ____31 ✅
```

So `[5 4 0 2 3 1]` is Topologically Sorted ✅

Note:

* There Can be Multiple Valid Topological Ordering
* `4 5 2 3 1 0` This is also va lid Topological Sort for the graph

```
for the above list [4 5 2 3 1 0]

 u   &   v
 ↓       ↓
 5  ->  0  : 5 appear before 0. _5___0 ✅ 
 4  ->  0  : 4 appear before 0, 4____0 ✅
 5  ->  2  : 5 appear before 2, _52___ ✅
 4  ->  1  : 4 appear before 1, 4____1 ✅
 2  ->  3  : 2 appear before 3, __23__ ✅
 3  ->  1  : 3 appear before 1, ___31_ ✅
```

**Note:**

* **Topological Sort (Topo Sort)** → Only valid on **Directed Acyclic Graphs (DAG)** ✅
* **If the graph is not Acyclic (contains cycles)** → There may be two connected vertices, `u` and `v`, such that the order in which they appear depends on the path direction. In a cycle, traversing **clockwise** or **anticlockwise** leads to conflicting orders.
* **If the graph is not Directed (Undirected)** → There may be two connected vertices, `u` and `v`, with both `u → v` and `v → u` being valid. This creates ambiguity, making it impossible to decide which vertex comes first.

#### Topological Sorting (DFS)

```
   (5)         (4)
    |   ⬊    ⬋  |
    |    (0)     |
    ⬇            ⬇
   (2) ➡ (3) ➡ (1)
```

```
0 ->
1 ->
2 -> {3}
3 -> {1}
4 -> {0,1}
5 -> {0,2}
```

```
 0     1    2    3    4    5
┌────┬────┬────┬────┬────┬────┐
│  0 │  0 │ 0  │ 0  │ 0  │ 0  │ 
└────┴────┴────┴────┴────┴────┘
visited
```

```
For All Nodes 👇
```

```
0 -> {}  : dfs(node=0) -> vis[0]=1
✅ No Adjacent Node        :   st.push(0)

								│   │
								│ 0 │
								└───┘ stack
```

```
1 -> {} : dfs(node=1) -> vis[1]=1
✅ No Adjacent Node         :          st.push(1)

										│ 1 │
										│ 0 │
										└───┘ stack
```

```
2 -> {3} : dfs(node=2) -> vis[2]=1
               \ ⤣                  :      st.push(2)
3 -> {1} :    dfs(node=3)  -> vis[3]=1          ⬉
✅ Node 1 Already visited            :       st.push(3)

												| 2 |
												| 3 |
												│ 1 │
												│ 0 │
												└───┘ stack
```

```
4 -> {0,1} : dfs(node=4) -> vis[4]=1
✅ Node 0 and 1 Already visited     :           st.push(4)

													| 4 |
													| 2 |
													| 3 |
													│ 1 │
													│ 0 │
													└───┘ stack
```

```
5 -> {0,2} : dfs(node=5) -> vis[5]=1 & st.push(5)
✅ Node 0 and 2 Already visited  :                    st.push(5)

														| 5 |
														| 4 |
														| 2 |
														| 3 |
														│ 1 │
														│ 0 │
														└───┘ stack
```

```
| 5 |
| 4 |
| 2 |
| 3 |
│ 1 │          
│ 0 │
└───┘
Topological Sort :
5 4 2 3 1 0 --> One of the Linear Ordering

```

**Topological Sort - DFS Algorithm**

```sh
1. Create vis[] array and initialize to 0.
2. For each unvisited node:
    a. Call DFS(node).
3. In DFS(node):
    a. Mark node as visited = 1. # vis[node=1]
    b. For each adjacent node it:
    #------------------------------------------------
        - If not visited, call DFS(adj). # !vis[adj] -> DFS(adj)
    c. After visiting all adjacents, push node into stack. # st.push()
    #----------------------------------------------------------
4. After all DFS calls, pop all elements from stack and store into ans[].
5. Return ans[] as Topological Order.
```

#### _Topological Sort - DFS C++ Code_

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
		vis[node] = 1;
		// Traverse Adjacent Nodes
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[]){
		int vis[V] = {0};
		stack<int> st;
		// Loop and DFS(). Because We can't reach to every nodes through single start at node `0`
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}
		// Stack -> Ans list
		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};
```

**In place of Stack, we could use `ans` vector Directly**

```cpp
st.push() ----then----> ans.push_back(st.top())

ans.push_back() -----then----> reverse(ans.begin(), ans.end())
```

## [G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS](https://youtu.be/73sneFXuTEg) ^G22

#### Topological Sorting BFS (Kahn's Algorithm )

**Indegree** -> No. of Incoming edges to a node

```
Indegree:
  0               0
   (5)         (4)
    |   ⬊    ⬋  |
    |   2 (0)    |
    ⬇            ⬇
 1 (2) ➡ (3) ➡ (1) 2
          1
```

```
 0     1    2    3    4    5
┌────┬────┬────┬────┬────┬────┐
│  2 │  2 │ 1  │ 1  │ 0  │ 0  │ 
└────┴────┴────┴────┴────┴────┘
Indegree
```

**Indegree Rule -> Topological Sort**

* **Nodes with lower indegree** will appear **before** nodes with higher indegree in the topological ordering.
* **Nodes with the same indegree** can appear in **any order** relative to each other.

**Queue**

```
|   |
│   │
│   │
└───┘
  Q
```

**Kahn's Algorithm for Topological Sort** (BFS)

1. Insert all nodes with indegree `0` into the queue `Q`.
2. While the queue is not empty:
   * Remove the front node from the queue.
   * Add it to the topological order.
   * For each adjacent node of the current node:
     * Reduce its indegree by `1`.
     * If its indegree becomes `0`, insert it into the queue.
3. Repeat until the queue is empty.
4. Check for cycles:
   * If the topological order contains fewer nodes than the total number of nodes, the graph has a cycle.

**Key Points:**

* Nodes with **indegree `0`** are processed first.
* The algorithm ensures **lexicographically smallest** order when using a min-heap instead of a queue.
* **Cycle detection:** If all nodes are not processed, the graph contains a **cycle**.

**Topological Sort - BFS (Kahn's Algorithm)**

```sh
1. Create indegree[] array and initialize to 0.
2. For each edge u -> v in the graph:
    a. Increment indegree[v] by 1.
3. Create a queue q.
    a. For each node i:
        - If indegree[i] == 0, push i into the queue.
4. While the queue is not empty:
    a. Pop a node from the queue. queue. # q.pop()
    b. Add the node to the topo[] vector. # topo.insert(node)
    c. For each adjacent node it of the popped node:
    # ------------------------------------------------
        i. Decrease indegree[it] by 1.
        ii. If indegree[it] == 0, push it into the queue.
    # -----------------------------------------------------
5. If the size of topo[] is less than V (total nodes), a cycle exists, return an empty vector.
6. Return the topo[] vector as the topological sorted order.
```

#### _Topological Sort - BFS (Kahn's Algorithm) C++ Code_

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
	
	// Step 1: Calculate indegree for each node
	int indegree[V] = {0};  // Vector to store indegree
	for(int i = 0; i < V; i++) {
		for(auto it : adj[i]) {  
			indegree[it]++;   // Increment indegree of adjacent nodes
		}
	}

	// Step 2: Push all nodes with indegree 0 into the queue
	queue<int> q;  // queue to Store zero indegree vertices
	for(int i = 0; i < V; i++) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}

	// Step 3: Perform Kahn's Algorithm
	vector<int> topo;  // Vector to store topological ordering
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);  // Add current node to the topo sort

		// Decrease indegree of adjacent nodes
		for(auto it : adj[node]) {
			indegree[it]--;
			if(indegree[it] == 0) {
				q.push(it);  // Add adjacent nodes with indegree 0 to the queue
			}
		}	
	}

	// Step 4: Return the topological sort
	return topo;
}
```

**Time Complexity TC:`O(V+E)`**

* **`O(V)`** → Iterating through all vertices to initialize the indegree array.
* **`O(E)`** → Iterating over all edges while processing the adjacent nodes.
* Therefore, the overall time complexity is `O(V + E)`.

**Space Complexity SC`:O(n)`**

* **Queue:** `O(V)` → In the worst case, all vertices could be pushed into the queue.
* **Indegree array:** `O(V)` → Stores the indegree of each vertex.
* **Topological order vector:** `O(V)` → Stores the result of the topological sort.

***

## [G-23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm | BFS](https://youtu.be/iTBaI90lpDQ)

## [# G-24. Course Schedule I and II | Pre-requisite Tasks | Topological Sort](https://youtu.be/WAOfKpxYHR8)

## [# G-25. Find Eventual Safe States - BFS - Topological Sort](https://youtu.be/2gtg3VsDGyc)

## [# G-26. Alien Dictionary - Topological Sort](https://youtu.be/U3N_je7tWAs)

***

## [G-27. Shortest Path in Directed Acyclic Graph - Topological Sort](https://youtu.be/ZUFQfFaU-8U?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) ^G27

### Directed Acyclic Graph + Weight

**Shortest Path in DAG - Topo Sort + Relaxation Algorithm**

```sh
1. Create adj[] list from edges with (node -> {adj, weight}).
2. Create vis[] array and initialize to 0.
3. For each unvisited node:
    a. Call DFS(node).
4. In DFS(node):
    a. Mark node as visited. # vis[node] = 1
    b. For each adjacent node (v, wt):
        - If not visited, call DFS(v). # !vis[v] -> DFS(v)
    c. Push node into stack after all calls. # st.push(node)
5. Create dist[] array of size N, initialize with 1e9.
6. Set dist[source] = 0.
7. While stack is not empty:
    a. Pop node from stack.
    b. For each adjacent (v, wt):
        - If dist[node] + wt < dist[v], update dist[v]. # Relax
8. Replace all 1e9 in dist[] with -1 (unreachable nodes).
9. Return dist[] as shortest paths from source.

```

#### _Shortest Path in DAG -Using Topo Sort + Edge Relaxation | C++ Code_

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
  public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

      // Step 1: Build graph (adjacency list)
      vector < pair < int, int >> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // Step 2: Topological sort
      int vis[N] = {0};
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }

      // Step 2: Topological Sort
      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      // Step 4: Relax edges in topological order
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }
	// Step 5: Convert unreachable nodes' distance to -1
      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};
```

## [# G-28. Shortest Path in Undirected Graph with Unit Weights](https://youtu.be/C4gxoTaI71U?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) ^G28

### Undirected Graph + Unit Weight

**Shortest Path - Undirected Graph - BFS Algorithm**

```sh
1. Create adj[] list from edges for undirected graph.
2. Create dist[] array of size N, initialized with 1e9.
3. Set dist[src] = 0.
4. Create queue q and push src.
5. While q is not empty:
    a. Pop node from front.
    b. For each adjacent node:
        - If dist[node] + 1 < dist[adj], update and push. # Relaxation
6. Create ans[] with -1.
7. For each i: if dist[i] != 1e9, set ans[i] = dist[i].
8. Return ans[] as shortest distance from src.
```

#### _Shortest Path - Undirected Graph - BFS C++ Code_

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.    
    
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = 1e9;
        // BFS Implementation.
        dist[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Updated shortest distances are stored in the resultant array ‘ans’.
        // Unreachable nodes are marked as -1. 
        vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        return ans; 
    }
};
```

***

## [G-29. Word Ladder - I | Shortest Paths](https://youtu.be/tRPda0rcf8E) ^G29

## [G-30. Word Ladder - 2 | Shortest Paths](https://youtu.be/DREutrv2XD0) ^G30

## [G-31. Word Ladder - 2 | Optimised Approach for Leetcode](https://youtu.be/AD4SFl7tu7I) ^G31

***
