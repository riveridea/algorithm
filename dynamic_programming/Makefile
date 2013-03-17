CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		dyn_prog.o knapsack.o changemaking.o

LIBS =

TARGET =	dyn_prog

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
