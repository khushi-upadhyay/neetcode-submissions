class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++){

            if(s[i] != ']')
                st.push(s[i]);

            else{
                string curr = "";

                // get string inside []
                while(st.top() != '['){
                    curr += st.top();
                    st.pop();
                }

                // remove '['
                st.pop();

                string k = "";

                // get number before [
                while(!st.empty() && isdigit(st.top())){
                    k += st.top();
                    st.pop();
                }

                // reverse because stack gives it backwards
                reverse(curr.begin(), curr.end());
                reverse(k.begin(), k.end());

                int num = stoi(k);

                string temp = "";

                for(int j = 0; j < num; j++){
                    temp += curr;
                }

                // push decoded string back into stack
                for(char c : temp){
                    st.push(c);
                }
            }
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};