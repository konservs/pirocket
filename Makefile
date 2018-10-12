TARGET = pirocket
#CC = gcc
CC = g++
FLAGS = -Iinc -Wall -lm
ODIR = obj
SDIR = src

_OBJSC = main.o smbus.o
_OBJSX = altimeter.o

OBJSC = $(patsubst %,$(ODIR)/%,$(_OBJSC))
OBJSX = $(patsubst %,$(ODIR)/%,$(_OBJSX))


.PHONY: all clean

	
all: $(TARGET)
	
clean:
	rm -rf $(TARGET) $(OBJSC) $(OBJSX)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(TARGET): $(OBJSC) $(OBJSX)
	$(CC) $(FLAGS) -o $(TARGET) $^
