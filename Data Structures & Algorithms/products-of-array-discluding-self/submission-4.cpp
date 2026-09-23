class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long Pr = 1;
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) cnt++;
            else Pr *= nums[i];
        }
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){ 
            if(cnt > 0){
                if(nums[i] == 0 && cnt == 1) ans[i] = Pr;
                else ans[i] = 0;
            }
            else ans[i] = Pr/nums[i];
        }
        return ans;
    }
};
