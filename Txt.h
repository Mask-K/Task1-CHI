#pragma once

#include <string>

namespace l1 {
    class Txt {
    public:
        Txt();
        Txt(const std::string& path);
        Txt(const Txt& other);
        Txt(Txt&& other) noexcept;

        Txt& operator=(const Txt& other);
        Txt& operator=(Txt&& other) noexcept;

        ~Txt();

        size_t size () const;

    private:
        std::string* _data{};
        size_t _size{};
    };
}


