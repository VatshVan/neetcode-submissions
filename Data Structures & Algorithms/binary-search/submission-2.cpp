class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() <= 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = nums.size();
        while(l <= r){
            int mid = (l+r)/2;
            // cout << mid << endl;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};
