CXX=g++              # 指定编译器
CXXFLAGS=-std=c++11  # 指定编译选项

all: main cli

main:
	$(CXX) $(CXXFLAGS) -o ./bin/main ./src/main.cpp ./src/Account.cpp ./src/checkTask.cpp ./src/thread1.cpp ./src/Tasks.cpp -lpthread

clean:
	rm -f *.o 

cli:
	$(CXX) $(CXXFLAGS) -g -o ./bin/cli ./src/cli.cpp ./src/Account.cpp ./src/Tasks.cpp

