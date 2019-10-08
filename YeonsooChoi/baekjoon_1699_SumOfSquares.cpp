//
//  main.cpp
//  icpc_h
//
//  Created by yeonsoo choi on 07/10/2019.
//  Copyright © 2019 yeonsoo choi. All rights reserved.
//

/*
 아이디어
 input = x^2 + alpha 로 생각. (x = sqrt(input) 부터 1까지)
 cache[alpha]가 이미 있다면 cache[input]은 x^2이 추가된 것이므로 cache[alpha] + 1 해줌
 cache[alpha]가 없다면, input을 alpha로 바꿔서 함수 재 호출 후 위에 부분 반복.
 */


#include <iostream>
#include <math.h>

using namespace std;

int cache[100001];




void find(int input){
    
    int root = sqrt(input);
    int square = root * root;
    int ans;
    
    
    
    if(square == input){        // 제곱수들은 해당 cache에 1저장 후 함수종료.
        cache[square] = 1;
    }
    
    
    
    else{
        
        
        for(int i = root ; i > 0 ; i-- ){       // ex) 26 입력 시, 5^2 + .../ 4^2 + ... / .../ 1^2 + ... 모두 확인해줌.
            
            square = i*i;
            int alpha = input - square;
            
            
            if(cache[alpha] != 9999){       // 이미 저장된 값이 있다면
                
                ans = cache[alpha] + 1;
                
                if(cache[input] > ans){     // 최솟값을 저장
                    cache[input] = ans;
                }
            
            }
            
            else{
                
                find(alpha);                //이미 저장된 값이 없다면, 함수 호출 먼저 해줌
                ans = cache[alpha] + 1;
                
                
                if(cache[input] > ans){
                    cache[input] = ans;
                }
                
            }

        }
        
    }
    
    
    
}


int main(){
    
    int input;
    
    cin >> input ;
    
    for(int i=0 ; i< 100001 ; i++){     // cache를 큰수로 초기화
        cache[i] = 9999;
    }
    
    
    find(input);
    
    cout << cache[input] << endl;       //해당 input의 cache값 출력
    
    return 0;
}

/*
 25
 26
 11339
 34567
 113
 
 1
 2
 3
 4
 2
 
 */
