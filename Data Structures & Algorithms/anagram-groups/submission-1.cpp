class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(auto x : strs ){ // store in map 
         string s = x; // keeping s and x differently s is sorted string and x is anagram
         sort(s.begin(), s.end());
         mp[s].push_back(x); // pushing the vector of ["ate","eat","tea"] (original string)
        
    }
    vector<vector<string>> ans;
    for(auto x : mp){
        ans.push_back(x.second);
    }
    return ans;
    }
};





// make a map and in that store sorted string and vector of anagram 
// eg for sorted string ate store eat, tea , ate 
// then push the vector in ans vector 
// and keep unordered map 
// x = "eat"

// s = x = "eat"

// sort(s) → "aet"

// mp["aet"].push_back("eat")

// ✅ mp = { "aet": ["eat"] }

