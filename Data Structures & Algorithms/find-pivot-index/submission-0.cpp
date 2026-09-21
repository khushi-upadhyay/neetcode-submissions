class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left =0, right =0;
        int n = nums.size();
        int total =0;
        for(int i =0; i < n; i++){
            total += nums[i];
        }
        for(int i =0; i < n ; i++){
            right = total - left - nums[i];
            if(right == left)
            return i;

        else left += nums[i];
        }

        return -1;
        
    }
};


// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11


// nums left = 1+7+3
// nums right = 5+6
// num pivot = 6 that is index = 3

// total = 28 => l + r + pivot
// l = total - r- pivot 