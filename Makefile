CXX=g++              # 指定编译器
CXXFLAGS=-std=c++11  # 指定编译选项

all: main

main:
	$(CXX) $(CXXFLAGS) -o main main.cpp Account.cpp checkTask.cpp search.cpp thread1.cpp  Tasks.cpp -lpthread

clean:
	rm -f *.o main

