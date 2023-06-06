#include <bits/stdc++.h> 
// /************************************************************

//     Following is the TreeNode class structure:

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

// vector<int> getTopView(TreeNode<int> *root) {
//     // Write your code here.
//     // first node of every line will be my top view 
//     // TC - O(N), SC - O(N)
//     vector<int> ans;
//     if (root==NULL){
//         return ans;
//     }
//     map<int,int> mpp;// the first stores the line and second - node value 
//     queue<pair<TreeNode<int>*,int>> q;
//     q.push({root,0});
//     while (!q.empty()){
//         auto it = q.front();
//         q.pop();
//         TreeNode<int> *node = it.first;
//         int line = it.second;
//         // if the line is not found we will have to add it to the 
//         if (mpp.find(line)==mpp.end()){
//             mpp[line] = node->val;
//         }
//         if (node->left!=NULL){
//             q.push({root->left, line-1});
//         }
//         if (node->right!=NULL){
//             q.push({root->right, line+1});
//         }
//     }
//     for (auto it : mpp){
//         ans.push_back(it.second);
//     }
//     return ans;

// }
vector<int> getTopView(TreeNode<int> *root) {
    //level order traversal, only deviation from vertical needs to be considered.
    vector<int> ans;
    if(!root) return ans;
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int sz=q.size();
        for(int i=0 ; i<sz ; i++){
            auto node=q.front().first;
            int line=q.front().second;
            if(mp[line]==0) mp[line]=node->val;
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
            q.pop();
        }
    }
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}
