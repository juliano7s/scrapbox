#pragma once

#include <exception>

class GControlException :
    public std::exception
{
    public:
        GControlException(void);
        GControlException(const char* const& msg) : std::exception(msg) { }
        ~GControlException(void);
};

