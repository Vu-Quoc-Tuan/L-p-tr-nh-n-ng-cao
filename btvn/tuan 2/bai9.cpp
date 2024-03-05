#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int tempx=99999;
    int tempy=99999;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(x<tempx) tempx=x;
        if(y<tempy) tempy=y;
    }
    cout<<tempx*tempy;
    return 0;
}
