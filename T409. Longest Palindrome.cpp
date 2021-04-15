class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>a;
        for(char c : s){
            a[c]++;
        }
        int cnt = 0;
        for(auto item : a){
            if(item.second&1){
                cnt++;
            }
        }
        cnt = cnt == 0 ? 0 : cnt - 1; 
        return s.length() - cnt;
    }
};