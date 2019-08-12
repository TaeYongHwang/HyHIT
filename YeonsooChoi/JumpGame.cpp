#include <iostream>

using namespace std;
int board[101][101],check;
int repetition[101][101];// 이미 계산됨을 표시하기 위함

int jump(int a, int b, int n){ // a행 b열 행의 수(n) 을 인자로 받음
    
    if(a == n-1 && b == n-1) // (a,b) 가 (n-1, n-1) 이면 도착한 것
        return 1; // 도착하면 1이 반환된다.
    
    if(board[a][b] + a < n && repetition[a][b] != 2){ // 오른쪽으로 이동
                                                    // 오른쪽, 아래쪽 두쪽으로 갈 수 있기 때문에 repetition이 2가되면 이미 확인한 것
        check = jump(a + board[a][b], b, n);
        repetition[a][b]++;                        // 오른쪽 한번 봤으면 확인했다고 표시
    }
    if(board[a][b] + b < n && repetition[a][b] != 2){ // 아래쪽으로 이동
        check = jump(a, b+ board[a][b], n);
        repetition[a][b]++;                        // 아래쪽 한번 봤으면 확인했다고 표시
    }
    
    
    return check; // 최종 반환 => 도착화지 못했으면 check 가 0, 도착했으면 check가 1
}


int main() {
    
    int c, n, tmp;
    
    cin >> c;
    
    while(c--){
        
        for(int i=0; i< 101 ; i++){ // board, repetition 초기화
            for(int j=0; j< 101 ; j++){
                board[i][j]=0;
                repetition[i][j]=0;
            }
        }
        
        
        cin >> n;
        for(int i=0 ; i< n ; i++){
            for(int j=0 ; j< n ; j++){
                
                cin >> tmp;
                board[i][j] = tmp;
            }
        }
        
        check = 0; // check 초기화
        
        if(jump(0,0, n)) // 도착하면 1반환, 못하면 0 반환하므로
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        
        
        
    }
    
    
    
    return 0;
}

/*
2
7
2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 2
3 3 1 2 3 4 1
1 5 2 9 4 7 0
7
2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 3
3 3 1 2 3 4 1
1 5 2 9 4 7 0
 
 */
