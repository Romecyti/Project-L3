#pragma once
#include <exception>
#include <string>


class SettingsFileError :public std::exception
{
private:
    std::string _msg;
public:
    SettingsFileError(const char * msg);
    SettingsFileError(const std::string &msg);

    const char * what()const noexcept override;
};

