# Question : Calculate the maximum size of the squares of the 1 present in the board.

def maximum_size(board,r,c):
    dp = [[0 for j in range(c+1)] for i in range(r+1)]             # creating a dp array filled with zero with extra column and the row

    visited = [[-1 for j in range(c)] for i in range(r)]            # creating a visited array
                                                                # to take care of the 0 by default values.
    for i in range(r):
        for j in range(c):
            if board[i][j] == 0 :
                visited[i][j] = 0


    # Value stored at a particular place -> maximum size of the square by taking it as topmost left point

    for i in range(r-1,-1,-1):
        for j in range(c-1,-1,-1):         # DIRECTION : direction is from bottom to up
            if visited[i][j] == -1:         # if board value id zero then no action is needed.
                ans1 = dp[i][j+1]
                ans2 = dp[i+1][j]
                ans3 = dp[i+1][j+1]
                dp[i][j] = 1+min(ans1,ans2,ans3)

    ans = 0
    for i in range(r):
        for j in range(c):
            if dp[i][j]>ans:
                ans = dp[i][j]

    return ans
    


# main
r = int(input())
c = int(input())
board = []
for i in range(r):         # making a loop for row times
    col = [int(ele) for ele in input().split()]         # taking the column input
    board.append(col)           # adding the full column in the board list to make it a 2D array

print(maximum_size(board,r,c))