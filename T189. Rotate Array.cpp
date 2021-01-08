class Solution {
public:
    void reverse(int s,int e,vector<int>& num){
        for(int i = s;i <= s+(e-s-1)/2;i++){
            swap(num[i],num[e+s-i]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(0,n-1,nums);
        reverse(0,k-1,nums);
        reverse(k,n-1,nums);

    }
};