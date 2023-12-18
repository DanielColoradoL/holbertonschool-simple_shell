# Simple Shell Project
by Team Daniel and Nick (Cohort 22) Holberton School Australia, Melbourne

This is a simple Unix shell implementation developed as part of the curriculum at Holberton School. The shell supports both interactive and non-interactive modes, basic command execution, including built-in commands and external commands.

**Features**
* Interactive command execution
* Non-interactive command execution
* Executing commands from a file
* Handling command arguments
* Environment variable expansion
* Error handling and exit status
* Signal handling (Ctrl+C)
* Custom prompt display

This is created with C (programming language) and vim (code editor).

## Table of Contents
* [Installation](#installation)
* [Usage](#usage)
* [Flowchart](#flowchart)
* [Documentation](#documentation)
* [Author](#author)
* [Copyright](#copyright)


## Installation
To run this project, install it locally by cloning our repository using the command ```git clone``` as shown below:

```
git clone https://github.com/DanielColoradoL/holbertonschool-simple_shell
```

## Usage

### Makefile

Our repository contains a _makefile_, and with file it allows you to compile all of the c files in the repo with simple command ```make``` and when you do this it will create an executable called ```./hsh```.

Here are some useful commands:

* ```make```: Compile the shell
* ```make clean```: Remove object files

### Interactive Mode

When you run in interactive mode ```./hsh``` the outcome will be:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

### Non-Interactive Mode

When you run in non-interactive mode, the outcome will be:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Built-in Commands
The shell supports the following built-in commands:

```exit```: Exit the shell
```env```: Print the current environment
```pwd```: Show the path of the current working directory

### External Commands
The shell is capable of executing external commands by searching for the corresponding executable files in the directories listed in the ```PATH``` environment variable. It uses the ```execve``` system call to launch external programs.


## Flowchart
Below is a flowchart showing the basic implementation of how our function works and the steps the function goes through to return the desired result.

![_printf flowchart](https://github.com/haoningng/holbertonschool-printf/blob/master/_printf%20flowchart.jpg)

## Documentation

### MANUAL
To see the manual page for this function, type the following line into the command line:

```
man ./man_1_simple_shell
```

## AUTHORS

Please read the [AUTHORS](https://github.com/DanielColoradoL/holbertonschool-simple_shell/blob/main/AUTHORS) file for details on our code of conduct, and the process for submitting pull requests.

## COPYRIGHT

This Simple Shell was created for educational purposes under the framework and guidance of Holberton School, Melbourne Australia.
