class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3)return n - 1;
        else{
            int x = n / 3;
            int y = n % 3;
            if(y == 0)return pow(3,x);
            if(y == 1)return pow(3,x-1) * 4;
            return pow(3,x) * 2;
        }
    }
};
//推导 计算极大值可以算出，每段长e最大