class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0,right = 0,cost = 0;
        while(right < s.length()){
            cost += abs(s[right] - t[right]);
            if(cost > maxCost){
                cost -= abs(s[left] - t[left]);
                left++;
            }
            right++;
        }
        return right - left;
    }
};