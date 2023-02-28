Node* solve(Node* root,int k,int n)
{
    if(root==NULL )
    {
        return NULL;
    }
    if(root->data==n )
    {
        return root;      // ye condition check kar lena
    }
    
    Node* leftN=solve(root->left,k);
    Node* rightN=solve(root->right,k);

    if(leftN!=NULL && rightN==NULL)
    {
        k--;
        if(k=0)
        {
            k=INT_MAX;
            return root;
        }
        return leftN;
    }
    if(leftN==NULL && rightN!=NULL)
    {
        k--;
        if(k=0)
        {
            k=INT_MAX;
            return root;
        }
        return rightN;
    }
   
    return NULL;
}

