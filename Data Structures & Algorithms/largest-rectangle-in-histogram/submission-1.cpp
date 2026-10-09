
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), mx = 0;

        // Store {starting index, height} in increasing height order
        stack<pair<int,int>> st;

        for(int i = 0; i < n; i++){
            int start = i;

            // If current height is smaller, calculate areas
            // for taller bars and remove them from the stack
            while(!st.empty() && heights[i] < st.top().second){
                int area = st.top().second * (i - st.top().first);
                mx = max(mx, area);

                // Extend the current bar to the popped bar's start
                start = st.top().first;
                st.pop();
            }

            // Store the earliest starting index and current height
            st.push({start, heights[i]});
        }

        // Calculate areas for remaining bars using n as right boundary
        while(!st.empty()) {
            int area = st.top().second * (n - st.top().first);
            mx = max(mx, area);
            st.pop();
        }

        return mx;  // Return the maximum rectangle area
    }
};
