class FreqStack {
private:
    vector<int> v;                  // Stores elements in the order they were pushed
    unordered_map<int, int> mp;     // Stores frequency of each element

public:
    FreqStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);           // Add the value to the end
        mp[val]++;                  // Increase its frequency
    }
    
    int pop() {
        int mx = 0;

        // Find the maximum frequency among all elements
        for(auto x : mp){
            if(x.second > mx) 
                mx = x.second;
        }

        // Start from the most recently pushed element
        int i = v.size() - 1;

        // Move backwards until we find an element
        // having the maximum frequency
        while(mp[v[i]] != mx) 
            i--;

        // This is the element we need to remove
        int val = v[i];

        // Remove it from the vector
        v.erase(v.begin() + i);

        // Decrease its frequency
        mp[val]--;

        return val;
    }
};