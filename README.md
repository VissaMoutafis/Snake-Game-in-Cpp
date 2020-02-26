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

- [x] Increase speed of the snake when it devours a snack.
- [x] Add a scoreboard.
- [ ] Fix the window-resize factor, since it gets all messy when you minimize/maximize the terminal window.
- [x] Create a 'Game' class and provide interface through that function so that the user don't have to mess with the graphics    snake and controller classes. 
- [ ] Implement the Game::printGameStatistics function to print the score and games played of each player.

---

## Prerequisities

You need to install the following packages:

- __libncurses5-dev__ : Developer’s libraries for ncurses,
- __libncursesw5-dev__ : Developer’s libraries for ncursesw,
- __gcc__ : C\C++ compiler,
- __make__ : instalation tool.

Open up a terminal and type the folllowing commands:

```shell
#make sure everything is updated
~$ sudo apt update && sudo apt upgrade

#Now to install compiler and instalation tool
~$ sudo apt-get install gcc make

#And the actuall library (ncurses)
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

__Note__: You might want to delete the objective files and keep only the src part (__clean up__). In that case:
```shell
~$ make clean
```
and you are set.

---

## Contributors
[VissaM](https://github.com/VissaMoutafis)

Special thanks to [plato(otalpster)](https://github.com/otalpster) for fixing a bug that i would never notice! (Thnx man)

---

## Licence: MIT
Check the file LICENCE or click the following [link](https://github.com/VissaMoutafis/Snake_Game_in_Cpp/blob/master/LICENSE).

## Appendix
If you are interested to know more about terminal gui apps and __especially ncurses library__, check [this](http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html) out!

Another ncurses guide (maybe more begginer friendly) is [this](http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html) one.

### Enjoy!
