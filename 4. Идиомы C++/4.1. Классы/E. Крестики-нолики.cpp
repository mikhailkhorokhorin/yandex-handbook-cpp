#include <iostream>
#include <vector>

class TicTacToe {
   public:
    const size_t N;
    const size_t K;

   private:
    std::vector<std::vector<int>> Table;
    int currentPlayer;

   public:
    TicTacToe(size_t n, size_t k) : N(n), K(k), currentPlayer(1) {
        Table.assign(N, std::vector<int>(N, 0));
    }

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    int GetCurrentPlayer() const {
        return currentPlayer;
    }

    bool Set(size_t i, size_t j) {
        Table[i][j] = currentPlayer;
        currentPlayer = currentPlayer % 2 + 1;
        bool wins =
            CheckRow(i, j) || CheckColumn(i, j) || CheckDiagonal1(i, j) || CheckDiagonal2(i, j);
        return wins;
    }

   private:
    bool CheckRow(size_t i, size_t j) const {
        size_t d1 = 0;
        while (d1 <= j && Table[i][j - d1] == Table[i][j])
            ++d1;

        size_t d2 = 0;
        while (j + d2 < N && Table[i][j + d2] == Table[i][j])
            ++d2;

        return d1 + d2 > K;
    }

    bool CheckColumn(size_t i, size_t j) const {
        int val = Table[i][j];

        size_t count = 1;
        for (size_t ii = i; ii > 0 && Table[ii - 1][j] == val; --ii)
            ++count;

        for (size_t ii = i + 1; ii < N && Table[ii][j] == val; ++ii)
            ++count;

        return count >= K;
    }

    size_t CountInDirection(size_t i, size_t j, int di, int dj) const {
        int val = Table[i][j];
        size_t count = 0;
        int x = static_cast<int>(i);
        int y = static_cast<int>(j);
        while (x >= 0 && y >= 0 && x < static_cast<int>(N) && y < static_cast<int>(N) &&
               Table[x][y] == val) {
            ++count;
            x += di;
            y += dj;
        }
        return count;
    }

    bool CheckDiagonal1(size_t i, size_t j) const {
        return CountInDirection(i, j, -1, -1) + CountInDirection(i, j, 1, 1) - 1 >= K;
    }

    bool CheckDiagonal2(size_t i, size_t j) const {
        return CountInDirection(i, j, -1, 1) + CountInDirection(i, j, 1, -1) - 1 >= K;
    }
};

std::ostream& operator<<(std::ostream& out, const TicTacToe& field) {
    for (size_t i = 0; i < field.N; ++i) {
        for (size_t j = 0; j < field.N; ++j) {
            switch (field(i, j)) {
                case 0:
                    out << '.';
                    break;
                case 1:
                    out << 'X';
                    break;
                case 2:
                    out << 'O';
                    break;
            }
        }
        out << std::endl;
    }
    return out;
}