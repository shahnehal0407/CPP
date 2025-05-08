class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int a = mat.size();
        int b = mat[0].size();
        int left = 0;
        int right = b - 1;
        vector<int> ans;

        while (left <= right) {
            int mid = (left + right) / 2;
            int max_row = 0;

            for (int i = 0; i < a; i++) {
                if (mat[i][mid] > mat[max_row][mid]) max_row = i;
            }

            int left_neigh=0;
            int right_neigh=0;
            if(mid>0)left_neigh=mat[max_row][mid-1];
            else left_neigh=-1;
            if(mid<b-1) right_neigh= mat[max_row][mid+1];
            else right_neigh=-1;

            if (mat[max_row][mid] > left_neigh && mat[max_row][mid] > right_neigh) {
                ans.push_back(max_row);
                ans.push_back(mid);
                break;
            }
            else if (left_neigh > mat[max_row][mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
