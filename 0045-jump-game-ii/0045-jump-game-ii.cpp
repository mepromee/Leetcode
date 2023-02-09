class Solution {
public:
    int jump(vector<int>& arr) {
        if(arr.size()==1) return 0;
	    int reach = arr[0], mx=0;
	    int jump = 1;
	    for(int i = 0; i<arr.size();i++) {
		    if(reach >= arr.size()-1) break;
		    if(i<=reach){
			    mx = max(mx,i+arr[i]);
		    }
		    if(i==reach) {
                reach = mx;
                jump++;
		    }
	    }
        return jump;
    }
};