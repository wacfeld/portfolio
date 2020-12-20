# dd4yu
Some of Daniel D. Yu's code. Details listed below. Sorted by date, latest to earliest.

If you are short on time, the most relevant projects are "[Monopoly in x86](#mon86)", "[Monopoly in C](#monc)", "[MITON](#miton)", "[Chess Computer](#chessc)".

## Larger projects (~5 hours or more)

### RC5 (folder rc5) - c. July 2020 (grade 12)
- Language: C
- A program which encrypts a given file using the RC5 block cipher, ECB mode of operation.

### Monopoly in x86 (folder monopoly_) - c. June 2020 (grade 11) <a id="mon86"></a>
- Language: x86 assembly (NASM).
- Like Monopoly (C) below, but in assembly.
- Everything, including the pseudo-random number generation (Middle Squared Weyl Sequence) is done from scratch.
- System calls are only used to get the time (to seed the PRNG), and to print out the results.

### Monopoly in C (folder monopoly) - c. March 2020 (grade 11) <a id="monc"></a>
- Language: C
- A simulation of the game of Monopoly (everything move-related) to determine the most commonly landed on square.
- The results for Monpoly (x86) and Monopoly (C) can be found here: https://docs.google.com/spreadsheets/d/1EN8JJjIpM0mYPidNXOiXu0DbAe5UrhyenMqqPiV_Ocw/edit#gid=0

### Netflix Ratings (folder chrome-extension) - c. June 2018 (grade 9)
- Language: Javascript/HTML
- A Chrome extension for Netflix, which detects when the user hovers over a thumbnail, searches Google for the movie/show, and displays its rating next to the thumbnail.

### MITON (folder gridfinal) - c. Feb-Mar 2018 (grade 9) <a id="miton"></a>
- Language: Python 3.
- a.k.a. *M*ulti-*I*ntersection *T*raffic *O*ptimization using *N*eural networks. Keras was used for the neural networks, but everything else was done from scratch.
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

### Chess Computer (folder chesscomputer) - c. May 2017 (grade 8) <a id="chessc"></a>
- Language: Python 3.
- Uses minimax (cost function based on raw material) to play chess against the user.
- Only features not implemented are en-passant, castling, and promotion.
- Plays at a tolerable speed with look-ahead depth of two.

### Neuron Simulation (folder NeuronSim) - c. Jan-Apr 2016 (grade 7)
- Language: Java
- Mimicks an action potential in an actual neuron.
- Times how long it takes for the action potential to travel, depending on speed of diffusion.
- Won a pewter medal at WWSEF 2016.

### Huffman Coding (folder HuffmanCoding2) - c. 2015 (grade 6-7)
- Language: C++
- Takes in string of text, determines frequency of each letter, builds Huffman tree, outputs compressed result.

### Twenty Four Tester (folder TwentyFourTester) - c. 2015 (grade 6-7)
- Language: Java
- Given four poker card values, determines all possible ways to combine them with '+', '-', '\*', '/' to create the number 24.

### Timing (folder AAA Science I-S) - c. 2015 (grade 6)
- Language: HTML/Javascript
- Shows the user a clock for 10 seconds, then asks them to click a button once a second, for 30 seconds.
- Measures the user's accuracy in counting.
- In the control group, the clock's interval is 1000 ms. In two other groups, the interval is 950 ms or 1050 ms.

## Smaller projects (~5 hours or less)

### Underneath folder "C":
- All of these are in the language C, sometimes using Python 3 as well.
- Most of these are c. 2019-2020.
- Headers are named after the respective folders.
#### 15jump
- Finds and lists all possible solutions of the "Triangle Peg Board" game.
#### anagram
- Takes in a line of text, removes spaces, punctuation, capitalization, then sorts the letters alphabetically, to facilitate the finding of anagrams.
#### arithmetic
- Generates random arithmetic questions for the user to solve. 
#### colors
- Generates random colors in RRGGBB format.
#### doubletangent
- In a quartic polynomial with two humps, finds the line tangent to both of these humps.
- Confirms by-hand calculation of the exact formula of the line.
#### hashdict
- Takes in a list of people's names and ages, puts them in a hash dictionary with linked lists, and then counts the entries in each linked list.
- Careful choice of the hash function and dictionary size makes the entries evenly distributed, as the program demonstrates.
#### knightassassin
- Brute forces the solution to this puzzle: https://fivethirtyeight.com/features/can-you-solve-the-chess-mystery/
#### physics
- Simulates the collision of two particles
#### postfix
- Takes in a post-fix notation mathematical expression and evaluates the answer.
#### rev_txt
- Takes in a paragraph of text and reverses the order of the words, while preserving punctuation.
#### risk_stats
- Figures out the likelihood of winning a battle in the board game Risk, given the number of troops on each side.
- Uses the Monte Carlo method
#### sqrt
- Irrelevant name -- does not actually square root.
- Using gradient descent, finds the extrema of a given quintic polynomial.
#### stack
- A proof-of-concept a variable-type stack in C, which unlike C++ has no templates.
- The push() and pop() functions take in/return void pointers.
- Uses memcpy to pop and push, given the size of the element as an argument.
#### thomaegraph
- Graphs Thomae's Function, which is continuous over the irrationals, discontinuous over the rationals, and nowhere-differentiable.
#### turingmachine
- Implements a Turing machine.

### Regex (folder regex) - date unknown
- Language: C++
- A simple regex matching program (recognizes '?', '\*', '+', '.'), written from scratch.

### Quine (folder quine) - date unknown
- Languages: C++ and Python3
- Two Quine programs that print their own source code
- quine.cpp does not seem to work, but quine.py does.
