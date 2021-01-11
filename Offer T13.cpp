class Solution {
public:
    int sum_bit(int x){
        int ans = 0;
        while(x != 0){
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int movingCount(int m, int n, int k) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ans = 1;
        dp[0][0] = 1;
        for(int i = 0;i < m; ++i){
            for(int j = 0;j < n; ++j){
                if((i == 0 && j == 0) || sum_bit(i)+sum_bit(j) > k)
                    continue;
                if(i >= 1)dp[i][j] |= dp[i-1][j];
                if(j >= 1)dp[i][j] |= dp[i][j-1];
                if(dp[i][j])ans++;
            }
        }
        return ans;
    }
};