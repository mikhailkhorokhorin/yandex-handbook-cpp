#include <set>
#include <vector>

class Stock {
   private:
    std::vector<std::pair<int, int>> boxes;

    struct ByWComp {
        bool operator()(const std::pair<int, size_t>& a, const std::pair<int, size_t>& b) const {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        }
    };

    struct ByVComp {
        bool operator()(const std::pair<int, size_t>& a, const std::pair<int, size_t>& b) const {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        }
    };

    std::set<std::pair<int, size_t>, ByWComp> byW;
    std::set<std::pair<int, size_t>, ByVComp> byV;

   public:
    void Add(int w, int v) {
        size_t id = boxes.size();
        boxes.push_back({w, v});
        byW.insert({w, id});
        byV.insert({v, id});
    }

    int GetByW(int min_w) {
        auto iter = byW.lower_bound({min_w, boxes.size()});

        if (iter == byW.end())
            return -1;

        size_t id = iter->second;

        byW.erase(iter);
        byV.erase({boxes[id].second, id});
        return id;
    }

    int GetByV(int min_v) {
        auto iter = byV.lower_bound({min_v, boxes.size()});

        if (iter == byV.end())
            return -1;

        size_t id = iter->second;

        byV.erase(iter);
        byW.erase({boxes[id].first, id});
        return id;
    }
};
