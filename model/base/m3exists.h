#pragma once
#include <exception>
#include <string>


class m3Exist :public std::exception
{
private:
    std::string _msg;
public:
    m3Exist(const char * msg);
    m3Exist(const std::string &msg);

    const char *what()const noexcept override;
};

