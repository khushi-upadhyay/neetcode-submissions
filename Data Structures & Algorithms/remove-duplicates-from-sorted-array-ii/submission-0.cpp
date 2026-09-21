class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == INT_MAX)
                continue;

            count = 1;
            sum++;

            int j = i + 1;

            while (j < nums.size() && nums[j] == nums[i]) {

                count++;

                if (count > 2) {
                    nums[j] = INT_MAX;
                }
                else {
                    sum++;
                }

                j++;
            }

            i = j - 1;
        }

        sort(nums.begin(), nums.end());

        return sum;
    }
};