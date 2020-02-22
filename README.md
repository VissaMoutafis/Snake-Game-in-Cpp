# Snake Game in C++

## Abstract

A simple snake game, with terminal GUI implemented using ncurses library.

#### Controls:

- __Up-Arrow__ to go up.
- __Down-Arrow__ to go down.
- __Left-Arrow__ to go left.
- __Right-Arrow__ to go right.
- __q__ to exit game. 

### TODO:

- [ ] Add a scoreboard.
- [ ] Fix the window-resize factor, since it gets all messy when you minimize/maximize the terminal window.

---

## Prerequisities

You need to install the following two packages:

- __libncurses5-dev__ : Developer’s libraries for ncurses,
- __libncursesw5-dev__ : Developer’s libraries for ncursesw,
- __gcc__ : C\C++ compiler,
- __make__ : instalation tool.

Open up a terminal and type the folllowing commands

```shell
~$ sudo apt update && sudo apt upgrade
#Now to install compiler and instalation tool
~$ sudo apt-get install gcc make
#And the actuall library
~$ sudo apt-get install libncurses5-dev libncursesw5-dev
```
Now you are ready to use the repo.

---

## Downloading, Instalation and Running the Program

Now we will install and run the program, but first let's download the repo:

```shell
~$ git clone https://github.com/VissaMoutafis/Snake_Game_in_Cpp

# cd in the directory
~$ cd Snake_Game_in_Cpp

#run the 'make run' to install and play
~$ make run
```

and enjoy playing!

__Note__: You might want to delete the objective files and keep only the src part. In that case:
```shell
~$ make clean
```
and you are set.

---

## Contributors
[VissaM](https://github.com/VissaMoutafis)

---

## Licence: MIT
Check the file LICENCE.

### Enjoy!
