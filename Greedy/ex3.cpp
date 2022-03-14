#include <iostream>
#include <cmath>

using namespace std;

void printSolution(int result[], int n){
  cout << "[ ";
  for(int i = 0; i < n; i++){
    cout << result[i] << ", ";
  }
  cout << "]" << endl;
}

void resetArray(int array[], int n){
  for (int i = 0; i < n; i++){
    array[i] = 0;
  }
}



bool changeMakingGreedy(unsigned int c[], unsigned int stock[],
  unsigned int n, unsigned int t, int usedCoins[]){
    int change = t;
    
    for(int i = n - 1 ; i >= 0; i--){
      //If the ammount of the coin is above the change, skip
      if(c[i] > t) continue;

      //Number of coins needed to make the change
      int needed = change / c[i]; 
      int ammount = needed < stock[i] ? needed : stock[i];
      
      usedCoins[i] = usedCoins[i] + ammount;
      stock[i] = stock[i] - ammount;
      change = change - ammount * c[i];
    }

    return change == 0 ? true : false;
}

int main(){
  unsigned int coins[4] = {1, 2, 5, 10};
  unsigned int stock1[4] = {3, 5, 2, 1};
  unsigned int stock2[4] = {1, 2, 4, 2};
  int result[4] = {0, 0, 0, 0};

  if(!changeMakingGreedy(coins, stock1, 4, 8, result)){
    cout << "NO MATCHES AVAILABLE FOR THE FIRST STOCK" << endl;
    return EXIT_FAILURE;
  }

  printSolution(result, 4);
  resetArray(result, 4);

  if(!changeMakingGreedy(coins, stock2, 4, 38, result)){
    cout << "NO MATCHES AVAILABLE FOR THE SECOND STOCK" << endl;
    return EXIT_FAILURE;
  }

  printSolution(result, 4);
}