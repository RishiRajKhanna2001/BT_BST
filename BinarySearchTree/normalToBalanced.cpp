void inorder(TreeNode<int>* root,vector<int> &v)
    {
      if (root == NULL) {
        return;
      }
      inorder(root->left, v);
      v.push_back(root->data);
      inorder(root->right, v);
    }
    
TreeNode<int>* inorderToBst(int s,int e,vector<int> &v)
{
   if(s>e)
   {
     return NULL;
   }
   int mid=(s+e)/2;
   TreeNode<int>* newroot=new TreeNode<int>(v[mid]);
   newroot->left=inorderToBst(s,mid-1,v);
   newroot->right=inorderToBst(mid+1,e,v);
   return newroot;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
  vector<int> v;
  inorder(root,v);
  return inorderToBst(0,v.size()-1,v);
}
