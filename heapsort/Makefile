CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		heapsort.o

LIBS =

TARGET =	heapsort

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
