import numpy as np
import math

class cell:
    def __init__(self):
        self.parent = [-1,-1]
        self.f = math.inf
        self.g = math.inf
        self.h = math.inf
        
'''**********************************
Function name   :   isValid
Functionality   :   checks whether the cell with given coordinates is within the range of maze and is unblocked
Arguments       :   coordinates - list of 2 elements [x,y]
Return Value    :   True/False
***********************************'''
def isValid(coordinates):
    return (coordinates[0] in range(dims[0]) and coordinates[1] in range(dims[1]) and maze[coordinates[0]][coordinates[1]])

'''**********************************
Function name   :   grassFire
Functionality   :   used as heuristics for Astar
                    Note: Here we have not used simple heruistic functions as the are not very effective
Arguments       :   cells, src
Return Value    :   None
***********************************'''
def grassFire(cells,src):
    tempList = []
    tempList.append(src)
    while(len(tempList)):
        temp = tempList[0]
        x,y = temp
        tempList.pop(0)
        if(isValid([x-1,y]) and cells[x-1][y].h == math.inf):
            cells[x-1][y].h = min(cells[x][y].h + 1,cells[x-1][y].h)
            tempList.append([x-1,y])
        if(isValid([x,y-1]) and cells[x][y-1].h == math.inf):
            cells[x][y-1].h = min(cells[x][y].h + 1,cells[x][y-1].h)
            tempList.append([x,y-1])
        if(isValid([x,y+1]) and cells[x][y+1].h == math.inf):
            cells[x][y+1].h = min(cells[x][y].h + 1,cells[x][y+1].h)
            tempList.append([x,y+1])
        if(isValid([x+1,y]) and cells[x+1][y].h == math.inf):
            cells[x+1][y].h = min(cells[x][y].h + 1,cells[x+1][y].h)
            tempList.append([x+1,y])
'''**********************************
Function name   :   tracePath
Functionality   :   Used to track the path obtained used Astar
Arguments       :   cells, dest
Return Value    :   Final shortest path
***********************************'''
def tracePath(cells,dest):
    x,y = dest
    path = []
    while(not (cells[x][y].parent == [x,y])):
        path.append([x,y])
        x,y = cells[x][y].parent
    path.append([x,y])
    return path[::-1]

'''**********************************
Function name   :   astarAlgorithm
Functionality   :   Assigns value of f,g to all cells of the maze
Arguments       :   src, dest
Return Value    :   None
***********************************'''
def AStarAlgorithm(src,dest):
    if(isValid(src) == False):
        print("Invalid Source")
        return
    if(isValid(dest) == False):
        print("Invalid Destination")
        return
    if(src == dest):
        print("Already at the destination")
        return
    closedList = np.zeros(dims)
    cells = []
    #cells = [[cell()]*dims[1]]*dims[0]
    for i in range(dims[0]):
        temp12 = []
        for j in range(dims[1]):
            temp12.append(cell())
        cells.append(temp12)

    x,y = src
    cells[x][y].parent=[x,y]
    cells[x][y].f = 0
    cells[x][y].g = 0
    cells[x][y].h = 0
    grassFire(cells,src)
    openList = []
    openList.append([0,src])
    foundDest = False
    while(len(openList)):
        temp = openList[0]
        x,y = temp[1]
        openList.pop(0)
        closedList[x][y] = 1
        '''8 Possible successors of this cell
                         N.W.   N    N.E
                           \    |    /
                            \   |   /
                        W - ---Cell - ---E
                            /   |   \
                           /    |    \
                        S.W     S    S.E.
        Cell -->Popped Cell(i, j)'''
        #CASE1: N.W
        x -= 1
        y -= 1
        if(isValid([x,y])):
            if(dest == [x,y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if(not  closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g+1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                #print(cells[x][y].f)
                if(cells[x][y].f > fNew):
                    openList.append([fNew,[x,y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
        #CASE2: N
        y += 1
        if (isValid([x, y])):
            if (dest == [x, y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if (not closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g + 1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                if (cells[x][y].f > fNew):
                    openList.append([fNew, [x, y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
        #CASE3: N.E
        y += 1
        if (isValid([x, y])):
            if (dest == [x, y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if (not closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g + 1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                if (cells[x][y].f > fNew):
                    openList.append([fNew, [x, y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
        #CASE4: W
        x += 1
        y -= 2
        if (isValid([x, y])):
            if (dest == [x, y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if (not closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g + 1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                if (cells[x][y].f > fNew):
                    openList.append([fNew, [x, y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
        #CASE5: E
        y += 2
        if (isValid([x, y])):
            if (dest == [x, y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if (not closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g + 1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                if (cells[x][y].f > fNew):
                    openList.append([fNew, [x, y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
        #CASE6: S.W
        x += 1
        y -= 2
        if (isValid([x, y])):
            if (dest == [x, y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if (not closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g + 1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                if (cells[x][y].f > fNew):
                    openList.append([fNew, [x, y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
        #CASE7: S
        y += 1
        if (isValid([x, y])):
            if (dest == [x, y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if (not closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g + 1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                if (cells[x][y].f > fNew):
                    openList.append([fNew, [x, y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
        #CASE8: S.E
        y += 1
        if (isValid([x, y])):
            if (dest == [x, y]):
                cells[x][y].parent = temp[1]
                foundDest = True
                break
            if (not closedList[x][y]):
                gNew = cells[temp[1][0]][temp[1][1]].g + 1
                hNew = cells[x][y].h
                fNew = gNew + hNew
                if (cells[x][y].f > fNew):
                    openList.append([fNew, [x, y]])
                    cells[x][y].parent = temp[1]
                    cells[x][y].f = fNew
                    cells[x][y].g = gNew
                    #cells[x][y].h = hNew
    if(foundDest):
        print(tracePath(cells,dest)) #If destination is found, trace it
    else:
        print("Failed to reach the destination")


if __name__=='__main__':
    '''Description of Maze -
        1 --> Cell is not blocked
        0 --> Che cell is blocked'''
    global maze
    maze = [[1, 1, 1, 1, 1],
        [1 ,1 ,1 ,0 ,1],
        [0, 0, 1, 0, 1],
        [1 ,1 ,1 ,0 ,1],
        [1, 0, 1, 0, 1],
        [1 ,0 ,1 ,1 ,1],
        [1, 0, 1, 0, 1],
        [1 ,1 ,1 ,1 ,1 ]]
    global dims
    dims = [8,5]
    src = [0,0]
    dest = [7,0]
    AStarAlgorithm(src,dest)