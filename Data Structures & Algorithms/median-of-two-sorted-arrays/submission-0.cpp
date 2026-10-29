class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums = nums1;
        for(int i = 0; i < nums2.size(); i++){
            nums.push_back(nums2[i]);
        }
        sort(nums.begin(), nums.end());
        double median = 0;
        for(int i = 0; i < nums.size(); i++){
            cout<< nums[i]<<endl;
        }
        if(nums.size() % 2 == 0){
            median = nums[(nums.size()-1)/2] + nums[nums.size()/2];
            median =  median/2;

        }
        else {
            median = nums[nums.size()/2] ;
        }
        return median;
       
    }
};