class Solution {
public:
    // The intution is if we take and and or of two nos the  tot bits will be equal to the no of total bits in both nos
    typedef long long ll;
    int setbits(int n)
    {
        int cnt = 0;
        while(n){
            cnt += (n%2);
            n /= 2;
        }
        return cnt;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) 
    {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> v;
        for(auto& i: s){
            int x = setbits(i);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        
        ll ans = 0;
        for(int i=0;i<v.size();i++)
        { // we are just using the logic of if two nos have sum >=k
            // check for v[i]  how many nos have sum more than v[i]
            auto it = lower_bound(v.begin(),v.end(),k-v[i]);
            ans += (v.end()-it);
        }
        return ans;
        
    }
};