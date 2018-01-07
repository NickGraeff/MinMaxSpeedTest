# Using the g++ compiler
CC = g++

# Compile-time flags
CFLAGS = -std=c++11

# Include external header files
INCLUDES = -I../nsh

# Define the source files
SRCS1 = DivConq.cpp
SRCS2 = LazyLoop.cpp

# Define the object files
OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)

# Define the name of the executable file
MAIN1 = DivConqMethod 
MAIN2 = LazyLoopMethod 

# Build the executable
default: $(MAIN1) $(MAIN2)
		 @echo Compiled DivConq and LazyLoop project successfully

# Files required to maintain the executable
$(MAIN1): $(SRCS1)
		 $(CC) $(SRCS1) -o $(MAIN1)

# Files required to maintain the executable
$(MAIN2): $(SRCS2)
		 $(CC) $(SRCS2) -o $(MAIN2)

# Clean up the old project
clean:
		 $(RM) *.o *~ $(MAIN1) $(MAIN2)

