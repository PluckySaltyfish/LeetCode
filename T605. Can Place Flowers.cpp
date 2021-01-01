class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int fn = flowerbed.size();
        for(int i = 0;i < fn; ++i){
            if(flowerbed[i]==0){
                if((i==0||flowerbed[i-1]==0)&&((i==fn-1)||flowerbed[i+1]==0)){
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
        }
        return cnt>=n;
    }
};