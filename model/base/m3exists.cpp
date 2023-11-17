#include "m3exists.h"

m3Exist::m3Exist(const char *msg):_msg(msg)
{

}

m3Exist::m3Exist(const std::string &msg):_msg(msg)
{

}

const char *m3Exist::what() const noexcept
{
    return  _msg.c_str();
}
