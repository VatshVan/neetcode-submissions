class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long time = 0;
            for (int x : piles) time += (x + mid - 1) / mid;
            if (time <= h) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
};