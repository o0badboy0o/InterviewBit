bool isPal(string a,int l,int r)
{
    while(l<r)
    {
        if(a[l]!=a[r])
        {
            return false;
        }
        l++,r--;
    }
    return true;
}

int Solution::minCut(string a) 
{
    if(a.length()==1) return 0;
    if(isPal(a,0,a.length()-1)) return 0;
    vector<int> cuts(a.length(),INT_MAX);
    vector<vector<bool>> hash(a.length(),vector<bool>(a.length(),0));
    for(int i=0;i<a.length();i++)
    {
        for(int j=i;j<a.length();j++)
        {
            if(isPal(a,i,j))
            {
                hash[i][j]=1;
            }
        }
    }
    for(int i=0;i<a.length();i++)
    {
        if(hash[0][i])
        {
            cuts[i]=0;
        }
        else
        {
            cuts[i]=cuts[i-1]+1;
            for(int j=0;j<i;j++)
            {
                if(hash[j][i] && cuts[j-1]+1<cuts[i])
                {
                    cuts[i]=cuts[j-1]+1;
                }
            }
        }
    }
    return cuts.back();
}