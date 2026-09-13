class Solution {
public:
    string mergeAlternately(string word1, string word2){
        int s1 = word1.size(), s2 = word2.size();
        string newword = "";
        if(s1 >= s2){
            for(int i = 0; i < s2; i++){
                newword += word1[i];
                newword += word2[i];

            }
             for(int j = s2; j < s1; j++){
            newword += word1[j];
        }
        }
        if(s1 < s2){
            for(int i = 0; i < s1; i++){
                newword += word1[i];
                newword += word2[i];

            }
        }
        for(int j = s1; j < s2; j++){
            newword += word2[j];
        }

     return newword;

    }
};