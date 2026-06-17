class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0, R= 1, maxp = 0;
        while(R<prices.size()){
            if(prices[R]>prices[L]){
                int p = prices[R] - prices[L];
                maxp = max(maxp, p);
            }
            else L = R;
            R++;
        }
        return maxp;  
    }
};