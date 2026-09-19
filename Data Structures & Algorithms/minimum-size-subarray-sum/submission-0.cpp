class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int minLength = INT_MAX;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                minLength = min(j - i +1, minLength);
                sum = sum - nums[i];
                i++;
            }
            j++; 
    }
    return minLength == INT_MAX ? 0 : minLength;
}
};