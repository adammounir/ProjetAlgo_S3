main : main.c read_file.c read_file.h root.c sentence.c
	gcc main.c read_file.c root.c sentence.c -Wall -Wextra -o main
	
.PHONY : clean
clean : 
	-rm $(objects) main
