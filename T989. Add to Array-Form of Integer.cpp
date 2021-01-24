class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int p = 0,cnt = 0,n = A.size();
        vector<int>ans;
        while(K){
            int s = K % 10 + p;
            K /= 10;
            if(n-1-cnt >= 0)s += A[n-1-cnt];
            ans.emplace_back(s % 10);
            p = s/10;
            cnt++;
        }
        while(cnt < n){
            int s = A[n-1-cnt] + p;
            ans.emplace_back(s%10);
            p = s / 10;
            cnt++;
        }
        if(p)ans.emplace_back(p);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//也可以将K直接加到最后一位，然后依次整除