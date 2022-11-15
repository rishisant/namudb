// @author: rishisant
// @date: 2022-14-11
// @version: 1.0

#include "Database.cpp"
#include "Encryption.cpp"

#define LIGHT_BLUE "\033[1;34m"
#define BOLD "\033[1m"
#define CLEAR "\033[0m"

int main () {
    cout << LIGHT_BLUE << " [͇̿W͇̿E͇̿L͇̿C͇̿O͇̿M͇̿E͇̿] ͇̿  [͇̿T͇̿O͇̿] ͇̿  [͇̿N͇̿A͇̿M͇̿U͇̿D͇̿B͇̿!͇̿] " << CLEAR << endl;

    while (true) {
        cout << BOLD << "Select an option from the list of commands:\n" 
        << CLEAR
        << "1. Create a new database\n"
        << "2. Load an existing database\n"
        << "3. Exit\n"
        << BOLD
        << "Enter your choice: ";
        int choice;
        cin >> choice;

        // Create a new database (choice 1)
        // Prompt user for all data, including headers, columns, rows, etc.
        if (choice == 1) {
            cout << LIGHT_BLUE << "\n[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅C̲̅R̲̅E̲̅A̲̅T̲̅I̲̅O̲̅N̲̅:̲̅]\n" << CLEAR;
            cout << BOLD << "Enter the name of the database (note all databases are saved as .namu files): "
            << CLEAR;
            string name;
            cin >> name;
            name += ".namu";

            cout << BOLD << "Enter the number of columns: " << CLEAR;
            int columns;
            cin >> columns;

            cout << BOLD << "Enter the number of rows: " << CLEAR;
            int rows;
            cin >> rows;

            vector<string> headerNames;
            vector<vector<string>> data;

            for (int i = 0; i < columns; i++) {
                cout << BOLD << "Enter the name of column " << i + 1 << ": " << CLEAR;
                string headerName;
                getline(cin >> std::ws, headerName);
                headerNames.push_back(headerName);
            }

            for (int i = 0; i < rows; i++) {
                vector<string> row;
                for (int j = 0; j < columns; j++) {
                    cout << BOLD << "Enter the value of row " << i + 1 << " and column " << j + 1 << ": " << CLEAR;
                    string value;
                    getline(cin >> std::ws, value);
                    row.push_back(value);
                }
                data.push_back(row);
            }

            Database db(data, headerNames);

            // Ask the user if they'd like to print the database
            cout << BOLD << "Would you like to print the database? (y/n): " << CLEAR;
            char print;
            cin >> print;
            if (print == 'y') {
                cout << LIGHT_BLUE << "\n[P̲̅R̲̅I̲̅N̲̅T̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]\n" << CLEAR;
                db.print();
            }

            // Ask user if they'd like to save the database
            cout << BOLD << "Would you like to save the database? (y/n): " << CLEAR;
            char save;
            cin >> save;
            if (save == 'y') {
                db.encrypt(db);
                db.save(name);
                cout << LIGHT_BLUE << "\n[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅S̲̅A̲̅V̲̅E̲̅D̲̅]\n" << CLEAR;
            }
        }
        // Loading database (choice 2)
        else if (choice == 2) {
            cout << LIGHT_BLUE << "\n[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅L̲̅O̲̅A̲̅D̲̅I̲̅N̲̅G̲̅:̲̅]\n" << CLEAR;
            cout << BOLD << "Enter the name of the database (note all databases are saved as .namu files): "
            << CLEAR;
            string name;
            cin >> name;

            if (name.find(".namu") == string::npos) {
                name += ".namu";
            }

            cout << LIGHT_BLUE << "\n[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅L̲̅O̲̅A̲̅D̲̅E̲̅D̲̅ ̲̅S̲̅U̲̅C̲̅C̲̅E̲̅S̲̅S̲̅F̲̅U̲̅L̲̅L̲̅Y̲̅]\n" << CLEAR;
            Database db(name);
            db.decrypt(db);
            int choice;

            while (choice != 3) {
                bool is_encrypted = false;
                cout << BOLD << "Select an option from the list of commands:\n" 
                << CLEAR
                << "1. Print the database\n"
                << "2. Modify the database\n"
                << "3. Exit\n"
                << BOLD
                << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    cout << LIGHT_BLUE << "\n[P̲̅R̲̅I̲̅N̲̅T̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]\n" << CLEAR;
                    if (is_encrypted) {
                        Database to_print = db;
                        to_print.encrypt(to_print);
                        to_print.print();
                    }
                    else {
                        db.print();
                    }
                }
                else if (choice == 2) {
                    cout << LIGHT_BLUE << "\n[M̲̅O̲̅D̲̅I̲̅F̲̅Y̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]\n" << CLEAR;
                    cout << BOLD << "For reference, would you like to print the database? (y/n): " << CLEAR;
                    char print;
                    cin >> print;
                    if (print == 'y') {
                        cout << endl << LIGHT_BLUE << "\n[P̲̅R̲̅I̲̅N̲̅T̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]\n" << CLEAR;
                        db.print();
                        cout << endl;
                    }

                    cout << BOLD << "There are a total of " << db.getColumns() << " columns and " << db.getRows() << " rows.\n" << CLEAR;
                    int row = -1, column = -1;
                    while (true) {
                        cout << BOLD << "Enter the column number: " << CLEAR;
                        cin >> column;
                        cout << BOLD << "Enter the row number: " << CLEAR;
                        cin >> row;
                        if (column > db.getColumns() || row > db.getRows()) {
                            cout << BOLD << "Invalid row or column number. Please try again.\n" << CLEAR;
                        }
                        else {
                            break;
                        }
                    }

                    row--; column--;
                    cout << BOLD << "Under column [" << db.getHeaderName(column) << "] and data [" << db.getCell(row, column) << "], enter the new value: " << CLEAR;
                    string value;
                    cin >> value;
                    db.setCell(row, column, value);
                    cout << LIGHT_BLUE << "\n[M̲̅O̲̅D̲̅I̲̅F̲̅I̲̅C̲̅A̲̅T̲̅I̲̅O̲̅N̲̅ ̲̅S̲̅U̲̅C̲̅C̲̅E̲̅S̲̅S̲̅F̲̅U̲̅L̲̅L̲̅Y̲̅ ̲̅C̲̅O̲̅M̲̅P̲̅L̲̅E̲̅T̲̅E̲̅D̲̅]\n" << CLEAR;

                    cout << BOLD << "Would you like to save the database? (y/n): " << CLEAR;
                    char save;
                    cin >> save;
                    if (save == 'y') {
                        db.encrypt(db);
                        is_encrypted = true;
                        db.save(name);
                        cout << LIGHT_BLUE << "\n[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅S̲̅A̲̅V̲̅E̲̅D̲̅]\n" << CLEAR;
                    }
                }
                else if (choice == 3){
                    return 0;
                }

            }

        }
        else {
            break;
        }
    }
    return 0;
}