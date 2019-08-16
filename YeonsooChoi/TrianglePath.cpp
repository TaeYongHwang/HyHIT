#include <iostream>

using namespace std;

int triangle[101][101], Max[101][101];

void max_path(int row , int column){// 최대값찾기
    
    if(triangle[row+1][column] != 0){ //아래로 갔을 때 삼각형이 안끊겼을 때
        if( Max[row][column] + triangle[row+1][column] > Max[row+1][column]){//여태 왔던 길 + 앞으로 갈 길 > 앞으로 갈 길이 이미 가지고 있는 최대값
            Max[row+1][column] = Max[row][column] + triangle[row+1][column];
            max_path(row+1,column);// 조건을 만족할 때만 다음번으로 이동 (전부 다 보면 시간초과), 지금 갖고있는 값보다 작으면 볼 필요 x
        }
    }
    
    if(triangle[row+1][column+1] != 0){//아래 오른쪽으로 갔을 때 삼각형이 안끊겼을 때
        if( Max[row][column] + triangle[row+1][column+1] > Max[row+1][column+1]){
            Max[row+1][column+1] = Max[row][column] + triangle[row+1][column+1];
            max_path(row+1,column+1);
        }
    }
}



int main() {
    
    int c;
    cin >> c;
    
    while(c--){
        int line, tmp, ans=0;
        cin >> line;
        
        for(int i= 0; i< 101; i++){
            for(int j=0; j< 101 ;j++){
                triangle[i][j]=0;
            }
        }
        
       
        for(int i=0; i< line ; i++){ // triangle, max 초기화
            for(int j= 0 ; j< i+1 ; j++){
                cin >> tmp;
                triangle[i][j] = tmp;
                Max[i][j] = tmp;
            }
        }
        
        max_path(0,0);//0행0열 부터 시작
        
        for(int i=0 ; i< line ; i++){ // Max들의 마지막 라인에 각 길에대한 최대값들이 저장돼있다
            if(ans < Max[line-1][i]){ // 마지막 라인 중 가장 큰 값을 ans에 저장
                ans = Max[line-1][i];
            }
        }
        
        cout << ans << endl;
        
    }
    return 0;
}
/*
2
5
6
1  2
3  7  4
9  4  1  7
2  7  5  9  4
5
1
2 4
8 16 8
32 64 32 64
128 256 128 256 128
*/

