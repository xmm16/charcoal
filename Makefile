SRC = src/main.c src/lex/lex_ll.c src/lex.c src/tree.c
END = coalc.bin 
END_D = coalc_debug.bin

COMP = gcc
FLAGS = -I include

all: $(END)

$(END): $(SRC)
	$(COMP) $(SRC) -o $(END) $(FLAGS)

debug: $(END_D)

$(END_D): $(SRC)
	$(COMP) $(SRC) -o $(END_D) $(FLAGS) -g

clean:
	rm -rf $(END) $(END_D)

.PHONY: all clean
