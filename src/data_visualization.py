import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import nums_from_string as nfs
import math


def setFigure(pixel):
    plt.figure(dpi=pixel)

def plot(components, color="blue"):
    ax = plt.subplot()
    ax.set_facecolor('#333333')  
    for component in components:
        for line in component.lines:
            plt.plot([line.n1.x, line.n2.x], [line.n1.y, line.n2.y], linewidth=1, color=color)       
        for arc in component.arcs:
            ax.add_patch(mpatches.Arc((arc.center.x, arc.center.y), arc.radius*2, arc.radius*2, theta1=arc.endAngle, theta2=arc.beginAngle, color=color, linewidth=1))
        for point in component.points:
            plt.plot([point.x], [point.y], 'o', color=color, markersize=3)


def loadFile(filePath):
    f = open(filePath, 'r')
    lines = f.readlines()
    f.close()
    return lines

def numsFromString(str):
    return nfs.get_nums(str)


def preprocessData(file_path, assemblies=None, coppers=None, set_of_points=None):
    # read data and put it into components
    text = loadFile(file_path)
    presentComponent = "None"
    for line in text:
        if "assembly" in line and "assemblygap" not in line:
            presentComponent = "assembly"
            assemblies.append(Assembly())
        elif "copper" in line and "coppergap" not in line:
            presentComponent = "copper"
            coppers.append(Copper())
        elif "points" in line:
            presentComponent = "points"
            set_of_points.append(Points())
        elif "line" in line:
            dataOfLine = numsFromString(line)
            newLine = Line(Point(dataOfLine[0], dataOfLine[1]), Point(dataOfLine[2], dataOfLine[3]))
            if presentComponent == "assembly":
                assemblies[-1].lines.append(newLine)
            if presentComponent == "copper":
                coppers[-1].lines.append(newLine)
        elif "arc" in line:
            dataOfLine = numsFromString(line)
            newArc = Arc(Point(dataOfLine[0], dataOfLine[1]), Point(dataOfLine[2], dataOfLine[3]), Point(dataOfLine[4], dataOfLine[5]), "CCW" not in line)
            if presentComponent == "assembly":
                assemblies[-1].arcs.append(newArc)
            if presentComponent == "copper":
                coppers[-1].arcs.append(newArc)
        elif "point" in line:
            dataOfLine = numsFromString(line)
            newPoint = Point(dataOfLine[0], dataOfLine[1])
            if presentComponent == "points":
                set_of_points[-1].points.append(newPoint)
        


# Components
assemblies = []
coppers = []

expanded_assemblies = []
expanded_coppers = []

set_of_points = []

class Base:
    ASSEMBLY_GAP = None
    COPPER_GAP = None
    SILSCREEN_GAP = None

    def __init__(self, lines=None, arcs=None, points=None):
        self.lines = []
        self.arcs = []
        self.points = []

class Assembly(Base):
    None


class Copper(Base):
    None

class Points(Base):
    None







# Datas
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Line:
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2
        self.length = math.sqrt((n1.x - n2.x) ** 2 + (n1.y - n2.y) ** 2)


class Arc:
    def __init__(self, begin, end, center, clockwise):
        self.begin = begin
        self.end = end
        self.center = center
        self.clockwise = clockwise
        self.radius = math.sqrt((begin.x - center.x) ** 2 + (begin.y - center.y) ** 2)
        self.beginAngle = calculateDegree(center, begin)
        self.endAngle = calculateDegree(center, end)
        if self.beginAngle == self.endAngle:
            self.endAngle += 360
        if self.clockwise == False:
            temp = self.beginAngle
            self.beginAngle = self.endAngle
            self.endAngle = temp

def calculateDegree(center, n):
    x = n.x - center.x;
    y = n.y - center.y;
    z = math.sqrt(x * x + y * y);
    angle = round(math.asin(abs(y) / z), 4)

    if angle == 0 and x == 0:
        angle = round(math.pi / 2, 4)
    if x >= 0 and y >= 0:             # first quadrant
        angle = angle
    elif x < 0 and y >= 0:         # second quadrant
        angle = math.pi - angle
    elif x < 0 and y < 0:         # third quadrant
        angle += math.pi
    elif x >= 0 and y < 0:        # forth quadrant
        angle = 2 * math.pi - angle
    return angle / math.pi * 180




preprocessData("D:/repos/2022CAD-E/res/testing-data.txt", assemblies=assemblies, coppers=coppers)
preprocessData("D:/repos/2022CAD-E/res/output.txt", assemblies=expanded_assemblies, coppers=expanded_coppers, set_of_points=set_of_points)
setFigure(pixel=130)

plot(assemblies, "white")
plot(coppers, "white")
plot(expanded_assemblies, "yellow")
plot(expanded_coppers, "yellow")
# plot(set_of_points, "red")
plt.show()              