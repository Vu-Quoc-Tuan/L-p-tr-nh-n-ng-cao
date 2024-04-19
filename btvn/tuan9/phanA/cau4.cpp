#include <iostream>

void cau4() {
  int* temp = new int;
  *temp = 10;
  int* check = temp;
  delete temp;
  std::cout << *check << std::endl;
}

int main() {
  cau4();
  return 0;
}
/*
xảy ra lỗi do con trỏ check trỏ vào địa chỉ của temp nhưng temp đã bị xóa
=> khi in ra giá giá trị của check thì sẽ là 1 số ngẫu nhiên
*/
