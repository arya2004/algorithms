#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <unordered_set>

using namespace std;


int Josephus(int n, int k)
{
    k--;
    int arr[n];


    for (int i = 0; i < n; i++) {
        arr[i] = 1;
    }  
    int cnt = 0, cut = 0,

        num = 1;

    while (cnt < (n - 1)) {

    
        while (num <= k) {
            cut++;

            cut = cut % n;
            if (arr[cut] == 1) {
             
                num++;
            }
        }

        num = 1;

        arr[cut] = 0;

        
        cnt++;
        cut++;

     
        cut = cut % n;


        while (arr[cut] == 0) {
            cut++;


            cut = cut % n;
        }
    }


    return cut + 1;
}


int main()
{
    int n = 25, k = 2;
    cout << Josephus(n, k) << endl;
    return 0;
}

