GPP = g++

B = bison 
F = flex

TARGET = COMPILER

GRAMMER_FILES = Parser/grammer.cpp
LEXER_FILES =  Lexer/lexer.cpp

CPP_FILES = InterMedCode/IC.cpp LDefs/operators.cpp SymbolTable/symbol.cpp CodeGen/codeGen.cpp 
MAIN_SRC_FILE = Helium.cpp

run: $(TARGET)
	./COMPILER Helium_TEST_CODE
	rm -f COMPILER 

all: $(TARGET) 

$(TARGET) : $(GRAMMER_FILES) $(LEXER_FILES) $(CPP_FILES)
	$(GPP) -o COMPILER $(GRAMMER_FILES) $(LEXER_FILES) $(CPP_FILES) $(MAIN_SRC_FILE) -g

Parser/grammer.cpp : Parser/grammer.y
	-rm -f Parser/grammer.cpp Parser/grammer.hpp 
	$(B) -d -o Parser/grammer.cpp Parser/grammer.y 

Lexer/lexer.cpp : Lexer/lexfile.l
	-rm -f Lexer/lexer.cpp
	$(F) -o Lexer/lexer.cpp Lexer/lexfile.l

clean:
	rm -f COMPILER 



