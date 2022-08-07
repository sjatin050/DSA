class Solution {
public:
    int mod = 1e9+7;
    // we need to find without mod
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
    {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1)
            return 0;
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        //dp[0][1] = 1;
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0]==0)
            dp[i][0]=1;
            else
                break;
        }
            
        
        for(int i=0;i<n;i++)
        {
            if(!obstacleGrid[0][i])
                dp[0][i]=!obstacleGrid[0][i];
            else
                break;
        }
            
        for(int i = 1 ; i <m ; ++i)
        {
            for(int j = 1 ; j < n ; ++j)
            {
               if(!obstacleGrid[i][j])
                    dp[i][j] = (dp[i-1][j]+dp[i][j-1]);
                
                //cout<<dp[i][j]<<" ";
            }
            //cout<<"\n";
                
        }
            
        return dp[m-1][n-1];
    }
};