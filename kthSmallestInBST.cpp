#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// void inorder(TreeNode<int>* root, int &k, int &ans){
//     if (root==NULL){
//         return -1;
//     }
//     inorder(root->left, k, ans);
//     k--;
//     if (k==0){
//         int ans = root->data;
//         return;
//     }
//     inorder(root->right, k, ans);
// }

// int kthSmallest(TreeNode<int> *root, int k)
// {
// 	//	Write the code here.
//     int ans = -1;
//     inorder(root, k, ans);
//     return ans;
// }
void inorder(TreeNode<int>* root, int& k, int& element) {
	if (!root || k < 0) {
		return;
	}
	inorder(root -> left, k, element);
	--k;
	if (!k) {
		element = root -> data;
		return;
	}
	inorder(root -> right, k, element);
}
int kthSmallest(TreeNode<int> *root, int k) {
	int element;
	inorder(root, k, element);
	return element;
}
