#Makefile to compile the project

CXX = g++
CXXFLAGS = -g -Wall
RM = rm -f

PROJECT = main.exe
SOURCE = main.cpp TwiST.cpp AT.cpp non_zero.cpp phi_function.cpp prod_c_V.cpp psi_function.cpp vector_minus.cpp vector_prod.cpp vector_sum.cpp
HEADER = functions.h
OBJS = $(subst .cc,.o,$(SOURCE)))

#*********************

all: $(PROJECT)
	
$(PROJECT):
	$(CXX) $(CXXFLAGS) $(HEADER) $(SOURCE) -o $(PROJECT)

clean: 
	$(RM) $(OBJS)
