#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<pair<int,int>> friend_pair;



// 중복이 있으면 true 없으면 false
bool find(vector <int>& children){  //c++ 표현 찾아보자
   
    for(int i=0;i<children.size();i++){
        for(int j=i+1;j<children.size();j++){
            
            if(children[i]==children[j])
                return true;
        }
    }
    
    return false;
    
}


int to_check_all(vector<int>& children, int start_idx, int repeat_num, int mate){
    
    int sum=0;
    
    if(repeat_num ==0){
        if(!find(children))
            return 1;// 중복이 없고, (mate)C(repeat_num)  -> combination / 만족하기에 1 return.
        else
            return 0;
        
    }
    
    if(start_idx > mate)
        return 0;
    
    
    for(int i =start_idx ; i<mate ; i++){
        
        int temp1 = friend_pair[i].first;
        int temp2 = friend_pair[i].second;
        
        children.push_back(temp1);
        children.push_back(temp2);
        sum += to_check_all(children, i + 1, repeat_num - 1, mate);
        children.pop_back();
        children.pop_back();
        
        
    }
    
    return sum;
    
    
    
}


int main() {
    
    int test_case_num;
    int tmp1, tmp2, number, mate,sum;
    vector<int> children;
    cin >> test_case_num;
    
    for(int i=0;i<test_case_num;i++){
        
        sum=0;
        
        cin >> number;//사람 명 수
        cin >> mate;//친구의 수
       
        for(int j=0;j<mate;j++){ // 친구쌍 friend_pair 에 저장
            cin >> tmp1;
            cin >> tmp2;
            friend_pair.push_back(make_pair(tmp1,tmp2));
        }
        
        sum += to_check_all(children, 0, number/2, mate); //성공할때마다 1씩 더해줌
        
        cout << sum << endl;
        
        friend_pair.clear();
        
    }
    
    return 0;

    
}
