# Cars and Pedestrians

import virtual, concrete
import random

class Car:
    def __init__(self, p):
        # cars spawn in Portals which are adjacent to the outer intersections
        # location == 0, 'p' is digital; 'm' is analog
        # when turning cars follow a rough circle

        self.parent = p  # either Portal, Lane, or Middle; this also tells us how it should behave
        self.prevparent = None  # used while in middle to tell the direction it's turning
        
        bigbrother = self.parent.parent
        self.destination = bigbrother.decidedest(self.parent)  # the portal it wants to get to
        self.path = bigbrother.pathfind(self.parent, self.destination)  # array of Intersections followed by one Portal, the path to follow to get to self.destination

        self.ticksfromspawn = 0  # note that this is not seconds, but ticks, so always integer value
        # ^ TODO: add stuff to increment this

        # these are used in conjunction with similar fields in Middle

        # stuff used in Lane
        # TODO: decide if certain car values (reaction speed, etc.) are random? If not, make static
        # ^ similar for Pedestrians

        # used when in the middle of an intersection
        self.pointstooccupy = None  # array of points the car will occupy, also used as path
        self.coords = [None, None]  # (0,0) is center of Intersection, x moves right, y moves up
        self.motionvector = [None, None]  # where it moves next in the Intersection; might change to direction and angle
        self.lanetoenter = None  # used in Road.offerroad()
        
        # used in lane
        self.position = None  # location on road, scalar, meters
        self.goingthroughyellow = None  # so that a car that is stopping at yellow doesn't start up again
        self.middlepathclear = None
        # ^ used with self.reactivity
        self.middlepath = None  # path to take when in Middle
        self.disttraveledinmid = None

        self.speed = None  # m/s, always multiple of 2?
        self.targetspeed = None  # what speed the car wants to get to while in Middle
        
        self.reactiondelay = []  # a list of lists, first element in sublist is reaction time left, second is the command to execute
        # ^ left is the number of ticks left (0, 1, 2, 3) and right is the command to execute

    minb = 0.5
    length = 449.326  # from bumper to bumper, centimeters
    reactivity = 3 # ticks, initial value for reactiondelay
    # ^ TODO: make everything use reactivity, and not just the number 3

    def run(self, comm):  # run an exec() command for reactiondelay
        exec(comm)  # need to do this because has to be run from inside Car

    @staticmethod
    def calcbuffer(speed):  # calculate real buffer based on speed
        # buffer should be half of speed in mph, converted to meters
        # this way half + half of each car = correct buffer
        mph = speed * 1.125  # divide by 1600, multiply by 3600, divide by 2
        b = mph + Car.length / 2  # car is included in this calculation
        return mph if mph > Car.minb else Car.minb  # so that cars don't get too close when speed is 0

    def setdecelspeed(self):
        if self.position > 0.5:
            currsl = self.parent.parentroad.speedlimit
            if self.position > currsl:
                self.speed = currsl
            else:
                self.speed = self.position
            # easiest way I can think of to get accurate speed change

        else:  # so we don't get the arrow paradox, because that would be bad
            self.speed, self.position = 0, 0

    def changespeedlinear(self):  # linearly approach c.targetspeed
        if self.targetspeed > self.speed:
            self.speed += 1
        elif self.targetspeed < self.speed:
            self.speed -= 1
        # if it's equal we can just leave it
            
    # @staticmethod
    # def deciderandvalues():
        # will return Gaussian random values for length, speed, acceleration, etc.
        # pass

        
class Pedestrian:
    # walking is a digital task
    # different pedestrians have different walking speeds
    # when a pedestrian walks it occupies, the crossing, stays on the same sidewalk,
    # then after x time goes to the other sidwalk and unoccupies the crossing

    def __init__(self, p):
        self.ticksfromspawn = 0  # see similar for Car
        self.walkingspeed = Pedestrian.decidewalkingspeed()  # m/s
        self.parent = p  # always a Sidewalk or ZebraCrossing
        self.walkingtimeleft = None
        self.justgothere = False  # just got here, not just go there!
        # ^ used when just arrived at Sidewalk and wants to push button
        bigbrother = self.parent.parent  # at init, parent of parent is MC
        self.destination = bigbrother.decidedest(self.parent)
        self.path = bigbrother.pathfind(self.parent, self.destination)
        self.currtarsw = None  # the current sidewalk they want to walk to
        self.currtarzc = None  # Zebra Crossing, or road ^
        #self.beenherebefore = False
        #self.strange = False

        self.pathrecord = [[self.parent, list(self.path)]]

    def timeleft(self, dist):
        return dist / self.walkingspeed * 10  # * 10 to make in ticks

    avgwalkingspeed = 1.39  # m/s
    @staticmethod
    def decidewalkingspeed():
        speed = random.gauss(Pedestrian.avgwalkingspeed, 0.5)
        if speed < 1.11:  # to avoid people getting negative speeds!!!
            speed = 1.11
        if speed > 1.67:
            speed = 1.67
        return speed
