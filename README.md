# ddyu4
Some of Daniel Yu's code. Details listed below.

## MITON (gridfinal)
- Written: February-March 2018 (grade 9).
- Language: python 3.
- a.k.a. Multi-Intersection Traffic Optimization Using Neural Networks. I used Keras for the neural networks, but everything else was done from scratch.
- carped.py defines the classes Car and Pedestrian, which drive and walk in the simulation.
- concrete.py defines classes Intersection, Road, Lane, Middle (the square in the middle of the intesection).
- draw.py was not used.
- graphics.py was not mine, but was also not used.
- main.py runs the simulation, controlling traffic light using the neural network. It measures the efficiency and trains the network.
- rnntest.py was unused.
- virtual.py defines classes ZebraCrossing, Sidewalk, Portal (each Car/Pedestrian is spawned at one Portal, then drives/walks to another Portal, and is destroyed, akin to entering and leaving a group of intersections), MindController (which spawns/destroys Cars/Pedestrians, makes them start, accelerate, stop, etc.).
