//User function Template for C++

class Solution {
  public:
  Node* nodeToParent(Node* root,int target,map<Node*,Node*> &parentToMap)
  {
     Node* res=NULL;
     
     // now doing level order traversal
     queue<Node*> q;
     q.push(root);
     parentToMap[root]=NULL;
     while(!q.empty())
     {
         Node* temp=q.front();
         q.pop();
         
         if(temp->data==target)
         {
             res=temp;
         }
         
         if(temp->left)
         {
             parentToMap[temp->left]=temp;
             q.push(temp->left);
         }
         
         if(temp->right)
         {
             parentToMap[temp->right]=temp;
             q.push(temp->right);
         }
         
         
     }
     return res;
  }
  
  int findtime(map<Node*,Node*> parentMap,Node* targetNode)
  {
      int ans=0;
      map<Node*,bool>visited;
      queue<Node*> q;
      q.push(targetNode);
      bool flag=false;  // to check ki queue me add hua ya nhi
      
      while(!q.empty())
      {

          int size=q.size();
          
          for(int i=0;i<size;i++)
          {
              Node* temp=q.front();
              q.pop();
              if(temp->left && !visited[temp->left])
              {
                  flag=true;
                  q.push(temp->left);
                  visited[temp->left]=1;
              }
              if(temp->right && !visited[temp->right])
              {
                  flag=true;
                  q.push(temp->right);
                  visited[temp->right]=1;
              }
              if(parentMap[temp] && !visited[parentMap[temp]])
              {
                  flag=true;
                  q.push(parentMap[temp]);
                  visited[parentMap[temp]]=1;
              }
          }
          if(flag)
          {
          ans++;
          }
      }
      ans-=1;
      return ans;
      
  }
  
    int minTime(Node* root, int target) 
    {
        // find target
        // do mapping of nodes with their parent
        // find time , using a level order traversal ans a stack containg status of node i.e. burnt or not
        map<Node*,Node*> parentMap;
        Node* targetNode=nodeToParent(root,target,parentMap);
        int ans= findtime(parentMap,targetNode);
        return ans<0?0:  ans;
    }
};