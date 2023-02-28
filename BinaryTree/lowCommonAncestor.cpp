Node* lowestCommonAnccesstor(Node* root,n1,n2)
{

    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }

    Node* leftNode=lowestCommonAnccesstor(root->left,n1,n2);
    Node* rightNode=lowestCommonAnccesstor(root->right,n1,n2);

    if(leftNode!=NULL && rightNode==NULL)
    {
        return leftNode;
    }
    else if(leftNode==NULL && rightNode!=NULL)
    {
        return rigthNode;
    }
    else if(leftNode==NULL && rightNode==NULL)
    {
        return root;
    }
    else{
        return NULL;
    }
    // make calls
}



