#include <vector>

template <typename T>
class Table {
   private:
    std::vector<std::vector<T>> data_;

   public:
    Table(size_t rows, size_t cols) : data_(rows, std::vector<T>(cols)) {
    }

    std::vector<T>& operator[](size_t i) {
        return data_[i];
    }

    const std::vector<T>& operator[](size_t i) const {
        return data_[i];
    }

    void resize(size_t new_rows, size_t new_cols) {
        data_.resize(new_rows);
        for (auto& row : data_)
            row.resize(new_cols);
    }

    std::pair<size_t, size_t> size() const {
        if (data_.empty())
            return {0, 0};
        return {data_.size(), data_[0].size()};
    }
};