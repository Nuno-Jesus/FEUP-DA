#include <iostream>
#include <cmath>

using namespace std;

void printSolution(int a, int b, int array[]){
  cout << "{ ";
  for(int i = a; i < b; i++){
    cout << array[i] << ", ";
  }
  cout << " }";

  cout << "Indexes : " << a << ", " << b << endl;
}

int maxSubsequence(int A[], unsigned int n , int &i, int &j){
  int max = INT32_MIN;
  int sum = 0;
  int c = 1, k = 0, l;
  
  for(c = 1; c < n; c++){  //Controls the size of the subarray
    for(k = 0; k < n - c; k++){ //Controls where the subarray starts
      for(l = k; l < k + c; l++){ //Sums the elements
        sum = sum + A[l];
      }   

      if(sum > max){
        max = sum;
        i = k;
        j = l;
      }

      sum = 0;
    }
  }

  return max;
}

int main(){
  int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int i, j;

  cout << "Maximum sum of the sequence " << maxSubsequence(a, 9, i, j) << endl;
  printSolution(i, j, a);
}