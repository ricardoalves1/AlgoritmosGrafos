#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair; 

class Graph { 

    int V;
    list< pair<int, int> > *adj; 
  
    public: 
        Graph(int V);
        void addEdge(int u, int v, int w);
        void dijkstra(int src);
};

Graph::Graph(int V) {
    this->V = V; 
    adj = new list<iPair> [V]; 
}
  
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
}

void Graph::dijkstra(int src) {
    int numV = V;

    vector<int> dist(numV, INT_MAX);
    vector<int> parent(numV, -1);

    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

    dist[src] = 0;
    parent[src] = src;

    pq.push({dist[src], src});

    while (!pq.empty()) {

        int u = pq.top().second;

        pq.pop();
        
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = i->first;
            int w = i->second;

            if(dist[v] > (dist[u] + w)) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << "to \t dist" << endl;
    for (int i = 0; i < numV; ++i)
        cout << i << "\t " << dist[i] << endl;

    cout << endl << "vetex \t parent" << endl;
    for (int i = 0; i < numV; ++i)
        cout << i << "\t " << parent[i] << endl;

}


int main () {
    int V = 0, E = 0;

    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
  
    g.dijkstra(0);

    return 0;
}