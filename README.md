Simple Shell

Introduction

This repository is a Holberton School Project. The school project consisted in writing a shell like sh (Bourne Shell) by Stephen Bourne, in C, using a limited number of standard library functions. So instead, we used our own functions that we rewrote over the past three months.

The goal in this project was to make us understand how a shell works. To single out some items: what is the environment, the difference between functions and system calls, how to create processes using execve...

====Task1 : 1. Simple shell 0.1========
Write a UNIX command line interpreter.

    Usage: simple_shell

Your Shell should:

    Display a prompt and wait for the user to type a command. A command line always ends with a new line.
    The prompt is displayed again each time a command has been executed.
    The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
    The command lines are made only of one word. No arguments will be passed to programs.
    If an executable cannot be found, print an error message and display the prompt again.
    Handle errors.
    You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

    use the PATH
    implement built-ins
    handle special characters : ", ', `, \, *, &, #
    be able to move the cursor
    handle commands with arguments

execve will be the core part of your Shell, don’t forget to pass the environ to it…
====Task2 : 2. Simple shell 0.2========
Simple shell 0.1 +

    Handle command lines with arguments
