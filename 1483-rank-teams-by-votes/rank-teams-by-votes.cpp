#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return "";

        int m = votes[0].size();  // number of teams / positions

        // Map from team char to vector of counts per position
        unordered_map<char, vector<int>> counts;
        for (char c : votes[0]) {
            counts[c] = vector<int>(m, 0);
        }

        // Fill counts
        for (const string &vote : votes) {
            for (int i = 0; i < m; ++i) {
                char team = vote[i];
                counts[team][i]++;
            }
        }

        // Extract all teams into a vector
        string teams = votes[0];  // contains all teams exactly once

        // Sort with custom comparator
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            // Compare position by position
            for (int i = 0; i < m; ++i) {
                if (counts[a][i] != counts[b][i]) {
                    // Higher count at this position should come earlier
                    return counts[a][i] > counts[b][i];
                }
            }
            // All counts equal -> alphabetical order
            return a < b;
        });

        return teams;
    }
};
