void inorder(BinaryTreeNode<int>* root,vector<int> &v)
{
    if(root==NULL)
    {
        return ;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);

}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	
    vector<int> v;
    inorder(root,v);
    int i=0;
    int j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]>target)
        {
            j--;
        }
        else if(v[i]+v[j]<target)
        {
            i++;
        }
        else if(v[i]+v[j]==target)
        {
          return true;
        }
    }
    return false;
}
