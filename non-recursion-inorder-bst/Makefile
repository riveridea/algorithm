INC=-I../elements-of-programming-interviews-read-only/

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++0x $(INC)

OBJS =		non-recursion-inorder-bst.o

LIBS =

TARGET =	nri

$(TARGET):	$(OBJS)
	$(CXX)  -o $(TARGET) $(INC) $(OBJS) $(LIBS) 

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

