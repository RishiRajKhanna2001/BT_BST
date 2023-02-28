void maxSumAndLength(Node* root,int &maxLength,int length,int sum,int &maxSum)
{
    if(root==NULL)
    {
        if(length>maxLength)
        {
            maxLength=length;
            maxSum=max(sum,maxSum);
        }
        else if(length==maxLength)
        {
            maxSum=max(sum,maxSum);
        }
        return;
    }
    sum+=root->data;

    maxSumAndLength(root->left,maxLength,length+1,maxSum,sum);
    maxSumAndLength(root->right,maxLength,length+1,maxSum,sum);
}

// int main()
// {
//     Node* root==NULL; // given
//     int sum=0;
//     int maxSum=0;

//     int length=0;
//     int maxLength=0;
//     maxSumAndLength()
// }