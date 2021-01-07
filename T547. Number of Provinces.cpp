class Solution {
public:
    int par[201];//分组信息
    int rk[201];//每一组树的深度
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);//查询一次后直接连到根结点上
        }
    }

    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x==y)return;
        if(rk[x]<rk[y]){
            //如果x的深度比y小，x连到y下
            par[x] = y;
        }else{
            //如果x的深度比y大，y连到x下
            par[y] = x;
            if(rk[x]==rk[y])rk[x]++;
            //同深度相连，深度会增加
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n ; ++i) {
            par[i] = i;
            rk[i] = 0;
        }
        for(int i = 0;i < n; ++i){
            for(int j = 0;j < n; ++j){
                if(isConnected[i][j])
                    unite(i,j);
            }
        }
        set<int>prov;
        for(int i = 0;i < n; ++i){
            prov.insert(find(i));
        }
        return prov.size();
    }
};