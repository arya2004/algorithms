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

int bruteForce(int a, int b, int m){

    int res = pow(a,b);
    res = res % m;
    return res;
}

int fastExponentiation(int a, int b, int m){

    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    cout << res << endl;
    return res;
}

int main() {
    //a^b % m
    int a = 2;
    int b = 3;
    int m = 5;
    int brute = bruteForce(a,b,m);
    int fast = fastExponentiation(a,b,m);
    cout << "Brute Force: " << brute << endl;
    cout << "Fast Exponentiation: " << fast << endl;

    return 0;
}