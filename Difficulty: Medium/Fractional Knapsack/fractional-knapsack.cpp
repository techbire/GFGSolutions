class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, pair<int, int>>> items;

        for (int i = 0; i < val.size(); i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }

        sort(items.rbegin(), items.rend());

        double profit = 0;

        for (auto &item : items) {
            int value = item.second.first;
            int weight = item.second.second;

            if (capacity >= weight) {
                profit += value;
                capacity -= weight;
            } else {
                profit += (double)capacity * value / weight;
                break;
            }
        }

        return profit;
    }
};