class Solution {
public:
    int fib(int n) {
        int dp[31] = {0,1};
        for(int i = 2;i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};