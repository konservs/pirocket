TARGET = pirocket
CC = gcc
FLAGS = -Iinc -Wall -lm
ODIR = obj
SDIR = src
_OBJS = main.o smbus.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

.PHONY: all clean


	
all: $(TARGET)
	
clean:
	rm -rf $(TARGET) $(OBJS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $^
