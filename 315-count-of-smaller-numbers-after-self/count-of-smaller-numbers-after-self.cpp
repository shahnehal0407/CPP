#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); // store indices [0,1,2,...]

        mergeSort(nums, indices, 0, n - 1, res);
        return res;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& indices, int left, int right, vector<int>& res) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, indices, left, mid, res);
        mergeSort(nums, indices, mid + 1, right, res);

        merge(nums, indices, left, mid, right, res);
    }

    void merge(vector<int>& nums, vector<int>& indices, int left, int mid, int right, vector<int>& res) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (nums[indices[j]] < nums[indices[i]]) {
                // right element is smaller → contributes to count
                rightCount++;
                temp[k++] = indices[j++];
            } else {
                res[indices[i]] += rightCount;
                temp[k++] = indices[i++];
            }
        }

        while (i <= mid) {
            res[indices[i]] += rightCount;
            temp[k++] = indices[i++];
        }

        while (j <= right) {
            temp[k++] = indices[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            indices[left + p] = temp[p];
        }
    }
};
