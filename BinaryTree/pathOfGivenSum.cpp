#include<iostream>
using namespace std;

void countPath(Node* root,vector<int> path,int &count,int k)
{
    if(root==NULL)
    {
        return ;
    }
    path.push(root->data);
    countPath(root->left,path,count);
    countPath(root->right,path,count);
    
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--)
    {
        sum+=path[i];
        if(sum==k)
        {
            count++;
        }
    }
    path.pop();
}


// int main()
// {
//     vector<int> v;
//     v.push_back(10);
//     while(int i=0;i<v.length();i++)
//     {
//         cout<<v[i]<<" ";
//     }
// }


