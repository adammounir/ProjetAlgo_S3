main : main.c read_file.c struct.h
	gcc main.c read_file.c -Wall -Wextra -o main
.PHONY : clean
clean : 
	-rm $(objects) main
