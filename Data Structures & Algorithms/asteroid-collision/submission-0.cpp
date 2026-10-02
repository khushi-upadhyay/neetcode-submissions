class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int i = 0;
        while( i < asteroids.size()){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
                i++;
            }
            else if( asteroids[i]< 0){
                while(!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top() ){
                    st.pop();
                }
                if(st.empty() || st.top() < 0) st.push(asteroids[i]);
                else if( abs(asteroids[i]) == st.top()){
                    st.pop();
                }
                i++;
            }
            else {
                st.pop();
                i++;
            }
        }
        int n = st.size();
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            v[(n - 1) - i] = st.top();
            st.pop();
        }

        return v;
        
    }
};