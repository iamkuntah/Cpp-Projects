#include <iostream>

using namespace std;

int main()
{
  int arr[3];

  // input
  for (int i = 0; i < 3; i++)
  {
    cin >> arr[i];
  }

  // output

  for (int i = 0; i < 3; i++)
  {
    cout << "Numbers are: " << arr[i] << endl;
  }

  return 0;
}