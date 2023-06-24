#include<bits/stdc++.h>

TreeNode<int>* func(vector<int>& inOrder, int inS, int inE, vector<int>& postOrder, int postS, int postE, map<int, int>& mp){
     if(inS>inE || postS>postE) return nullptr;
     TreeNode<int>* root = new TreeNode<int>(postOrder[postE]);
     int inRoot = mp[root->data];
     int nElm = inRoot - inS;
     root->left = func(inOrder, inS, inRoot-1, postOrder, postS, postS+nElm-1, mp);
     root->right = func(inOrder, inRoot+1, inE, postOrder, postS+nElm, postE-1, mp);
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     map<int, int> mp;
     for(int i=0;i<inOrder.size();i++)
          mp[inOrder[i]] = i;
     
     return func(inOrder, 0, inOrder.size()-1, postOrder, 0, postOrder.size()-1, mp);
}
