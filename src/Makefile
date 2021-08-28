#Makefile
#Edited to use Xcode tools, clang++ and lldb

CFLAGS = -std=c++11 -Wall
CFLAGS += -g

all : ../obj/toolbox.o
	clang++ $(CFLAGS) -o acpd acpd.cxx ../obj/toolbox.o
	
../obj/toolbox.o : toolbox.cxx
	clang++ -c $(CFLAGS) -o ../obj/toolbox.o toolbox.cxx
	
