int final(int intPart,int precision,int N)
{
    int factor=1;
    int ans=intPart;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(int j=0;j*j<N;i+=factor)
        {
            ans=j;
        }
    }
    return ans;
}
