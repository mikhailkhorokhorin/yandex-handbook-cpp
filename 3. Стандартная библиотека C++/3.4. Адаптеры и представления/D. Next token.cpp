#include <string_view>

bool NextToken(std::string_view& view, char delimiter, std::string_view& token) {
    if (view.empty())
        return false;

    size_t pos = view.find(delimiter);
    if (pos == std::string_view::npos) {
        token = view;
        view.remove_prefix(view.size());
        return true;
    }

    token = view.substr(0, pos);
    view.remove_prefix(pos + 1);
    return true;
}
