#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string a;
    string b;
    cin>>a>>b;
    string fin = "";
    for(int x = 0; x < a.length(); x++){
        for(int y = 0; y < b.length(); y++){
            if(a[x]==b[y] && b[y]!=(char)1){
                fin += a[x];
                b[y] = (char)1;
                a[x] = (char)1;
            }
        }
    }
    std::sort(fin.begin(),fin.end());
    cout<<fin<<endl;
}