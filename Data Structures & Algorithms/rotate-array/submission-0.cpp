class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int>temp(nums.size()); // to store the new rotated array
        // for(int i = 0; i < nums.size() ; i++){
        //     temp[(i+k)% nums.size() ] = nums[i]; // storing vals to rotated index 
        // }
        // nums = temp;


        //  approach 2
        int n = nums.size();
        if (n <= 1) return;   // nothing to rotate

            k %= n;               // normalize k
            if (k == 0) return;   // no rotation needed

         reverse(nums.begin(),nums.begin()+(n -k));
         reverse(nums.begin()+(n-k), nums.end());
        reverse(nums.begin(),nums.end());
      

        
    }
};