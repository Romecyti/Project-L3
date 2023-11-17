#pragma once
#include <exception>
#include <string>


class m3DepassementTaille :public std::exception
{
private:
    std::string _msg;
public:
    m3DepassementTaille(const char * msg);
    m3DepassementTaille(const std::string &msg);

    const char * what()const noexcept override;
};

