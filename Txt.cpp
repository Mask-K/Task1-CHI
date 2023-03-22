#include "Txt.h"
#include <fstream>

namespace l1{

    Txt::Txt() : _data(nullptr), _size(0){}

    Txt::Txt(const std::string &path) : _size(0){
        std::ifstream stream(path);
        if(stream.is_open()){
            std::string line;
            while(std::getline(stream, line)){
                ++_size;
            }
            _data = new std::string[_size];

            stream.clear();
            stream.seekg(0, std::ios::beg);
            for(int i =0; i < _size; ++i){
                std::getline(stream, line);
                _data[i] = line;
            }
        }
        else
            _data = nullptr;
    }

    Txt::Txt(const Txt &other) {
        *this = other;
    }

    Txt::Txt(Txt &&other) noexcept {
        *this = std::move(other);
    }

    Txt &Txt::operator=(const Txt &other) {
        _data = new std::string[other._size];
        _size = other._size;
        for(int i = 0; i < _size; ++i){
            _data[i] = other._data[i];
        }
        return *this;
    }

    Txt &Txt::operator=(Txt &&other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _size = other._size;
            other._data = nullptr;
            other._size = 0;
        }
        return *this;
    }

    Txt::~Txt() {
        delete[] _data;
        _data = nullptr;
        _size = 0;
    }

    size_t Txt::size() const {
        return _size;
    }
}