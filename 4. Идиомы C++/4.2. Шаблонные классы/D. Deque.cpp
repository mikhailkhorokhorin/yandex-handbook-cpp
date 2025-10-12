#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
   private:
    std::vector<T> head_;
    std::vector<T> tail_;

   public:
    bool Empty() const {
        return head_.empty() && tail_.empty();
    }

    size_t Size() const {
        return head_.size() + tail_.size();
    }

    void Clear() {
        head_.clear();
        tail_.clear();
    }

    const T& operator[](size_t i) const {
        if (i < head_.size())
            return head_[head_.size() - i - 1];

        return tail_[i - head_.size()];
    }

    T& operator[](size_t i) {
        if (i < head_.size())
            return head_[head_.size() - i - 1];

        return tail_[i - head_.size()];
    }

    const T& At(size_t i) const {
        if (i >= Size())
            throw std::out_of_range("Index out of range");

        return (*this)[i];
    }

    T& At(size_t i) {
        if (i >= Size())
            throw std::out_of_range("Index out of range");

        return (*this)[i];
    }

    const T& Front() const {
        if (!head_.empty())
            return head_.back();

        return tail_.front();
    }

    T& Front() {
        if (!head_.empty())
            return head_.back();

        return tail_.front();
    }

    const T& Back() const {
        if (!tail_.empty())
            return tail_.back();

        return head_.front();
    }

    T& Back() {
        if (!tail_.empty())
            return tail_.back();

        return head_.front();
    }

    void PushFront(const T& elem) {
        head_.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail_.push_back(elem);
    }
};
