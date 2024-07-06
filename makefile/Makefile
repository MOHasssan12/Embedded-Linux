CC=gcc
INCS=./include/
src=./src/
obj=./bin/
source=$(wildcard ./src/*.c)
object=$(patsubst ./src/%.c,./bin/%.o,$(source))

programType=calc

all:$(programType)
$(obj)%.o:$(src)%.c
	$(CC) -I $(INCS) -c $< -o $@ 

$(programType):$(object)
	$(CC) -I $(INCS)  $(object) -o ./build/$(programType) 

.PHONY: clean

clean:
	@rm -f $(obj)
	@rm -f $(programType)



