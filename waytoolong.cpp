#include <iostream>
#include <string>

int main(){
  int n;
  std::string input;
  std::cin>>n;
  
  while(n--){
    std::cin>>input;
    if(input.size()>10){
      std::cout<<input[0]<<input.size()-2<<input[input.size()-1]<<std::endl;
    }
    else{
      std::cout<<input<<std::endl;
    }
  }

}