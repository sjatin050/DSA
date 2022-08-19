class Solution {
public:
   int minCostConnectPoints(vector<vector<int>>& ps) 
   {
        int n = ps.size(), res = 0, i = 0, connected = 1;
        vector<int> min_d(n, 1e9);
        while (connected < n) 
        {
            // taken i as int_max so that we dont consider it again
            // we are doing this to make it work as visited
            min_d[i] = INT_MAX;
            int min_j = i;
            for (int j = 0; j < n; j++)
            {
                if (min_d[j] != INT_MAX) 
                {
                    // taken manahatten distance
                    min_d[j] = min(min_d[j], abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]));
                    if(min_d[j] < min_d[min_j])
                    min_j = j ;
                }
            }
                
            res += min_d[min_j];
            i = min_j;
            connected++;
        }
        return res;
    }
};