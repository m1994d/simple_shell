`simple_shell project in progress`

The holbertonstudents-simple_shell program is a recreation of the shell as part of the assignments at the Holberton Colombia School.

<h2> FLOWCHART </h2>

(![164135193-62dd3e0d-c257-45d5-952e-1c02f8be8d8f](https://user-images.githubusercontent.com/98677728/185253413-a72ddf64-30f8-4548-8f5f-6c01b21be478.jpg)

<h2> USAGE </h2>

To use the simple_shell, compile all .c files in the repository. 

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

Then execute the resulting file,for following explanations, the executable file will be referred as hsh. 

`./hsh`

The simple_shellis capable of execute any executable file, , if it can be located at any directory of the PATH environment variable `for instance ls, pwd`.

<h2> Compilation </h2>

Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

<h2> Non interactive mode </h2>

`marlondiaz@MARLON2994:~/holbertonschool-simple_shell$ echo "ls" | ./hsh
AUTHORS   OFunctions.c  builtin.c          getPath.c  ls      man_simple_shell  shell.h
Makefile  README.md     functions_shell.c  hsh        main.c  no_builtin.c      shell_cmd.c`

By
###### Marlon Andres Diaz 
###### Marlon Amado
###### Daniel Lopez

This site was built for a project of [Holberton School Col](https://www.holbertoncolombia.com/).
