// Original Project Template given by Professor Sonmez A.
//
// Author: Tyler Griggs
// Last Edit Date: 11/18/2020
// VCU CMSC 257 FA20
//
// This file contains the logic for running a simple shell within a bash shell.
//      Some built-in commands and associated function calls are contained in this program.
//      This shell also provides the ability to use regular Linux shell commands for those which
//      are not already contained within this program.
//
// In general, comments with //   are from Author Tyler Griggs
//       while comments with /**/ are from Professor Sonmez A. template file
//
// ---------- Built-In Commands ----------
// pid      prints the Process IDentification number
// ppid     prints the PID of the parent process to which called it
// cd       "cd [directory]"    changes the working directory to [directory], and prints currect PATH
//          "cd"                prints the currect working directory PATH
// help     prints the Developer Name, Built-In Commands, and reference to Linux "man" manual pages
// exit     exits the shell using raise(), by sending itself a signal to kill its parent process (the shell)

/* $begin shellmain */
#include "csapp.h"
#define MAXARGS 128

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

static volatile int keepRunning = 1; // Shell Loop Boolean

void intHandler(int temp)
{ // Could do something on receiving interrupt signal
    // This program just keeps running shell
    keepRunning = 1;
}

int main(int argc, char *argv[])
{
    char cmdline[MAXLINE];           /* Command line */
    char prompt[64];                 // Create storage for prompt string
    strncpy(prompt, "my257sh>", 64); // Default Shell Prompt 'my257sh>'
    if (argc > 2)
    { // If argument count > 2, get argument 3, and put into string
        // From Project3 Help Video by Sonmez A. (@34:17)
        strncpy(prompt, strcat(argv[2], ">"), 64);
    }

    while (keepRunning) // MAIN LOOP, catches ^C interrupt
    {
        // Prepare to handle interupt signal ^C
        signal(SIGINT, intHandler);

        /* Read */
        printf("%s", prompt);
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);

        /* Evaluate */
        eval(cmdline);
    }
    return 0;
}
/* $end shellmain */

/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline)
{
    char *argv[MAXARGS]; /* Argument list execvp() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return; /* Ignore empty lines */

    if (!builtin_command(argv))
    {
        if ((pid = Fork()) == 0)
        { /* Child runs user job */
            if (execvp(argv[0], argv) < 0)
            {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

        /* Parent waits for foreground job to terminate */
        if (!bg)
        {
            int status;
            if (waitpid(pid, &status, 0) < 0)
            {
                unix_error("waitfg: waitpid error");
            }
            else
            { // Print the Child Process Exit Status on completion
                printf("Child Exit Status: %d\n\n", WEXITSTATUS(status));
            }
        }
        else
            printf("%d %s", pid, cmdline);
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv)
{
    // Kill Parent Shell Process if exit signal is raised in cmdline
    signal(SIGINT, kill(getppid(), SIGINT));

    if (!strcmp(argv[0], "quit")) /* quit command */
        exit(0);

    if (!strcmp(argv[0], "exit")) // Exit command //
        raise(SIGINT);            // exits the shell using raise() signal to self

    if (!strcmp(argv[0], "pid")) // Process ID command //
    {
        printf("%d\n\n", getpid());
        return 1;
    }
    if (!strcmp(argv[0], "ppid")) // Parent Process ID command //
    {
        printf("%d\n\n", getppid());
        return 1;
    }
    if (!strcmp(argv[0], "cd")) // Working Directory command(s) //
    {
        char s[100];

        if (argv[1] == NULL)
        { // For command "cd" Print out the working directory only
            printf("%s\n\n", getcwd(s, 100));
        }
        else
        { // For command "cd [directory]" Change to [directory],
            //      and print out the new working directory
            chdir(argv[1]);
            printf("%s\n\n", getcwd(s, 100));
        }
        return 1;
    }
    if (!strcmp(argv[0], "help")) // User Help command //
    {                             // Prints out Developer Information, and User-usage tips
        printf("\n*******************************************************************\n"
               "Developer Name: Tyler Griggs\n\n"
               "To change shell prompt, run the program with\n   "
               "   \"./my257sh -p [new_prompt]\"\n\n"
               "------------------- Built-In Commands ----------------------------\n"
               "pid      prints the Process IDentification number\n"
               "ppid     prints the PID of the parent process to which called it\n"
               "cd       \"cd [directory]\"    changes the working directory to [directory], and prints currect PATH\n"
               "         \"cd\"                prints the currect working directory PATH\n"
               "help     prints the Developer Name, Built-In Commands, and reference to Linux \"man\" manual pages\n"
               "exit     exits the shell using raise(), by sending itself a signal to kill its parent process (the shell)\n\n"
               "Or try using \"man [command]\" to refer to the Linux manual pages for that command.\n"
               "*******************************************************************\n\n");
        return 1;
    }
    if (!strcmp(argv[0], "&")) /* Ignore singleton & */
        return 1;

    // Otherwise it's not a built-in command
    return 0;
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv)
{
    char *delim; /* Points to first space delimiter */
    int argc;    /* Number of args */
    int bg;      /* Background job? */

    buf[strlen(buf) - 1] = ' ';   /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
        buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' ')))
    {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) /* Ignore spaces */
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0) /* Ignore blank line */
        return 1;

    /* Should the job run in the background? */
    if ((bg = (*argv[argc - 1] == '&')) != 0)
        argv[--argc] = NULL;

    return bg;
}
/* $end parseline */
