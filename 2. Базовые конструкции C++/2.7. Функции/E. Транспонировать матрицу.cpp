#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    size_t m = matrix[0].size();

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            result[j][i] = matrix[i][j];

    return result;
}