CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		dfs_iterative.o

LIBS =

TARGET =	dfs_iterative

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
