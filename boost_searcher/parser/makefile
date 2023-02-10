link=-lboost_system -lboost_filesystem
parser:parser.hpp parser.cpp
	g++ $^ -o $@ -std=c++11 $(link)
.PHONY:clean
clean:
	rm parser