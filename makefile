CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

all: launcher.cpp tokeit.cpp dosegfault.cpp doexiteight.cpp
        $(CC) $(CFLAGS) -o launcher launcher.cpp
        $(CC) $(CFLAGS) -o tokeit tokeit.cpp
        $(CC) $(CFLAGS) -o dosegfault dosegfault.cpp
        $(CC) $(CFLAGS) -o doexiteight doexiteight.cpp

launcher: launcher.cpp
        $(CC) $(CFLAGS) -o launcher launcher.cpp

tokeit: tokeit.cpp
        $(CC) $(CFLAGS) -o tokeit tokeit.cpp

clean:
        rm -rf launcher
        rm -rf tokeit
        rm -rf dosegfault
        rm -rf doexiteight
        rm -rf *.o


