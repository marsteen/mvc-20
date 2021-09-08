#**********************************************************************
#
# DiePlaneten - makefile
#
# written 2007 by Martin Steen
# dieplaneten@martin-steen.de
#
#**********************************************************************
#
# C++ : Name of C++ Compiler
#
C++ = g++
#
.SUFFIXES : .cpp .o
#
CPPFILES = main.cpp
#
#
TARGET   = cpp_concepts
#
default : $(TARGET)
#
CPPFLAGS = -std=c++2a
#
.cpp.o:
	$(C++) -c $(CPPFLAGS) -o$@ $<

#
clean:
	rm -f $(CPPOBJECTS) $(TARGET)
#
CPPOBJECTS = $(CPPFILES:.cpp=.o)
#
#
$(TARGET) : $(CPPOBJECTS)
	$(C++) $(CPPOBJECTS) -o $(TARGET)
