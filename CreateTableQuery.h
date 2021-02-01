#ifndef _CREATEQUERY_H
#define _CREATEQUERY_H

#include "Query.h"
#include "TokenType.h"

///@brief Class which represents a query which can create a new table

class CreateTableQuery : public Query
{
private:
    ///@brief The columns which the table will contain
    std::vector<Token> columns;
    ///@brief The primary key for the table which will represent a column which can contain only unique values
    Token primaryKey;

public:
    CreateTableQuery(const std::string&, const std::vector<Token>&, const Token&);

    void accept(Executor*) override;
    const std::vector<Token>& getColumns() const;
    const Token& getPrimaryKey() const;
};

#endif
