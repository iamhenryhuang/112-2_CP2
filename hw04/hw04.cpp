#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int total;
    cin >> total;

    vector<pair<int, int>> shows(total);

    for(int i = 0; i < total; i++) {
        cin >> shows[i].first >> shows[i].second;
    }

    // base on endTime to sort (as early as possible)
    sort(shows.begin(), shows.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0;
    int lastEndTime = 0;

    for (int i = 0; i < total; i++) {
        if (shows[i].first > lastEndTime) {
            lastEndTime = shows[i].second;
            count++;
        }
    }

    cout << count;

    return 0;
}
