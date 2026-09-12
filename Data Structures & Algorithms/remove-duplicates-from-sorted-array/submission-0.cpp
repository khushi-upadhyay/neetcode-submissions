class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto x: nums){
            st.insert(x);
        }
        nums.clear();
        vector<int>v;
          for(auto x: st){
           nums.push_back(x);
        }
        for(int i = 0; i < nums.size(); i++){
            cout<< nums[i];
        }
        return nums.size();
    }
};