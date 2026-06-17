class Solution {
public:
    int characterReplacement(string s, int k) {
        int Left = 0, maxCount = 0, maxLen = 0;
        unordered_map<char,int>freq;// unordered because we want fast access
        for(int Right = 0; Right < s.size(); Right++){
            freq[s[Right]]++; // push element in map
            maxCount = max(maxCount, freq[s[Right]]); // max freq of a char in the current window
            if (Right - Left + 1 - maxCount > k) { // if window size - max freq > k
                freq[s[Left]]--; // remove element going out of the window
                Left++; // shrink window from the left
            }
            maxLen = max(maxLen, Right - Left + 1); // window size
        }
        
        return maxLen;
    }
};