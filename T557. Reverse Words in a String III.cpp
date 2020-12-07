class Solution {
public:
    string reverseWords(string s) {
        int st = 0,ed = 0,n = s.length();
        while(ed < n){
            if(s[ed] == ' '||ed == n - 1){
                int p1 = st,p2 = ed == n - 1 ? ed :ed - 1;
                while(p1 < p2){
                    swap(s[p1],s[p2]);
                    p1++;
                    p2--;
                }
                st = ed + 1;
            }
            ed++;
        }
        return s;
    }
};