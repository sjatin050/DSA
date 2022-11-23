// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    // n--> eggs
    // k--> floors
    // T.C.--> O(floors^2 * eggs) ==
    int solve(int n,int k)
    {
        
        
        
        // if only one egg then we need to start from the base and go to the top
        if(n==1)
        return k;
        
        if(n>=2 && (k==0 || k==1))
        return k;
        
        if(dp[n][k]!=-1)
        return dp[n][k];
        int mini=INT_MAX;
        for(int i=1;i<=k;i++)
        {   
            // case 1: if egg breaks then consider its lower flowers {i-1}
            // case 2: if egg not break then consider its upper flowers {k-i}
            // we use max beacuse we need to find the worst case minimum no of attempts
            int temp=1+max(solve(n-1,i-1),solve(n,k-i));
            mini=min(mini,temp);
        }
        return dp[n][k]=mini;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends