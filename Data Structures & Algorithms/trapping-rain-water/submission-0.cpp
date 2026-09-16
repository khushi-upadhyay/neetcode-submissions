
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        // Store the maximum height seen from both sides
        int leftMax = height[left];
        int rightMax = height[right];

        int water = 0;

        while (left < right) {

            // Process the side with the smaller maximum height
            // Because the smaller boundary determines the water level
            if (leftMax <= rightMax) {
                left++;

                // Update the maximum height from the left
                leftMax = max(leftMax, height[left]);

                // Water trapped = leftMax - current height
                // leftMax is the limiting boundary because leftMax <= rightMax
                water += leftMax - height[left];
            }
            else {
                right--;

                // Update the maximum height from the right
                rightMax = max(rightMax, height[right]);

                // Water trapped = rightMax - current height
                // rightMax is the limiting boundary because rightMax < leftMax
                water += rightMax - height[right];
            }
        }

        // Return the total amount of trapped rainwater
        return water;
    }
};