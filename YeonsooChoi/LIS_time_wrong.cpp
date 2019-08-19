#include <iostream>

using namespace std;


int elements[501], count_storage[501], Max;


void count_sequence(int before, int after){ // 두개의 인자를 받아 크기를 비교하는 함수
 
    /*       cache를 위함. but 틀림
    if(count_storage[after] != 1){
        count_sequence(before, after + 1);
    }
    */
 
    if(elements[before] < elements[after] && count_storage[after]> Max){ //뒤에 수가 크면 after 를 before 로 가지는 함수 호출
	    								// 9 1 3 7 5 6 20 과 같은 예외 처리를 위해 (before, after+1)도 호출  
        count_sequence(after, after+1);
        count_sequence(before, after+1);
       
        if(count_storage[before] < count_storage[after] + 1){
            count_storage[before] = count_storage[after] + 1;
            Max = count_storage[before];
        }
        
    }
    else{// 앞에 수가 크면 (before, after+1)만 호출
        if(elements[after] != 0)
            count_sequence(before, after+1);
    }
}





int main() {
   
    int c, num_elements, tmp;
    cin >> c;
    
    while(c--){
        
        cin >> num_elements;
        Max = 0;
        
        for(int i=0 ; i< 501 ; i++){
            elements[i] = 0;
            count_storage[i] = 1;
        }
        
        for(int i= 0 ; i< num_elements ; i++){
            cin >> tmp;
            elements[i]=tmp;
        }
        
        
        for(int i= 0 ; i< num_elements; i++){ // 모든 경우를 보기 위해서 for문
                count_sequence(i, i+1);
        }
        
        
        
        for(int i= 0 ; i< num_elements ; i++){
            if(Max < count_storage[i])
                Max = count_storage[i];
        }
        
        
        cout << Max << endl;
        
        
    }
    
    
    return 0;
}
/*
-------------------------
예시


4
4
1 2 3 4
8
5 4 3 2 1 6 7 8
8
5 6 7 8 1 2 3 4
7
9 1 3 7 5 6 20
 
 
1
10
12 2 5 11 9 6 8 20 23 24
----------------------------
다른방법 생각
 
 뒤에서부터 진행
 a, b, c, d 에서
 c 까지 살펴봤다면
 b 는 c,d 중 count_storage 가 큰 값에 1 더함
 
 ex)
  1 3 2 4
 1. c.s[4] 에 1
 2. c.s[2] 에 c.s[4]+1
 3. c.s[3] 에 c.s[4]+1 (c.s[2]가 더 크지만 2 < 3 이므로)
 4. c.s[1] 에 c.s[3]+1 or c.s[2]+1 (둘 중 큰걸 골라야 하지만, 크기가 같으므로)
 
 -c 이용
   큐나 트리 이용
 살펴볼 때 마다 count_storage를 크기순으로 정렬
 제일 큰 값의 element 살펴보고 현재 element 보다 크면 count_storage+1 하고 재정렬 후 넘어감
 제일 큰 값의 element가 현재 element 보다 작으면 다음 큰 값으로 넘어가서 element 확인
 
 
 
------------------
*/
