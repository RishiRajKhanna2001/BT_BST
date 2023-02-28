// for every node X in the tree other than the leaves, it's value is equal to the sum of its left subtree's value and its right subtree's value

 pair<bool,int> isSum(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL)   // leaf nodes ke case me
        {
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }

        pair<bool,int> leftsum= isSum(root->left);
        pair<bool,int> rightsum= isSum(root->right);
        
        bool isleft=leftsum.first;
        bool isright=rightsum.first;
        bool val=root->data==leftsum.second+rightsum.second;
        
         pair<bool,int> ans;
         
        if(isleft && isright && val)
        {
          ans.first=true;
          ans.second=2*root->data;
        }
        else
        {
            ans.first=false;
        }
        return ans;
    }




    