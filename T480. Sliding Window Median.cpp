class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>window;
        vector<double>ans;
        int pos = 0;
        while(pos < nums.size()){
            window.insert(nums[pos]);
            if(window.size() > k){
                auto it = lower_bound(window.begin(),window.end(),nums[pos - k]);
                window.erase(it);
            }
            if(window.size() == k){
                if(k&1)ans.emplace_back(*next(window.begin(),k/2));
                else ans.emplace_back((*next(window.begin(),k/2)*1.0+*next(window.begin(),k/2-1))/2);
            }
            pos++;
        }
        return ans;
    }
};