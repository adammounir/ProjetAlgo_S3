main : main.c read_file.c read_file.h
	gcc main.c read_file.c  -Wall -Wextra -fsanitize=address -o main
.PHONY : clean
clean : 
	-rm $(objects) main
