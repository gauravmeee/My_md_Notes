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

# [G-5. Breadth-First Search (BFS) | C++ and Java | Traversal Technique in Graphs](https://youtu.be/-tgVpUgsQ5k?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)

BFS -> Breadth First Search
BFS -> Traversal Technique
BFS -> Level wise Traversal


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

*Note:* In any Level, Order doesn't matter, you can choose any nodes in any order within a level, basically its depend on the order of neighbour nodes in adjacency list for the node, Just make sure, the order of levels should be maintained.
ex:
``` scss
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

Print :   6  1 8 7   2 5  4
Level :  _0_ __1__   _2_  _3_
```

*Note :* We can reach to a `Node` in more than one way from starting, and the distance/level may be different, So we always count the way that is shorter to the Node. So we make a `visited array` to prevent traversing it more than one time from different path
```scss

Node 5 : level 3 ✔️
6 -> 7 -> 5

Node 5 : level 4  X (it should be counted in earlier level)
6 -> 1 -> 4 -> 5
```


## BFS Implementation Approach

Let the graph
```scss
                    (1)
                /           \
               (2)          (6)
             /    \       /     \
            (3)   (4)    (7)    (9)
                 /    \
                (5) __ (8) 
```

##### Initial Configuration 
1. In Queue :  Push Starting Node i.e. `1`
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

##### Loop Till Queue is Not Empty

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=1` that are not visited yet i.e. `2, 6`
3. Visited Array : Mark the Pushed nodes as `1` i.e. `vis[2]=1 , vis[6]=1`
4. Print(or Store) and Pop `queue.front`  i.e. `1`
```
Ajacency List:
1 -> { }
2 -> {2,0}
3 -> {1,3,4}
4 -> {2,5}
5 -> {4,8}
6 -> {1,7,9}
7 -> {6,8}
8 -> {5,7}
9 -> {6}

Queue :
| 6 | <- push 6
| 2 | <- push 2
|  ---> pop 1
|___|

visited array (n+1) z:
[ 0  1  1  0  0  0  1  0  0  0 ]  -> mark vis[2] & vis[6] as `1`
  0  1  2  3  4  5  6  7  8  9

printed : 1 <- print popped node
```

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=2` that are not visited yet i.e. `3, 4`
2. Visited Array : Mark the Pushed nodes as `1` i.e. `arr[3]=1, arr[4]=1`
3. Print and Pop  `queue.front` i.e. `2`
```
Queue :
| 4 | <- push 4
| 3 | <- push 3
| 6 |
|  ---> pop 2
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
|  ---> pop 6
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
|  ---> pop 3
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
|  ---> pop 4
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
|  ---> pop 7
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
|  ---> pop 9
|___|

printed : 1 2 6 3 4 7 9 <- print popped node
```

1. All neighbours of `5` are visited ✔️
2. Print and pop `queue.front` i.e. `5`
```
Queue :
| 8 |
|  ---> pop 5
|___|

printed : 1 2 6 3 4 7 9 5 <- print popped node
```

1. All neighbours of `8` are visited ✔️
2. Print and pop `queue.front` i.e. `8`
```
Queue :
|   |
|  ---> pop 8
|___|

printed : 1 2 6 3 4 7 9 5 8<- print popped node
```

Queue Empty ✅ -> Terminate -> All Not Visited


### *BFS C++ Code (0-based Indexing)*
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        // push the initial starting node 
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
```
*Note:* Code for both Directed and Undirected Graph is Same, Because whether it is directed or undirected, one can't go from node B to A, if it already gone through A to B because of visited array

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
*Note :* We used Array of Vector here for Adjacency List

<ins>Time  Complexity</ins>  TC:`O(V+2E)`
`while(!q.empty())` -> run for each nodes : `n`
`for(auto it : adj[node])` -> run for all adjacent node  i.e. degree of nodes (But only not visited satisfy if condition)
                        ->  (node1\*degree of node 1) + (node2\*degree of node 2) + . . . .

Total Time complexity = n + total degree -> n:V, total degree:2E = V + 2E


<ins>Space Complexity</ins>  SC`:O(3n)`
n -> BFS( ans ) List
n-> Queue
n -> Visited Node List


# [G-6. Depth-First Search (DFS) | C++ and Java | Traversal Technique in Graphs](https://youtu.be/Qzf1a--rhp8)

### *DFS C++ Code (0-based Indexing)*
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

```
*Note:* Code for both Directed and Undirected Graph is Same, Because whether it is directed or undirected, one can't go from node B to A, if it already gone through A to B because of visited array

Function to Make adjacent node
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

<ins>Time  Complexity</ins>  TC:`O(V+2E)` (Undirected Graph) for directed graph its depend on number of edges
`if(!vis[it])` -> For every node Calling the dfs() function once : `n`
`for(auto it : adj[node])` -> run for all adjacent node  i.e. degree of nodes (But only not visited satisfy if condition)
                        ->  (node1\*degree of node 1) + (node2\*degree of node 2) + . . . .

Total Time complexity = n + total degree -> n:V, total degree:2E = V + 2E


<ins>Space Complexity</ins>  SC`:O(3n)`
n -> BFS( ans ) List
n-> Recursion Stack (Worst case)
n -> Visited Node List