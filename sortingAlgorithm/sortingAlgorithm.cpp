#include <iostream>
using namespace std;

int main() {

    int number;
    int n;

    cout << "**** This sorting algorithm aims that find the smallest prime number between input numbers ****" << endl;
    cout << "How many numbers will you enter: ";
    cin >> n;
    int** array = new int* [n];
    for (int i = 0; i < n; ++i)
        array[i] = new int[2];
   

    int index = 0;
    cout << "Enter numbers for sorting algorithm: " << endl;

    while (index != n) {

        cin >> number;

        array[index][0] = number;
        index++;

    }

    //first index is a number
    //1.index is a prime number of first index.
    //array[0] = {24, 2}  --> 24 % 2 = 0
    //array[1] = {33, 3}

    for (index = 0; index < n; index++) {
        for (int i = 2; i <= array[index][0]; i++) {

            if (array[index][0] % i == 0) {      
                array[index][1] = i;            //set prime number into second index
                break;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int min;
        int temp, temp2;
        for (int j = i + 1; j < n; j++) {
            min = i;
            if (array[j][1] < array[min][1]) {      //compare two prime numbers
                min = j;
                temp = array[i][0];
                temp2 = array[i][1];
                array[i][0] = array[min][0];
                array[i][1] = array[min][1];
                array[min][0] = temp;
                array[min][1] = temp2;
            }
            else if (array[j][1] == array[min][1]) {        //if prime numbers are equal, compare input numbers.
                if (array[j][0] < array[min][0]) {
                    min = j;
                    temp = array[i][0];
                    temp2 = array[i][1];
                    array[i][0] = array[min][0];
                    array[i][1] = array[min][1];
                    array[min][0] = temp;
                    array[min][1] = temp2;
                }
            }
        }
    }

    cout << "After sorting algorithm " << endl;

    for (int i = 0; i < n; i++) {
        cout << array[i][0] << "  ";
    }

    cout << endl;
    return 0;
}
