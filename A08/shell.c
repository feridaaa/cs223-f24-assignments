/*---------------------------------
 *Author: Ferida Mohammed
 *Date: 11/1/24
 *Description: 
 ---------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <limits.h>

#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
    char *input;
    char cwd[PATH_MAX];
    

    while (1) {
        // Get current working directory
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd() error");
            continue;
        }

	// Customize prompt
        char prompt[PATH_MAX + 20];
        strcpy(prompt, ANSI_COLOR_CYAN);  
        strcat(prompt, cwd);              
        strcat(prompt, " :) ");           
        strcat(prompt, ANSI_COLOR_RESET); 

        
        input = readline(prompt);

        // Check if input is NULL or "exit"
        if (!input || strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        add_history(input);

        // Split input into command and arguments
        char *args[100];
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // Fork and execute the command
        pid_t pid = fork();
        if (pid == 0) {           // Child process
            if (execvp(args[0], args) < 0) {
                perror("Error executing command");
            }
            exit(EXIT_FAILURE);
        } 
	else {                  // Parent process: wait for the child to finish
            wait(NULL);
        }

	free(input);
    }

       
    

    return 0;
}
