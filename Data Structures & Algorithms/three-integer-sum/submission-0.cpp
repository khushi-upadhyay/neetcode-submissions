class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-2; i ++){ //dont have to go till last 2 as j,k will be there 
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    st.insert({nums[i],nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};