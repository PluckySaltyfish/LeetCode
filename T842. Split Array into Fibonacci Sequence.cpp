class Solution {
public:
    vector<int>ans;
    bool traceback(string &S,int pos){
        if(pos == S.length())
            return ans.size()>=3;
        long long num = 0;
        for(int i = pos;i < S.length(); ++i){
            if(i > pos && S[pos] == '0')break;
            num = num * 10 + (S[i] - '0');
            if(num > INT_MAX)break;
            if(ans.size() >= 2){
                long long sum = 0;
                sum = sum + ans[ans.size()-1] + ans[ans.size()-2];
                if(num < sum)
                    continue;
                else if(num > sum)
                    break;
            }
            ans.emplace_back(num);
            if(traceback(S,i+1))
                return true;
            ans.pop_back();
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) {
        traceback(S,0);
        return ans;
    }
};