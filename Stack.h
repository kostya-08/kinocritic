#pragma once
#include <vector>
#include <stdexcept>

namespace kinocritic {

template<typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(const T& item) { data.push_back(item); }
    void pop() {
        if (empty()) throw std::runtime_error("Стек пуст!");
        data.pop_back();
    }
    T top() const {
        if (empty()) throw std::runtime_error("Стек пуст!");
        return data.back();
    }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

} // namespace kinocritic