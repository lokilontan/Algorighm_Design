#include <iostream>
#include <vector>
#include <stdlib.h>     
#include <time.h> 
#include <chrono>

using namespace std;
using namespace std::chrono;


void swap(vector<int> &nums, int ind1, int ind2)
{
    int swap = nums[ind1];
    nums[ind1] = nums[ind2];
    nums[ind2] = swap;
}

void show(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void selection(vector<int> &nums){
    int minInd;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < nums.size(); i++) {
        minInd = i;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] < nums[minInd]) {
                minInd = j;
            }
        }
        swap(nums, minInd, i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nSorted numbers: " << endl;
    show(nums);
    cout << "Time taken: " << (double)duration.count()/1000000 <<"sec." << endl;

}

int main()
{
    cout << "How many numbers do you want to sort? ";
    int nElements;
    cin >> nElements;

    vector<int> nums;
    int element;
    srand (time(NULL));

    for (int i = 0; i < nElements; i++)
    {
        nums.push_back(rand() % 100);
    }

    cout << "\nYour numbers are: " << endl;
    show(nums);

    int sortAlgo = 0;

    if (!nums.empty())
    {
        cout << "\nWhich sorting algorithm do you want to use?" << endl;
        cout << "1. SELECTION Sort \n"
             << "2. INSERTION Sort \n";

        cin >> sortAlgo;

        while (sortAlgo < 1 || sortAlgo > 2)
        {
            cout << "\nWrong choice, try again..." << endl;
            cout << "1. SELECTION Sort \n"
                 << "2. INSERTION Sort \n";

            cin >> sortAlgo;
        }
    }

    selection(nums);

    return 0;
}
