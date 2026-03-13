CC := gcc
CFLAGS := -I../strlib/include -I./include
LDFLAGS := -L../strlib/out -l:libstr.a -lsqlite3

SRC := $(wildcard ./src/*.c ./src/memory/*.c ./src/strlib/*.c ./src/strlib/handler/*.c)
OBJ := $(patsubst ./src/%.c, ./out/%.o, $(SRC))

TARGET := ./out/main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

./out/%.o: ./src/%.c | ./out
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

./out:
	mkdir -p ./out

run: all
	@echo "=== Rodando $(TARGET) ==="
	@$(TARGET)

clean:
	rm -rf ./out/*.o ./out/*/*.o ./out/*/*/*.o ./out/main