class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k0;
    KthLargest(int k, vector<int>& nums) {
        k0 = k;
        for(auto num : nums){
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k0)
            pq.pop();
        return pq.top();
    }
};