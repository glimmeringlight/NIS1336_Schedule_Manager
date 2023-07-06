CXX=g++              # 指定编译器
CXXFLAGS=-std=c++11  # 指定编译选项

all: main

main: Account.o 
	$(CXX) $(CXXFLAGS) -o main main.cpp Account.o checkTask.cpp Tasks.cpp -lpthread

clean:
	rm -f *.o main
	rm USER_PWD.txt
