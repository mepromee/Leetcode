class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
private:
    vector<int> temp;
    void mergeSort(int l, int r, vector<int>&nums) {
        if(l >= r) return;
        int mid = (l+r)/2;
        mergeSort(l, mid, nums);
        mergeSort(mid+1, r, nums);
        merge(l,r,nums);
    }
    
    void merge(int l, int r, vector<int>&nums) {
        int mid = (l+r)/2;
        temp.clear();
        int i = l, j = mid+1;

        while(i<=mid && j <=r) {
            if(nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                j++;
            }
            else {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= r) {
            temp.push_back(nums[j]);
            j++;
        }
        for(i = l; i <= r; i++) {
            nums[i] = temp[i-l];
        }
    }
};
/*
9:37

2 5 1 3
*/