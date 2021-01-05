class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans;
        int cnt = 1,n = s.length();
        for(int i = 1;i < n; ++i){
            if(s[i]!=s[i-1]){
                if(cnt>=3)ans.emplace_back(vector<int>{i-cnt,i-1});
                cnt = 1;
            }
            else cnt++;
        }
        if(cnt>=3)ans.emplace_back(vector<int>{n-cnt,n-1});
        return ans;
    }
};