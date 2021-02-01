#ifndef _PARSER_H
#define _PARSER_H

#include <istream>
#include <vector>
#include "Scanner.h"
#include "Query.h"

/// @brief Class used to parse tokens by a given order

class Parser
{
private:
    /// @brief The scanner from which the tokens will be received
    Scanner scanner;
    /// @brief The current token received by the scanner
    Token currentToken;
    /// @brief The current query created by the parser
    Query* currentQuery;

    /// @brief Accepts a specified token type and checks whether it matches the current token type
    void consume(TokenType);
    /// @brief Accepts a token which represents data type for a table column
    void consumeDataType(Token&);
    /// @brief Checks whether the current token represents a column value
    void consumeColumnValue();
    /// @brief Checks whether the current token represents an operator
    void consumeOperator();
    /// @brief Checks whether the current token represents an aggregate type
    void consumeAggregate();
    /// @brief Checks whether the current token and all next tokens after him will match a valid create query
    void parseCreateQuery();
    /// @brief Checks whether the current token and all next tokens after him will match a valid insert query
    void parseInsertQuery();
    /// @brief Checks whether the current token and all next tokens after him will match a update create query
    void parseUpdateQuery();
    /// @brief Checks whether the current token and all next tokens after him will match a valid select query
    void parseSelectQuery();
    /// @brief Checks whether the current token and all next tokens after him will match a valid create table query
    void parseCreateTable();
    /// @brief Checks whether the current token and all next tokens after him will match a valid create index query
    void parseCreateIndex();
    /// @brief Checks whether the current token and all next tokens after him will match an aggregate pattern form a select query
    void parseSelectAggregate(std::vector<std::string>&, std::vector<TokenType>&);
    /// @brief Checks whether the current token and all next tokens after him will match a columns selection pattern form a select query
    void parseSelectColumns(std::vector<std::string>&);
    /// @brief Checks whether the current token and all next tokens after him will match a valid query pattern for select after the keyword 'FROM'
    void parseSelectAfterFrom(std::vector<std::string>&, std::vector<TokenType>&);
    /// @brief Checks whether the current token and all next tokens after him will match a valid where clause pattern of a query
    void parseWhereClause(std::string&, Token&, TokenType&);
    /// @brief Checks whether the current token and all next tokens after him will match a valid order by clause pattern of a query
    void parseOrderByClause(std::string&, TokenType&);
    /// @brief Checks whether the current token is a semi column
    void assureSemiColumn() const;
    /// @brief Deletes the instance of the current query
    void deleteQuery();
    /// @brief Parses and returns a token which contains a primary key field representation
    Token parsePrimaryColumn();
    /// @brief Parses a syntax for creating columns for a table
    void parseCreateTableColumns(std::vector<Token>&);
    /// @brief Parses a syntax for creating columns for a table
    void parseInsertColumns(std::vector<Token>& columnValues);
    /// @brief Parses a syntax for updating column values from a table
    void parseUpdateColumnsSet(std::vector<std::string>& columnNames, std::vector<Token>& columnValues);
public:
    Parser(std::istream&);
    /// @brief Creates a query instance based on the parsed tokens
    Query* parseQuery();
    ~Parser();
};

void error(const char*);

#endif
