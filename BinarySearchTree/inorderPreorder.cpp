pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp=root;
    int pre=-1;
    int succ=-1;

    while(temp->data!=key)
    {
        if(temp->data>key)
        {
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pre=temp->data;
            temp=temp->right;
        }
    }
    // predecessor
    BinaryTreeNode<int>* pred=temp->left;
    while(pred!=NULL)
    {
        pre=pred->data;
        pred=pred->right;
    }
    // successor
    BinaryTreeNode<int>* succe=temp->right;
    while(succe!=NULL)
    {
        succ=succe->data;
        succe=succe->left;
    }
    
     pair<int,int> ans=make_pair(pre,succ);

return ans;
}
