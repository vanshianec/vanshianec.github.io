#ifndef _STRINGTRIMMER_H
#define _STRINGTRIMMER_H

#include <string>

/// @brief Class used to trim characters from a string.

class StringTrimmer
{

public:

	/**
	*   @brief Removes leading characters from a specified string.
	*
	*   @param str  The string from which the characters will be removed
	*   @param chars  The characters to be removed from the string
	*   @return     New string with the removed characters
	*
	*   Example:
	*   @code
	*     std::string s = "   leading";
	*     StringTrimmer::ltrim(s);
	*     std::cout << s << std::endl;
	*     //outputs "leading" instead of "   leading"
	*   @endcode
	*/

	static std::string& ltrim(std::string& str, const std::string& chars);

	/**
	*   @brief Removes trailing characters from a specified string.
	*
	*   @param str  The string from which the characters will be removed
	*   @param chars  The characters to be removed from the string
	*   @return     New string with the removed characters
	*
	*   Example:
	*   @code
	*     std::string s = "trailing   ";
	*     StringTrimmer::rtrim(s);
	*     std::cout << s << std::endl;
	*     //outputs "trailing" instead of "trailing   "
	*   @endcode
	*/

	static std::string& rtrim(std::string& str, const std::string& chars);

	/**
	*   @brief Removes trailing and leading characters from a specified string.
	*
	*   @param str  The string from which the characters will be removed
	*   @param chars  The characters to be removed from the string
	*   @return     New string with the removed characters
	*
	*   Example:
	*   @code
	*     std::string s = "   trim   ";
	*     StringTrimmer::trim(s);
	*     std::cout << s << std::endl;
	*     //outputs "trim" instead of "   trim   "
	*   @endcode
	*/

	static std::string& trim(std::string& str);
};

#endif