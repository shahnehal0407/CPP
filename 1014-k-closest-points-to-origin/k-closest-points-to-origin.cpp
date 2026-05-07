class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, vector<vector<int>>> mp;
        vector<int> distances;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            mp[dist].push_back(points[i]);
            distances.push_back(dist);
        }

        sort(distances.begin(), distances.end());

        vector<vector<int>> ans;

        for (int i = 0; i < distances.size(); i++) {
            int dist = distances[i];

            while (!mp[dist].empty() && ans.size() < k) {
                ans.push_back(mp[dist].back());
                mp[dist].pop_back();
            }

            if (ans.size() == k) {
                break;
            }
        }

        return ans;
    }
};