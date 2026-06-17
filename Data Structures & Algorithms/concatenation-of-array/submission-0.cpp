class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = n; i < 2*n; i++){
            nums.push_back(nums[i-n]);
        }
    return nums;
    }
};