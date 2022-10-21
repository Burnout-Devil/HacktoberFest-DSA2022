  // Tabulation
        class Solution {
        public:
            int longestCommonSubsequence(string s1, string s2) {
                int n = s1.size();
                int m = s2.size();
                vector<vector<int>> dp(n+1,vector<int> (m+1,0));
                
                for(int i =0;i<=n;i++){
                    for(int j=0;j<=m;j++){
                        if(i == 0 or j == 0) dp[i][j] = 0;
                        else{
                            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                        }
                    }
                }
                
                return dp[n][m];
            }
        };
