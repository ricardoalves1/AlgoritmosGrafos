#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair; 
  
class Graph { 

    int V;
    list< pair<int, int> > *adj; 
  
    public: 
        Graph(int V);
        void addEdge(int u, int v, int w);
        void prim();
};

Graph::Graph(int V) {
    this->V = V; 
    adj = new list<iPair> [V]; 
}
  
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
}

void Graph::prim() {

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0;
    int mst_wt = 0;
  
    vector<int> key(V, INF);  
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 
  
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    while (!pq.empty()) { 

        int u = pq.top().second;
        
        if (inMST[u] == false) {
            mst_wt += pq.top().first;
        }
        
        pq.pop(); 

        inMST[u] = true; 
  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) { 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (inMST[v] == false && key[v] > weight) { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            }
        }
    }
  
    cout << "Edges\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << endl;
    }

    cout << "\nWeight: " << mst_wt;
}

int main() {

    int V = 0, E = 0;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
  
    g.prim();
  
    return 0; 
}