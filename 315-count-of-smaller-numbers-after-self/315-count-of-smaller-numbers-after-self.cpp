class Solution {
public:
   // we are sorting in decreasing ordeer
    void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while (i <= mid && j <= right) {
            
            if (v[i].first <= v[j].first) { 
                tmp[k++] = v[j++];
            }
            else {
                // aagr left array ka  vala element  bada hai right vale array ke elemnt  se ...to jitnme bhi right vale hai unhe count karo
                count[v[i].second] += right - j + 1;
                tmp[k++] = v[i++];
            }
        }
        // jo bach gaye unhe simply place kardoo
        while (i <= mid) {
            tmp[k++] = v[i++];
        }
        while (j <= right) {
            tmp[k++] = v[j++];
        }
        for (int i = left; i <= right; i++)
            v[i] = tmp[i-left];
    }        

    void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) 
    {
       if(left<right)
       {
            int mid = left + (right-left)/2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            merge(count, v, left, mid, right);
       }
       
    }

    vector<int> countSmaller(vector<int>& nums) 
    {
        int N = nums.size();
     // ye array banaya hai jis se me har ekarray elemnt ki pos ke according count bhar saku
        vector<pair<int, int> > v(N);
        for (int i = 0; i < N; i++)   
            v[i] = make_pair(nums[i], i);

        vector<int> count(N, 0);
        // sorting in descending order
        mergeSort(count, v, 0, N-1);
         // for(auto x:v)
        //     cout<<x.first<<" ";
        return count;
    }
};