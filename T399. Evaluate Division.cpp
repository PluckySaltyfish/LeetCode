class Solution {
public:
    int par[40];//分组信息
    double w[40];//每一组树的深度
    //初始化，每一个元素单独为一组
    int find(int x){
        if(x!=par[x]){
            int origin = par[x];
            par[x] = find(par[x]);
            w[x] *= w[origin];
        }
        return par[x];
    }
    
    void union_f(int x,int y,double value){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx==rooty)return;
        par[rootx] = rooty;
        w[rootx] = value * w[y] / w[x];
    }
    
    double connected(int x,int y){
        if(find(x) == find(y)){
            return w[x]/w[y];
        }
        else
            return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, int>m;
        int cnt = 0;
        vector<double>ans;
        for(int i=0;i<n;++i){
            string x = equations[i][0];
            string y = equations[i][1];
            if(!m.count(x)){
                m[x] = cnt;
                w[m[x]] = 1.0;
                par[m[x]] = cnt++;
            }
            if(!m.count(y)){
                m[y] = cnt;
                w[m[y]] = 1.0;
                par[m[y]] = cnt++;
            }
            union_f(m[x],m[y],values[i]);
        }
        for(int i=0;i<queries.size();++i){
            string x = queries[i][0];
            string y = queries[i][1];
            if(!m.count(x) || !m.count(y))
                ans.emplace_back(-1.0);
            else
                ans.emplace_back(connected(m[x],m[y]));
        }
        return ans;
    }
};