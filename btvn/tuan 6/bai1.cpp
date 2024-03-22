#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    char arr[m][n] = {{'0'}};

    while (k--) {
        int temp1 = rand() % m;
        int temp2 = rand() % n;
        arr[temp1][temp2] = '*';
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != '*') {
                int check = 0;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        int new_i = i + a;
                        int new_j = j + b;
                        if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && arr[new_i][new_j] == '*')
                            check++;
                    }
                }
                arr[i][j] = '0' + check;
            }
        }
    }


    char result[m][n];
for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        result[i][j] = '?';
    }
}
    int i=0;
    while(i<m*n){
        i++;
        int x,y;
        cin>>x>>y;
        result[x][y]=arr[x][y];
        if(arr[x][y]=='*'){
            cout<<"YOU’RE DEAD!"<<endl;
            for(int i=0;i<m;i++){
                for(int  j=0;j<n;j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }else {
            for(int i=0;i<m;i++){
                for(int  j=0;j<n;j++){
                    cout<<result[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }

    return 0;
}
