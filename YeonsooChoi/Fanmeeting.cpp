/*시간초과*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int c;
    string s_member,s_fan;
    vector<char>  member;
    vector<char> fan;

    cin >> c;
    while(c--){
        cin >> s_member;
        cin >> s_fan;

        for(int i =0 ; i<s_member.size() ; i++){
            member.push_back(s_member[i]);
            
        }
        
        for(int i =0 ; i<s_fan.size() ; i++){
            fan.push_back(s_fan[i]);
            
        }
        
        
        int num_member = member.size();
        int num_fan = fan.size();
        int check=1, ans=0;
        
        
        for(int i=0 ;i< num_fan - num_member + 1 ;i++){ // 겹치는 총 경우의수는 (팬의 수)-(멤버 수) + 1 가지 이다.
            
            for(int j=0; j<num_member ;j++ ){ // 각 경우마다 멤버가 마주하고있는 사람을 확인하여 남자남자가 마주한 경우 check를 0으로 바꾸고 더이상 검사하지않는다.
                if(member[j] == 'M'){
                    if(fan[j+i] == 'M'){
                        check = 0;
                        break;
                    }
                    
                }
            }
            
            if(check == 1){// 위 for문에서 break 없이 모두 돌았다는 의미 => 남남 만난 경우가 없다.
                ans++;
            }
            check =1;
        }
        
        cout << ans << endl;
        
        member.clear();
        fan.clear();
        
    }
    
    return 0;
}

/*
4
FFFMMM
MMMFFF
FFFFF
FFFFFFFFFF
FFFFM
FFFFFMMMMF
MFMFMFFFMMMFMF
MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF
 
 */

