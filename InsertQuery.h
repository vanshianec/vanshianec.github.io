#ifndef _INSERT_QUERY_H
#define _INSERT_QUERY_H

#include "Query.h"

///@brief Class which represents a query which can insert new values into a table

class InsertQuery : public Query
{
private:
    ///@brief The column values which will be inserted into the table
    std::vector<Token> columnValues;

public:
    InsertQuery(const std::string&, const std::vector<Token>&);

    void accept(Executor*) override;
    const std::vector<Token>& getInsertValues() const;
};

#endif
