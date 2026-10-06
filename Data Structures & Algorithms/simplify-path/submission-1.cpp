class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        for(int i = 0; i < path.size(); i++){
            string s = "";

            // skip /
            if(path[i] == '/') continue;

            // push directory name in stack
            while(i < path.size() && path[i] != '/'){
                s += path[i];
                i++;
            }

            if(s == ".." ){
                if(!st.empty()) st.pop();
            }            

            else if(s == ".")
                continue;

            else
                st.push(s);
        }

        string ans = "";

        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans.empty()){
            return "/";
        }

        return ans;
    }
};