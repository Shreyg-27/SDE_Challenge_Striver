#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int dfs(BinaryTreeNode<int>* root){
    if (root==NULL){
        return 0;
    }
    int leftHeight = dfs(root->left);
    if (leftHeight==-1){
        return -1;
    }
    int rightHeight = dfs(root->right);
    if (rightHeight==-1){
        return -1;
    }
    if (abs(leftHeight-rightHeight)>1){
        return -1;
    }
    return 1 + max(leftHeight, rightHeight);

}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return dfs(root)!=-1;
}
