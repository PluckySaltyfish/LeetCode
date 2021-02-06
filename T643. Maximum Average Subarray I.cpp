class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0,ans = -32768;
        int left = 0,right = 0;
        while(right < nums.size()){
            cout << right << endl;
            sum += nums[right];
            if(right - left + 1 > k)
                sum -= nums[left++];
            if(right - left + 1 == k)
                ans = max(ans,sum/k);
            right++;
        }
        return ans;
    }
};
