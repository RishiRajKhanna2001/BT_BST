vector<int> zigzag(Node* root) // zig-zag print 
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> temp;
        for(int i=0;i<size;i++)
        {
           int index=leftToRight?i:size-i-1; // using bool 
           Node* dumm=q.front;
           q.pop();
           temp[i]=dumm->data;
           if(dumm->left)
           {
            q.push(dumm->left);
           }
           if(dumm->right)
           {
            q.push(dumm->right);
           }
        }
        for(auto i:temp)
        {
            ans.push(i);
        }
    }
    return ans;
} 



