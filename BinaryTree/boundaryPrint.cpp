void printLeft(Node* root,vector<int> &ans)
{
    if((root==NULL)||(root->left==NULL && root->right==NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if(root->left)
    {
       printLeft(root->left);
    }
    else{
       printLeft(root->right);
    }
}

void printLeaf(Node* root,vector<int> &ans)
{
    if((root==NULL))
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    printLeaf(root->left);
    printLeaf(root->right);

}

void printRight(Node* root,vector<int> &ans)
{
    if((root==NULL)||(root->left==NULL && root->right==NULL))
    {
        return;
    }
    if(root->right)
    {
        printRight(root->right);
    }
    else
    {
        printRight(root->left);
    }
    
    ans.push_back(root->data);
}

vector<int> boundary(Node* root)
{
    vector<int> ans;

    if(root==NULL)
    {
        return ans;
    }
    
    ans.push_back(root->data);

    //first print root node
    //now print left row
    printLeft(root->left);

    //now print leaf nodes of leftsubtree
    printLeaf(root->left);
    //now print leaf nodes of rightsubtree
    printLeaf(root->right);

    //print right row in reverse
    printRight(root->right);
    return ans;
}