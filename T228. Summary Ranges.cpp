class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<string>ans;
        while(i < n){
            int s = i;
            int e = s;
            for(int j = i + 1;j < n; ++j){
                if(nums[j] != nums[e] + 1)
                    break;
                else
                    e = j;
            }
            if(s == e)ans.emplace_back(to_string(nums[s]));
            else ans.emplace_back(to_string(nums[s]) + "->" + to_string(nums[e]));
            i = e + 1;
        }
        return ans;
    }
};