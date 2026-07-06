class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> updatedEle(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            int mx = -1;
            for (int j = i + 1; j < arr.size(); ++j) {
                mx = max(arr[j], mx);
            }
            updatedEle[i] = mx;
        }
        return updatedEle;
    }
};