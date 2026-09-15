class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int left = j+1, right = n-1;
                long long sum =  nums[i] + nums[j]; // for overflow
                while(left < right){
                    if(sum + nums[left] + nums[right] < target) left++; // // for overflow not adding directly to sum 
                    else if(sum + nums[left] + nums[right]> target) right--;
                    else{
                        v.insert({ nums[i], nums[j], nums[left], nums[right]});
                        right--;
                        left++;
                    }
                }
            }
        }

        vector<vector<int>>vec;
        for(auto x:v ){
            vec.push_back(x);
        }
        return vec;
    }
};