class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 1,n = s.length();
        while(i < n && s[i-1] <= s[i])
            i++;
        if(i == n)return N;
        while(i > 0 && s[i-1] > s[i]){
            s[i-1] -= 1;
            i--;
        }
        for(++i;i < n; ++i){
            s[i] = '9';
        }
        return stoi(s);
    }
};