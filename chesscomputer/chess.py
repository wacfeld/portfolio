import time
import random
import os

def listifyAMatrixSincePythonIsMessedUp(matrix):
    listifiedMatrix = []
    for i in matrix:
        listifiedMatrix.append(list(i))
    return listifiedMatrix


def setupBoard(splitCode):
    board = [['*' for x in range(8)] for y in range(8)]
    for i in range(0, 8):  # which rank
        for j in range(0, 8):  # which file
            board[i][j] = splitCode[i][j]
    return board


def movePiece(board, x1, y1, x2, y2):
    boardChanged = listifyAMatrixSincePythonIsMessedUp(board)
    if boardChanged[y1][x1] == '*':
        return boardChanged
    boardChanged[y2][x2] = boardChanged[y1][x1]
    boardChanged[y1][x1] = '*'
    return boardChanged


def clear():
    os.system('cls')


def printBoard(inputBoard):
    clearEachTime = False

    if clearEachTime:
        clear()

    imageChessPieces = True
    chessPieceDict = {'K': '♔', 'Q': '♕', 'R': '♖', 'B': '♗', 'N': '♘', 'P': '♙', 'k': '♚', 'q': '♛', 'r': '♜',
                      'b': '♝', 'n': '♞', 'p': '♟', '*': '*'}

    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    if imageChessPieces:
        for y in range(8):
            for x in range(8):
                board[y][x] = chessPieceDict[board[y][x]]
        print('  ⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤')

        for i in range(0, len(board)):
            print(str((-1 * i - 1) % 8 + 1) + '  ' + str(board[i]).strip('[').strip(']').replace('*', ' ').replace("'",
                                                                                                                   ' ').replace(
                ', ', '│'))
            print('  ⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤')
        print('    a   b   c  d   e  f    g   h')
    else:
        print('    -------------------------------')
        for i in range(0, len(board)):
            print(str((-1 * i - 1) % 8 + 1) + '   ' + str(board[i]).strip('[').strip(']').replace('*', ' ').replace("'",
                                                                                                                    ' ').replace(
                ', ', '|'))
            print('    -------------------------------')
        print('     a   b   c   d   e   f   g   h')
    print("Point count " + str(getPointCount(board)))
    print()


def twoPiecesAreOppositeColor(piece1, piece2):
    return bool(piece1.isupper() != piece2.isupper() and piece1 != '*' and piece2 != '*')


def convertAlgebraicToNotAlgebraic(rank, file):
    rank -= 1
    rankNum = (-1 * rank - 1) % 8
    fileNum = ord(file) - 97
    return [fileNum, rankNum]


def getPointCount(board):
    pointBalance = 0
    for i in range(0, 8):
        for j in range(0, 8):
            piece = board[i][j]
            if piece == '*':
                continue
            if piece.islower():
                if piece == 'p':
                    pointBalance -= 1
                if piece == 'b' or piece == 'n':
                    pointBalance -= 3
                if piece == 'r':
                    pointBalance -= 5
                if piece == 'q':
                    pointBalance -= 9
                if piece == 'k':
                    pointBalance -= 1000
            else:
                if piece == 'P':
                    pointBalance += 1
                if piece == 'B' or piece == 'N':
                    pointBalance += 3
                if piece == 'R':
                    pointBalance += 5
                if piece == 'Q':
                    pointBalance += 9
                if piece == 'K':
                    pointBalance += 1000

    if positionIsCheckMate(board, True):
        pointBalance -= 1000
    if positionIsCheckMate(board, False):
        pointBalance += 1000
    return pointBalance


def countPieces(inputBoard):
    count = 0

    for i in range(8):
        for j in range(8):
            if inputBoard[i][j] != '*':
                count += 1

    return count


def coordsAreInRange(x, y):
    return x in range(8) and y in range(8)


def getAllBishopMoves(inputBoard, x, y):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    point = board[y][x]
    possibleMoves = []

    newX, newY = x + 1, y + 1
    while newX in range(x + 1, 8) and newY in range(y + 1, 8):
        if board[newY][newX] == '*':
            possibleMoves.append(movePiece(board, x, y, newX, newY))
        elif twoPiecesAreOppositeColor(point, board[newY][newX]):
            possibleMoves.append(movePiece(board, x, y, newX, newY))
            break
        else:
            break

        newX += 1
        newY += 1

    newX, newY = x - 1, y - 1
    while newX in range(0, x) and newY in range(0, y):
        if board[newY][newX] == '*':
            possibleMoves.append(movePiece(board, x, y, newX, newY))
        elif twoPiecesAreOppositeColor(point, board[newY][newX]):
            possibleMoves.append(movePiece(board, x, y, newX, newY))
            break
        else:
            break

        newX -= 1
        newY -= 1

    newX, newY = x + 1, y - 1
    while newX in range(x + 1, 8) and newY in range(0, y):
        if board[newY][newX] == '*':
            possibleMoves.append(movePiece(board, x, y, newX, newY))
        elif twoPiecesAreOppositeColor(point, board[newY][newX]):
            possibleMoves.append(movePiece(board, x, y, newX, newY))
            break
        else:
            break

        newX += 1
        newY -= 1

    newX, newY = x - 1, y + 1
    while newX in range(0, x) and newY in range(y + 1, 8):
        if board[newY][newX] == '*':
            possibleMoves.append(movePiece(board, x, y, newX, newY))
        elif twoPiecesAreOppositeColor(point, board[newY][newX]):
            possibleMoves.append(movePiece(board, x, y, newX, newY))
            break
        else:
            break

        newX -= 1
        newY += 1
    return possibleMoves


def getAllRookMoves(inputBoard, x, y):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    point = board[y][x]
    possibleMoves = []

    for i in range(x + 1, 8):
        if board[y][i] == '*':
            possibleMoves.append(movePiece(board, x, y, i, y))
        elif twoPiecesAreOppositeColor(point, board[y][i]):
            possibleMoves.append(movePiece(board, x, y, i, y))
            break
        else:
            break
    for i in range(x - 1, -1, -1):
        if board[y][i] == '*':
            possibleMoves.append(movePiece(board, x, y, i, y))
        elif twoPiecesAreOppositeColor(point, board[y][i]):
            possibleMoves.append(movePiece(board, x, y, i, y))
            break
        else:
            break
    for i in range(y + 1, 8):
        if board[i][x] == '*':
            possibleMoves.append(movePiece(board, x, y, x, i))
        elif twoPiecesAreOppositeColor(point, board[i][x]):
            possibleMoves.append(movePiece(board, x, y, x, i))
            break
        else:
            break
    for i in range(y - 1, -1, -1):
        if board[i][x] == '*':
            possibleMoves.append(movePiece(board, x, y, x, i))
        elif twoPiecesAreOppositeColor(point, board[i][x]):
            possibleMoves.append(movePiece(board, x, y, x, i))
            break
        else:
            break
    return possibleMoves


def getAllQueenMoves(inputBoard, x, y, ):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    return getAllRookMoves(board, x, y) + getAllBishopMoves(board, x, y)


def getAllPawnMoves(inputBoard, x, y):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    piece = board[y][x]
    # 5198972348
    possibleMoves = []

    if piece.isupper():
        if coordsAreInRange(y - 1, x - 1) and twoPiecesAreOppositeColor(board[y][x], board[y - 1][x - 1]):
            possibleMoves.append(movePiece(board, x, y, x - 1, y - 1))
        if coordsAreInRange(x + 1, y - 1) and twoPiecesAreOppositeColor(board[y][x], board[y - 1][x + 1]):
            possibleMoves.append(movePiece(board, x, y, x + 1, y - 1))

        if coordsAreInRange(x, y - 1) and y == 6 and board[y - 1][x] == '*':
            possibleMoves.append(movePiece(board, x, y, x, y - 1))
            if coordsAreInRange(x, y - 2) and board[y - 2][x] == '*':
                possibleMoves.append(movePiece(board, x, y, x, y - 2))
        elif coordsAreInRange(x, y - 1) and y == 1 and board[y - 1][x] == '*':
            tempBoard = listifyAMatrixSincePythonIsMessedUp(board)
            piecesToPromoteTo = ['Q', 'R', 'N', 'B']
            tempBoard[y][x] = '*'
            for i in piecesToPromoteTo:
                tempBoard[y - 1][x] = i
                possibleMoves.append(listifyAMatrixSincePythonIsMessedUp(tempBoard))
        elif coordsAreInRange(y - 1, x) and board[y - 1][x] == '*':
            possibleMoves.append(movePiece(board, x, y, x, y - 1))
    else:
        if coordsAreInRange(x + 1, y + 1) and twoPiecesAreOppositeColor(board[y][x], board[y + 1][x + 1]):
            possibleMoves.append(movePiece(board, x, y, x + 1, y + 1))
        if coordsAreInRange(x - 1, y + 1) and twoPiecesAreOppositeColor(board[y][x], board[y + 1][x - 1]):
            possibleMoves.append(movePiece(board, x, y, x - 1, y + 1))

        if coordsAreInRange(x, y + 1) and y == 1 and board[y + 1][x] == '*':
            possibleMoves.append(movePiece(board, x, y, x, y + 1))
            if coordsAreInRange(x, y + 2) and board[y + 2][x] == '*':
                possibleMoves.append(movePiece(board, x, y, x, y + 2))
        elif coordsAreInRange(x, y + 1) and y == 6 and board[y + 1][x] == '*':
            tempBoard = listifyAMatrixSincePythonIsMessedUp(board)
            piecesToPromoteTo = ['q', 'r', 'n', 'b']
            tempBoard[y][x] = '*'
            for i in piecesToPromoteTo:
                tempBoard[y + 1][x] = i
                possibleMoves.append(listifyAMatrixSincePythonIsMessedUp(tempBoard))
        elif coordsAreInRange(x, y + 1) and board[y + 1][x] == '*':
            possibleMoves.append(movePiece(board, x, y, x, y + 1))

    return possibleMoves


def getAllKnightMoves(inputBoard, x, y):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    possibleMoves = []

    coords = [
        [x - 1, y - 2],
        [x + 1, y - 2],
        [x + 2, y - 1],
        [x + 2, y + 1],
        [x - 2, y - 1],
        [x - 2, y + 1],
        [x - 1, y + 2],
        [x + 1, y + 2]
    ]

    for c in coords:
        if c[0] in range(8) and c[1] in range(8) and (
            twoPiecesAreOppositeColor(board[c[1]][c[0]], board[y][x]) or board[c[1]][c[0]] == '*'):
            possibleMoves.append(movePiece(board, x, y, c[0], c[1]))

    return possibleMoves


def findWhatWasTaken(inputBoard1, inputBoard2):
    board1 = listifyAMatrixSincePythonIsMessedUp(inputBoard1)
    board2 = listifyAMatrixSincePythonIsMessedUp(inputBoard2)
    for y in range(8):
        for x in range(8):
            if board1[y][x] != board2[y][x] and board2[y][x] != '*':
                return board1[y][x]


def getAllKingMoves(inputBoard, x, y):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    possibleMoves = []

    coords = [
        [x - 1, y - 1],
        [x, y - 1],
        [x + 1, y - 1],
        [x - 1, y],
        [x + 1, y],
        [x - 1, y + 1],
        [x, y + 1],
        [x + 1, y + 1]
    ]

    for c in coords:
        if coordsAreInRange(c[0], c[1]) and (
                board[c[1]][c[0]] == '*' or twoPiecesAreOppositeColor(board[y][x], board[c[1]][c[0]])):
            possibleMoves.append(movePiece(board, x, y, c[0], c[1]))
    return possibleMoves


def kingIsInCheck(inputBoard, whiteOrBlack):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    kingX = 0
    kingY = 0

    for y in range(0, 8):
        for x in range(0, 8):
            if board[y][x] == ('K' if whiteOrBlack else 'k'):
                kingX, kingY = x, y

    rookMoves = getAllRookMoves(board, kingX, kingY)
    bishopMoves = getAllBishopMoves(board, kingX, kingY)
    knightMoves = getAllKnightMoves(board, kingX, kingY)
    kingMoves = getAllKingMoves(board, kingX, kingY)

    if coordsAreInRange(kingX - 1, kingY - 1 if whiteOrBlack else kingY + 1) and (
        board[kingY - 1 if whiteOrBlack else kingY + 1][kingX - 1] == ('p' if whiteOrBlack else 'P')):
        return True
    if coordsAreInRange(kingX + 1, kingY - 1 if whiteOrBlack else kingY + 1) and (
        board[kingY - 1 if whiteOrBlack else kingY + 1][kingX + 1] == ('p' if whiteOrBlack else 'P')):
        return True

    for move in rookMoves:
        pieceTaken = findWhatWasTaken(board, move)
        if pieceTaken.upper() in ['R', 'Q']:
            return True

    for move in bishopMoves:
        pieceTaken = findWhatWasTaken(board, move)
        if pieceTaken.upper() in ['B', 'Q']:
            return True

    for move in knightMoves:
        pieceTaken = findWhatWasTaken(board, move)
        if pieceTaken.upper() == 'N':
            return True

    for move in kingMoves:
        pieceTaken = findWhatWasTaken(board, move)
        if pieceTaken.upper() == 'K':
            return True

    return False


whiteToMove = True


def interpCommand(inputBoard, rankAndFile):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    rank1 = int(rankAndFile[0][1])
    file1 = rankAndFile[0][0]
    converted1 = convertAlgebraicToNotAlgebraic(rank1, file1)

    rank2 = int(rankAndFile[1][1])
    file2 = rankAndFile[1][0]
    converted2 = convertAlgebraicToNotAlgebraic(rank2, file2)

    x = converted1[0]
    y = converted1[1]
    possibleMoves = []
    piece = board[y][x]
    if piece.upper() == 'R':
        possibleMoves = getAllRookMoves(board, x, y)
    if piece.upper() == 'B':
        possibleMoves = getAllBishopMoves(board, x, y)
    if piece.upper() == 'Q':
        possibleMoves = getAllQueenMoves(board, x, y)
    if piece.upper() == 'N':
        possibleMoves = getAllKnightMoves(board, x, y)
    if piece.upper() == 'K':
        possibleMoves = getAllKingMoves(board, x, y)
    if piece.upper() == 'P':
        possibleMoves = getAllPawnMoves(board, x, y)

    i = 0
    while i in range(len(possibleMoves)):
        if i in range(len(possibleMoves)) and kingIsInCheck(possibleMoves[i], True):
            del possibleMoves[i]
            i -= 1
        i += 1

    if movePiece(board, converted1[0], converted1[1], converted2[0], converted2[1]) in possibleMoves:
        board = movePiece(board, converted1[0], converted1[1], converted2[0], converted2[1])
    else:
        return board

    return board


def placePieceOnBoard(inputBoard, piece, location):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    notAlgebraic = convertAlgebraicToNotAlgebraic(int(location[1]), location[0])

    board[notAlgebraic[1]][notAlgebraic[0]] = piece

    return board


def findOptimalValIndex(values, whiteOrBlack):
    return values.index(max(values)) if whiteOrBlack else values.index(min(values))


def getAllPossibleMoves(inputBoard, whiteOrBlack):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    possibleMoves = []
    for y in range(8):
        for x in range(8):
            if board[y][x] != '*' and (board[y][x].isupper() if whiteOrBlack else board[y][x].islower()):
                if board[y][x].upper() == 'B':
                    possibleMoves += getAllBishopMoves(board, x, y)
                if board[y][x].upper() == 'R':
                    possibleMoves += getAllRookMoves(board, x, y)
                if board[y][x].upper() == 'Q':
                    possibleMoves += getAllQueenMoves(board, x, y)
                if board[y][x].upper() == 'P':
                    possibleMoves += getAllPawnMoves(board, x, y)
                if board[y][x].upper() == 'N':
                    possibleMoves += getAllKnightMoves(board, x, y)
                if board[y][x].upper() == 'K':
                    possibleMoves += getAllKingMoves(board, x, y)

    return possibleMoves


def getAllNotCheckMoves(inputBoard, whiteOrBlack):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)

    possibleMoves = getAllPossibleMoves(board, whiteOrBlack)

    i = 0
    while i in range(len(possibleMoves)):
        if i in range(len(possibleMoves)) and kingIsInCheck(possibleMoves[i], whiteOrBlack):
            del possibleMoves[i]
            continue
        i += 1

    return possibleMoves


def positionIsCheckMate(inputBoard, whiteOrBlack):
    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    if kingIsInCheck(inputBoard, whiteOrBlack) == False:
        return False
    possibleMoves = getAllPossibleMoves(inputBoard, whiteOrBlack)
    for move in possibleMoves:
        if not kingIsInCheck(move, whiteOrBlack):
            return False
    return True


class WeirdBoard:
    def __init__(self, inputBoard, inputParentBoard, inputChildrenBoards):
        self.board = inputBoard
        self.parentBoard = inputParentBoard

        self.childrenBoards = inputChildrenBoards

        self.pointCount = getPointCount(self.board)


def generateTree(rootBoard, parentBoard, depth, whiteToMove):

    if depth == 0:
        return rootBoard

    possibleMoves = getAllNotCheckMoves(rootBoard.board, whiteToMove)

    possibleWeirdBoards = []
    for move in possibleMoves:
        possibleWeirdBoards.append(WeirdBoard(move,rootBoard,None))

    rootBoard.childrenBoards = possibleWeirdBoards

    for child in rootBoard.childrenBoards:
        child = generateTree(child, rootBoard, depth-1, not whiteToMove)
    
    return rootBoard


def getAllLeafNodes(rootBoard):
    children = rootBoard.childrenBoards

    notLeafBoards = []
    leafBoards = []

    for child in children:
        if child.childrenBoards == None:
            leafBoards.append(child)
        else:
            notLeafBoards.append(child)

    for board in notLeafBoards:
        leafBoards.extend(getAllLeafNodes(board))

    return leafBoards


def getRandIndexOfGreatest(pointCounts, whiteOrBlack):
    greatestPointCount = (max(pointCounts) if whiteOrBlack else min(pointCounts))
    indicesOfGreatest = [i for i, x in enumerate(pointCounts) if x == greatestPointCount]
    return random.choice(indicesOfGreatest)

def findOptimalMove(rootBoard, whiteOrBlack):
    while True:
        leafNodes = getAllLeafNodes(rootBoard)

        parentNodes = []
        for leaf in leafNodes:
            parentNodes.append(leaf.parentBoard)
        subst = list(set(parentNodes))
        parentNodes = subst


        for parent in parentNodes:
            childPointCounts = []

            for child in parent.childrenBoards:
                childPointCounts.append(child.pointCount)
            randIndex = getRandIndexOfGreatest(childPointCounts,not whiteOrBlack)
            parent.pointCount = parent.childrenBoards[randIndex].pointCount

            if len(parentNodes) == 1:
                parent.board = parent.childrenBoards[randIndex].board

            parent.childrenBoards = None


        if len(parentNodes) == 1:
            return parentNodes[0]

        whiteOrBlack = not whiteOrBlack


def getComputerMove(inputBoard, whiteOrBlack):
    depth = 2

    board = listifyAMatrixSincePythonIsMessedUp(inputBoard)
    '''possibleMoves = getAllPossibleMoves(board, whiteOrBlack)

    i = 0
    while i in range(len(possibleMoves)):
        if i in range(len(possibleMoves)) and kingIsInCheck(possibleMoves[i], whiteOrBlack):
            del possibleMoves[i]
            i -= 1
        i += 1

    pointCounts = []
    for i in range(len(possibleMoves)):
        pointCounts.append(getPointCount(possibleMoves[i]))'''
    rootBoard = generateTree(WeirdBoard(board,None,None),None,depth,whiteOrBlack)

    optimalMove = findOptimalMove(rootBoard,whiteOrBlack)

    return optimalMove


chessBoard = [['*' for x in range(8)] for y in range(8)]

startCode = [
    'rnbqkbnr',
    'pppppppp',
    '********',
    '********',
    '********',
    '********',
    'PPPPPPPP',
    'RNBQKBNR'
]

fakeCode = [
    'rnbqkbnr',  # 8
    'pppp*ppp',  # 7
    '********',  # 6
    '********',  # 5
    '********',  # 4
    '********',  # 3
    'PPPPP**P',  # 2
    'RNBQKBNR'  # 1
]  # abcdefgh


def main():
    humanFirst = True

    print("Setting up board...")
    chessBoard = setupBoard(startCode)
    printBoard(chessBoard)

    while True:
        rAndF = input(':::').split('-')

        if rAndF == ['die']:
            print('ok')
            exit()
        try:
          thing = interpCommand(chessBoard, rAndF)
          printBoard(thing)
  
          if thing == chessBoard:
              printBoard(chessBoard)
              print('Invalid move')
              continue
  
          chessBoard = thing
  
          if positionIsCheckMate(chessBoard, not humanFirst):
              print("Checkmate!")
              return

        except:
            printBoard(chessBoard)
            print('Invalid command')
            continue
        time.sleep(1)

        computerMove = getComputerMove(chessBoard, not humanFirst).board
        chessBoard = computerMove
        printBoard(chessBoard)

        if positionIsCheckMate(chessBoard, humanFirst):
            print("Checkmate!")
            exit(0)

main()
