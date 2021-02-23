class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>s;
        s.emplace_back(-1);
        int i = 0,ans = 0;
        heights.emplace_back(0);
        while(i < heights.size()){
            if(s.back()==-1||heights[i] >= heights[s.back()]){
                s.emplace_back(i);
                i++;
            }
            else{
                int top = s.back();
                s.pop_back();
                int left = s.back();
                int right = i;
                ans = max(ans,heights[top] *(right - left - 1));
            }
        }
        return ans;
    }
};