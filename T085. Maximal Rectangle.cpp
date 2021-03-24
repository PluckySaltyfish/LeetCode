class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(!row)return 0;
        int col = matrix[0].size();
        vector<int>h(col + 1,0);
        int ans = 0;
        for(int i = 0;i < row; ++i){
            vector<int>mono;
            mono.emplace_back(-1);
            for(int j = 0;j < col; ++j){
                if(matrix[i][j] == '1')
                    h[j] += 1;
                else
                    h[j] = 0;
            }
            int j = 0;
            while(j < h.size()){
                if(mono.size() > 1 && h[j] < h[mono.back()]){
                    int back = mono.back();
                    mono.pop_back();
                    ans = max(ans,h[back]*(j - mono.back() - 1));
                }
                else{
                    mono.emplace_back(j);
                    j++;
                }
            }
        }
        return ans;
    }
};