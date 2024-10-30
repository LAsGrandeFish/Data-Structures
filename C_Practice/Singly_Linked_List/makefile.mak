CC = gcc
CFLAGS = -I../Unity-master/src
SOURCES = sll_unit_tests.c singly_linked_list.c node.c
TARGET = sll_unit_tests

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
