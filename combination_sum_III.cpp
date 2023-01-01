class Solution {
public:
void combine(int index,int k,int n,vector<int> object,vector<vector<int>> &ans,int temp)
{
   if(k==0)
   {
       if(n==0)
       {   
          ans.push_back(object);
       }
        return;
   }

   for(int i=index;i<=9;i++)
   {
       object.push_back(i);
       combine(i+1,k-1,n-i,object,ans,temp);
       object.pop_back();
   }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int index=1;
        int temp=n;
        vector<vector<int>> ans;
        vector<int> object;
        combine(index,k,n,object,ans,temp);
        return ans;

    }
};