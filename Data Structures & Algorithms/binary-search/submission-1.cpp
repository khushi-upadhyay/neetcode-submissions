class Solution {
public:
    int search(vector<int>& nums, int target) {
        int Left = 0, Right = nums.size()-1;
        while(Left <= Right){
            int mid = (Left+Right)/2;
            if(nums[mid] < target) Left = mid+1;
            else if(nums[mid] > target) Right = mid-1;
            else return mid;
        }
        return -1;
        
    }
};