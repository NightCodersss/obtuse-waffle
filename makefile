CXX=g++
CFLAGS=-c -std=c++14 -g -Wall -Wextra -Werror -pedantic
LDFLAGS=-lopencv_core -lopencv_imgproc
SOURCES=main.cpp opencv_image.cpp opencv_image_binarizer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
