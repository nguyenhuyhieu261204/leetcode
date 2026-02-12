CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Recursively find all C source files in the project
SOURCES = $(shell find . -name "*.c" -type f)
# Generate executable names by removing .c extension and directory path
PROGRAMS = $(SOURCES:.c=)

# Create directory structure for object files to avoid conflicts
OBJ_DIR = obj
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Default target
all: $(SOURCES)
	@for src in $(SOURCES); do \
		echo "Compiling $$src..."; \
		dir=$$(dirname "$$src"); \
		mkdir -p "$$dir"; \
		$(CC) $(CFLAGS) "$$src" -o "$${src%.c}"; \
	done

# Compile a specific program
compile-%:
	@src_file=$$(find . -name "$*.c" -type f | head -n 1); \
	if [ -n "$$src_file" ]; then \
		echo "Compiling $$src_file..."; \
		$(CC) $(CFLAGS) "$$src_file" -o "$${src_file%.c}"; \
	else \
		echo "Source file $*.c not found!"; \
		exit 1; \
	fi

# Run a specific program (e.g., make run-best-time-to-buy-and-sell-stock)
run-%:
	@exe_file=$$(find . -name "$*" -type f -executable | head -n 1); \
	if [ -n "$$exe_file" ]; then \
		./$$exe_file; \
	else \
		echo "Executable $* not found!"; \
		exit 1; \
	fi

# Clean all executables
clean:
	find . -type f -executable -exec rm -f {} +
	@echo "All executables removed."

# List all available programs
list:
	@echo "Available C source files:"
	@for src in $(SOURCES); do \
		exe="$${src%.c}"; \
		if [ -x "$$exe" ]; then \
			status="(compiled)"; \
		else \
			status="(not compiled)"; \
		fi; \
		echo "  $$exe $$status"; \
	done

# Help target
help:
	@echo "Available targets:"
	@echo "  all               - Compile all programs (default)"
	@echo "  clean             - Remove all executables"
	@echo "  list              - List all available programs"
	@echo "  compile-<name>    - Compile a specific program (e.g., make compile-best-time-to-buy-and-sell-stock)"
	@echo "  run-<name>        - Run a specific program (e.g., make run-best-time-to-buy-and-sell-stock)"
	@echo "  help              - Show this help message"

.PHONY: all clean list help
