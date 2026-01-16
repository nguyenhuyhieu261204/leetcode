CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Find all C source files in the current directory
SOURCES = $(wildcard *.c)
PROGRAMS = $(SOURCES:.c=)

# Default target
all: $(PROGRAMS)

# Compile each program
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Special rule to avoid issues with intermediate files
$(PROGRAMS): $(SOURCES)

# Run a specific program (e.g., make run-best-time-to-buy-and-sell-stock)
run-%:
	./$*

# Clean executables
clean:
	rm -f $(PROGRAMS)

# List all available programs
list:
	@echo "Available programs:"
	@for prog in $(PROGRAMS); do \
		echo "  $$prog"; \
	done

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Compile all programs (default)"
	@echo "  clean   - Remove all executables"
	@echo "  list    - List all available programs"
	@echo "  run-<name> - Run a specific program (e.g., make run-practice1)"
	@echo "  help    - Show this help message"

.PHONY: all clean list help
