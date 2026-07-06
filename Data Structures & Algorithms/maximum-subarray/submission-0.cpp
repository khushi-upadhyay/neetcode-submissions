class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0];
        int currsum = 0;
        for(int i = 0; i < nums.size(); i++){
            currsum = max(currsum, 0);
            currsum += nums[i];
            mx = max(currsum, mx);
        }
        return mx;
    }
};
