class Solution {
public:
    // if I pass by reference the strings then T.C will become less
    int dp[1000+1][1001];
    string str1,str2;
    int solve(int ind1,int ind2)
    {
        if(ind1<=0 || ind2<=0)
            return 0;
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(str1[ind1-1]==str2[ind2-1])
        return dp[ind1][ind2]=1+solve(ind1-1,ind2-1);
        else
        {
            return dp[ind1][ind2]=max(solve(ind1-1,ind2),solve(ind1,ind2-1));
        }
    }
    int longestCommonSubsequence(string st1, string st2) 
    {
        memset(dp,-1,sizeof(dp));
        str1=st1;
        str2=st2;
        return solve(str1.size(),str2.size());
    }
};