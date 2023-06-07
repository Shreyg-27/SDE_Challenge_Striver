#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// long long int findMax(TreeNode<int> *root, int &maxi){
//     // base case 
//     if (root==NULL){
//         return 0;
//     }
//     int leftMax = findMax(root->left, maxi);
//     int rightMax =findMax(root->right, maxi);

//     int value = root->val;
//     maxi = max(maxi, leftMax+rightMax+value);
//     return max(leftMax, rightMax) + value;
// }

// long long int findMaxSumPath(TreeNode<int> *root)
// {
//     // Write your code here.
//     long long int maxi = INT_MIN;
//     if (root==NULL){
//         return -1;
//     }
//     findMax(root, maxi);
//     if (root->left ==NULL || root->right==NULL){
//         return -1;
//     }
//     return maxi;
// }

int solve(TreeNode<int>* root,int &maxi){

// maxi is be reference so that it can store new values

    if(root==NULL)return 0;

    int lefty=solve(root->left,maxi);

    int righty=solve(root->right,maxi);

    maxi=max(maxi,lefty+righty+root->val);

    return max(lefty,righty)+root->val;

}

long long int findMaxSumPath(TreeNode<int> *root)

{

    int maxi=0;

    if(root==NULL)return -1;

    solve(root,maxi);

    if(root->left==NULL||root->right==NULL)return -1;

    return maxi;

    // Write your code here.

}
