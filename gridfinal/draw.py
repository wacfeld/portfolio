import virtual, concrete, carped
import os

circle = '●'
square = '■'

middleX = 76
middleY = 20

canvas = [[' ' * middleX * 2] for i in range(middleY * 2)]

def draw(inter):
    os.system('clear')
    
    # draw middle, then roads and lanes, and finally pedestrians
    for x in range(middleX - 3, middleX + 2):
        canvas[middleY-3][x] = '_'

    for l in canvas:
        print(''.join(l))

draw(5)
