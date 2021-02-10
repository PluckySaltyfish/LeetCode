class Solution {
public:
    int maxLenofK(vector<int>& A, int K){
        int left =0,right = 0,n = A.size(),len = 0,ans = 0;
        unordered_map<int,int>m;
        while(right < n){
            if(m[A[right]] == 0)
                len++;
            m[A[right]]++;
            while(len > K){
                m[A[left]]--;
                if(!m[A[left]])len--;
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return maxLenofK(A,K) - maxLenofK(A,K-1);
    }
};