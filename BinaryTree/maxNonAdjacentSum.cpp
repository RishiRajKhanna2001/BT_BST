pair<int,int> maxNonAdjacent(Node* root) // first when niche choosen the and second when not choosen
{
    if(root==NULL)
    {
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> lPair=maxNonAdjacent(root->left);
    pair<int,int> rPair=maxNonAdjacent(root->right);

    pair<int,int> ans;
    ans.first=root->data+lPair.second+rPair.second;
    ans.second=max(lPair.first,lPair.second)+max(rPair.first,rPair.second);

    return ans;
}

int main()
{
    maxNonAdjacent(root);
    return max(ans.first,ans.second);
}


