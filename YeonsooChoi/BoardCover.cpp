#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

char board[21][21];// 가로 세로 최대가 20 이므로 넉넉하게 21개 칸 준비
int row,column;






int cover(int t_row, int t_column ){
    
    int count=0;
    
    if(t_column == column){// 입력된 값이 board  의 column을 벗어날 때 다음 row로 이동
        t_row = t_row+1;
        t_column =0;
    }
    
    
    if(t_row == row-1  && t_column == column-1){//마지막칸이 비어있으면 0, 차있으면 1 return
        if(board[t_row][t_column]=='#')
            return 1;
        else
            return 0;
        
        
    }
    
    
    
    
    if(board[t_row][t_column]=='#'){//칸이 차있으면 다음칸 호출
        return cover(t_row,t_column+1);//cover(t_row,t_column+1) 이 아니고 retuern cover(t_row,t_column+1)
    }
    
    
    if(t_row+1 < row && t_column+1 < column){// board를 벗어나지 않으면 실행(오른쪽 && 아래)
    
        if(board[t_row][t_column] == '.' && board[t_row+1][t_column] == '.'
           && board[t_row+1][t_column+1] == '.'){ //시작점부터 (아래,오른쪽) 모양
            
            board[t_row][t_column] = '#';
            board[t_row+1][t_column] = '#';
            board[t_row+1][t_column+1] = '#';
            
            count += cover(t_row , t_column+1);
            
            board[t_row][t_column] = '.';
            board[t_row+1][t_column] = '.';
            board[t_row+1][t_column+1] = '.';

        }
        
        
        if(board[t_row][t_column] == '.' && board[t_row][t_column+1] == '.'
           && board[t_row+1][t_column+1]=='.'){ //시작점부터 (오른쪽,아래) 모양
            

            board[t_row][t_column] = '#';
            board[t_row][t_column+1] = '#';
            board[t_row+1][t_column+1] = '#';
            
            count += cover(t_row,t_column+1 );
            
            board[t_row][t_column] = '.';
            board[t_row][t_column+1] = '.';
            board[t_row+1][t_column+1] = '.';

        }
        
        if(board[t_row][t_column] == '.' && board[t_row+1][t_column] == '.'
           && board[t_row][t_column+1] == '.'){//시작점부터 (오른쪽)||(아래) 모양
           

            board[t_row][t_column] = '#';
            board[t_row+1][t_column] = '#';
            board[t_row][t_column+1] = '#';
            
            count += cover(t_row,t_column+1 );
            
            board[t_row][t_column] = '.';
            board[t_row+1][t_column] = '.';
            board[t_row][t_column+1] = '.';

        }
    }
    
    
    
    if(t_row+1 < row && column-1 > -1){//board를 벗어나지 않으면 실행(왼쪽 && 아래)
    
        if(board[t_row][t_column] == '.' && board[t_row+1][t_column] == '.'
           && board[t_row+1][t_column-1] == '.'){// 시작점부터 (아래,왼쪽) 모양
            

            board[t_row][t_column] = '#';
            board[t_row+1][t_column] = '#';
            board[t_row+1][t_column-1] = '#';
            
            count += cover(t_row , t_column+1 );
            
            board[t_row][t_column] = '.';
            board[t_row+1][t_column] = '.';
            board[t_row+1][t_column-1] = '.';
            
        }
    }
   
    return count;
    
}


int main() {
   
    int test_c;
    char tmp;
    
    cin >> test_c;
    
    for(int i= 0 ; i< test_c ; i++){
        
        int count=0;
        
        for(int j=0;j<21;j++){ // 처음에 board의 모든 칸을 #으로 초기화
            for(int k=0;k<21;k++)
                board[j][k]='#';
        }
        
        cin >> row;
        cin >> column;
        
        for(int j= 0 ; j< row ; j++){// 게임판 모양 받음.
            for(int k= 0 ; k< column ; k++){
                cin >> tmp;
                board[j][k]=tmp;
               
                if(tmp == '.' ) //흰칸의 수 세기
                    count++;
            }
        }
        
        
        
        
        if(count % 3 == 0){//흰칸이 3의 배수이면 진행
            
            cout << cover(0,0) << endl;
        }
        else
            cout << "0" << endl;

        
    }
    
    return 0;
}
