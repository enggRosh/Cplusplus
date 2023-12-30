#include <iostream>

using namespace std;
// take all the input and calculate total positive and negative sum, and their count
void sums(float inp_array[], int n, float& pos_sum, float& neg_sum, int& pos_count, int& neg_count) {
  for (int i = 0; i < n; i++) {
    if (inp_array[i] > 0) {
      pos_sum += inp_array[i];
      pos_count++;
    } else if (inp_array[i] < 0) {
      neg_sum += inp_array[i];
      neg_count++;
    }
  }
}

int main() {
  float inp_array[10];
  int n = 0;
   while (true) { //enter the loop to start taking input
    cout << "Enter a real number (or 0 to stop): ";
    cin >> inp_array[n];

    if (inp_array[n] == 0) {  //checks for the input value 0
      break;
    }
    n++;
  }
  float pos_sum = 0;
  float neg_sum = 0;
  int pos_count = 0;
  int neg_count = 0;
  sums(inp_array, n, pos_sum, neg_sum, pos_count, neg_count); //calling the sum function for sum calculation

  cout << "Positive sum: " << pos_sum << endl;
  cout << "Negative sum: " << neg_sum << endl;
  cout << "Positive count: " << pos_count << endl;
  cout << "Negative count: " << neg_count << endl;
//calculate average value of each number
  if (pos_count > 0) {  
    cout << "Positive average: " << pos_sum / pos_count << endl;
  }
  if (neg_count > 0) {
    cout << "Negative average: " << neg_sum / neg_count << endl;
  }
  return 0;
}
