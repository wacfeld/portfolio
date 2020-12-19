import tensorflow as tf
import math
import virtual, concrete, carped
import sys
import os
import random

from keras.layers import Input, Dense
from keras.models import Model
from keras.models import Sequential
import keras

import numpy as np

# A few unit definitions:
# a tick is 1/10 a second
# speed is measured in m/s, acceleration in m/s^2
# distance is measured in m
# time increments by 0.1 s, distance by 0.1 m, similar for speed and acceleration
# drivers have reaction delay of 300 ms, pedestrians 0

def getlightcarstates(mc):  # returns vector with states for cars, lights, etc.
    statevector = []  # first sidelen^2 are lights, for s*s intersections, 2 _pairs_ of car lights, which run in parallel with ped lights, so ped lights don't matter
    carvector = []
    # we scan mc.intersections typewriter style, and then put in the light state for the vertical roads, horizontal roads, then the corresponding ZCs
    for i in mc.intersections:
        for j in i:
            state1 = j.roads[0].light.state
            statevector.append(1 if state1 == 'g' else (0.5 if state1 == 'y' else 0))

            for road in j.roads:
                for lane in road.lanes:  # from left to right
                    carvector.append(math.tanh(len(lane.cars)))
    statevector += carvector  # carvector is length sidelen^2*4*3
    return statevector  # we do not calculate lane length here because that is constant over each epoch, it is calculated in main()


def getrandomstates():  #not actually random, just green
    return [2] * LIGHT_SIZE  # 2 means green



sidelen = 5
targetcars = 100 # how many we want to get through each runthrough

# Hyper Parameters
INPUT_SIZE = sidelen**2 * 13  # rnn input size, 1 light determines all, and 12 lane conditions, 1 + 12 = 13

LIGHT_SIZE = sidelen**2  # one light per intersection determines the other 7

LR = 0.02  # learning rate -- unnecessary?
HIDDEN_SIZE = 4  # number of hidden layers
HIDDEN_NODES = 8  # how many nodes in each hidden layer

overallmode = 'n'
def main():
    print('hello!')
    filepath = str(sys.argv[1])
    folder = 'drive/sim/moretesting/genetic' + filepath + '/genetic/saves/'
    os.system('touch ' + folder + 'test')
    # create the neural network
    model = Sequential()
    model.add(Dense(units=INPUT_SIZE, kernel_initializer='random_uniform', bias_initializer='random_uniform', batch_size=1, activation='sigmoid', input_shape=(INPUT_SIZE,)))
    for i in range(HIDDEN_SIZE):
        model.add(Dense(units=HIDDEN_NODES, kernel_initializer='random_uniform', bias_initializer='random_uniform', activation='sigmoid'))
    model.add(Dense(units=LIGHT_SIZE, kernel_initializer='random_uniform', bias_initializer='random_uniform', activation='sigmoid'))
    
    print('Done initializing')

    losses = []
    runthrough = 10
    i = 0
    bestloss = 1000
    save = False
    mc = virtual.MindController(sidelen, 'a')
    while True:
        

        while mc.carsgottenthrough < targetcars:
            tickvect = getlightcarstates(mc)
            lightvect = model.predict(np.array([tickvect]), batch_size=1, verbose=0).tolist()[0]
            mc.lightvector = lightvect
            mc.onetick()
        i += 1
        losses.append(mc.ticks)
        runthrough -= 1
        #print('rt ' + str(runthrough))
        if save and (sum(losses)/len(losses) > bestloss):
            save = False
            runthrough = 0
        # now I see why javascript is evil, and why dynamic type languages in general are evil, and high level languages in general are evil -- 22:57, 3-31-2-18
        if runthrough <= 0:
            
            if save:
                save = False
                #bestloss = sum(losses)/len(losses)

                path = 'drive/sim/moretesting/genetic' + filepath + '/genetic/saves/1000-' + str(sum(losses)/i)
                os.system('touch ' + path)
                model.save(path)
                print('failed')
                print('bestloss is ' + str(sum(losses)/len(losses)))

                losses = []
                model = Sequential()
                model.add(Dense(units=INPUT_SIZE, kernel_initializer='random_uniform', bias_initializer='random_uniform', batch_size=1, activation='sigmoid', input_shape=(INPUT_SIZE,)))
                for j in range(HIDDEN_SIZE):
                    model.add(Dense(units=HIDDEN_NODES, kernel_initializer='random_uniform', bias_initializer='random_uniform', activation='sigmoid'))
                model.add(Dense(units=LIGHT_SIZE, kernel_initializer='random_uniform', bias_initializer='random_uniform', activation='sigmoid'))

                runthrough += 10
                for l in losses:
                    print(l)
                print()
                print()
                print()
                mc = virtual.MindController(sidelen, overallmode)
                continue
            if sum(losses)/len(losses) < bestloss and not save:
                #bestloss = sum(losses)/i
                print('hunch')
                runthrough += 50
                save = True
            elif not save:
                print('failed')
                losses = []
                model = Sequential()
                model.add(Dense(units=INPUT_SIZE, kernel_initializer='random_uniform', bias_initializer='random_uniform', batch_size=1, activation='sigmoid', input_shape=(INPUT_SIZE,)))
                for j in range(HIDDEN_SIZE):
                    model.add(Dense(units=HIDDEN_NODES, kernel_initializer='random_uniform', bias_initializer='random_uniform', activation='sigmoid'))
                model.add(Dense(units=LIGHT_SIZE, kernel_initializer='random_uniform', bias_initializer='random_uniform', activation='sigmoid'))

                runthrough += 10

        mc = virtual.MindController(sidelen, overallmode)
        
if __name__ == '__main__':
    main()
