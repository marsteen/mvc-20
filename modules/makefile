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
.SUFFIXES : .cpp .o .cppm .pcm
#
CPPFILES = source/main.cpp
MODFILES = source/math.cppm \
           source/math2.cppm
#
#
TARGET   = cppmod
#
default : $(TARGET)
#
CPPFLAGS = -std=c++2a -fmodules-ts -fprebuilt-module-path=./source
#
.cpp.o:
	$(C++) -c $(CPPFLAGS) -o$@ $<

#
clean:
	rm -f $(CPPOBJECTS) $(MODOBJECTS) $(PCMFILES)
#
CPPOBJECTS = $(CPPFILES:.cpp=.o)
MODOBJECTS = $(MODFILES:.cppm=.o)
PCMFILES   = $(MODFILES:.cppm=.pcm)
#
modules : $(MODFILES)
	./compilemod.sh $(MODFILES)

#
$(TARGET) : $(CPPOBJECTS)
	$(C++) $(MODOBJECTS) $(CPPOBJECTS) -o $(TARGET)
