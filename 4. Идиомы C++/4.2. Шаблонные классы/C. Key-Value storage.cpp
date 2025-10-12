template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* const value) const {
    auto iter = data.find(key);

    if (iter == data.end())
        return false;

    if (value != nullptr)
        *value = iter->second;

    return true;
}
