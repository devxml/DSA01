class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        vector<int> ans{-1, -1};

        // First occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans[0] = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            } 
        }

        // Reset
        start = 0;
        end = nums.size() - 1;

        // Last occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans[1] = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};