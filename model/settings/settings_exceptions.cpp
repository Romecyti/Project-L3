#include "settings_exceptions.h"

SettingsFileError::SettingsFileError(const char *msg):_msg(msg)
{

}

SettingsFileError::SettingsFileError(const std::string &msg):_msg(msg)
{

}

const char *SettingsFileError::what() const noexcept
{
    return  _msg.c_str();
}
