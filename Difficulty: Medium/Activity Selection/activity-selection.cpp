class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});}
        sort(activities.begin(), activities.end());
        int count = 0;
        int lastFinish = -1;
        for (auto &activity : activities) {
            int finishTime = activity.first;
            int startTime = activity.second;
            if (startTime > lastFinish) {
                count++;
                lastFinish = finishTime;
            }
        }
        return count;
    }
};