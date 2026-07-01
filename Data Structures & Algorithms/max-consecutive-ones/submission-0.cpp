class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int count = 0;
        int mx = 0;
        while (i < nums.size()) {
            if (nums[i] == 1) {
                count++;

            }

            else {
                count = 0;
            }
            mx = max(count, mx);
            i++;
        }
        return mx;
    }
};