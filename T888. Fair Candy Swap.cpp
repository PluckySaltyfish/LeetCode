class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0,sumB = 0;
        unordered_set<int>hashset;
        for(auto i : A){
            sumA += i;
            hashset.insert(i);
        }
        for(auto i : B)sumB += i;
        int diff = (sumA - sumB) >> 1;
        for(auto i : B){
            if(hashset.count(diff + i))
                return {diff + i,i};
        }
        return {};
    }
};