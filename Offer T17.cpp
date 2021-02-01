class Solution {
public:
    vector<int> printNumbers(int n) {
        long long num = 0;
        vector<int>ans;
        while(n--)num = num * 10 + 9;
        for(int i = 1;i <= num; ++i)
            ans.emplace_back(i);
        return ans;
    }
};
//大数
class Solution {
public:
    vector<string>ans;
    void dfs(int x,int &n,string num){
        if(x==n){
            if(num.length())ans.emplace_back(num);
            return;
        }
        for(int i = 0;i < 10; ++i){
            if(i==0&&num.length()==0)
                dfs(x+1,n,num);
            else{
                char pos = '0' + i ;
                dfs(x+1,n,num + pos);
            }
        }
    }
    vector<string> printNumbers(int n) {
        dfs(0,n,"");
        return ans;
    }
};