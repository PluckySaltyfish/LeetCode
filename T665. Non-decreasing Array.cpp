class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int k = 1,n = nums.size();
        for(int i = 0;i < n - 1; ++i){
            if(nums[i] > nums[i+1]){
                if(!k)return false;
                k--;
                if(i > 0 && i < n - 2){
                    if(nums[i-1] <= nums[i+1])
                        nums[i] = nums[i+1];
                    else{
                        nums[i+1] = nums[i];
                    }
                }
            }
        }
        return true;
    }
};