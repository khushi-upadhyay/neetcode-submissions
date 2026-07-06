class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            int mx = 0;
            for(int j = i+1; j < arr.size(); j++){
                arr[i] = arr[j];
                mx = max(arr[i], mx);
                arr[i] = mx;
            }
            
        }
        arr[arr.size()-1] = -1;
        return arr;
        
    }
};