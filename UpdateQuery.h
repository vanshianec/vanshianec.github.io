#ifndef _UPDATE_QUERY_H
#define _UPDATE_QUERY_H

#include "Query.h"
#include "TokenType.h"

///@brief Class which represents a query which can update values from an existing table

class UpdateQuery : public Query
{
private:
    ///@brief The column names from which the values will be updated
    std::vector<std::string> columnNames;
    ///@brief The values which will be inserted into the specified column names
    std::vector<Token> columnValues;
    ///@brief A column on which a where clause can be used to updated specific data only
    std::string whereColumn;
    ///@brief The operator of the where clause
    TokenType op;
    ///@brief The where value operand on which the operator will operate
    Token whereValue;

public:
    UpdateQuery(const std::string&, const std::vector<std::string>&, const std::vector<Token>&,
                const std::string&, const TokenType&, const Token&);

    void accept(Executor*) override;

    const std::vector<std::string>& getColumnNames() const;
    const std::vector<Token>& getColumnValues() const;
    const std::string& getWhereColumn() const;
    TokenType getOp() const;
    const Token& getWhereValue() const;
};

#endif
