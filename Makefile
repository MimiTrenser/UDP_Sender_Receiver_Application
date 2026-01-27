# Compiler settings
CC = gcc
CFLAGS = -Wall -g

# Source directory
SRC_DIR = src

# Targets
all: server client

# Build the server executable from src/server.c
server: $(SRC_DIR)/server.c
	$(CC) $(CFLAGS) -o server $(SRC_DIR)/server.c

# Build the client executable from src/client.c
client: $(SRC_DIR)/client.c
	$(CC) $(CFLAGS) -o client $(SRC_DIR)/client.c

# Clean up binaries
clean:
	rm -f server client

