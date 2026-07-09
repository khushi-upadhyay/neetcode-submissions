class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        n = n/3;
        map<int, int>mp;
        for(auto x: nums){
            mp[x]++;
        }
        vector<int>v;
        for(auto x: mp){
            if(x.second > n){
                v.push_back(x.first);
            }
        }
        return v;
        
    }
};