#include <list>
#include <map>
#include <optional>
#include <stdexcept>

template <typename Key1, typename Key2, typename Value>
class BiMap {
   private:
    std::map<Key1, Value*> map1_;
    std::map<Key2, Value*> map2_;
    std::list<Value> values_;

   public:
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2,
                const Value& value) {
        if (!key1 && !key2)
            throw std::invalid_argument("Keys are empty");

        if (key1 && map1_.count(*key1))
            throw std::invalid_argument("Key already exists");

        if (key2 && map2_.count(*key2))
            throw std::invalid_argument("Key already exists");

        values_.push_back(value);
        Value* ptr = &values_.back();

        if (key1)
            map1_[*key1] = ptr;

        if (key2)
            map2_[*key2] = ptr;
    }

    Value& GetByPrimaryKey(const Key1& key) {
        return *map1_.at(key);
    }

    const Value& GetByPrimaryKey(const Key1& key) const {
        return *map1_.at(key);
    }

    Value& GetBySecondaryKey(const Key2& key) {
        return *map2_.at(key);
    }

    const Value& GetBySecondaryKey(const Key2& key) const {
        return *map2_.at(key);
    }
};
