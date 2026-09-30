class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int ans = 0;
        for(auto i: tokens){
            if(i == "+"){
               int x = st.top();
                st.pop();
               int y = st.top();
                st.pop();
                ans = x+y;
                st.push(ans);
            }
            else if(i == "-"){
               int x = st.top();
                st.pop();
               int y = st.top();
                st.pop();
                ans = y-x;
                st.push(ans);
            }
            else if(i == "*"){
               int x = st.top();
                st.pop();
               int y = st.top();
                st.pop();
                ans = x*y;
                st.push(ans);
            }
            else if(i == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                ans = y/x;
                st.push(ans);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
        
    }
};