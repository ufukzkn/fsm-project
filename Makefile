# Run with the following commands: 
# cd "h:\\directory_of_file"
# mingw32-make         <- Run "all"
# mingw32-make clean   <- Run "clean"
# ./main.exe           <- Run the executable

all: main.o Person.o Customer.o BankEmployee.o BankSystem.o
	g++ main.o Person.o Customer.o BankEmployee.o BankSystem.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp

Person.o: Person.cpp Person.hpp
	g++ -c Person.cpp

Customer.o: Customer.cpp Customer.hpp
	g++ -c Customer.cpp

BankEmployee.o: BankEmployee.cpp BankEmployee.hpp
	g++ -c BankEmployee.cpp

BankSystem.o: BankSystem.cpp BankSystem.hpp
	g++ -c BankSystem.cpp

clean:
	rm -f *.o main.exe
