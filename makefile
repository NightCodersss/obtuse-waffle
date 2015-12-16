CXX=g++
CFLAGS=-c -std=c++14 -g -Wall -Wextra -Werror -pedantic -DBOOST_LOG_DYN_LINK
LDFLAGS=-lopencv_core -lopencv_imgproc -lopencv_highgui -lpthread  -lboost_log -lboost_system -lboost_thread `pkg-config opencv --libs`
SOURCES=main.cpp opencv_image.cpp opencv_image_binarizer.cpp opencv_image_loader.cpp opencv_image_denoiser.cpp image_preprocessor.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
