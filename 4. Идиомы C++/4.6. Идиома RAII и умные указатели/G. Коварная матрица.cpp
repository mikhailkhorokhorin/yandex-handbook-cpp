Matrix(const Matrix& other) : rows(other.rows), columns(other.columns) {
    data = new T*[rows];
    size_t i = 0;
    try {
        for (; i != rows; ++i) {
            data[i] = new T[columns];

            for (size_t j = 0; j != columns; ++j)
                data[i][j] = other.data[i][j];
        }
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete[] data[k];

        delete[] data;
        throw;
    }
}

Matrix& operator=(const Matrix& other) {
    if (this == &other)
        return *this;

    T** new_data = new T*[other.rows];
    size_t i = 0;

    try {
        for (; i != other.rows; ++i) {
            new_data[i] = new T[other.columns];

            for (size_t j = 0; j != other.columns; ++j)
                new_data[i][j] = other.data[i][j];
        }
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete[] new_data[k];

        delete[] new_data;
        throw;
    }

    for (size_t k = 0; k != rows; ++k)
        delete[] data[k];

    delete[] data;

    data = new_data;
    rows = other.rows;
    columns = other.columns;

    return *this;
}

Matrix(Matrix&& other) noexcept : data(other.data), rows(other.rows), columns(other.columns) {
    other.data = nullptr;
    other.rows = 0;
    other.columns = 0;
}

Matrix& operator=(Matrix&& other) noexcept {
    if (this != &other) {
        for (size_t k = 0; k != rows; ++k)
            delete[] data[k];

        delete[] data;

        data = other.data;
        rows = other.rows;
        columns = other.columns;

        other.data = nullptr;
        other.rows = 0;
        other.columns = 0;
    }

    return *this;
}
