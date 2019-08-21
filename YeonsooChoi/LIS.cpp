#include <iostream>

using namespace std;

int elements[501], count_storage[501];

int main() {
    
    int c, num_elements, tmp, max;
    cin >> c;
    
    while(c--){
        
        cin >> num_elements;
        int ans = 0;
        
        for(int i=0 ; i< 501 ; i++){// 배열 초기화
            elements[i] = 0;
            count_storage[i] = -1;
        }
        
        for(int i= 0 ; i< num_elements ; i++){
            cin >> tmp;
            elements[i]=tmp;
        }
        
        
        count_storage[num_elements-1] = 1;// 마지막elements의 count_storage  값은 무조건 1
        
      /*
        뒤에서부터 모두 탐색
       ex) 1,2,3,4
        4번에 1 저장
        3번으로 가서 4번과 비교후 3번이 크면 max에 1이 저장돼 있으므로 3번이 1로 초기화,
      4번이 크면 4번 저장값 + 1  
       2번으로 가서 3,4 번과 비교. 위와 같이 반복
       1번으로 가서 2,3,4번과 비교. 위와 같이 반복 후 종료
       
       */



        for(int i= num_elements-1 ; i> -1 ; i--){ 
            max =1 ;
            for(int j= i+1 ; j< num_elements; j++){

                if(elements[i] < elements[j] && max < count_storage[j]+1){
                    max= count_storage[j]+1;
                }
            }
            
            count_storage[i] = max; // 앞에수가 더 크면 여기서 초기화
            
        }
        
        
        for(int i= 0 ; i< num_elements ; i++){
            if(ans < count_storage[i])
                ans = count_storage[i];
        }
        
        
        cout << ans << endl;
        
        
    }
    
    
    return 0;
}
