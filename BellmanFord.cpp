// #include <bits/stdc++.h> 
// // # define maxi 1e9

// int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
//     // Write your code here.
//     // bellman ford algo 
//     // 1 iterate over all the vertices for n-1 times 
//     // 2 iterate over all the vertices over 1 more time 
//     // 3 if any update, then negative cycle is present
//     // 4 else we got the shortest distance
//     // TC - O(V*E)
//     // SC O(V)
//     // step 1 
//     vector<int> shortestDistance(n+1,maxi);
//     shortestDistance[src] = 0;
//     for (int t=1;t<n;t++){
//         bool noUpdate = true;
//         for (int i=0;i<m;i++){
//             if (shortestDistance[edges[i][0]] != maxi && shortestDistance[edhes[i][1]] > 
//             shortestDistance[edges[i][0]])
//         }
//     }
// }

#include <bits/stdc++.h>
#define maxi 1e9

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Bellmon Ford Algorithm
    // Step 1: Iterate over all the virtices for (n-1) time.
    // Step 2: Iterate over all the vertices one more time.
    // Case -> if any update: Negitive cycle is present.
    //      -> else we got the shortest distance.
    // Time Complexity: O(V*E)
    // Space Complexity: O(V)
    // Step 1:
    vector<int> shortestDistance(n + 1, maxi);
    shortestDistance[src] = 0;
    for(int t = 1; t < n; t++){
        bool noUpdate = true;
        for(int i = 0; i < m; i++){
            if(shortestDistance[edges[i][0]] != maxi && shortestDistance[edges[i][1]] > shortestDistance[edges[i][0]] + edges[i][2]){
                shortestDistance[edges[i][1]] = shortestDistance[edges[i][0]] + edges[i][2];
                noUpdate = false;
            }
        }
        if(noUpdate) return shortestDistance[dest];
    }
    // Step 2: Iterate one more time
    bool noUpdate = true;
    for(int i = 0; i < m; i++){
        if(shortestDistance[edges[i][1]] > shortestDistance[edges[i][0]] + edges[i][2]){
            shortestDistance[edges[i][1]] = shortestDistance[edges[i][0]] + edges[i][2];
            noUpdate = false;
        }
    }
    // Negitive Cycle Detected
    if(!noUpdate) return INT_MIN;
    return shortestDistance[dest];
}
