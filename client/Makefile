CXX= g++
CXXFLAGS= -std=c++17 -Wall
LDFLAGS= -lboost_system -lpthread

SRCS= $(wildcard *.cpp)
OBJS= $(SRCS:.cpp=.o)

TARGET= client

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean: 
	rm -f $(OBJS) $(TARGET)
