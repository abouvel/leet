class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()); // Max pile size
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            // Calculate hours needed at speed `mid`
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid; // Equivalent to ceil(pile / mid)
            }

            if (hours > h) {
                left = mid + 1;  // Too slow, need to eat faster
            } else {
                result = mid;    // Try slower speeds
                right = mid - 1;
            }
        }

        return result;
    }
};
