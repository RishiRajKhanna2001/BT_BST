 pair<int,int> dia(Node* root)
    {
        // base case
        if(root==NULL)
        {
            pair<int,int> p= make_pair(0,0); // represent diameter and height 
            return p;        
        }
        
        pair<int,int> left=dia(root->left);
        pair<int,int> right=dia(root->right);  
        
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        
        return ans;
        
    }
    
    int diameter(Node* root) {
        return dia(root).first;
    }

    /// method 2
        
    int height(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        
        return max(left,right)+1;
        
    }
    int diameter(Node* root) {
        // Your code here
        //base case
        if(root==NULL)
        {
            return 0;
        }
        
        int pa1=diameter(root->left);
        int pa2=diameter(root->right);
        int pa3=height(root->left)+height(root->right)+1;
        
        return max(pa1,max(pa2,pa3));
        
    }