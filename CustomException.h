#pragma once
#include <exception>
#include <string>

namespace kinocritic {

class CustomException : public std::exception {
private:
    std::string msg;
public:
    explicit CustomException(const std::string& message) : msg(message) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

} // namespace kinocritic