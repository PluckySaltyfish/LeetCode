class Solution {
public:
    vector<int>par,rk;
    int find(int x){
        if(x == par[x])
            return x;
        else return par[x] = find(par[x]);
    }
    void unite_f(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(rk[x] > rk[y])
            par[y] = x;
        else{
            par[x] = y;
            if(rk[x] == rk[y])rk[x]++;
        }
    } k  
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>>m1;
        par.resize(n);
        rk.resize(n);
        for(int i = 0;i < n; ++i){
            par[i] = i;
            rk[i] = 1;
        }
        for(auto i : pairs)
            unite_f(i[0],i[1]);
        string ans = "";
        for(int i = 0;i < n; ++i){
            int g = find(i);
            if(!m1.count(g))m1[g] = priority_queue<char,vector<char>,greater<char>>();
            m1[g].push(s[i]);
        }
        for(int i = 0;i < n; ++i){
            int g = find(i);
            ans += m1[g].top();
            m1[g].pop();
        }
        return ans;
    }
};