# Daniel Yu's Code
Some of my programming projects.
I can be contacted at `dd4yu@uwaterloo.ca`.

## [ULTRAKILL Mod](https://github.com/wacfeld/UKML)
- A mod written in C# for the Unity game ULTRAKILL
- Patches game methods at runtime to modify enemy behaviour and add new behaviours

## [Forecast Evaluation](https://github.com/phac-nml-phrsd/casteval)
- An R package which facilitates the evaluation of time series forecasts
- Flexibly accepts forecasts as either a set of individual model realizations or as the summary of an ensemble of realizations via quantiles at each time point
- Includes support for multiple common scoring methods
- Provides a suite of visualization tools to help assess forecast and scoring performance

## [C Compiler](https://github.com/wacfeld/comp)
- Written in C, x86 assembly
- A C to x86 assembly compiler
- Roughly follows the C90 standard
- Was created using [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) and the C90 standard as reference, as well as limited consultation of GCC gas output, and various sources on the structure of stack frames. No other help was used for the creation of the expression parser or statement parser.
- See repository for more details

## [Scheme Interpreter](https://github.com/wacfeld/ploy)
- Written in C++
- Interpreter for the Scheme dialect of Lisp
- Implements arithmetic, lambdas, definitions, and other basic syntax/functions
- Understands what a [Y combinator](https://github.com/wacfeld/ploy/blob/master/Y.png) is

## [Monopoly in x86](https://github.com/wacfeld/portfolio/tree/main/monopoly_)
- Written in x86 assembly (NASM)
- Like [Monopoly in C](https://github.com/wacfeld/portfolio#monopoly-in-c) below, but in assembly
- Everything is done from scratch
- PRNG uses Middle Squared Weyl Sequence
- System calls are only used to get the time (to seed the PRNG), and to print out the results.

## [Modular Chess Piece Library](https://github.com/wacfeld/fairy)
- Written in Python3
- A program which allows one to create new [fairy chess](https://en.wikipedia.org/wiki/Fairy_chess) pieces from elementary ones
- Each piece is a Python function which returns the valid moves it can make, and pieces can be combined/modified with various operations

## [Tetris UI and Bot](https://github.com/wacfeld/tetrui)
- Written in C++
- Implements singleplayer and versus Guideline Tetris, including SRS, garbage, 7-bag, move reset, and combo recognition
- Also contains a perfect-clear finder and versus bot

## [Multi-Intersection Traffic Optimization using Neural Networks](https://github.com/wacfeld/portfolio/tree/main/gridfinal)
- Written in Python 3.
- Uses Keras to train a neural network to outperform hardcoded traffic light configurations.
- Won a gold medal at WWSEF 2018.
- carped.py defines the classes Car and Pedestrian, which drive and walk in the simulation.
- concrete.py defines classes Intersection, Road, Lane, Middle (the square in the middle of the intesection).
- draw.py was not used.
- graphics.py was not mine, but was also not used.
- main.py runs the simulation, controlling traffic light using the neural network. It measures the efficiency and trains the network.
- rnntest.py was unused.
- virtual.py defines classes ZebraCrossing, Sidewalk, Portal (each Car/Pedestrian is spawned at one Portal, then drives/walks to another Portal, and is destroyed, akin to entering and leaving a group of intersections), MindController (which spawns/destroys Cars/Pedestrians, makes them start, accelerate, stop, etc.).
- saves/ contains various generations of the neural network, as well as a graph of the network's improvement over time.
- Trained for approximately 12 hours.

## [Solving a Linear Algebra Problem in x86 Assembly](https://github.com/wacfeld/intri)
- Written in x86 assembly
- Given three points on the unit sphere, and a third point P, determines whether P is inside the curved triangle with the three points as vertices.
- Implements cross product within the 8 x87 floating point registers (does not need to store intermediate values in memory)

## [Drum Tablature to MIDI](https://github.com/wacfeld/tabs)
- Written in C
- Reads in a file containing drum tablature, and outputs a playable MIDI file

## [Hindsight (Time-tracking program)](https://github.com/wacfeld/hindsight)
- Written in C
- A time-tracking program inspired by the clocking function of Emacs Org-mode.
- Takes input from text file, processes it, and then prints various kinds of summaries as requested by the user.

## [Monopoly in C](https://github.com/wacfeld/portfolio/tree/main/monopoly)
- Written in C
- A simulation of the Monopoly board game (including chance cards/community chest cards) to determine the most commonly landed on square.
- The results for Monpoly (x86) and Monopoly (C) can be found [here](https://docs.google.com/spreadsheets/d/1EN8JJjIpM0mYPidNXOiXu0DbAe5UrhyenMqqPiV_Ocw/edit#gid=0).

## [RC5 Block Cipher](https://github.com/wacfeld/portfolio/tree/main/rc5)
- Written in C
- A program which encrypts a given file using the RC5 block cipher, ECB mode of operation.

## [Chess Engine](https://github.com/wacfeld/portfolio/tree/main/chesscomputer)
- Written in Python 3.
- Uses minimax (cost function based on raw material) to play chess against the user.
- Only features not implemented are en-passant, castling, and promotion.

## [Huffman Coding](https://github.com/wacfeld/portfolio/tree/main/HuffmanCoding2)
- Written in C++
- Takes in string of text, determines frequency of each letter, builds Huffman tree, outputs compressed result.

## [Twenty Four Tester](https://github.com/wacfeld/portfolio/tree/main/TwentyFourTester)
- Written in Java
- Given four poker card values, determines all possible ways to combine them with '+', '-', '\*', '/' to create the number 24.

## Smaller projects

### [Hex Board Game](https://github.com/wacfeld/hex)
- Written in C++
- UI for the Hex board game

### [Unimake](https://github.com/wacfeld/unimake)
- Written in Python3
- A script which, given a file, copies it into a temporary folder with a makefile for that filetype, and provides real-time previews of the resulting output
- Useful for writing markdown, math notation, [ABC notation](https://abcnotation.com/), etc. and being able to see the output without any manual rendering or extra files.

### [wordladder](https://github.com/wacfeld/wordladder)
- Written in C
- Given a dictionary, a start word, and an end word of the same length, searches for a [word ladder](https://en.wikipedia.org/wiki/Word_ladder) between the two

### [texttobrainf](https://github.com/wacfeld/texttobrainf)
- Written in C
- Takes text stream as input, outputs semi-optimized brainf*** code which prints the given text

### [15jump](https://github.com/wacfeld/portfolio/tree/main/15jump)
- Finds and lists all possible solutions of the "Triangle Peg Board" game.

### [anagram](https://github.com/wacfeld/portfolio/tree/main/anagram)
- Takes in a line of text, removes spaces, punctuation, capitalization, then sorts the letters alphabetically, to facilitate the finding of anagrams.
### [arithmetic](https://github.com/wacfeld/portfolio/tree/main/arithmetic)
- Generates random arithmetic questions for the user to solve. 
### [colors](https://github.com/wacfeld/portfolio/tree/main/colors)
- Generates random colors in RRGGBB format.
### [doubletangent](https://github.com/wacfeld/portfolio/tree/main/doubletangent)
- In a quartic polynomial with two humps, finds the line tangent to both of these humps.
- Confirms by-hand calculation of the exact formula of the line.
### [hashdict](https://github.com/wacfeld/portfolio/tree/main/hashdict)
- Takes in a list of people's names and ages, puts them in a hash dictionary with linked lists, and then counts the entries in each linked list.
- Careful choice of the hash function and dictionary size makes the entries evenly distributed, as the program demonstrates.
### [knightassassin](https://github.com/wacfeld/portfolio/tree/main/knightassassin)
- Brute forces the solution to this puzzle: https://fivethirtyeight.com/features/can-you-solve-the-chess-mystery/
- I later realized that this solution was incorrect. However the code is still correct.
### [physics](https://github.com/wacfeld/portfolio/tree/main/physics)
- Simulates the collision of two particles
### [postfix](https://github.com/wacfeld/portfolio/tree/main/postfix)
- Takes in a post-fix notation mathematical expression and evaluates the answer.
### [rev_txt](https://github.com/wacfeld/portfolio/tree/main/rev_txt)
- Takes in a paragraph of text and reverses the order of the words, while preserving punctuation.
### [risk_stats](https://github.com/wacfeld/portfolio/tree/main/risk_stats)
- Figures out the likelihood of winning a battle in the board game Risk, given the number of troops on each side.
- Uses the Monte Carlo method
### [sqrt](https://github.com/wacfeld/portfolio/tree/main/sqrt)
- Inaccurate name -- does not actually square root.
- Using gradient descent, finds the extrema of a given quintic polynomial.
### [stack](https://github.com/wacfeld/portfolio/tree/main/stack)
- A proof-of-concept a variable-type stack in C, which unlike C++ has no templates.
- The push() and pop() functions take in/return void pointers.
- Uses memcpy to pop and push, given the size of the element as an argument.
### [thomaegraph](https://github.com/wacfeld/portfolio/tree/main/thomaegraph)
- Graphs Thomae's Function, which is continuous over the irrationals, discontinuous over the rationals, and nowhere-differentiable.
### [turingmachine](https://github.com/wacfeld/portfolio/tree/main/turingmachine)
- Implements a Turing machine.

### [eulercircuit](https://github.com/wacfeld/portfolio/tree/main/eulercircuit)
- Given a connected graph with all vertices of even degree, finds a Eulerian Circuit.
- First finds a closed simple path, then recursively expands it by removing used edges and inserting more closed simple paths, until the graph is exhausted.
- Time complexity O(number of edges).

### [regex](https://github.com/wacfeld/portfolio/tree/main/regex)
- Written in C++
- A simple regex matching program (recognizes '?', '\*', '+', '.'), written from scratch.

### [quine](https://github.com/wacfeld/portfolio/tree/main/quine)
- Languages: C++ and Python3
- Two Quine programs that print their own source code
- quine.cpp does not seem to work, but quine.py does.
