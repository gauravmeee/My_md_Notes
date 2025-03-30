
>Important Algorithms
- Kahn's Algorithm
- 
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

**Adjacency Matrix:**

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
	┌-----------------------┐
0	| 0 | 0 | 0 | 0 | 0 | 0 |
	|---+---+---+---+---+---|
1	| 0 | 0 | 1 | 1 | 0 | 0 |
	|---+---+---+---+---+---|
2	| 0 | 1 | 0 | 0 | 1 | 1 |
	|---+---+---+---+---+---|
3	| 0 | 1 | 0 | 0 | 1 | 0 |
	+---+---+---+---+---+---|
4	| 0 | 0 | 1 | 1 | 0 | 1 |
	|---+---+---+---+---+---|
5	| 0 | 0 | 1 | 0 | 1 | 0 |
	└-----------------------┘

Space : N x N (Costly)
```

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

**Adjacency List :**
```
List for Each Nodes (In c++, list are vector)
Vector<vector<int>> adj(n+1)
adj[0] -> {}
adj[1] -> {2,3}
adj[2] -> {1,4,5}
adj[3] -> {1,4}
adj[4] -> {3,2,5}
adj[5] -> {2,4}

Space Complexit - 2*E  (Each edges is considered twice)
```

```cpp
// Implementation of Adjacency List
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


⭐ Always use the for loop in any traversal. so that our traversing not end, on disconnected components i.e. when have multiple components.

*Note:* To Handle any Traversal Algorithm/Function to Handle not connected components use the for loop:
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
7 -> {6, 9}
8 -> {4 ,5}
9 -> {6}
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

##### Loop till Queue is Empty

1. In Queue : Using Given `Adjacency List`, Push neighbour node of `queue.front=1` that are not visited yet i.e. `2, 6`
3. Visited Array : Mark the Pushed nodes as `1` i.e. `vis[2]=1 , vis[6]=1`
4. Print(or Store) and Pop `queue.front`  i.e. `1`

```
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


### *BFS Traversal | C++ Code (0-based Indexing)*
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
// Return BFS Traversal Order
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

##### <ins>Time  Complexity</ins>  TC:`O(V+2E)`
`while(!q.empty())` -> run for each nodes : `n`
`for(auto it : adj[node])` -> run for all adjacent node  i.e. degree of nodes (But only not visited satisfy if condition)
                        ->  (node1\*degree of node 1) + (node2\*degree of node 2) + . . . .

Total Time complexity = n + total degree -> n:V, total degree:2E = V + 2E


##### <ins>Space Complexity</ins>  SC`:O(3n)`
n -> BFS( ans ) List
n-> Queue
n -> Visited Node List


# [G-6. Depth-First Search (DFS) | C++ and Java | Traversal Technique in Graphs](https://youtu.be/Qzf1a--rhp8)

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

### *DFS Traversal | C++ Code (0-based Indexing)*
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
*Note:* Code for both Directed and Undirected Graph is Same, Because whether it is directed or undirected, one can't go from node B to A, if it already gone through A to B because of visited array.
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

##### <ins>Time  Complexity</ins>  TC:`O(V+2E)` (Undirected Graph) for directed graph its depend on number of edges
`if(!vis[it])` -> For every node Calling the dfs() function once : `n`
`for(auto it : adj[node])` -> run for all adjacent node  i.e. degree of nodes (But only not visited satisfy if condition)
                        ->  (node1\*degree of node 1) + (node2\*degree of node 2) + . . . .

Total Time complexity = n + total degree -> n:V, total degree:2E = V + 2E


##### <ins>Space Complexity</ins>  SC`:O(3n)`
n -> DFS( ans ) List
n-> Recursion Stack (Worst case)
n -> Visited Node List


# [G-11. Detect a Cycle in an Undirected Graph using BFS | C++ | Java](https://youtu.be/BPlrALf1LDU)

Here, In Place of `queue<node>`, we will keep track of the the previous node from which it come i.e. Parent Node. `queue<node, parent>`

For a Node, If it's one or more adjacent node are already visited. There are two cases
1. If the visited Node is its Parent node. than it is obvious it should be visited. 
2. But if the visited node is not parent that's mean, the visited node is traversed From a different Path and so make a cycle.
3. 
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
            (7)
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
                 ^  ^ add in queue and mark it as visited

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


***Detect Cycle using BFS | C++ Code:****
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

*Note :* Whenever there is Problem Related to Multiple Components, Don't forget to use
```
for(int i = 0;i<V;i++) { 
            if(!vis[i]) {
                // BFS or DFS 
            }
        }
```


##### <ins>Time  Complexity</ins>  TC:`O(V+2E) + O(n)`
`for(int i = 0;i<V;i++)` -> n 
Note TC will not equal `O(V+2E) * O(n)`. For loop will only called the `detect()` function whenever it is not visited. and hence for loop will only contribute to `o(n)` addtion of time complexity



##### <ins>Space Complexity</ins>  SC`:O(4n)`
n -> BFS( ans ) List
2n-> Queue
n -> Visited Node List

# [G-12. Detect a Cycle in an Undirected Graph using DFS | C++ | Java](https://youtu.be/zQ3zgFypzX4)

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

DFS to detect  cycle
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


***Detect Cycle using DFS | C++ Code: ***
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
*Note :* For loop will take care of disconnected components


##### <ins>Time  Complexity</ins>  TC:`O(V+2E) + O(n)`
`for(int i = 0;i<V;i++)` -> n 
Note TC will not equal `O(V+2E) * O(n)`. For loop will only called the `detect()` function whenever it is not visited. and hence for loop will only contribute to `o(n)` addtion of time complexity i.e.  TC:`O(V+2E) + O(n)`

##### <ins>Space Complexity</ins>  SC`:O(3n)`
n -> BFS( ans ) List
n-> Queue
n -> Visited Node List 


# [# G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS](https://youtu.be/73sneFXuTEg)

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


- Let Consider the Ordering `5 4 0 2 3 1`
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

So  `[5 4 0 2 3 1]` is Topologically Sorted ✅

Note: 
- There Can be Multiple Valid Topological Ordering
- `4 5 2 3 1 0` This is also valid Topological Sort for the graph
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


✅ **Topological Sort (Topo Sort)** → Only valid on **Directed Acyclic Graphs (DAG)**
- **If the graph is not Acyclic (contains cycles)** →  There may be two connected vertices, `u` and `v`, such that the order in which they appear depends on the path direction. In a cycle, traversing **clockwise** or **anticlockwise** leads to conflicting orders.
- **If the graph is not Directed (Undirected)** →  There may be two connected vertices, `u` and `v`, with both `u → v` and `v → u` being valid. This creates ambiguity, making it impossible to decide which vertex comes first.


### Topological Sorting ( Kahn's Algorithm BFS )


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

**Topological Sort - Indegree Rule**
- **Nodes with lower indegree** will appear **before** nodes with higher indegree in the topological ordering.
- **Nodes with the same indegree** can appear in **any order** relative to each other.

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
    - Remove the front node from the queue.
    - Add it to the topological order.
    - For each adjacent node of the current node:
        - Reduce its indegree by `1`.
        - If its indegree becomes `0`, insert it into the queue.
3. Repeat until the queue is empty.
4. Check for cycles:
    - If the topological order contains fewer nodes than the total number of nodes, the graph has a cycle.

**Key Points:**
- Nodes with **indegree `0`** are processed first.
- The algorithm ensures **lexicographically smallest** order when using a min-heap instead of a queue.
- **Cycle detection:** If all nodes are not processed, the graph contains a **cycle**.

**C++ Code** (BFS)
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

##### <ins>Time  Complexity</ins>  TC:`O(V+E)`
- **`O(V)`** → Iterating through all vertices to initialize the indegree array.
- **`O(E)`** → Iterating over all edges while processing the adjacent nodes.
- Therefore, the overall time complexity is `O(V + E)`.

##### <ins>Space Complexity</ins>  SC`:O(n)`
- **Queue:** `O(V)` → In the worst case, all vertices could be pushed into the queue.
- **Indegree array:** `O(V)` → Stores the indegree of each vertex.
- **Topological order vector:** `O(V)` → Stores the result of the topological sort.