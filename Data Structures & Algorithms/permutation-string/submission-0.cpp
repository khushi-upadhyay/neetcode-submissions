class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){return false;}
        map<char,int> mp1;
        int n = s1.size();
        for (auto x : s1) mp1[x]++;
        for (int i = 0; i <= s2.size() - n; i++) {
            map<char,int> mp2;
            string substringS2 = s2.substr(i, n);
            for (auto x : substringS2) mp2[x]++;
            if (mp1 == mp2) return true;
        }
        return false;
    }
};