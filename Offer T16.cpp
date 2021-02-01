class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long num = n;
        if(num < 0){
            x = 1 / x;
            num = -num; 
        }g
        while(num){
            if(num & 1)res *= x;
            x *= x;
            num >>= 1;
        }
        return res;
    }
};