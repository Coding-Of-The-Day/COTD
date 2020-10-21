import sys
sys.setrecursionlimit(100000)

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]
temp_count = 0


def dfs(x, y):
    global temp_count
    visit[x][y] = 1

    if int(matrix[x][y]) == 1:
        temp_count += 1
        matrix[x][y] = 0
    for i in range(0, 4):
        newX = x + dx[i]
        newY = y + dy[i]
        if int(N) > newX >= 0 and 0 <= newY < int(M):
            if matrix[newX][newY] == 1 and 0 == int(visit[newX][newY]):
                dfs(newX, newY)


visit = []
matrix = []
T = int(input())
for _ in range(0, T):
    count = 0
    M, N, k = map(int, input().split())
    matrix = [[0] * M for i in range(0, N)]
    visit = [[0] * M for i in range(0, N)]
    for i in range(0, k):
        x, y = map(int, input().split())
        matrix[y][x] = 1

    for i in range(0, N):
        for j in range(0, M):
            if int(matrix[i][j]) == 1 and int(visit[i][j]) == 0:
                dfs(i, j)
                if temp_count > 0:
                    count += 1

    print(count)
