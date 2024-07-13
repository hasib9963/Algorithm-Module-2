#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, temp, left, mid);
            mergeSort(nums, temp, mid + 1, right);
            merge(nums, temp, left, mid, right);
        }
    }

    void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        int i = left;    // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = left;    // Starting index to merge into temp array

        // Merge the two halves into the temp array
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Copy the remaining elements of left subarray, if any
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        // Copy the remaining elements of right subarray, if any
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // Copy the merged elements back to the original array
        for (i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }
    }
};