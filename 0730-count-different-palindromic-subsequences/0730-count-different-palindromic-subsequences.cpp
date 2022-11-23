class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int N = S.size();
        long MOD = 1e9 + 7;
        
        vector<vector<int>> T(N, vector<int>(N, 0));
        
        for (int i = 0; i < N; ++i)
            T[i][i] = 1;
        
        for (int gap = 2; gap <=N; ++gap) 
        {
            for (int i = 0;i<N-gap+1;++i) 
            {
                int j=i+gap-1;
                //Fill in T[i][j]
                if (S[i] != S[j]) 
                {
                    T[i][j] = T[i+1][j] + T[i][j-1] - T[i+1][j-1];
                } 
                else 
                {
                    // Si, Si+1, ..., Sj-1, Sj
                    // Si+1, ...., Sj-1
                    // we are doubling it beacause let string be ### and we are adding b from both side --> b###b
                    // so a new palindrom has added to each and every palindromic strings of ### 
                    // so we take --> noofpal(###)+ noofpal(b###b)= 2*noofpal(###)
                    
                    T[i][j] = 2 * T[i+1][j-1];
                    
                    // b and bb is not added so we further consider  3 more cases
                    int l = i+1, r = j-1;
                    while(l <= r && S[l] != S[i]) l++;
                    while(l <= r && S[r] != S[i]) r--;
                    // case1
                    if (l < r) {
                        // S(i, j) = b # # b . . b # # b where # != b
                        // removing T[l+1][r-1] because elements in range [l+1,r-1]--> b from left and b from right has already come and we have counted it double so we are removing it 
                        T[i][j] -= T[l+1][r-1];   
                    }
                    // case2
                    if (l == r) {
                        // S(i, j) = b # # b # # b where # != b
                        // add only bb , as single b has already come i.e. we add 1 only for bb
                        T[i][j] += 1;
                    }
                    // case3
                    if (l > r) {
                        // S(i, j) = b # # # b where # != b
                        // add b and bb i.e. we add 2 also
                        T[i][j] += 2;
                    }
                }
                T[i][j] = (T[i][j] + MOD)%MOD;
            }
        }
        // cout<<"  ";
        // for(int j=0;j<N;j++)
        //     cout<<j<<" ";
        // cout<<"\n";
        // for(int i=0;i<N;i++)
        // {
        //     cout<<i<<"-";
        //     for(int j=0;j<N;j++)
        //     {
        //         cout<<T[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return T[0][N-1];
    }
};