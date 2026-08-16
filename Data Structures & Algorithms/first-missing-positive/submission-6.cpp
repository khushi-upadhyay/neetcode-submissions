class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        int smallest = 1;
        for (auto x : nums) {
            if (x > 0) {
                st.insert(x);
            }
        }
        for (auto x: st) {
            if (x != smallest) {
                return smallest;
            } else {
                smallest++;
            }
        }
        return smallest;
    }
};