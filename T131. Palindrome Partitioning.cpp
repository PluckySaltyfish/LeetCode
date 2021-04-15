//动态规划算出来每一对是不是回文串

class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<int>>dp;
    vector<string>ans0;
    void dfs(string &s,int pos){
        if(pos == s.length()){
            ans.emplace_back(ans0);
            return;
        }
        for(int i = pos;i < s.length(); ++i){
            if(dp[pos][i]){
                ans0.emplace_back(s.substr(pos,i-pos+1));
                dfs(s,i+1);
                ans0.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp.assign(n,vector<int>(n,1));
        for(int i = n - 1; i >= 0; --i){
            for(int j = i+1; j < n; ++j){
                if(s[i]!=s[j] || dp[i+1][j-1] == 0)
                    dp[i][j] = 0;
            }
        }
        dfs(s,0);
        return ans;
    }
};