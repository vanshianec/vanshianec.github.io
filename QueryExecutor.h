#ifndef _QUERY_EXECUTOR_H
#define _QUERY_EXECUTOR_H

#include <fstream>
#include "Executor.h"
#include <map>
#include <unordered_map>
#include <set>

/// @brief Visitor class used to execute query type objects

class QueryExecutor : public Executor
{
private:
    /// @brief The filestream which will be used to to store and retrieve table data
    std::fstream fileStream;

    /// @brief Writes the column data into the file stream field
    void writeInsertArgument(const std::string&, const TokenType&);
    /// @brief Retrieve the index of the column from the table data which is read from the file stream field
    int findColumnIndex(int, const std::string&, std::vector<TokenType>&, std::vector<std::string>&);
    /// @brief Retrieve the value of the column with the given type from a file
    std::string readColumnValue(const TokenType&);
    /// @brief Opens the file stream field to read from a file with the given table name
    void openTableFile(const std::string&);
    /// @brief Reads the size of the table columns from the file stream field
    int readColumnsSize();
    /// @brief Reads the columns of the table from the file stream field
    void readTableColumns(int columnsSize, const std::vector<Token>& insertValues,
                          std::vector<std::string>& columnNames, std::vector<TokenType>& columnTypes);
    /// @brief Updates all rows from the table which match the given where clause
    void updateRows(int columnsSize, const Token&, const TokenType&, const std::vector<TokenType>&, int,
                    std::unordered_map<int, std::string>&, std::unordered_map<int, Token>&);
    /// @brief Checks whether the query data matches the expected data from the table
    void validateArgumentType(const Token&, const TokenType&, const std::string&);
    /// @brief Reads all rows which match the where clause and should be selected
    void readRowsToSelect(const SelectQuery&, int, const std::vector<std::string>&,
                          const std::vector<TokenType>&, const Token&, int, std::unordered_map<int, std::string>&);
    /// @brief Reads the primary key of the table from the file stream field
    void readPrimaryKeyValues(int, const std::vector<TokenType>&, const std::vector<std::string>&,
                              const Token&, std::set<std::string>&);
    /// @brief Checks whether the value to be inserted already exists for a column specified as a primary key
    void checkForDuplicateValue(int, const std::vector<Token>&, const std::vector<std::string>&,
                                const Token&, const std::set<std::string>&);
public:
    void execute(CreateTableQuery&) override;
    void execute(CreateIndexQuery&) override;
    void execute(InsertQuery&) override;
    void execute(UpdateQuery&) override;
    void execute(SelectQuery&) override;
};

/// @brief Throws an exception with the given message
void error(const std::string&);
/// @brief Checks whether the given file exists or not
bool fileExists(const char*);
/// @brief Checks whether the specified where condition is met
bool isWhereConditionMet(const std::string&, const TokenType&, const Token&);
/// @brief Checks whether the column value is greater than the query value
bool isMoreThan(const std::string&, const Token&);
/// @brief Checks whether the column value is less than the query value
bool isLessThan(const std::string&, const Token&);
/// @brief Checks whether the column value is equal to the query value
bool areValuesEqual(const std::string&, const Token&);
/// @brief Checks whether the table contains a column as the one passed in the where clause of the query
bool validateWhereColumn(const std::string&, const std::vector<TokenType>&, int, const Token&);
/// @brief Checks whether the passed column arguments from the query match the expected column types from the table
bool validateQueryColumnArguments(const std::vector<Token>&, const std::vector<std::string>&,
                                  const std::vector<TokenType>&, const std::vector<std::string>&,
                                  std::unordered_map<int, std::string>&, std::unordered_map<int, Token>&);
/// @brief Checks whether the passed column names from the query match the expected column names from the table
bool validateQueryColumnNames(std::unordered_map<int, std::string>&, const std::vector<std::string>&,
                         const std::vector<std::string>&);
/// @brief Prints all selected rows from the query and each rows' columns
void printSelectedRows(const std::vector<std::vector<Token>>&);
/// @brief Writes a string value with the given file stream
void writeStringValue(std::fstream&, const std::string&);
/// @brief Aggregates(Reduces) all rows based on the list of aggregates
void aggregateRows(const std::vector<TokenType>&, std::vector<std::vector<Token>>&);

#endif
