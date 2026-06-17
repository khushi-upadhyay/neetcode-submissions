class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto i : nums){
            mp[i]++;
        }

        for(auto i: mp){
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> result;
        while(!minHeap.empty()){ 
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};


// create map 
// min heap in pair 
// push map in heap -> freq first then num till k else pop
// push min heap top into vector and pop it 