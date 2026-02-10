class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1, high = *max_element(arr.begin(), arr.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hrs = calc(arr, mid);

            if (hrs <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

    long long calc(vector<int>& arr, int speed) {
        long long hrs = 0;
        for (int x : arr)
            hrs += (x + speed - 1) / speed; // ceil(x/speed)
        return hrs;
    }
};
