#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if(a.size() != b.size()) {
        return a.size() > b.size();
    } else {
        int sigma = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] > b[i]) {
                sigma += (a[i] - b[i]) * (a[i] - b[i]);
            } else {
                sigma -= (a[i] - b[i]) * (a[i] - b[i]);
            }
        }
        return sigma > 0;
    }
}

int main() {
    int total;
    cin >> total;
    vector<vector<int>> save(total);

    for(int i = 0; i < total; ++i) {
        int subTotal;
        cin >> subTotal;
        save[i].resize(subTotal);
        for(int j = 0; j < subTotal; ++j) {
            cin >> save[i][j];
        }
    }

    sort(save.begin(), save.end(), cmp);

    for (const auto& vectors : save) {
        for (int i = 0; i < vectors.size(); ++i) {
            cout << vectors[i];
            if (i != vectors.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
