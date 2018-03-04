CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/main


c_parser.tab.cpp c_parser.tab.hpp : c_parser.y
	bison -v -d c_parser.y -o c_parser.tab.cpp

c_lexer.yy.cpp : c_lexer.flex c_parser.tab.hpp
	flex -o c_lexer.yy.cpp  c_lexer.flex

main.o : ast.hpp ast/*.hpp


bin/main : main.o c_parser.tab.o c_lexer.yy.o c_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/main $^

clean :
	rm c_src/*.o
	rm bin/*
	rm c_src/*.tab.cpp
	rm c_src/*.yy.cpp
