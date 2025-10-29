SRC = src/main.c src/lex/lex_ll.c src/lex.c
END = coalc.bin 

COMP = gcc
FLAGS = -I include

all: $(END)

$(END): $(SRC)
	$(COMP) $(SRC) -o $(END) $(FLAGS)

clean:
	rm $(END)

.PHONY: all clean
