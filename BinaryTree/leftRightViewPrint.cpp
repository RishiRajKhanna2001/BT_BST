void leftView(Node* root,vector<int> ans,int level)
{
  if(root==NULL)
  {
    return ans;
  }

  if(level==ans.size())
  {
     ans.push_back(root);
  }

leftView(root->left,ans,level+1)
leftView(root->right,ans,level+1)
}
void rightView(Node* root,vector<int> ans,int level)
{
  if(root==NULL)
  {
    return ans;
  }

  if(level==ans.size())
  {
     ans.push_back(root);
  }

rightView(root->right,ans,level+1);
rightView(root->left,ans,level+1);
}
int main()
{
    Node* root//given


    int level=0;
    vector<int> ans;
    leftView(root,ans,level)
}