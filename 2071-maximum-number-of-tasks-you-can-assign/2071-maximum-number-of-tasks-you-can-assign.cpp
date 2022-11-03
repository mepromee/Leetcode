class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int l = 0, h = n-1, mid, ans = -1;
        while(l <= h) {
            mid = (l + h) / 2;
            if(canAssignAll(mid, tasks, workers, pills, strength)) {
                ans = mid;
                l = mid+1;
            }
            else {
                h = mid-1;
            }
        }
        
        return ans+1;
    }
private:
    bool canAssignAll(int x, vector<int>&tasks, vector<int>&workers, int pills, int strength) {
        multiset<int> st(workers.begin(), workers.end());
        bool possible = true;
        
        for(int i = x; i >=0 ; i--) {
            if(st.empty()) {
                possible = false;
                break;
            }
            auto it = st.end();
            it--;
            
            if(tasks[i] <= *it) {
                st.erase(st.find(*it));
            }
            else if(pills > 0) {
                it = st.lower_bound(tasks[i] - strength);
                if(it == st.end()) {
                    possible = false;
                    break;
                }
                
                st.erase(st.find(*it));
                pills--;
            }
            else {
                possible = false;
                break;
            }
        }
        
        return possible;
    }
};
    
/*
4:35

5 5 8 9 9
1 2 4 6 6
*/