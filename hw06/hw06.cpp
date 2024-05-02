#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int cabinNum;

    while (cin >> cabinNum) {
        vector<int> B(cabinNum);

        for (int i = 0; i < cabinNum; ++i) {
            cin >> B[i];
        }

        deque<int> station;
        int currentCabin = 1;
        bool possible = true;

        for (int i = 0; i < cabinNum; ++i) {
            while (currentCabin <= cabinNum && (station.empty() || (station.front() != B[i] && station.back() != B[i]))) {
                station.push_back(currentCabin++);
            }

            if (station.empty() == false) {
                if (station.front() == B[i]) {
                    station.pop_front();
                } else if (station.back() == B[i]) {
                    station.pop_back();
                } else {
                    possible = false;
                    break;
                }
            } else {
                possible = false;
                break;
            }
        }

        if (possible == true) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }

    return 0;
}
