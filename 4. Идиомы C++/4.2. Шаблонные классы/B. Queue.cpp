#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
   private:
    Container data_;

   public:
    Queue() = default;

    T& front() {
        return data_.front();
    }

    const T& front() const {
        return data_.front();
    }

    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        data_.pop_front();
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        return data_.size();
    }

    bool operator==(const Queue& other) const {
        return data_ == other.data_;
    }

    bool operator!=(const Queue& other) const {
        return !(*this == other);
    }
};