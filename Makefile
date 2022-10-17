CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

OBJS = llrec.o llrec-test.o

llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

llrec.o: llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

llrec-test.o: llrec-test.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

stack: stack.h stack_test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) stack_test.cpp -o stack
	
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 