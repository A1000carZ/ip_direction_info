#include <iostream>
#include <string.h>

class IPDirection
{
public:
    std::string direction;
    IPDirection(std::string direction)
        : direction(direction) {}
    char getIpClass(void);
    void getInfo(void);
    std::string getPreffix(void);
    std::string getNetworkId(void);
    std::string getHost(void);
    std::string getIpMask(void);
    ~IPDirection();
};