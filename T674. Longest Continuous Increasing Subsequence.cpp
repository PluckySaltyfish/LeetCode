class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        int cnt = 1,ans = 1;
        for(int i = 1;i < n; ++i){
            if(nums[i] > nums[i-1]){
                cnt++;
                ans = max(ans,cnt);
            }
            else
                cnt = 1;
        }
        return ans;
    }
};
