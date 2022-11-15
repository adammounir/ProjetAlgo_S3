main : main.c read_file.c read_file.h root.c
	gcc main.c read_file.c root.c  -Wall -Wextra  -fsanitize=address -o main
.PHONY : clean
clean : 
	-rm $(objects) main
