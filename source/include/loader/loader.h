#pragma once 

#include <string>


class Loader {
public:
    virtual ~Loader() { }
    
    virtual bool load(const std::string& path) = 0;
};
