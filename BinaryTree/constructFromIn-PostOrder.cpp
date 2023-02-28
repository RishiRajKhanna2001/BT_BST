Node* solve(int in[],int start,int end,int post[],int &idx,int n)
{
  if(idx<0||start>end )
  {
      return NULL;
  }
  int ele=post[idx--];
  Node* root=new Node(ele);
  int pos;
  for(int i=0;i<n;i++)
  {
      if(in[i]==ele)
      {
          pos=i;
      }
  }
  
  root->right=solve(in,pos+1,end,post,idx,n); // bcz. left part pehle process ho rha hai har iteration me
  root->left=solve(in,start,pos-1,post,idx,n);
  return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIdx=n-1;
    Node* ans=solve(in,0,n-1,post,postIdx,n);
    return ans;
}
