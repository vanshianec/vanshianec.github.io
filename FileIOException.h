#ifndef _FILEIOEXCEPTION_H
#define _FILEIOEXCEPTION_H

#include <string>

/// @brief Custom made exception for file inputs and outputs.

class FileIOException : public std::exception
{
private:
	/// @brief The message to be displayed from the exception.
	std::string message;
public:
	FileIOException(const std::string&);
	const char* what() const noexcept;
};

#endif