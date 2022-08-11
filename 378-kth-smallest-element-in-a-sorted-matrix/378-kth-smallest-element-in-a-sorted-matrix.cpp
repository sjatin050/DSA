

class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int n=mat.size(),m=mat[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        //unordered_map<long long int,int> mp;
        pq.push({mat[0][0],0,0}); // val, i , j
        vis[0][0]=1;
        int ans;
        while(k--)
        {
            auto ele=pq.top();
            pq.pop();
            
            ans=ele[0];
            int i=ele[1];
            int j=ele[2];
            if(i+1<n && vis[i+1][j]==0)
            {
                //cout<<mat[i+1][j]<<"\n";
                pq.push({mat[i+1][j],i+1,j});
                vis[i+1][j]=1;
            }
            if(j+1<m && vis[i][j+1]==0)
            {
                //cout<<mat[i+1][j]<<"\n";
                pq.push({mat[i][j+1],i,j+1});
                vis[i][j+1]=1;
            }
        }
        return ans;
    }
};