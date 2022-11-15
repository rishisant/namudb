// @author: rishisant
// @date: 2022-14-11
// @version: 1.0

#define BOLD "\033[1m"
#define CLEAR "\033[0m"

#include "Database.h"
#include "Encryption.h"

#include <random>
#include <chrono>

// Get encryptor
Encryptor Database::get_encryptor() {
    return crypt;
}

vector<string> Database::split(const string& s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

Database::Database(string filename) {
    // Construct the Encryptor
    // this->crypt = Encryptor(this->crypt.get_key());

    // Open file
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File match failed." << endl;
        return;
    }

    // Read file
    string line;
    

    // Get the first line, which is the encryption key
    // Decrypt this key with "namudb"
    string enc_key;
    getline(file, enc_key);
    this->crypt.set_key(this->crypt.decrypt_text(enc_key, "namudb"));


    // Modify headerNames
    getline(file, line);
    headerNames = split(line, ',');
    for (int i = 0; i < headerNames.size(); i++) {
        this->columns++;
        header[headerNames[i]] = i;
    }

    // Read data
    while (getline(file, line)) {
        data.push_back(split(line, ','));
    }
    this->rows = data.size();

    // Close file
    file.close();
}

Database::Database(vector<vector<string>> data, vector<string> headerNames) {
    // Construct the Encryptor
    this->crypt = Encryptor();

    // Modify headerNames
    this->data = data;
    this->headerNames = headerNames;
    // Modify header
    for (int i = 0; i < headerNames.size(); i++) {
        header[headerNames[i]] = i;
    }
}

void Database::printHeader() {
    // Print headerNames
    for (int i = 0; i < headerNames.size(); i++) {
        cout << headerNames[i] << ", ";
    }
    cout << endl;
}

void Database::printRow(int row) {
    // Print row
    for (int i = 0; i < data[row].size(); i++) {
        cout << data[row][i] << ", ";
    }
    cout << endl;
}

void Database::printColumn(int column) {
    // Print column
    for (int i = 0; i < data.size(); i++) {
        cout << data[i][column] << endl;
    }
}

// Adding polymorphism functionality purely for column name
void Database::printColumn(string columnName) {
    // Print column
    for (int i = 0; i < data.size(); i++) {
        cout << data[i][header[columnName]] << endl;
    }
}

void Database::printCell(int row, int column) {
    // Print cell
    cout << data[row][column] << endl;
}

void Database::addRow(vector<string> row) {
    // Add row
    data.push_back(row);
    rows++;
}

void Database::addColumn(string columnName, vector<string> column) {
    // Add column
    // Add column name to headerNames
    headerNames.push_back(columnName);
    // Add column name to header
    header[columnName] = headerNames.size() - 1;
    // Add column to data
    for (int i = 0; i < data.size(); i++) {
        data[i].push_back(column[i]);
    }
    columns++;
}

void Database::addCell(int row, int column, string value) {
    // Add cell
    data[row][column] = value;
}

void Database::deleteRow(int row) {
    // Delete row
    data.erase(data.begin() + row);
    rows--;
}

void Database::deleteColumn(int column) {
    // Delete column
    // Delete column name from headerNames
    headerNames.erase(headerNames.begin() + column);
    // Delete column name from header
    header.erase(headerNames[column]);
    // Delete column from data
    for (int i = 0; i < data.size(); i++) {
        data[i].erase(data[i].begin() + column);
    }
    columns--;
}

// Adding polymorphism functionality purely for column name
void Database::deleteColumn(string columnName) {
    // Delete column
    // Delete column name from headerNames
    headerNames.erase(headerNames.begin() + header[columnName]);
    // Delete column name from header
    header.erase(columnName);
    // Delete column from data
    for (int i = 0; i < data.size(); i++) {
        data[i].erase(data[i].begin() + header[columnName]);
    }
    columns--;
}

void Database::deleteCell(int row, int column) {
    // Delete cell
    data[row][column] = "";
}

vector<string> Database::getRow(int row) {
    // Return row
    return data[row];
}

vector<string> Database::getColumn(int column) {
    // Return column
    vector<string> columnData;
    for (int i = 0; i < data.size(); i++) {
        columnData.push_back(data[i][column]);
    }
    return columnData;
}

vector<vector<string>> Database::getData() {
    // Return data
    return data;
}

vector<string> Database::getHeaderNames() {
    // Return headerNames
    return headerNames;
}

string Database::getHeaderName(int column) {
    // Return headerName
    return headerNames[column];
}

map<string, int> Database::getHeader() {
    // Return header
    return header;
}

int Database::getRows() {
    // Return rows
    return rows;
}

int Database::getColumns() {
    // Return columns
    return columns;
}

string Database::getCell(int row, int column) {
    // Return cell
    return data[row][column];
}


void Database::setRow(int row, vector<string> rowData) {
    // Set row
    data[row] = rowData;
}

void Database::setColumn(int column, vector<string> columnData) {
    // Set column
    for (int i = 0; i < data.size(); i++) {
        data[i][column] = columnData[i];
    }
}

void Database::setCell(int row, int column, string value) {
    // Set cell
    data[row][column] = value;
}

void Database::setData(vector<vector<string>> data) {
    // Set data
    this->data = data;
}

void Database::setHeaderNames(vector<string> headerNames) {
    // Set headerNames
    this->headerNames = headerNames;
}

void Database::setHeader(map<string, int> header) {
    // Set header
    this->header = header;
}

void Database::save(string fileName) {
    // Open file
    ofstream file;
    file.open(fileName);

    // First, write the encryption key and encrypt it with "namudb" as the string
    string enc_key = this->crypt.get_key();
    file << this->crypt.encrypt_text(enc_key, "namudb") << endl;

    // Write headerNames
    for (int i = 0; i < headerNames.size(); i++) {
        file << headerNames[i];
        if (i != headerNames.size() - 1) {
            file << ",";
        }
    }
    file << endl;

    // Write data
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            file << data[i][j];
            if (j != data[i].size() - 1) {
                file << ",";
            }
        }
        file << endl;
    }

    // Close file
    file.close();
}

void Database::load(string fileName) {
    // Open file
    ifstream file;
    file.open(fileName);

    string line;

    // First, read the encryption key and decrypt it with "namudb" as the string
    string enc_key;
    getline(file, enc_key);
    this->crypt.set_key(this->crypt.decrypt_text(enc_key, "namudb"));

    // Read headerNames
    getline(file, line);
    stringstream ss(line);
    string headerName;
    while (getline(ss, headerName, ',')) {
        headerNames.push_back(headerName);
    }

    // Read data
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<string> row;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    // Close file
    file.close();

    // Set rows and columns
    rows = data.size();
    columns = data[0].size();

    // Set header
    for (int i = 0; i < headerNames.size(); i++) {
        header[headerNames[i]] = i;
    }
}

// void Database::print() {
//     // Print headerNames
//     for (int i = 0; i < headerNames.size(); i++) {
//         cout << headerNames[i];
//         if (i != headerNames.size() - 1) {
//             cout << "|| ";
//         }
//     }
//     cout << endl;

//     // Print data
//     for (int i = 0; i < data.size(); i++) {
//         for (int j = 0; j < data[i].size(); j++) {
//             cout << data[i][j];
//             if (j != data[i].size() - 1) {
//                 cout << "|| ";
//             }
//         }
//         cout << endl;
//     }
// }

void Database::print() {
    // Print nicely to ensure that all columns are the same width (i.e whitespace is the same)
    // Use the length of the headername of that column to ensure that whitespace is distrbuted evenly
    // Center the data and headernames in the column

    // Print headerNames, ensuring that whitespace is distributed evenly and that the headername is centered
    for (int i = 0; i < headerNames.size(); i++) {
        // Calculate whitespace
        int whitespace = headerNames[i].length();
        for (int j = 0; j < data.size(); j++) {
            if (data[j][i].length() > whitespace) {
                whitespace = data[j][i].length();
            }
        }
        // Print whitespace
        for (int j = 0; j < (whitespace - headerNames[i].length()) / 2; j++) {
            cout << " ";
        }
        // Print headerName
        cout << BOLD << headerNames[i] << CLEAR;
        // Print whitespace
        for (int j = 0; j < (whitespace - headerNames[i].length()) / 2; j++) {
            cout << " ";
        }
        // Print whitespace
        if (whitespace % 2 == 1) {
            cout << " ";
        }
        // Print seperator
        if (i == 0) {
            cout << "|| ";
        }
        else if (i != headerNames.size() - 1) {
            cout << " || ";
        }
    }
    cout << endl;

    // Print data, ensuring that whitespace is distributed evenly according to the headername and that the data is centered
    // Use getCell to get the data, as well as other getters that have been predefined

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            // Calculate whitespace
            int whitespace = headerNames[j].length();
            for (int k = 0; k < data.size(); k++) {
                if (data[k][j].length() > whitespace) {
                    whitespace = data[k][j].length();
                }
            }
            // Print whitespace
            for (int k = 0; k < (whitespace - getCell(i, j).length()) / 2; k++) {
                cout << " ";
            }
            // Print data
            cout << getCell(i, j);
            // Print whitespace
            for (int k = 0; k < (whitespace - getCell(i, j).length()) / 2; k++) {
                cout << " ";
            }
            // Print whitespace
            if (whitespace % 2 == 1) {
                cout << " ";
            }
            // Print seperator
            if (j == 0) {
                cout << "|| ";
            }
            else if (j != data[i].size() - 1) {
                cout << " || ";
            }
        }
        cout << endl;
    }

    return;
}

// Encryption and decryption
void Database::encrypt(Database& db) {
    // Encrypt the entire database 
    // Use the encrypt function from the Encryption class
    // Return the encrypted database
    string encryption_key = this->crypt.get_key();

    // Iterate through the header names, encrypting each one
    for (int i = 0; i < db.headerNames.size(); i++) {
        db.headerNames[i] = crypt.encrypt_text(db.headerNames[i], encryption_key);
    }

    // Iterate through the data, encrypting each cell
    for (int i = 0; i < db.data.size(); i++) {
        for (int j = 0; j < db.data[i].size(); j++) {
            db.data[i][j] = crypt.encrypt_text(db.data[i][j], encryption_key);
        }
    }
}

void Database::decrypt(Database& db) {
    // Decrypt the entire database
    // Use the decrypt function from the Encryption class
    // Return the decrypted database
    string decryption_key = this->crypt.get_key();

    // Iterate through the header names, decrypting each one
    for (int i = 0; i < db.headerNames.size(); i++) {
        db.headerNames[i] = crypt.decrypt_text(db.headerNames[i], decryption_key);
    }

    // Iterate through the data, decrypting each cell
    for (int i = 0; i < db.data.size(); i++) {
        for (int j = 0; j < db.data[i].size(); j++) {
            db.data[i][j] = crypt.decrypt_text(db.data[i][j], decryption_key);
        }
    }
}