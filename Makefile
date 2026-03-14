CC := gcc
CFLAGS := -Iinclude
LDFLAGS := -L./out -l:libstr.a -lsqlite3

# Fontes do projeto principal
SRC := main.c $(wildcard ./src/*.c) $(wildcard ./src/handler/*.c)
OBJ := $(patsubst %.c, ./out/%.o, $(SRC))

# Fontes da biblioteca
LIB_SRC := $(wildcard ./strlib/src/*.c) $(wildcard ./strlib/src/handler/*.c)
LIB_OBJ := $(patsubst ./strlib/src/%.c, ./out/obj/%.o, $(LIB_SRC))
LIB := ./out/libstr.a

TARGET := ./out/main

# Regra principal
all: $(LIB) $(TARGET)

# Compilar biblioteca
$(LIB): $(LIB_OBJ)
	ar rcs $@ $^

# Compilar objetos da biblioteca
./out/obj/%.o: ./strlib/src/%.c | ./out/obj
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar objetos do projeto principal
./out/%.o: %.c | ./out
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Linkar executável
$(TARGET): $(OBJ) $(LIB)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Criação de diretórios
./out:
	mkdir -p ./out

./out/obj:
	mkdir -p ./out/obj

# Rodar
run: all
	@echo "=== Rodando $(TARGET) ==="
	@$(TARGET)

# Limpeza
clean:
	rm -rf ./out/*.o ./out/*/*.o ./out/*/*/*.o ./out/main ./out/libstr.a ./out/obj