class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        vector<int>dp = vector<int>(n);
        dp[0] = nums[0];
        if(n > 1)dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
        return dp[n - 1];
    }
};