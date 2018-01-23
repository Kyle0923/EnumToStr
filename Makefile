CXX = g++ -std=c++11
HEADER = EnumToStr.h
INC = .
usrCode = main.cpp
output = main

all: $(usrCode:.cpp=.o)
	$(CXX) $(usrCode:.cpp=.o) -o $(output)

%.o: %.cpp
	$(CXX) -c $<

clean:
	rm $(output) $(usrCode:.cpp=.o)
