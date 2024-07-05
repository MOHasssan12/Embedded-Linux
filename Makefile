CC=gcc
INCS=../include
src=$(wildcard *.c)
obj=$(patsubst %.c,%.o,$(src))
programType=calc

all:$(programType)
%.o:%.c
	$(CC) -I $(INCS) -c $< 

$(programType):$(obj)
	$(CC)  $(obj) -o $(@) 

.PHONY: clean

clean:
	@rm -f $(obj)
	@rm -f $(programType)


