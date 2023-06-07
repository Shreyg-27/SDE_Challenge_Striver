// #include <bits/stdc++.h> 
// /************************************************************

//     Following is the TreeNode class structure

//     template <typename T>
//     class TreeNode {
//        public:
//         T val;
//         TreeNode<T> *left;
//         TreeNode<T> *right;

//         TreeNode(T val) {
//             this->val = val;
//             left = NULL;
//             right = NULL;
//         }
//     };

// ************************************************************/

// int getMaxWidth(TreeNode<int> *root)
// {
//     // Write your code here.
//     if (!root){
//         return 0;
//     }
//     int ans = 0;
//     queue<pair<TreeNode<int> *, int>>q;

//     q.push({root, 0});
//     while (!q.empty()){
//         int size = q.size();
//         int currMin = q.front().second;
//         int leftMost, rightMost;
//         for (int i=0;i<size;i++){
//             int curr_id = q.front().second-currMin;// to prevent over flow 
//             TreeNode<int> *temp = q.front().first;
//             q.pop();
//             if (i==0){
//                 leftMost = curr_id;
//             }
//             if (i==size-1){
//                 rightMost = curr_id;
//             }
//             if (temp->left){
//                 q.push({temp->left,curr_id*2+1});
//             }
//             if (temp->right){
//                 q.push({temp->right,curr_id*2+2});
//             }

//         }
//         ans = max(ans, rightMost - leftMost + 1);
//     }
//     return ans;
// }

#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int n = q.size();
        cnt = max(cnt, n);
        
        for(int i = 0; i < n; i++){
            TreeNode<int> *tmp = q.front();
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
    }
    
    return cnt;
    
}
