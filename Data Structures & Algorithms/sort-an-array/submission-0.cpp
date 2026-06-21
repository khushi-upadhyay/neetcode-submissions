class Solution {
public:
    void mergeSort(vector<int> & nums, int low, int high){
        int mid = low + ((high-low)/2);
        if(low >= high) return ;
        mergeSort(nums, low, mid); //divide 
        mergeSort(nums, mid+1, high);//divide 
        merge(nums, low, mid, high);//merge

    }
    void merge(vector<int> & nums, int low, int mid, int high){
        vector<int> temp;
        int left = low; 
        int right = mid+1;
        while(left<=mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }

        }
        while(left<= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
      
    }

    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size() -1;
        mergeSort(nums, low, high);
        return nums;
        
        
    }
};