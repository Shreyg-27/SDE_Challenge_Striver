#include <bits/stdc++.h> 
// /************************************************************

//     Following is the TreeNode class structure

//     template <typename T>
//     class TreeNode {
//        public:
//         T data;
//         TreeNode<T> *left;
//         TreeNode<T> *right;

//         TreeNode(T data) {
//             this->data = data;
//             left = NULL;
//             right = NULL;
//         }
//     };

// ************************************************************/
// TreeNode<int> *helper(vector<int> &inorder,int inStart, int inEnd,
//  vector<int> &preorder, int preStart, int preEnd, map<int,int> mp){
//     if (preStart>preEnd || inStart>inEnd){
//         return NULL;
//     }

//     TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
//     int elem = mp[root->data];
//     int nElem = elem-inStart;
//     root->left = helper(inorder,inStart, elem-1, preorder, preStart+1, 
//     preStart+nElem,mp);
//     root->right = helper(inorder, elem+1, inEnd, preorder, preStart+nElem+1,
//     preEnd, mp);

//     return root;

//  }


// TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
// {
// 	//    Write your code here
//     int preStart = 0;
//     int preEnd = preorder.size()-1;
//     int inStart = 0;
//     int inEnd = inorder.size()-1;

//     map<int,int> mp;
//     for (int i=inStart;i<=inEnd;i++){
//         mp[inorder[i]] = i; 
//     }
//     return helper(inorder,inStart,inEnd,preorder,preStart,preEnd,mp);
// }


TreeNode<int> *buildIt(vector<int> &preorder, int preStart, int preEnd,
                  vector<int> &inorder, int inStart, int inEnd,
                  map<int, int> &inMap) {
  if (preStart > preEnd || inStart > inEnd)
    return NULL;

  TreeNode<int> *root =
      new TreeNode<int> (preorder[preStart]); // preorder---> ROOT Left Right
  int inRoot = inMap[root->data];
  int left = inRoot - inStart; // keep track of left elements
  root->left = buildIt(preorder, preStart + 1, preStart + left, inorder,
                       inStart, inRoot - 1, inMap);
  root->right = buildIt(preorder, preStart + left + 1, preEnd, inorder,
                        inRoot + 1, inEnd, inMap);
  return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
            map<int,int>mp;
        int n= preorder.size();
        int m = inorder.size();
        for(int i=0;i<m;i++) mp[inorder[i]] = i; //store index--
        return buildIt(preorder,0,n-1,inorder,0,m-1,mp);
    
}
