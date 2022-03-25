#include <iostream>
#include <fstream>
#include "heapsort.h"
using namespace std;

int main()
{
    ifstream in;
    int n;
    in.open("input.txt");
    in >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];

    in.close();

    my_priority_queue<int> pq(arr, n);

    ofstream out;
    out.open("output.txt");
    while (!pq.isEmpty())
    {
        out << pq.top() << " ";
        pq.pop();
    }

    out.close();
}
