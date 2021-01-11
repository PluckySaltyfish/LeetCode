class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,int idx,int x,int y){
        if(board[x][y] == word[idx]){
            if(idx == word.length()-1)return true;
            board[x][y] = '#';
            int offsets[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto offset : offsets){
                int x0 = x + offset[0];
                int y0 = y + offset[1];
                if(x0>=0&&x0<board.size()&&y0>=0&&y0<board[0].size()&&board[x0][y0]!='#')
                    if(dfs(board,word,idx+1,x0,y0))return true;
            }
            board[x][y] = word[idx];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i < board.size(); i++){
            for(int j = 0;j < board[0].size(); j++){
                if(dfs(board,word,0,i,j))return true;
            }
        }
        return false;
    }
};