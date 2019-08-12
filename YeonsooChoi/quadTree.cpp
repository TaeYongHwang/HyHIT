#include <iostream>
#include <vector>
#include <string>

using namespace std;
string quad_tree;

/*
  태용아 참고좀 했엉... >_<
 */

string up_side_down(string tmp){
    
    if(tmp.front() == 'x'){
        int from=1;
        string LU = up_side_down(tmp.substr(from));
        from += LU.size();
        
        string RU = up_side_down(tmp.substr(from));
        from += RU.size();
        
        string LD = up_side_down(tmp.substr(from));
        from += LD.size();
        
        string RD = up_side_down(tmp.substr(from));
        
        return 'x' + LD + RD + LU + RU;
        
    }
    
    string str= "";
    str += tmp.front();
     
    //string str = tmp.front();   이렇게는 안되나?
    
    return str;
}



int main() {
    
    int testcase;
    cin >> testcase;
    
    while(testcase--){
       
        string ans= "";
        cin >> quad_tree;
        ans += up_side_down(quad_tree);
        
        cout << ans << endl;
    }
    
    
    return 0;
}
