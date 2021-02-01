#ifndef _EXECUTOR_H
#define _EXECUTOR_H

#include "SelectQuery.h"
#include "CreateTableQuery.h"
#include "CreateIndexQuery.h"
#include "InsertQuery.h"
#include "UpdateQuery.h"

/// @brief Class used to execute queries

class Executor
{
public:
    /// @brief Executes a SelectQuery object
    virtual void execute(SelectQuery&) = 0;
    /// @brief Executes a CreateTableQuery object
    virtual void execute(CreateTableQuery&) = 0;
    /// @brief Executes a CreateIndexQuery object
    virtual void execute(CreateIndexQuery&) = 0;
    /// @brief Executes a InsertQuery object
    virtual void execute(InsertQuery&) = 0;
    /// @brief Executes a UpdateQuery object
    virtual void execute(UpdateQuery&) = 0;
    virtual ~Executor();
};

#endif
