#include <iostream>

using namespace std;
int clocks[16]; // 2차원배열 모양 상관x 1차원으로 받는다.
int linked_list[10][16]=   // 행 -> 버튼번호 , 열-> 연결된 시계번호 / 연결돼있으면 1 아니면 0
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,
 0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,
 1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0,
 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,
 0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,
 0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1,
 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
 0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0
};


/*
 1. 각 시계를 바꿀 수 있는 버튼번호를 정렬
     0  -> 0,3,5
     1  -> 0,8
     2  -> 0,5,8
     3  -> 1,6,8,9
     ...
     14 -> 1,5,6,7
     15 -> 2,5,6,7
 
2. 시계를 바꿀 수 있는 버튼이 1개인 것 부터 눌러서 맞춰줌
 
3. 누른 버튼을 지우고(누르면 2번에서 맞춰둔 12시가 바뀌어 버리기 때문에)
      시계를 바꿀 수 있는 남은 버튼이 1개인 것들을 다음에 늘러줌
 */


void push_button(int current_time, int clock_num){ // *3시간씩 앞으로 움직인다 의 의미!
    
    if(current_time +3 != 15){ // 현재 시간이 9,6,3시 일 때, 각각 12,9,6시로 바꿔줌
        clocks[clock_num]= current_time + 3;
    }
    else{
        clocks[clock_num]= 3;
    }// 현재 시간이 12시 일 떄, 3시로 바꿔줌
}



void check_linked(int button_num){ // 연결돼있으면 버튼을 누른다.
    
    for(int i=0 ; i< 16 ; i++){
        if(linked_list[button_num][i]==1){
            push_button(clocks[i], i);
        }
    }
}




int main() {
    
    int test_case;
   
    cin >> test_case;
    
    
    
    for(int i= 0 ; i< test_case ; i++){
        
        int ans=0; // ans 초기화
        
        for(int j=0;j<16;j++){ // clocks 초기화
            
            cin >> clocks[j];
        }
        
        if(clocks[8] != clocks[12]){
            cout << -1 << endl;
            continue;
        }
        while(clocks[11] != 12){ // 1번버튼
            check_linked(1);
            ans++;
        }
        
        while(clocks[13] != 12){ // 9번버튼
            check_linked(9);
            ans++;
        }
        
        while(clocks[8] != 12){  // 4번버튼  , 12번 시계는 자동으로 바뀐다.
            check_linked(4);
            ans++;
        }
        
        if(clocks[9] != 12){  // 1,9번 버튼이 이미 눌렸고 더이상 누르지 않기에 자동으로 12가 돼야된다. 아니면 안되는 경우
            cout << -1 << endl;
            continue;
        }
        
        while(clocks[6] != 12){ // 3번버튼
            check_linked(3);
            ans++;
        }
        
        while(clocks[10] != 12){ // 2번버튼
            check_linked(2);
            ans++;
        }
        
        while(clocks[7] != 12){ // 7번버튼
            check_linked(7);
            ans++;
        }
        
        if(clocks[4] != clocks[5]){
            cout << -1 << endl;
            continue;
        }
        
        while(clocks[4] != 12){  // 8번버튼  , 5번 시계는 자동으로 바뀐다.
            check_linked(8);
            ans++;
        }
        
        while(clocks[1] != 12){ // 0번버튼
            check_linked(0);
            ans++;
        }
        
        while(clocks[3] != 12){ // 6번버튼
            check_linked(6);
            ans++;
        }
        
        if(clocks[0]==clocks[2]  &&  clocks[2]==clocks[14]  &&  clocks[14]==clocks[15]){
            
            while(clocks[0] != 12){ // 5번버튼 , 2,14,15 자동 바뀜
                check_linked(5);
                ans++;
            }
            
        }
        else{
            cout << -1 << endl;
            continue;
        }
        
        
        cout << ans << endl;
        
        
    }
    
    return 0;
}

