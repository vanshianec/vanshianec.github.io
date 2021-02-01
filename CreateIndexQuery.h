#ifndef _CREATE_INDEX_QUERY_H
#define _CREATE_INDEX_QUERY_H

#include "Query.h"

///@brief Class which represents a query which can create an index for a given column

class CreateIndexQuery : public Query
{
private:
    ///@brief The column name for which the index will be created
    std::string columnName;
public:
    const std::string& getColumnName() const;

    CreateIndexQuery(const std::string&, const std::string&);
    void accept(Executor*) override;
};

#endif
