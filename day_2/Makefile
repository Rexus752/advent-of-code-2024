# Compiler
CC := gcc

# Compiler flags
CFLAGS := -g -Wall -Wextra -Wpedantic -Wconversion

# Directories
SRCDIR = src
BINDIR = bin
OBJDIR = build

# Source files
MAIN_SRC = $(SRCDIR)/main.c

# Object files
MAIN_OBJ = $(OBJDIR)/main.o

# Executables
MAIN_EXE = $(BINDIR)/main

# Targets
all: $(BINDIR) $(OBJDIR) $(MAIN_EXE)

# Folder creation
$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Main target
$(MAIN_EXE): $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -o $@

# Main object file
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Phony targets
.PHONY: all clean
