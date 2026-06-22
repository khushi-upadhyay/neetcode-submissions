class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mp;
         for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans;
        for(auto x: mp){
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second > nums.size()/2){
                ans = x.first;
            }
        }
        return ans;
    }
};