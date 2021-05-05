/**
 * @file main.cpp
 * @brief This is a graph project.
 * @details This is the long brief at the top of main.cpp.
 * @author Addis Bogale and Bona Tufa
 * @date 4/2/2021
 */
 

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Graph{
private:
    int n;
public:
    vector <int> adj;

   Graph(vector<int> a, int input) {
       n = input;
       adj = a;
   }

void addEdge(vector<int> adj, int u, int v)
{
    adj.push_back(v);
    adj.push_back(u);
}
void delEdge(vector<int> adj, int u, int v)
{
    // Traversing through the first vector list
    // and removing the second element from it
    for (int i = 0; i < adj.size(); i++) {
        if (adj[i] == v) {
            adj.erase(adj.begin() + i);
            break;
        }
    }
 
    // Traversing through the second vector list
    // and removing the first element from it
    for (int i = 0; i < adj.size(); i++) {
        if (adj[i] == u) {
            adj.erase(adj.begin() + i);
            break;
        }
    }
}


bool hasEdge(int i, int j) {
    vector<int>::iterator it;
    it = find (adj.begin(), adj.end(), i);
    if (it != adj.end())
        return adj[i];
}


void outEdges(int i, vector<int> &edges) {
    for (int k = 0; k < adj.size(); k++)
        edges.push_back(adj.at(k));
}

void inEdges(int i, vector<int> &edges) {
    for (int j = 0; j < n; j++) {
        vector<int>::iterator it;
        it = find (adj.begin(), adj.end(), i);
        if (it != adj.end()) 
                edges.push_back(j);
    }
}

int nVertices() {
    return n * n;
}


void bfs(Graph &g, int r) {
    bool *seen = new bool[g.nVertices()];
    vector<int> q;
    q.push_back(r);
    seen[r] = true;
    while (q.size() > 0) {
        int i = q.back();
        cout << endl << i << " > " << "This is BFS" << endl;
        q.pop_back();
        vector<int> edges;
        g.outEdges(i, edges);
        for (int k = 0; k < edges.size(); k++) {
            int j = edges[k];
            if (!seen[j]) {
                q.push_back(j);
                seen[j] = true;
            }
        }
    }
    delete[] seen;
}



void dfs2(Graph &g, int r) {
    bool *c = new bool[g.nVertices()];
    vector<int> s;
    s.push_back(r);
    while (s.size() > 0) {
        int i = s.back();
        cout << endl << i << " > " << "This is DFS"<< endl;
        s.pop_back();
        if (c[i] == *c) {
            c[i] = c;
            vector<int> edges;
            g.outEdges(i, edges);
            for (int k = 0; k < edges.size(); k++)
                s.push_back(edges[k]);
        }
    }
delete[] c;
}

void printGraph(vector<int> adj, int V)
{   
    int x;
    for (int v = 0; v < V; ++v) {
        cout << "vertex " << v << " ";
        for (auto x : adj)
            cout << "-> " << x;
        printf("\n");
        break;
    }
    printf("\n");
}
};

int main()
{
    int v;
    vector<int> value;
    
    Graph test = Graph(value, 10);

    // Adding edge as shown in the example figure
    
    
    test.addEdge(value, 0, 4);
    test.addEdge(value,1, 2);
    test.addEdge(value,1, 3);
    test.addEdge(value,1, 4);
    test.addEdge(value,2, 3);
    test.addEdge(value,3, 4);
 
    // Printing adjacency matrix
    test.printGraph(value, v);
 
    // Deleting edge (1, 4)
    // as shown in the example figure
    test.delEdge(value, 1, 4);
 
    // Printing adjacency matrix
    test.printGraph(value, v);
 
    return 0;
}