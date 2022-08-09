class Solution {
public:
    long long numberOfWeeks(vector<int>& a) 
    {
       
        int n=a.size();
        long long ans=0;
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans+=a[i];
            maxi=max(maxi,(long long)a[i]);
        }
        ans-=maxi;
        if(maxi<=ans+1)
        {
            return maxi+ans;
        }
        else
        {
            return 2*ans+1;
        }
        
    }
};