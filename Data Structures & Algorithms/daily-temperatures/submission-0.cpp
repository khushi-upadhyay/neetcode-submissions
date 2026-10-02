class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        st.push(n -1);
        int i = n -2;
        vector<int>ans(n);
        ans[n-1] = 0;
 
        while(i >= 0){
            while( !st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            st.push(i);
            if(st.size() == 1) {
                ans[i] = 0;
            }
            i--;
        }
        return ans;
    }
};