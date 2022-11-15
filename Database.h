// @author: rishisant
// @date: 2022-14-11
// @version: 1.0

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cctype>

using std::string, std::vector, std::cout, std::cin, std::endl, std::map, std::ifstream, std::ofstream, std::istringstream, std::ostream_iterator, std::transform, std::back_inserter, std::function, std::isspace, std::stringstream;

#include "Encryption.h"

class Database {
    private:
    Encryptor crypt;
    vector<vector<string>> data;
    map<string, int> header;
    vector<string> headerNames;
    vector<string> split(const string& s, char delim);
    int rows;
    int columns;

    public:
    // Get encryptor
    Encryptor get_encryptor();
    // Encrypt the database and decrypt the database
    void encrypt(Database& db);
    void decrypt(Database& db);

    // Constructor Commands
    Database(string filename);
    Database(vector<vector<string>> data, vector<string> headerNames);

    // Print Database Commands
    void print();
    void printHeader();
    void printRow(int row);
    void printColumn(int column);
    void printColumn(string columnName);
    void printCell(int row, int column);

    // Append to Database Commands
    void addRow(vector<string> row);
    void addColumn(string columnName, vector<string> column);
    void addCell(int row, int column, string value);

    // Save & Load Database Commands
    void save(string filename);
    void load(string filename);

    // Delete from Database Commands
    void deleteRow(int row);
    void deleteColumn(int column);
    void deleteColumn(string columnName);
    void deleteCell(int row, int column);

    // Getters
    vector<vector<string>> getData();
    map<string, int> getHeader();
    string getHeaderName(int column);
    vector<string> getHeaderNames();
    vector<string> getRow(int row);
    vector<string> getColumn(int column);
    int getRows();
    int getColumns();
    string getCell(int row, int column);

    // Setters
    void setData(vector<vector<string>> data);
    void setHeader(map<string, int> header);
    void setHeaderNames(vector<string> headerNames);
    void setRow(int row, vector<string> newRow);
    void setColumn(int column, vector<string> newColumn);
    void setCell(int row, int column, string value);
};

#endif