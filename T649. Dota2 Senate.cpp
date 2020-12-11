class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>D,R;
        int n = senate.size();
        for(int i = 0;i < n; ++i){
            if(senate[i]=='D')D.push(i);
            else R.push(i);
        }
        while(!D.empty()&&!R.empty()){
            int d = D.front(),r = R.front();
            D.pop();
            R.pop();
            if(d < r)
                D.push(d+n);
            else
                R.push(d+n);
        }
        if(D.empty())return "Radiant";
        return "Dire";
    }
};