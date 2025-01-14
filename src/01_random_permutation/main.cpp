
// C++
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
/*

code to generate sandom permutation of a given array


a permutation is good if A[i] != i for any i
a
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // For shuffle
#include <random>    // For random_device and mt19937
#include <ctime>

vector<int> random_vector() {

    vector<int> v;
    for(int i = 1; i < 1097; i++){
        v.push_back(i);
    }
    set<string> s;
    


    static random_device rd; 
    static mt19937 rng(rd()); 

    // Shuffle the vector
    shuffle(v.begin(), v.end(), rng);

    return v;
}

int maxUpdates(vector<int> arr){
    int count = 0;
    int max = arr[0];
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
            count++;
        }
    }

    return count;
}

int main() {
    // map<vector<int>, int> mpp;

    // for (int i = 0; i < 600000; i++) {
    //     vector<int> v = random_vector();
    //     mpp[v] += 1;
    // }

    // for (const auto &it : mpp) {
    //     cout << "vector: ";
    //     for (int i : it.first) {
    //         cout << i << " ";
    //     }
    //     cout << "count: " << it.second << endl;
    // }

    double cnt = 0;
    int itr = 100000;

    for (int i = 0; i < itr; i++) {
        vector<int> v = random_vector();
        int c = maxUpdates(v);
        cnt += c;
        cnt / itr;
    }
    

    cout << "Average: " << cnt / itr << endl;


    return 0;
}
