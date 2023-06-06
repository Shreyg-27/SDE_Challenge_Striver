vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);

        }
    }
    return ans;
}
