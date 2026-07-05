class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> newnums;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val)
                continue;
            else {
                newnums.push_back(nums[i]);
            }
        }

        nums = newnums;
        return nums.size();
    }
};