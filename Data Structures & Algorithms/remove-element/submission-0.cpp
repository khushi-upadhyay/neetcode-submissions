class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> removed;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] != val){
                removed.push_back(nums[i]);
                

            }
        }
        for(int i = 0; i < removed.size(); i++){
            nums[i] = removed[i];
            cout<<"print" << removed[i]<< endl;
        }
        return removed.size();
        
    }
};