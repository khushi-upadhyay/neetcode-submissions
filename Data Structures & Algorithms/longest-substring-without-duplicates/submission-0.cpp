class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
         int mx = 0;
        
        int l = 0;
        for(int r =0; r< s.size(); r++){
            mp[s[r]]++;   // insert in map

            while(mp[s[r]]>1) // value greater than 1
             {
                mp[s[l]]--; // remove from mp
                l++;

            }
           
            mx = max(mx, r-l+1) ;

        }
        return mx;
    }
};
