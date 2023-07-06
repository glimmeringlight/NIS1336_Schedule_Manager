CXX=g++              # 指定编译器
CXXFLAGS=-std=c++11  # 指定编译选项

all: main

main:
	$(CXX) $(CXXFLAGS) -o bin/main main.cpp Account.cpp checkTask.cpp Tasks.cpp -lpthread

clean:
	rm -f *.o 

cli:
	$(CXX) $(CXXFLAGS) -o bin/cli cli.cpp Account.cpp Tasks.cpp

