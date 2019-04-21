CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

all: launcher.cpp tokeit.cpp
        $(CC) $(CFLAGS) -o launcher launcher.cpp
        $(CC) $(CFLAGS) -o tokeit tokeit.cpp

launcher: launcher.cpp
        $(CC) $(CFLAGS) -o launcher launcher.cpp

tokeit: tokeit.cpp
        $(CC) $(CFLAGS) -o tokeit tokeit.cpp

clean:
        rm -rf launcher
        rm -rf tokeit
        rm -rf *.o

