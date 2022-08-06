class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void fun(vector<int>& a, int x, int lo) 
    {
        if (x == 0) 
        {
            ans.push_back(temp);
            return;
        }
        for (int i = lo; i < a.size(); ++i) 
        {
            int it = a[i];
            // if value is more then x
            if (it > x) 
            return;
            temp.push_back(it);
            fun(a, x - it, i);
            temp.pop_back();// backtracking
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int x) 
    {
          sort(a.begin(), a.end());
        // removing all duplicate elemets
        // int n = unique(a.begin(), a.end()) - a.begin();
        // a.resize(n);
        a.erase(unique(a.begin(), a.end()), a.end());
        ans.clear();
        temp.clear();
        fun(a, x, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};