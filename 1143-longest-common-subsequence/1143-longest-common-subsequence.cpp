class Solution {
public:
    int dp[1000+1][1001];
    
    int solve(string &str1,string &str2,int ind1,int ind2)
    {
        if(ind1<=0 || ind2<=0)
            return 0;
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(str1[ind1-1]==str2[ind2-1])
        return dp[ind1][ind2]=1+solve(str1,str2,ind1-1,ind2-1);
        else
        {
            return dp[ind1][ind2]=max(solve(str1,str2,ind1-1,ind2),solve(str1,str2,ind1,ind2-1));
        }
    }
    int longestCommonSubsequence(string str1, string str2) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(str1,str2,str1.size(),str2.size());
    }
};