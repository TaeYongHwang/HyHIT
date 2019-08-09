#include <iostream>
#include <vector>

using namespace std;

vector<int> fences;


int make_square(int num){// 입력된 num 부터 시작하여 왼쪽, 오른쪽으로 이동. 최대크기의 사각형을 찾는다.
                         // ex) 3번째높이가 4라면, 
    
    int ans=1;// 처음 사각형 시작점 1개
    
    for(int i= num ; i< fences.size()-1 ; i++){ //오른쪽으로 이동하며, 높이가 높거나 같은 곳 있으면 이동 후 사각형 개수 더해줌
        if(fences.at(num) <= fences.at(i+1)){
            ans++;
        }
        else
            break;
        
    }
    for(int i= num ; i> 0 ; i--){ //왼쪽으로 이동하며, 높이가 높거나 같은 곳 있으면 이동 후 사각형 개수 더해줌
        if(fences.at(i-1) >= fences.at(num)){
            ans++;
        }
        else
            break;
    }
    
    return ans;
    
}



int main() {
    
    int test_c;
    cin >> test_c;
    while(test_c--){
        
        int num_of_fence, max=0, tmp;
        int height;
        
        cin >> num_of_fence;
        
        for(int i=0; i< num_of_fence; i++){
            
            cin >> height;
            fences.push_back(height);
            
            
        }
        
        
        
        for(int i= 0 ; i< num_of_fence ; i++){ // 0번 사각형부터 차례로, 모든 사각형을 각각 시작점으로 출발.
            
            tmp = make_square(i);
            
            if(max < tmp * fences.at(i)){ //사각형 개수 * 높이(fences.at(i))
                max = tmp * fences.at(i);
            }
            
        }
        
        cout << max << endl;
        
        fences.clear();
        
    }
    
    
    
    return 0;
}
