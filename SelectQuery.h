#ifndef _SELECT_QUERY_H
#define _SELECT_QUERY_H

#include "Query.h"
#include "TokenType.h"

///@brief Class which represents a query which can select values from a specified table

class SelectQuery : public Query
{
private:
    ///@brief List of column names which will be selected from the table
    std::vector<std::string> columnNames;
    ///@brief List of aggregates by which a given columns can be selected
    std::vector<TokenType> aggregates;
    ///@brief A column on which a where clause will be executed
    std::string whereColumn;
    ///@brief The operator of the where clause
    TokenType whereOp;
    ///@brief The value of the where clause
    Token whereValue;
    ///@brief A column by which the selected data can be ordered
    std::string orderByColumn;
    ///@brief The type of ordering by which the data can be selected (Ascending, Descending)
    TokenType orderType;

public:
    SelectQuery(const std::string&, const std::vector<std::string>&, const std::vector<TokenType>&,
                const std::string&, const TokenType&, const Token&, const std::string&, const TokenType&);

    void accept(Executor*) override;

    const std::vector<std::string>& getColumnNames() const;
    const std::vector<TokenType>& getAggregates() const;
    const std::string& getWhereColumn() const;
    TokenType getWhereOp() const;
    const Token& getWhereValue() const;
    const std::string& getOrderByColumn() const;
    TokenType getOrderType() const;
};

#endif
