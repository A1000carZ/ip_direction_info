#include "ip_direction.h"

IPDirection::~IPDirection()
{
    std::cout << "Proceso terminado" << std::endl;
}
char IPDirection::getIpClass()
{
    char octect[4];
    int i = 0;
    int ip = 0;

    while (direction[i] != '.')
    {
        octect[i] = direction[i];
        i++;
    }
    i--;

    int j = 1;

    while (i >= 0)
    {
        ip = ip + (octect[i] - '0') * j;
        j = j * 10;
        i--;
    }

    if (ip >= 1 && ip <= 127)
    {
        return 'A';
    }
    else if (ip >= 128 && ip <= 191)
    {
        return 'B';
    }
    else if (ip >= 192 && ip <= 223)
    {
        return 'C';
    }
    else
        return 'D';
}

std::string IPDirection::getPreffix()
{
    switch (getIpClass())
    {
    case 'A':
        return "/8";
        break;
    case 'B':
        return "/16";
    case 'C':
        return "/24";
    default:
        return "none";
        break;
    }
}

std::string IPDirection::getIpMask()
{
    switch (getIpClass())
    {
    case 'A':
        return "255.0.0.0";
        break;
    case 'B':
        return "255.255.0.0";
    case 'C':
        return "255.255.255.0";
    default:
        return "none";
        break;
    }
}

std::string IPDirection::getNetworkId()
{
    char ipClass = getIpClass();
    char networkId[12];
    for (int e = 0; e < 12; e++)
    {
        networkId[e] = '\0';
    }

    if (ipClass == 'A')
    {
        int i = 0, j = 0, count = 0;
        while (count < 1)
        {
            networkId[i++] = direction[j++];
            if (direction[i] == '.')
            {
                count++;
            }
        }
        std::string sNet = networkId;

        std::string result = sNet + ".0.0.0";
        return result;
    }
    else if (ipClass == 'B')
    {
        int i = 0, j = 0, count = 0;
        while (count < 2)
        {
            networkId[i++] = direction[j++];
            if (direction[i] == '.')
            {
                count++;
            }
        }

        std::string sNet = networkId;

        std::string result = sNet + ".0.0";

        return result;
    }
    else if (ipClass == 'C')
    {
        int i = 0, j = 0, count = 0;
        while (count < 3)
        {
            networkId[i++] = direction[j++];
            if (direction[i] == '.')
            {
                count++;
            }
        }

        std::string sNet = networkId;

        std::string result = sNet + ".0";

        return result;
    }
    else
    {
        return "none";
    }
}

std::string IPDirection::getHost()
{
    std::string host = "";
    std::string networkId = getNetworkId();
    for (int i = 0; i < direction.size(); i++)
    {
        if (direction[i] != networkId[i] || direction[i] == '.')
        {
            host = host + direction[i];
        }
    }

    return host;
}

void IPDirection::getInfo()
{
    char ipClass = getIpClass();
    std::string preffix = getPreffix();
    std::string ipMask = getIpMask();
    std::string networkId = getNetworkId();
    std::string host = getHost();

    std::cout << "\nInformacion acerca de esta dirección" <<std::endl<< std::endl;
    std::cout << "Direccion ip\t\tclase\t\tPrefijo\t\tMascara por default\t\tNetwork Id\t\tHost\t\t" << std::endl
        << std::endl;
    std::cout << direction << "\t\t" << ipClass << "\t\t" << preffix << "\t\t" << ipMask << "\t\t\t" << networkId << "\t\t" << host << "\t\t" << std::endl
        << std::endl;
}