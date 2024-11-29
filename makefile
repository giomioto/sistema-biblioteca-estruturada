# Nome do compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -std=c11

# Nome do executável
TARGET = main

# Lista de arquivos fonte
SRCS = main.c

# Regra padrão
all: $(TARGET)
# Obter todos os arquivos .c no diretório atual
SRCS = $(wildcard *.c)

# Obter os nomes dos arquivos objeto correspondentes
OBJS = $(SRCS:.c=.o)

# Regra para compilar todos os arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar o executável com todos os arquivos objeto
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
# Regra para compilar o executável
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Regra para limpar arquivos compilados
clean:
	rm -f $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)