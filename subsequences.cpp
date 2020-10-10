#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> list;
string abc = "abc";
void findStrings(string input, int pos){
    int counter = 0;
    for(int i=0; i<input.size(); i++){
        if(input[i] == '?'){
           ++counter;
        } 
    }
    if(counter == 0){
        list.push_back(input);        
        return;
    }
    // Eğer soru işareti varsa
    if(input[pos] == '?'){
      for(int i=0; i<abc.size(); i++){
          input[pos] = abc[i];
          findStrings(input, pos+1);
      }
    } else{
        findStrings(input, pos+1);
    }

}

int findSub(string input){
    int counter = 0;
    for(int i=0; i<input.size()-2; i++){
        if(input[i] == 'a'){
            for(int j=i+1; j<input.size()-1; j++){
                if(input[j] == 'b'){
                    for(int k=j+1; k<input.size(); k++){
                        if(input[k] == 'c'){
                            counter++;
                        }
                    }
                }
            }    
        }
    }
    return counter;
}

int main(){
    int size;
    string input ;
    cin >> size >> input;

    findStrings(input, 0);
    int counter=0;
    for(int i=0; i<list.size(); i++){
        counter += findSub(list[i]);
    }

    cout << counter << endl;


    return 0;
}
