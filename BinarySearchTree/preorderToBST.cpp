BinaryTreeNode<int>* preorderBst(int min,int max,vector<int> &preorder,int &i)
{
    if(i>=preorder.size())
    {
        return NULL;
    }
    if(preorder[i]<min || preorder[i]>max)
    {
        return NULL; 
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[i++]);
    root->left=preorderBst(min,root->data,preorder,i);
    root->right=preorderBst(root->data,max,preorder,i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int min=INT_MIN;
    int max=INT_MAX;
    int i=0;
    return preorderBst(min,max,preorder,i);
}