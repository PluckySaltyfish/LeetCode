//状态记录，一次遍历
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(),flag = 0,len = 1,max_len = 1;
        if(n == 1)return 1;
        for(int i = 1;i < n; ++i){
            if(arr[i] == arr[i-1]){
                flag = 0;
                len = 1;
            }
            else {
                if(flag==0||((arr[i]-arr[i-1])^flag)< 0)//异或判断两个数符号是否相等
                    len++;
                else len = 2;
                flag = arr[i]-arr[i-1];
                max_len = max(len,max_len);
            }
        }
        return max_len;
    }
};

//O(1)空间的DP，分别用两个dp记录以i结尾上升，下降湍流数组的长度，互相辅助更新
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(),ans = 1,dp1 = 1,dp2 = 1;
        for(int i = 1;i < n; ++i){
            if(arr[i] == arr[i-1]){
                dp1 = dp2 = 1;
            }
            else if(arr[i] > arr[i-1]){
                dp2 = dp1 + 1;
                dp1 = 1;
                ans = max(ans,dp2);
            }
            else{
                dp1 = dp2 + 1;
                dp2 = 1;
                ans = max(ans,dp1);
            } 
        }
        return ans;
    }
};
