# NAMUDB
Howdy!
This is NamuDB, a database creation and encryption software that creates local databases.

## Compilation
To compile in your Terminal, please run the following commands in sequential order:
```sh
make
make run
```

## Usage
Once you have compiled the program and run it, you are free to create your own databases!
You can create databases (which will be stored in the same directory as the program).

## Prompt 1
```
 [͇̿W͇̿E͇̿L͇̿C͇̿O͇̿M͇̿E͇̿] ͇̿  [͇̿T͇̿O͇̿] ͇̿  [͇̿N͇̿A͇̿M͇̿U͇̿D͇̿B͇̿!͇̿] 
Select an option from the list of commands:
1. Create a new database
2. Load an existing database
3. Exit
```

Open opening the program, you have the choice of creating or loading a database.
Type **1** to create a database or **2** to load an existing database.

## Prompt 2
```
[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅C̲̅R̲̅E̲̅A̲̅T̲̅I̲̅O̲̅N̲̅:̲̅]
Enter the name of the database (note all databases are saved as .namu files): test
Enter the number of columns: 2
Enter the number of rows: 2
Enter the name of column 1: Name
Enter the name of column 2: Age
Enter the value of row 1 and column 1: Harry
Enter the value of row 1 and column 2: 25
Enter the value of row 2 and column 1: Johnny
Enter the value of row 2 and column 2: 18
Would you like to print the database? (y/n): y
```
This is a sample database with only 2 columns and 2 rows.

## Prompt 3
```
[P̲̅R̲̅I̲̅N̲̅T̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]
 Name || Age 
Harry || 25 
Johnny|| 18 
Would you like to save the database? (y/n): y
```
This is the final result.

### File encryption
Every database has a unique key that is encrypted, and the database itself looks as follows: (test.namu)
```
,,4/-
,4?,*<
,+(0,px
"14';,su
```
One can note how the file is completely encrypted.

### File decryption
File decryption happens within the scope of the program, but **.namu** files cannot be viewed within an external editor.
This is purely for safety and logic reasons; if you wish to view the database, you can open it in the program.
```
Select an option from the list of commands:
1. Create a new database
2. Load an existing database
3. Exit
Enter your choice: 2

[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅L̲̅O̲̅A̲̅D̲̅I̲̅N̲̅G̲̅:̲̅]
Enter the name of the database (note all databases are saved as .namu files): test

[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅L̲̅O̲̅A̲̅D̲̅E̲̅D̲̅ ̲̅S̲̅U̲̅C̲̅C̲̅E̲̅S̲̅S̲̅F̲̅U̲̅L̲̅L̲̅Y̲̅]
Select an option from the list of commands:
1. Print the database
2. Modify the database
3. Exit
Enter your choice: 1

[P̲̅R̲̅I̲̅N̲̅T̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]
 Name || Age 
Harry || 25 
Johnny|| 18 
```

## Prompt 4
One can also modify these values. Let's say I wanted to modify Johnny's age, which is located in column **2** and row **2**.
```
Select an option from the list of commands:
1. Print the database
2. Modify the database
3. Exit
Enter your choice: 2

[M̲̅O̲̅D̲̅I̲̅F̲̅Y̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]
For reference, would you like to print the database? (y/n): y


[P̲̅R̲̅I̲̅N̲̅T̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]
 Name || Age 
Harry || 25 
Johnny|| 18 

There are a total of 2 columns and 2 rows.
Enter the column number: 2
Enter the row number: 2
Under column [Age] and data [18], enter the new value: 20
```
Now, the file looks as follows:
```
"#%8*
#%(,
%-
#:?7,~w
- # 5,~r
```
Here, I have successfully modified the data. Once I open the database file again, this is what I am greeted with:
```
 [͇̿W͇̿E͇̿L͇̿C͇̿O͇̿M͇̿E͇̿] ͇̿  [͇̿T͇̿O͇̿] ͇̿  [͇̿N͇̿A͇̿M͇̿U͇̿D͇̿B͇̿!͇̿] 
Select an option from the list of commands:
1. Create a new database
2. Load an existing database
3. Exit
Enter your choice: 2

[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅L̲̅O̲̅A̲̅D̲̅I̲̅N̲̅G̲̅:̲̅]
Enter the name of the database (note all databases are saved as .namu files): test

[D̲̅A̲̅T̲̅A̲̅B̲̅A̲̅S̲̅E̲̅ ̲̅L̲̅O̲̅A̲̅D̲̅E̲̅D̲̅ ̲̅S̲̅U̲̅C̲̅C̲̅E̲̅S̲̅S̲̅F̲̅U̲̅L̲̅L̲̅Y̲̅]
Select an option from the list of commands:
1. Print the database
2. Modify the database
3. Exit
Enter your choice: 1

[P̲̅R̲̅I̲̅N̲̅T̲̅I̲̅N̲̅G̲̅:̲̅ ̲̅]
 Name || Age 
Harry || 25 
Johnny|| 20 
```
As you can see, the data has been modified, and the database remains encrypted.

## Conclusion
Implementing this program was quite difficult, especially when it came to encrypting and decrypting, since this was my first attempt at doing so. However, it proved to be a fun experiment and project as a whole. I do plan on making this into an actual program in the future, however for now it will just be a Terminal-run program.