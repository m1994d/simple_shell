`simple_shell project in progress`

The holbertonstudents-simple_shell program is a recreation of the shell as part of the assignments at the Holberton Colombia School.


<details><summary> FLOWCHART </summary>

<p>
<h2> FLOWCHART </h2>

(![164135193-62dd3e0d-c257-45d5-952e-1c02f8be8d8f](https://github.com/m1994d/holbertonschool-simple_shell/blob/main/images/Flow_chart_shell.png)

</p>

</details>

<details><summary>Usage</summary>

<p>
<h2> USAGE </h2>

To use the simple_shell, compile all .c files in the repository. 

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

Then execute the resulting file,for following explanations, the executable file will be referred as hsh. 

`./hsh`

The simple_shellis capable of execute any executable file, , if it can be located at any directory of the PATH environment variable `for instance ls, pwd`.

</p>

</details>

<details><summary> Invocation</summary>

<p>
<h2> Invocation </h2>

After compile all .c located in this repository you can call the created shell using:

`./hsh`
</p>

</details>

<details><summary>Non interactive mode</summary>

<p>
<h2> Non interactive mode </h2>

`$:~/holbertonschool-simple_shell$ echo "ls" | ./hsh
AUTHORS   OFunctions.c  builtin.c          getPath.c  ls      man_simple_shell  shell.h
Makefile  README.md     functions_shell.c  hsh        main.c  no_builtin.c      shell_cmd.c`
</p>

</details>

<h2> Structure in shell.h </h2>

```
/**
 * struct SLL - structure to manage the shell
 * @flags: arguments
 * @Command: parameter command
 * @num_flags: number of arguments
 */
typedef struct SLL
{
	char *Command;
	char **flags;
	int num_flags;
} sll_t;

```

By
###### Marlon Andres Diaz 
###### Marlon Amado
###### Daniel Lopez

This site was built for a project of [Holberton School Col](https://www.holbertoncolombia.com/).
