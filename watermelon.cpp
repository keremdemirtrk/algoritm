#include <iostream>

int weight;

bool check(int weigth){
  if(weight>2 && weigth % 2 == 0){
    return 1;
  }else{
    return 0;
  }
}

int main() {
  std::cin >> weight;
  check(weight);
  if(check(weight) == 1 ){
   std::cout << "yes" << std::endl;
  }else {
    std::cout << "no" << std::endl;
  }
}