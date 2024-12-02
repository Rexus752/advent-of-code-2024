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
ARRAY_SORT_SRC = $(SRCDIR)/array_sort.c

# Object files
MAIN_OBJ = $(OBJDIR)/main.o
ARRAY_SORT_OBJ = $(OBJDIR)/array_sort.o

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
$(MAIN_EXE): $(MAIN_OBJ) $(ARRAY_SORT_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(ARRAY_SORT_OBJ) -o $@

# Main object file
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Edit distance object file
$(ARRAY_SORT_OBJ): $(ARRAY_SORT_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Phony targets
.PHONY: all clean
