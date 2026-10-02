class StockSpanner {
    stack<int> st;  
    vector<int> prices;
    int i = 0;

public:
    int next(int price) {
        prices.push_back(price);

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int ans;

        if (st.empty())
            ans = i + 1;
        else
            ans = i - st.top();

        st.push(i);
        i++;

        return ans;
    }
};