#ifndef _SCANNER_H
#define _SCANNER_H

#include <istream>
#include "Token.h"

/// @brief Class used to read characters from an input stream and convert them to tokens

class Scanner
{
public:

    /// @brief Creates and instance of Scanner with the given input stream
    Scanner(std::istream&);

    /// @brief Returns the next token which is constructed based on the sequence of characters read from the stream
    Token nextToken();
    /// @brief Skips all whitespace characters until a non whitespace character or end of stream is reached
    void skipWhiteSpace();
    /// @brief Checks whether more tokens can be or end of stream is reached
    bool hasMoreTokens() const;

private:
    /// @brief Input stream object which the characters will be read from
    std::istream& input;

    /// @brief Returns a token which contains the '<' symbol
    Token lessThanOperator();
    /// @brief Returns a token which contains the '>' symbol
    Token moreThanOperator();
    /// @brief Returns a token containing the operator '!='
    Token notEqualOperator();
    /// @brief Returns a token which represents a string value
    Token stringValue();
    /// @brief Returns a token which represents a string value but in the form of a variable syntax
    Token stringVariable(char);
    /// @brief Returns a token with numeric characters
    Token numberVariable(char);
    /// @brief Checks if the given character and all characters after him are in the valid form of a negative number
    void validateNegativeNumber(char) const;

};

/// @brief Checks whether the given character is alphabetic or contains underscore
bool isAlphabeticOrUnderscore(char);
/// @brief Checks whether the given character sequence is a valid floating point representation of a number
void validateFloatingPointNumber(const std::string&, int, int);
/// @brief Checks if the given character starts with '-' or if it is a digit character
bool isNumber(char);
/// @brief Checks whether the given character is a dot character
bool isDot(char);


#endif
