# Compiler and flags
CC = gcc
CFLAGS = -I. -Wall -Wextra

# Linker flags
LDFLAGS = -lcmocka -Wl,--wrap=add_numbers

# Source files
SRCS = UTest_Add.c add.c internal.c

# Output binary
TARGET = test_calculate_sum

# Default target
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Clean up the generated files
clean:
	rm -f $(TARGET)
	rm -f *.o
