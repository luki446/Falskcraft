#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>

#ifdef __DEBUG
    #define DEBUG(x) std::cout << "DEBUG[" << __FILE__ << ":" << __LINE__ << "] " << #x << " == " << x << '\n';
    #define LOG(x) std::cout << "LOG: " << x << '\n';
    #define LOGy(x, y) std::cout << "LOG: " << x << y << '\n';
#else
    #define DEBUG(x) 
    #define LOG(x)
    #define LOGy(x, y)
#endif
#endif