def paint(board, n,m,k):
    for i in range(n//2):
        for j in range(m//2):
            c=(i+j)%3
            if k>0:
                board[2*i][2*j]=c*2
                board[2*i][2*j+1]=c*2
                board[2*i+1][2*j]=c*2+1
                board[2*i+1][2*j+1]=c*2+1
                k-=2
            else:
                board[2*i][2*j]=c*2
                board[2*i+1][2*j]=c*2
                board[2*i][2*j+1]=c*2+1
                board[2*i+1][2*j+1]=c*2+1

def h_paint(board, i, m, k):
    for j in range(m//2):
        board[i][2*j]=10+j%2
        board[i][2*j+1]=10+j%2
def v_paint(board, n, j, k):
    for i in range(n//2):
        board[2*i][j]=12+i%2
        board[2*i+1][j]=12+i%2

def print_b(board):
    for v in board:
        print(''.join(map(lambda x: chr(x+ord('a')), v)))

t = int(input())
for _ in range(t):
    n,m,k=list(map(int,input().split()))
    n2=n-n%2
    m2=m-m%2
    board = [m*[-1] for _ in range(n)]

    if k%2==0:
        if n%2:
            if (m//2)%2==0 and k>= m//2 and (m2*n2)//2>=k-(m//2):
                print("YES")
                h_paint(board, -1, m2, k)
                k-=m2//2
                paint(board, n2, m2, k)
                print_b(board)
            else:
                print("NO")
        elif (m2*n2)//2>=k:
            print("YES")
            paint(board, n2, m2, k)
            if m%2:
                v_paint(board, n, -1, k)
            print_b(board)
        else:
            print("NO")
    else:
        if n%2 and (m//2)%2 and (m2*n2)//2>=k-(m//2) and k>=(m//2):
            print("YES")
            h_paint(board, -1, m2, k)
            k-=m2//2
            paint(board, n2, m2, k)
            print_b(board)
        else:
            print("NO")