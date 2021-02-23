class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>s;
        int ans = 0;
        for(int i = 0; i < height.size(); ++i){
            while(!s.empty() && height[i] > height[s.back()]){
                int back = s.back();
                s.pop_back();
                if (s.empty()) break;
                ans += (min(height[i],height[s.back()]) - height[back])*(i - s.back() - 1);
            }
            s.emplace_back(i);
        }
        return ans;
    }
};