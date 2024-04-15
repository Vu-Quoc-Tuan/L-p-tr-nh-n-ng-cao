#include<bits/stdc++.h>
using namespace std;

//int main( )
//{
//   int a[4] = {1,2,3,4};
//   for (int *cp = a; (*cp) != '4'; cp++) {
//      cout << (void*) cp << " : " << (*cp) << endl;
//   }
//   return 0;
//double a[4] = {1,2,3,4.2};
//   for (double *cp = a; (*cp) != '4.2'; cp+=2) {
//      cout << (void*) cp << " : " << (*cp) << endl;
//   }
//   return 0;
//}

/*
ban đầu nó hàm swap sẽ tạo ra hai con trỏ ( sao chép từ s1,s2) và swap nó=> sẽ ko ảnh hưởng tới giá trị của s1,s2
sau khi sửa => tạo ra 2 con trỏ tới con trỏ s1 và s2=> swap giá tri của x, y cũng chính là swap địa chỉ của 2 con trỏ s1,s2

*/


//void swap_pointers(char** x, char** y)
//{
//   char *tmp;
//   tmp = *x;
//   *x = *y;
//   *y = tmp;
//}
//int main()
//{
//   char a[] = "I should print second";
//   char b[] = "I should print first";
//
//   char *s1 = a;
//   char *s2 = b;
//   swap_pointers(&s1,&s2);
//   cout << "s1 is " << s1 << endl;
//   cout << "s2 is " << s2 << endl;
//   return 0;
//}

int main()  {
     char *temp=new char;//sửa để tạo 1 con trỏ trỏ con trỏ mới
   char **s=&temp;
   char foo[] = "Hello World";
   *s = foo;
   printf("s is %s\n",*s);// in ra giá trị của con trỏ trỏ con trỏ s ( chuỗi foo)
   s[0] = foo;
   printf("s[0] is %s\n",s[0]);
   return(0);
}
