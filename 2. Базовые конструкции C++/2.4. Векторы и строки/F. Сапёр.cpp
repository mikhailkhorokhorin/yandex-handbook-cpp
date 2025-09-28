#include <iostream>
#include <vector>

int main() {
    int m, n, k;
    std::cin >> m >> n >> k;

    std::vector<std::vector<int>> field(m, std::vector<int>(n, 0));
    std::vector<std::pair<int, int>> mines(k);

    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;

        x--;
        y--;

        mines[i] = {x, y};
        field[x][y] = -1;
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (auto [x, y] : mines) {
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] != -1) {
                field[nx][ny]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] == -1)
                std::cout << "*";
            else
                std::cout << field[i][j];

            if (j + 1 < n)
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}