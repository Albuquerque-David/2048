# 2048
A version of 2048 built with ncurses as a Computer I final project

# Table of Content

- [How to Play](#how-to-play)
- [Dependencies](#dependencies)
  - [Debian](#debian)
  - [Arch](#arch-linux)
  - [Fedora](#fedora)
- [Compilation](#compilation)
- [Running](#running)
- [Troubleshooting](#troubleshooting)
  - [Interface](#interface)
  - [Build](#build)
- [Disclaimer](#disclaimer)

# How to Play

The game starts with 2 tiles, each of which can be, randomly, 2 or 4 . If you press any direction, all the blocks will move to this direction the as far as possible, if tiles with the same number get touched while moving, they will be merge into one. Every move add a new tile in a new random position (2 or 4, randomly).
The goal is reach up one tile to the 2048 value, you lose if you don't have any possible movement.

# Dependencies
```
gcc
make
ncurses
```
### Debian

`sudo apt-get install libncurses5-dev gcc make`

### Arch Linux
`sudo pacman -S make gcc ncurses`

### Fedora
 `yum install gcc make ncurses`

# Compilation
```
git clone https://github.com/edufcarvalho/2048
cd 2048
make or gcc -lncurses -O2 -Wall -ansi -pedantic -Wno-unused-result src/*.c -o 2048
```

# Running

`make run` or `./2048`

# Troubleshooting

### Interface

If you have interface issues, it means your OS isn't ready to work with unicode characters, when you run the game, use the the `--no--unicode` flag and a simpler interface will appear. Ex.: `./2048 --no-unicode`

### Build

Package managers has some issues with ncurses installing, if the makefile don't be able to access the library (see [dependencies](#dependencies)) use the command `gcc -lncurses -O2 -Wall -ansi -pedantic -Wno-unused-result src/*.c -o 2048` to compile.

# Disclaimer

Some of the commits and release tags are 100% in portuguese because the game was made as a college project, and we are supposed to write this on our maternal language. You can see the original repository clicking [here](https://github.com/C1-UFRJ-G2/Trabalho-1-de-Comp-1-2020-PLE---2048).