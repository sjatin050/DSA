class Solution {
public:
    bool validPartition(vector<int>& nums) 
    {
        int n = nums.size();
		vector<int> dp(n,-1);
        return helper(nums, dp, 0, n);
    }
      
    bool helper(vector<int> &arr, vector<int> &dp, int start_indx, int n)
    {
        if(start_indx >= n)
            return true;
        
        if(dp[start_indx] != -1)
            return dp[start_indx];
      
        if(start_indx + 1 < n && arr[start_indx] == arr[start_indx + 1])
        {
            bool ans1=false,ans2=false;
			ans1= helper(arr, dp, start_indx + 2, n);
			
            if(start_indx + 2 < n && arr[start_indx] == arr[start_indx +2])
            {
				ans2 = helper(arr, dp, start_indx + 3, n);
				
            }
            
            return dp[start_indx]=ans1||ans2;
        }
        
 
        if(start_indx + 2 < n && arr[start_indx + 1] - arr[start_indx] == 1 && arr[start_indx+2] - arr[start_indx] == 2)
        {
            return dp[start_indx] = helper(arr, dp, start_indx+3, n);
           
        }
        
        return dp[start_indx] = false;
    } 
};