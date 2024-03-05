//Phan A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int hour,money;
    cin>>hour;
    if(hour<=100){
        cout<<hour*12000;
    }else{
        if(hour-100<=50){
            cout<<100*12000+(hour-100)*16000;
        }else {
            if(hour-150<=50){
               cout<<100*12000+50*16000+(hour-150)*20000;
            }else cout<<100*12000+50*16000+50*20000+(hour-200)*25000;
        }
    }
}

//Phan B
#include<bits/bits/stdc++.h>
using namespace std;

int main()
{
    int tn;
    cin>>tn;
    int tra, nhan;
    int ttt=tn-tn*9/100;
    if(ttt<=1000000){
        nhan=ttt;
        tra=tn-ttt;
    }else{
        if(ttt<=1500000){
            nhan=ttt-(ttt-1000000)*0.1;
            tra=tn-ttt;
        }else{
            if(ttt<=2000000){
            nhan=ttt-500000*0.1-(ttt-1500000)*0.15;
            tra=tn-ttt;
            }else {
              nhan=ttt-500000*0.1-500000*0.15-(ttt-2000000);
              tra=tn-ttt;
            }
        }
    }
    cout<<tra<<endl<<nhan;
    return 0;
}

//phan C
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<n*pow(1.02,12);
    return 0;
}

//phan D
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int thunhap=100*12000+50*16000;
    int sauthue=1875000+1500000;
    cout<<sauthue<<endl;
    sauthue-=2000000;
    int no=10000000;
    while(no>0){
        no-=sauthue;
        cout<<no*0.02<<endl;
        no=no*1.02;
        cout<<no<<endl;
        cout<<endl;
    }
}

//phan E
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int no=10000000;
    int sothang=0;
    int tn;int lai;
    while(no>0){
        int tg;
        cin>>tg;
        if(tg==100){
           lai =no*0.02;
            cout<<lai<<endl;
            tn=100*12000-200000*0.1;
            cout<<tn<<endl;
            no=no-(tn+1500000-2000000)+lai;
            cout<<no<<endl;
        }else
        {
            lai=no *0.02;
            cout<<lai<<endl;
            if(tg>150){
                tn=100*12000+50*16000+(tg-150)*20000;
                tn-=(500000*0.1+500000*0.15+(tn-2000000)*0.2);
                cout<<tn<<endl;
                no=no-(tn+1500000-2000000)+lai;
            cout<<no<<endl;
            }
        }
        sothang++;
    }
    cout<<sothang<<endl;
    cout<<tn-500000+no;
    return 0;
}
