namudb: DBDriver.cpp Database.cpp Database.h Encryption.cpp Encryption.h
	g++ -std=c++17 -o namudb DBDriver.cpp 

run:
	./namudb