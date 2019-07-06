#include <iostream>
#include <vector>

using namespace std;

vector<int> storage;


void Printing(){
    vector<int>::iterator iter = storage.begin();
    
    cout << "(" << *iter;
    iter++;
    
    for(;iter != storage.end(); iter++){
        cout << ", " << *iter;
    }

    cout << ")" << endl;
}



void pick(int num, int end){
    
    if(end==0){
        Printing();
    }
    else{
        for(int i=0;i<num;i++){
            
            storage.push_back(i);
            end--;
            pick(num,end);
            storage.pop_back();
            end++;
        }
        
    }
    
    
}


void nCk(int num, int k){
    if(k==0){
        Printing();
        
    }
    else{
        for(int i=0;i<num;i++){
            
            
            for(int j=0 ; j <storage.size() ; j++){
                
                if(storage.at(j)==i){// storage에 있는 원소인지 확인, 있으면 함수 나감.
                    return;
                }
                
            }
            storage.push_back(i);
            k--;
            nCk(num,k);
            storage.pop_back();
            k++;
            
        }
    }
}



void nPk(int num, int k){
    if(k==0){
        for(int j= 0 ; j< storage.size() ; j++){
            for(int l=j+1;l<storage.size();l++){
                if(storage.at(j)==storage.at(l)){// 같은것이 있으면 제외, 있으면 함수나감
                    return;
                }
            }
        }
        
        Printing();
    }
    
    else{
        for(int i= 0 ; i< num ; i++){
            
            storage.push_back(i);
            k--;
            nPk(num,k);
            storage.pop_back();
            k++;
        }
    }
    
}




int main(){
    
    int num,k;
    cin >> num >> k;
    int end = num;
    cout << "----all count "<<num <<"----" << endl;
    pick(num,end);
    cout << "----" << num <<"C"<< k <<"----"<< endl;
    nCk(num,k);
    cout << "----" << num <<"P"<< k << "----" << endl;
    nPk(num,k);
    
    
}
