#include <iostream>

using namespace std;

void printSolution(unsigned int selected[3]){
  cout << "{ ";
  for(int i = 0; i < 3; i++)
    cout << selected[i] << ", ";

  cout << "}" << endl;
}

bool sum3a(unsigned int T, unsigned int selected[3]){
  bool hasCombo = false;
  
  for(int i = 1; i < T; i++){
    for(int k = 1; k < T; k++){
      for(int j = 1; j < T; j++){
        if(i + j + k == T){
          selected[0] = i; selected[1] = k; selected[2] = j;
          printSolution(selected);
          hasCombo = true;
        }
      }
    }
  }

  return hasCombo;
}

bool sum3b(unsigned int T, unsigned int selected[3]){
  bool hasCombo = false;
  
  for(int i = 1; i < T; i++){
    for(int k = 1; k < T; k++){
      if(i + k < T){
        selected[0] = i; selected[1] = k; selected[2] = T - i - k;
        printSolution(selected);
        hasCombo = true;
      }
    }
  }

  return hasCombo;
}

int main(){
  unsigned int selected[3];
  unsigned int T = 10;

  /* if(!sum3a(T, selected))
    cout << "NO O(n³) COMBOS AVAILABLE" << endl; */

  if(!sum3b(T, selected))
    cout << "NO O(n²) COMBOS AVAILABLE" << endl;

  return EXIT_SUCCESS;
}