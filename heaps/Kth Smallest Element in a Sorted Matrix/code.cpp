class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        // {value, row, column}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > minHeap;

        // Put first element of every row
        for (int row = 0; row < n; row++) {
            minHeap.push({matrix[row][0], row, 0});
        }

        while (k--) {

            auto [value, row, col] = minHeap.top();
            minHeap.pop();

            // Add next element from same row
            if (col + 1 < n) {
                minHeap.push({
                    matrix[row][col + 1],
                    row,
                    col + 1
                });
            }

            if (k == 0) {
                return value;
            }
        }

        return -1;
    }
};