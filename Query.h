#ifndef _QUERY_H
#define _QUERY_H

#include "Executable.h"
#include "Scanner.h"
#include <string>
#include <vector>

/// @brief Abstract class which represents a query executable

class Query : Executable
{
private:
    /// @brief The name of the table in which the query will be executed
    std::string tableName;

protected:
    /// @brief Creates an instance of Query
    Query(const std::string&);
    /// @brief Static function which can be used by all instances of Query to check if the column values they receive are valid
    static void validateColumnValues(const std::vector<Token>&);

public:
    virtual void accept(Executor*) = 0;
    const std::string& getTableName() const;
    static const int maxStringValueLength = 64;
    virtual ~Query();
};

#endif
