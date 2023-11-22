CC = gcc

CFLAGS = -Wall

TARGET = main

SOURCES = main.c ADT/*.c assets/*.c database/*.c features/*.c

$(TARGET): $(SOURCES)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	@rm -f $(TARGET)

run: $(TARGET)
	@./$(TARGET)