class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto i: nums){mp[i]++;}
        for(auto value : mp){
            if(value.second > 1) return true;
        }

        return false;
        
    }
};