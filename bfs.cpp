// #include <bits/stdc++.h> 
// vector<int> BFS(int vertex, vector<pair<int, int>> edges)
// {
//     // Write your code here
//     int vis[vertex] = {0};
//     vis[0] = 1;
//     queue<int> q;
//     // push the node in the queue 
//     q.push(0);
//     vector<int> bfs;
//     // iterate till the queue is empty 
//     while (!q.empty()){
//         int node = q.front();
//         q.pop();
//         bfs.push_back(node);
//         for (auto it : edges[node]){
//             // if the neighbour has previously not been visited, 
//             // store in Q and mark as visited
//             if (!vis[it]){
//                 vis[it] = 1;
//                 q.push(it);
//             } 
//         }
//     }
//     return bfs;
// }
#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   // Write your code here
   vector<int>adj[vertex+1];
   int m=edges.size();
   for(int i=0;i<m;i++){
       adj[edges[i].first].push_back(edges[i].second);
       adj[edges[i].second].push_back(edges[i].first);
   }
   for(int i=0;i<vertex;i++)
      sort(adj[i].begin(),adj[i].end());
   vector<int>vis(vertex+1,0);
   vector<int>bfsans;
   for(int i=0;i<vertex;i++){
       if(!vis[i]){
           queue<int>q;
           q.push(i);
           vis[i]=1;
           while(!q.empty()){
               int node=q.front();
               q.pop();
               bfsans.push_back(node);
               for(auto it:adj[node]){
                   if(!vis[it]){
                       q.push(it);
                       vis[it]=1;
                   }
               }
            }
       }
   }
   return bfsans;
}
