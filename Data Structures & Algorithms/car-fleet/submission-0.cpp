class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>v;
        for(int i = 0; i < position.size(); i++ ){
            v.push_back({position[i], speed[i]});
        }

        sort(v.rbegin(), v.rend());

        stack<double>st;
        for( auto& x: v){
            double time = (target - x.first)/ double(x.second);
            if(st.empty() || time > st.top()) st.push(time);
        }

        return st.size();
    }
};

// ## 1. Store Position and Speed


// v.push_back({position[i], speed[i]});

// Each pair stores:
// {position, speed}

// 2. Sort Cars by Position
// sort(v.rbegin(), v.rend());

// Sort from:
// Closest to target → Farthest from target

// We process the front car first.
// 3. Calculate Time to Reach Target
// double time = (target - x.first) / double(x.second);

// Formula
// time = distance / speed

// Where:
// distance = target - position
// speed = x.second

// So:
// time = (target - position) / speed

// 4. Check if It Creates a New Fleet
// if(st.empty() || time > st.top())
//     st.push(time);

// st.top() = time taken by the fleet ahead.
// Case 1: time > st.top()
// The current car takes longer to reach the target.
// So it cannot catch the fleet ahead.
// Therefore, it creates a new fleet.
// Current car = 5 sec
// Fleet ahead = 3 sec

// 5 > 3 → New fleet

// Case 2: time <= st.top()
// The current car will catch the fleet ahead.
// So it becomes part of the same fleet.
// Current car = 2 sec
// Fleet ahead = 3 sec

// 2 <= 3 → Same fleet

// We don't push it into the stack.
// 5. Why st.size()?
// Every time we push into the stack, we have found a new fleet.
// Therefore:
// return st.size();

// gives the total number of fleets.
// ⭐ Main Idea
// Calculate the time each car takes to reach the target.
// - time > st.top() → New fleet
// - time <= st.top() → Joins existing fleet
// The stack stores the time of each fleet.