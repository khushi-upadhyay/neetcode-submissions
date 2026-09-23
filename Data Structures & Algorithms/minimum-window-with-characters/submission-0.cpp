class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        // If t is larger than s, it is impossible to find a window
        if(n > m) return "";

        unordered_map<char, int> mp;

        // Stores the size of the smallest valid window found
        int minWindowSize = INT_MAX;

        // Number of characters from t that are still required
        int requiredCount = n;

        // i = left pointer, j = right pointer
        // start_i stores where the best window starts
        int start_i = 0, i = 0, j = 0;

        // Store the frequency of every character required from t
        for(auto x : t)
            mp[x]++;

        // Expand the window using j
        while(j < m) {

            char ch = s[j];

            // If this character was still needed,
            // we have now found one required character
            if(mp[ch] > 0) {
                requiredCount--;
            }

            // Decrease its frequency.
            // It can become negative if we have extra copies.
            mp[ch]--;

            // When requiredCount becomes 0,
            // the current window contains all characters of t
            while(requiredCount == 0) {

                // Calculate current window size
                int currentWindow = j - i + 1;

                // Update the smallest window found so far
                if(minWindowSize > currentWindow) {
                    minWindowSize = currentWindow;
                    start_i = i;
                }

                // Remove the character at the left side
                // because we are trying to shrink the window
                mp[s[i]]++;

                // If its frequency becomes positive,
                // we just removed a required character
                if(mp[s[i]] > 0) {
                    requiredCount++;
                }

                // Move left pointer forward
                i++;
            }

            // Expand the window to the right
            j++;
        }

        // If no valid window was found, return ""
        // Otherwise return the smallest window
        return minWindowSize == INT_MAX
            ? ""
            : s.substr(start_i, minWindowSize);
    }
};