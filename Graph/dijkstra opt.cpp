//Implementation for Dijkstra's SSSP(Single source shortest path) algorithm
//This is an optimized algorithm running in O(E*log(V))
 
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX //Infinity
 
const int sz=10001; //Maximum possible number of vertices. Preallocating space for DataStructures accordingly
vector<pair<int,int> > a[sz]; //Adjacency list
int dis[sz]; //Stores shortest distance
bool vis[sz]={0}; //Determines whether the node has been visited or not
 
void Dijkstra(int source, int n) //Algorithm for SSSP 
{
    for(int i=0;i<sz;i++) //Set initial distances to Infinity
        dis[i]=INF;
    //Custom Comparator for Determining priority for priority queue (shortest edge comes first)
    class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};
    priority_queue<pair<int,int> ,vector<pair<int,int> >, prioritize> pq; //Priority queue to store vertex,weight pairs
    pq.push(make_pair(source,dis[source]=0)); //Pushing the source with distance from itself as 0
    while(!pq.empty())
    {
        pair<int, int> curr=pq.top(); //Current vertex. The shortest distance for this has been found
        pq.pop();
        int cv=curr.first,cw=curr.second; //'cw' the final shortest distance for this vertex
        if(vis[cv]) //If the vertex is already visited, no point in exploring adjacent vertices
            continue;
        vis[cv]=true; 
        for(int i=0;i<a[cv].size();i++) //Iterating through all adjacent vertices
            if(!vis[a[cv][i].first] && a[cv][i].second+cw<dis[a[cv][i].first]) //If this node is not visited and the current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw))); //Set the new distance and add to priority queue
    }
}
 
int main() //Driver Function for Dijkstra SSSP
{
    int n,m,x,y,w;//Number of vertices and edges
    //cout<<"Enter number of vertices and edges in the graph\n";
    cin>>n>>m;
    for(int i=0;i<m;i++) //Building Graph
    {
        cin>>x>>y>>w; //Vertex1, Vertex2, weight of edge
        a[x].push_back(make_pair(y,w));
        a[y].push_back(make_pair(x,w));
    }
    //cout<<"Enter source for Dijkstra's SSSP algorithm\n";
    int source;
    cin>>source;
    Dijkstra(source,n);//SSSP from source (Also passing number of vertices as parameter)
    cout<<"Source is: "<<source<<". The shortest distance to every other vertex from here is: \n";
    for(int i=1;i<=n;i++)//Printing final shortest distances from source
    {
        cout<<"Vertex: "<<i<<" , Distance: ";
        dis[i]!=INF? cout<<dis[i]<<"\n" : cout<<"-1\n";
    }
    return 0;
}


// // Time complexity : O(ElogV)
// #include <bits/stdc++.h>
// using namespace std;
 
// typedef vector<int> vi;
// typedef pair<int,int> pii;
// typedef vector< pii > vii;
// #define INF 0x3f3f3f3f
 
// vii *G;   // Graph
// vi Dist;  // for storing the distance of every other node from source.
// /*==========================================*/
// void Dijkstra(int source, int N) {
//     priority_queue<pii, vector<pii>, greater<pii> > Q;   // min heap
//     Dist.assign(N,INF);
//     Dist[source] = 0;
//     Q.push({0,source});
//     while(!Q.empty()){
//         int u = Q.top().second;
//         Q.pop();
//         for(auto &c : G[u]){
//             int v = c.first;
//             int w = c.second;
//             if(Dist[v] > Dist[u]+w){
//                 Dist[v] = Dist[u]+w;
//                 Q.push({Dist[v],v});
//             }
//         }
//     }
// }
// /*===========================================*/
// int main() {
//     int N, M, u, v, w, source;  // N-total no of nodes, M-no. of edges, 
//     cin >> N >> M;              // u,v and w are the end vertices and the weight associated with an edge
//     G = new vii[N+1];
    
//     for(int i=0;i<M;++i){
//         cin >> u >> v >> w;
//         G[u].push_back({v,w});
//         G[v].push_back({u,w});
//     }
//     cin >> source;
//     Dijkstra(source,N);
    
//     for(int i=0;i<N;i++)
//         cout<<Dist[i]<<" ";
//     cout<<endl;
    
//     return 0;
// }