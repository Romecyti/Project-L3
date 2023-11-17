#include "m3exceptions.h"




m3DepassementTaille::m3DepassementTaille(const char *msg):_msg(msg)
{

}

m3DepassementTaille::m3DepassementTaille(const std::string &msg):_msg(msg)
{

}

const char *m3DepassementTaille::what() const noexcept
{
    return  _msg.c_str();
}
