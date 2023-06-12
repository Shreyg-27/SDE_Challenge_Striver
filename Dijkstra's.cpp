#include <bits/stdc++.h> 
#include<unordered_map>
#include<list> 
#include<set> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    // create adj list 
    unordered_map<int,list<pair<int,int>>> adj;
    for (int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // creation of distance array with infinite value initially 
    vector<int> dist(vertices);
    for (int i=0;i<vertices;i++){
        dist[i] = INT_MAX;
    }

    // creation of set on the basis of dist and node 
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while (!st.empty()){
        // fetch the top record 
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        // remove the top record now 
        st.erase(st.begin());
        // traverse on its neighbours 
        for (auto neighbour : adj[topNode]){
            if (nodeDistance+neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // if record not found, erase it 
                if (record != st.end()){
                    st.erase(record);
                }

                // distance update 
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // record push in the set 
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
    
    
}
