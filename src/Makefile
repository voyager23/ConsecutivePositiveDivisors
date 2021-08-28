#Makefile
#Edited to use Xcode tools, clang++ and lldb

CFLAGS = -std=c++11 -Wall
CFLAGS += -g

all : ../obj/toolbox.o
	g++ $(CFLAGS) -o acpd acpd.cxx ../obj/toolbox.o
	
diag : ../obj/toolbox.o
	g++ $(CFLAGS) -o diag diag.cxx ../obj/toolbox.o
	
../obj/toolbox.o : toolbox.cxx
	g++ -c $(CFLAGS) -o ../obj/toolbox.o toolbox.cxx
	
