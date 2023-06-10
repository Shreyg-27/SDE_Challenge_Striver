#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if (root==NULL){
        return -1;
    }
    if (root->val==X){
        return root->val;
    }
    if (root->val>X){
        floorInBST(root->left, X);
    }
    else{
        int floor = floorInBST(root->right,X);
        return (floor <= X && floor != -1) ? floor
                                               : root->val;
    }
}
