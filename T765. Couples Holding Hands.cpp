class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int map[60];
        for(int i = 0;i < row.size(); ++i)
            map[row[i]] = i;
        for(int i = 0;i < row.size() - 1;i += 2){
            if(row[i+1] != (row[i]^1)){
                map[row[i+1]] = map[(row[i]^1)];
                swap(row[i+1],row[map[(row[i]^1)]]);
                ans++;
            }
        }
        return ans;
    }
};
//并查集，算连通分量
class Solution {
public:
    int par[31] = {},rk[31] = {};
    int find(int x){
        if(x == par[x])
            return par[x];
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(rk[x] > rk[y]){
            par[y] = x; 
        }
        else{
            par[x] = y;
            if(rk[x] == rk[y])rk[y]++;
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int half = n / 2;
        int ans = 0;
        for(int i = 0;i < half; ++i)
            par[i] = i;
        for(int i = 0;i < n; i += 2)
            unite(row[i]/2,row[i+1]/2);
        unordered_map<int,int>m1;
        for(int i = 0;i < half; ++i){
            m1[find(i)]++;
        }
        for(auto it : m1)
            ans += it.second - 1;
        return ans;
    }
};