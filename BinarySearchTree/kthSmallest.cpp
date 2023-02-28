int inorder(BinaryTreeNode<int>* root, int k,int &c)
{
    if(root==NULL)
    {
        return -1;
    }
    int left=inorder(root->left,k,c);
    if(left!=-1)
    {
        return left; 
    }
    c++;
    if(c==k)
    {
      return root->data;
    }
    return inorder(root->right,k,c);

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int c=0;
    int ans=inorder(root,k,c);
    return ans;
}