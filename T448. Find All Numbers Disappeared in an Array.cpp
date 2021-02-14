//交换数字
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int left = 0;
        while(left < nums.size()){
            if(nums[left]==0||nums[left]==left+1)
                left++;
            else{
                if(nums[nums[left]-1] == nums[left])
                    nums[left] = 0;
                else swap(nums[left],nums[nums[left]-1]);
            }
        }
        for(int i = 0;i < nums.size(); ++i){
            if(nums[i] == 0)
                ans.emplace_back(i+1);
        }
        return ans;
    }
};
//给index+n
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0;i < nums.size(); ++i){
            int x = (nums[i]-1) % n;//这里是还原成原来的数，不能给x-1，会越界
            nums[x] += n;
        }
        for(int i = 0;i < nums.size(); ++i){
            if(nums[i] <= n)
                ans.emplace_back(i+1);
        }
        return ans;
    }
};