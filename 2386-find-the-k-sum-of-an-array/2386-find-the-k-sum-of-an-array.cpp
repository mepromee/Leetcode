class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long mxSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) mxSum += nums[i];
            else nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin(), nums.end());
        
        priority_queue<pair<long long,int>> pq;
        pq.push({-nums[0],0});
        k--;
        
        long long ans = mxSum;
        
        while(k--) {
            auto p = pq.top();
            pq.pop();
            
            long long num = -p.first;
            int id = p.second;
            
            if(id+1 < nums.size()) {
                pq.push({-(num + nums[id+1]), id+1});
                pq.push({-(num - nums[id] + nums[id+1]), id+1});
            }
            
            ans = min(ans, mxSum - num);
        }
        
        return ans;
    }
};
/*
11:56
12:03
*/