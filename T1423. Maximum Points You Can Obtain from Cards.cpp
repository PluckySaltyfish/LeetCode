class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0,right = 0,sum = 0,total = 0,n = cardPoints.size();
        int min_sum;
        for(int i = 0;i < n - k; ++i)
            min_sum += cardPoints[i];
        while(right < n){
            total += cardPoints[right];
            sum += cardPoints[right];
            if(right - left + 1 > n - k)
                sum -= cardPoints[left++];
            if(right - left + 1 == n - k)
                min_sum = min(min_sum,sum);
            right++;
        }
        return total - min_sum;
    }
};