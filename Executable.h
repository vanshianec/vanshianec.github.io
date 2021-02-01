#ifndef _EXECUTABLE_H
#define _EXECUTABLE_H

class Executor;

/// @brief Abstract class to be implemented by classes which need to use an Executor visitor class

class Executable
{
public:
    virtual void accept(Executor*) = 0;
};

#endif
