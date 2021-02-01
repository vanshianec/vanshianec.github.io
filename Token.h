#ifndef _TOKEN_H
#define _TOKEN_H

#include "TokenType.h"
#include <string>
#include <fstream>

/// @brief A struct used to create a token which has a type and a value

struct Token
{
    /// @brief The type of the token
    TokenType type;
    /// @brief The value which the token holds
    std::string value;

    /// @brief Allows the current token to be serialized by the given file stream
    void write(std::fstream&);
    /// @brief Allows the current token to be deserialized by the given file stream
    void read(std::fstream&);
};

#endif
