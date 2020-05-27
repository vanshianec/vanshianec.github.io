#ifndef _SERIALIZABLE_H
#define _SERIALIZABLE_H

class FileIO;

/// @brief Abstract class to be implemented by classes which need to be serialized or deserialized.

class Serializable
{
public:
	/// @brief Accept method using the visitor class FileIO
	virtual void accept(FileIO* visitor) = 0;
};

#endif