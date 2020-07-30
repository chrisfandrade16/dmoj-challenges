def calculateRPS(numberOfRounds, svenMoves, numberOfFriends, friendsMoves):
    svenPointsNormal = 0
    
    for friend in range(numberOfFriends):
        for move in range(numberOfRounds):
            if (svenMoves[move] == 'R' and friendsMoves[friend][move] == 'R') or (svenMoves[move] == 'P' and friendsMoves[friend][move] == 'P') or (svenMoves[move] == 'S' and friendsMoves[friend][move] == 'S'):
                svenPointsNormal += 1
            elif (svenMoves[move] == 'R' and friendsMoves[friend][move] == 'S') or (svenMoves[move] == 'P' and friendsMoves[friend][move] == 'R') or (svenMoves[move] == 'S' and friendsMoves[friend][move] == 'P'):
                svenPointsNormal += 2
                
    return svenPointsNormal

def RPS(numberOfRounds, svenMoves, numberOfFriends, friendsMoves):
    first = calculateRPS(numberOfRounds, svenMoves, numberOfFriends, friendsMoves)
    
    svenMovesBest = ""
    
    for move in range(numberOfRounds):
        appearances = [0, 0, 0]
        values = [0, 0, 0]
        
        for friend in range(numberOfFriends):
            if friendsMoves[friend][move] == 'R':
                appearances[0] = appearances[0] + 1
            elif friendsMoves[friend][move] == 'P':
                appearances[1] = appearances[1] + 1
            elif friendsMoves[friend][move] == 'S':
                appearances[2] = appearances[2] + 1
        
        values[0] = appearances[0] + (2 * appearances[2])
        values[1] = appearances[1] + (2 * appearances[0])
        values[2] = appearances[2] + (2 * appearances[1])

        maximum = values.index(max(values))

        if maximum == 0:
            svenMovesBest += 'R'
        elif maximum == 1:
            svenMovesBest += 'P'
        elif maximum == 2:
            svenMovesBest += 'S'
                
    second = calculateRPS(numberOfRounds, svenMovesBest, numberOfFriends, friendsMoves)

    print(first)
    print(second)

numberOfRounds = int(input())
svenMoves = str(input())
numberOfFriends = int(input())
friendsMoves = []

for counter in range(numberOfFriends):
    move = str(input())
    friendsMoves.append(move)

RPS(numberOfRounds, svenMoves, numberOfFriends, friendsMoves)