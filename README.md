# What is `fillit` ?

`fillit` is a program that solves a Tetris-like puzzle game.
It is a program that finds a way to assemble a given set of **Tetriminos(Tetris pieces)** altogether in the smallest possible square in the minimal amount of time, despite an exponentially growing number of possibilities each time a piece is added.

**This project was collaborated with an exceptionally skilled software developer,** [Gliperal](https://github.com/Gliperal).

# Game rules

### General rules

- Write in C
- Use of C Standard Library is forbidden. Use your self-written-library if necessary.
- Only allowed to use the following functions across the entire project.
    - open
    - close
    - write
    - read
    - malloc
    - free
    - exit
- Can have any memory leaks
- Global variables are forbidden

### Program entry

Your executable must take only one parameter, a file which contains a list of Tetriminos
to assemble. This file has a very specific format : every Tetrimino must exactly fit in a
4 by 4 chars square and all Tetriminos are **separated by a newline** each.

If the number of parameters sent to your executable is not 1, your program must display
its usage and exit properly. Your file should contain between 1 and 26 Tetriminos.

The description of Tetriminos must respect the following rules :

- Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
- A Tetrimino is a classic piece of Tetris composed of 4 blocks.
- Each character must be either a block character(’#’ ) or an empty character (’.’).
- Each block of a Tetrimino must touch at least one other block on any of his 4 sides
(up, down, left and right).

A few examples of valid descriptions of Tetriminos:

```
.... .... #### .... .##. .... .#.. .... ....
..## .... .... .... ..## .##. ###. ##.. .##.
..#. ..## .... ##.. .... ##.. .... #... ..#.
..#. ..## .... ##.. .... .... .... #... ..#.
```

A few examples of invalid descriptions of Tetriminos:

```
#### ...# ##... #. .... ..## #### ,,,, .HH.
...# ..#. ##... ## .... .... #### #### HH..
.... .#.. ....  #. .... .... #### ,,,, ....
.... #... ....     .... ##.. #### ,,,, ....
```

Because each Tetrimino fills only 4 of the 16 available boxes, it is possible to describe
the same Tetrimino in multiple ways. However, a rotated Tetrimino describes a different
Tetrimino from the original, in the case of this project. This means no rotation is possible
on a Tetrimino, when you will arrange it with the others.

Those Tetriminos are then perfectly equivalents on every aspect :

```
##.. .##. ..## .... .... ....
#... .#.. ..#. ##.. .##. ..##
#... .#.. ..#. #... .#.. ..#.
.... .... .... #... .#.. ..#.
```

These 5 Tetriminos are, for their part, 5 distincts Tetriminos on every aspect :

```
##.. .### .... .... ....
#... ...# ...# .... .##.
#... .... ...# #... .##.
.... .... ..## ###. ....
```

Finally, here is an example of a valid file your program must resolve:

```
$> cat -e valid_sample.fillit
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$>
```

...and an example of invalid file your program must reject for multiple reasons:

```
$> cat -e invalid_sample.fillit
...#$
...#$
...#$
...#$
....$
....$
....$
####$
$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$>
```

### **The smallest square**

The goal of this project is to arrange every Tetriminos with each others in order to make
the smallest possible square. But in some cases, this square should contains holes when
some given pieces won’t fit in perfectly with others.
Even if they are embedded in a 4x4 square, each Tetrimino is defined by its mini-
mal boundaries (their ’#’). The 12 remaining empty characters will be ignored for the
Tetriminos assemble process.

Tetriminos are ordered by they apparition order in the file. Among all the possible
candidates for the smallest square, we only accept the one where Tetriminos is placed on
their most upper-left position.

Example :

Considering the two following Tetriminos (’#’ will be replaced by digits for under-
standing purposes):

```
1...     ....
1...     ....
1... AND ..22
1...     ..22
```

The smallest square you can make with those 2 pieces is 4-char wide, but there is many possible versions that you can see right below:

```
a)   b)   c)   d)   e)   f)
122. 1.22 1... 1... 1... 1...
122. 1.22 122. 1.22 1... 1...
1... 1... 122. 1.22 122. 1.22
1... 1... 1... 1... 122. 1.22

g)   h)   i)   j)   k)   l)
.122 .1.. .1.. 221. ..1. ..1.
.122 .122 .1.. 221. 221. ..1.
.1.. .122 .122 ..1. 221. 221.
.1.. .1.. .122 ..1. ..1. 221.

m)   n)   o)   p)   q)   r)
22.1 .221 ...1 ...1 ...1 ...1
22.1 .221 22.1 .221 ...1 ...1
...1 ...1 22.1 .221 22.1 .221
...1 ...1 ...1 ...1 22.1 .221
```

According to the rule above, the right solution is then a)

### **Program output**

Your program must display the smallest assembled square on the standard output. To
identify each Tetrimino in the square solution, you will assign a capital letter to each
Tetrimino, starting with ’A’ and increasing for each new Tetrimino.

If the file contains at least one error, your program must display error on the stan-
dard output followed by a newline and have to exit properly.

*Example :*

```
$> cat sample.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$
$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
$>
```

*Another example :*

```
$> cat sample.fillit | cat -e
....$
....$
####$
....$
$
....$
...$
..##$
..##$
$> cat sample.fillit | cat -e
error$
$>
```

*Last Example :*

```
$> cat sample.fillit | cat -e
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$
....$
.##.$
.##.$
....$
$
....$
....$
##..$
.##.$
$
##..$
.#..$
.#..$
....$
$
....$
###.$
.#..$
....$
$> ./fillit sample.fillit | cat -e
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$
$>
```
