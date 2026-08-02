COMPILER = gcc
CFLAGS = -Wall -g -I.

# 1. Busca todos os .c (ignora a pasta out)
SRCS = $(shell find . -name "*.c" -not -path "./out/*")

# 2. Força todos os arquivos .o a terem "out/" no começo do caminho
OBJS = $(patsubst %.c, out/%.o, $(SRCS))

all: app

# O executável final fica na raiz
app: $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o app

# Regra que cria as subpastas dentro de out/ e compila os objetos lá dentro
out/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILER) $(CFLAGS) -c $< -o $@

# Executa o programa a partir da raiz
run: all
	./app

.PHONY: clean run
clean:
	rm -rf out app
