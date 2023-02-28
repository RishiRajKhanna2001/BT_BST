// method 1

void inorder(TreeNode<int>* root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

vector<int> mergv(vector<int> &v1,vector<int> &v2)
{
  vector<int> merge(v1.size()+v2.size());

  int i=0;
  int j=0;
  int k=0;
  while(i<v1.size() && j<v2.size())
  {
      if(v1[i]>v2[j])
      {
          merge[k++]=(v2[j++]);
      }
      if(v1[i]<v2[j])
      {
          merge[k++]=(v1[i++]);
      }
  }
  while(i<v1.size())
  {
     merge[k++]=(v1[i++]);
  }
  while(j<v2.size())
  {
     merge[k++]=(v2[j++]);   
  }
  return merge;
}


TreeNode<int>* inorderToBst(vector<int> &v,int s,int e)
{
if(s>e)
{
    return NULL;
}
int mid=(s+e)/2;
TreeNode<int> *root=new TreeNode<int>(v[mid]);
root->left=inorderToBst(v,s,mid-1);
root->right=inorderToBst(v,mid+1,e);
return root;
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> bst1;
    vector<int> bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    vector<int> merge=mergv(bst1,bst2);
    return inorderToBst(merge,0,merge.size()-1);
}

// method 2
