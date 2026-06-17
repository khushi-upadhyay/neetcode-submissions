class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 0;
        sort(nums.begin(),nums.end());
         int count = 1;
         if(nums.size() ==0) return 0;
        for(int i=0; i < nums.size()-1; i++)
        { 
           if (nums[i] != nums[i+1]) { 
            if(nums[i]+1 == nums[i+1]) count++;
            else {
                maxi = max(maxi,count);
                count =1;
            }
            
        } }
          maxi = max(count,maxi);  
        return maxi;
         }
    
   
    
};