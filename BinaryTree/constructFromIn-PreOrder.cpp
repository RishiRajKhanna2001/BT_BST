int find(int in[],int element,int n) // we can create a mapping instead, of the inorder elements with their index
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==element)
        {
            return i;
        }
    }
    return -1;
}
Node* solve(int in[],int start,int end,int pre[],int index,int n)
{
    if(index>=n || start>end)
    {
        return NULL;
    }
    int element=pre[index++];
    Node* root=new Node(element);
    int position=pos(in,n,element);
    for(int i=0;i<n;i++) // for finding position
    {
        if(in[i]==element)
        {
            position= i;
        }
    }
    root->left=solve(in,start,position-1,pre,index,n);
    root->right=solve(in,position+1,end,pre,index,n);
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
  // Code here
  int preOrderIdx=0;
  Node* ans=solve(in,0,n-1,pre,preOrderIdx,n);
  return ans;
}

