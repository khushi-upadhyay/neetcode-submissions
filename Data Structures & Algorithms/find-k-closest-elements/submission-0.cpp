class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binary search in a window
        int l = 0, r = arr.size() - k; // to stay in bound 

        while (l < r){
            int m = (l+r)/2;
            // if right side array is closer 
            if( x - arr[m] > arr[m+k] - x) l = m+1;
            else r = m; // either eqaul or r side is greater case
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
        
    }
};
// Intuition

// We need to find k closest elements to x from a sorted array.

// Instead of directly finding all k elements, think:

// Where should the window of size k start?

// If the window starts at l, the answer is:

// arr[l ... l+k-1]

// So the possible starting positions are:

// 0, 1, 2, ..., n-k

// That's why we do:

// int l = 0, r = arr.size() - k;

// We binary search among these possible starting positions.

// Why compare arr[m] and arr[m+k]?

// Suppose our current window starts at m:

// arr[m] ........ arr[m+k-1]

// The two elements we care about are:

// arr[m]       → leftmost element of current window
// arr[m+k]     → element just outside the window on the right

// We compare their distances from x:

// x - arr[m]

// and

// arr[m+k] - x

// Because the array is sorted, this tells us whether shifting the window right would give us a better set of elements.

// If:
// x - arr[m] > arr[m+k] - x

// The right-side element is closer to x.

// So we should move the window right:

// l = m + 1;

// Otherwise, keep the left side:

// r = m;

// This also handles the equal case correctly because the problem prefers the smaller elements when distances are equal.

// Dry Run

// Let's take:

// arr = [1,2,3,4,5]
// k = 4
// x = 3

// Possible windows of size 4:

// [1,2,3,4]
// [2,3,4,5]

// So:

// l = 0
// r = 5 - 4 = 1
// Iteration 1
// l = 0
// r = 1

// m = (0 + 1) / 2
//   = 0

// Compare:

// x - arr[m]
// = 3 - arr[0]
// = 3 - 1
// = 2

// and:

// arr[m+k] - x
// = arr[4] - 3
// = 5 - 3
// = 2

// They are equal.

// So:

// else
//     r = m;

// Therefore:

// r = 0

// Now:

// l = 0
// r = 0

// Loop ends.

// We return:

// arr[0 ... 3]

// which is:

// [1,2,3,4]