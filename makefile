#	Compliation Rules 
#	gcc -Wall -Werror -pedantic -Wextro -g -std=gnu89

CC = gcc 
CFLAG = -Wall -Werror -pedantic -Wextra -std=gnu89 -ggdb

shell:
	$(CC)$(CFLAG) *.c -o Shell_Beta_V0.4
	valgrind --leak-check=full ./Shell_Beta_V0.4

clean:
	rm -r shell_alpha_V0.3
