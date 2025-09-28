#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    std::pair<size_t, size_t> maxPos(0, 0);

    size_t n = matrix.size();
    size_t k = matrix[0].size();

    int maxNum = matrix[0][0];

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            if (matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
                maxPos = {i, j};
            }
        }
    }

    return maxPos;
}