class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        map<char, int> mp1;
        for(auto i : s1) mp1[i]++;

        for(int i = 0; i < m - n + 1; i++){
            map<char, int> mp2;
            for(int j = i; j < i + n; j++) {
                mp2[s2[j]]++;
            }

            if(mp1 == mp2) return true;
        }
        return false;
        
    }
};