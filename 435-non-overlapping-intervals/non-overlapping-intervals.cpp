class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // Check for overlap with last selected interval
            if (currStart < ans.back()[1]) {
                continue;  // overlap, skip this interval
            } else {
                ans.push_back(intervals[i]);  // no overlap, add it
            }
        }

        return intervals.size() - ans.size();  // number of intervals to remove
    }
};
