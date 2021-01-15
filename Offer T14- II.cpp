class Solution {
public:
    long long bigmod(int x){
        long long ans = 1;
        while(x--){
            ans = (ans * 3)%1000000007;
        }
        return ans%1000000007;
    }
    int cuttingRope(int n) {
        if(n <= 3)return n - 1;
        int x = n / 3;
        int y = n % 3;
        if(y == 0)return bigmod(x);
        if(y == 1)return (bigmod(x-1) * 4)%1000000007;
        return (bigmod(x) * 2)%1000000007;
    }
};