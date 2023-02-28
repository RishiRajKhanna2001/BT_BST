vector<int> bottomView(Node* root)
{
    vector<int> ans;
    map<int,int> mp;
    if(root==NULL)
    {
        return ans;
    }

    queue<pair<Node*,int>> q;
    q.push_back(make_pair(root,0));

    while(!q.empty())
    {
      Node* firstPair=q.front();
      q.pop();
      Node* frontn=firstPair.first;
      int hd=firstPair.second;
    
      mp[hd]=frontn->data;
       
      if(frontn->left)
      {
        q.push(make_pair(root,hd-1));
      }
      if(frontn->right)
      {
        q.push(make_pair(root,hd+1));
      }

    }

    for(auto i:mp)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;

}