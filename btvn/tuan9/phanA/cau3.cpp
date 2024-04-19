#include<bits/stdc++.h>
using namespace std;

int main()
{
    char* a = new char[10];
char* c = a + 3;
for (int i = 0; i < 9; i++) a[i] = 'a';
a[9] = '\0';
cerr <<"a: " << "-" << a << "-" << endl;
cerr <<"c: " << "-" << c << "-" << endl;
delete c;
cerr << "a after deleting c:" << "-" << a << "-" << endl;
/* không in ra dòng cerr cuối
do đã xóa con trỏ c hay là con trỏ a+3
khi đó việc truy cập vào mảng a sẽ bị lỗi vì mảng a+3 bị xóa
*/
}
