vector verticleOrder(Node* root)
{
    vector<int> final;
    if(root==NULL)
    {
        return NULL;
    }
    map<int,map<int,vector<int>>> ans;
    queue<pair<Node*,pair<int,int>>> q; // hd= horizontal distance , l=level;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty())
    {
        pair<Node*,pair<int,int>> firstp=q.front();
        q.pop();
        Node* firstNode=firstp.first;
        int hd=firstp.second.first;
        int l=firstp.second.second;
        ans[hd][l].push_back(firstNode->data);
        if(firstNode->left)
        {
            q.push(make_pair(firstNode->left,make_pair(hd-1,l+1)));
        }
        if(firstNode->right)
        {
            q.push(make_pair(firstNode->right,make_pair(hd+1,l+1)));
        }
    }
    for(auto i:ans)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                final.push_back(k);
            }
        }
    }
    return ans;
}

