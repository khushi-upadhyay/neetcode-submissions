class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProd(n) , suffixProd(n), res(n);
        prefixProd[0] = 1; // Initialize prefix product as 1 because there are no elements to the left of the first element
        for(int i = 1; i < n ; i++) {
            prefixProd[i] = nums[i-1] * prefixProd[i-1]; 
        }
        suffixProd[n-1] = 1; // Initialize suffix product as 1 because there are no elements to the right of the last element
        for(int j = n-2; j >= 0; j--){
            suffixProd[j] = nums[j+1]* suffixProd[j+1]; // because we are multiplying the current element with the suffix product of the next element
        }
        for(int i = 0 ; i < n ; i++){
            res[i] = prefixProd[i]*suffixProd[i];
        }
        return res;

    }
};



//  using prefix product and suffix product 
// prefix product 
// p[0] = 1
// p[i] = p[i-1] * a[i-1]
// suffix 
// s[n-1] = 1
// s[j] = s[j+1] * a[j+1]
