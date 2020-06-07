#SRC=$(wildcard src/*.cpp)
TARGET = txLog

SRCDIR=src
INC=include
ODIR=obj

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(SRCS:$(SRCDIR)/%.cpp=$(ODIR)/%.o)
#OBJ=$(SRC:.cpp=$(ODIR)/%.o)
CXX=$(shell wx-config --cxx)
WX_LIBS = $(shell wx-config --libs std,richtext)
WX_CXXFLAGS = $(shell wx-config --cxxflags)
CXXFLAGS=-I$(INC) $(WX_CXXFLAGS) $(WX_LIBS)

$(TARGET): $(OBJ)
	$(info OBJ=$(OBJ))
	$(info SRCS=$(SRCS))
	$(info TARGET=$(TARGET))
	$(info SRC=$(SRC))
	$(CXX) $(OBJ) $(CXXFLAGS) -o $@

$(OBJ): $(ODIR)/%.o : $(SRCDIR)/%.cpp
	$(info SRC=$(SRCS))
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./txLog

.PHONY: clean

clean:
	rm -f $(OBJ) run

