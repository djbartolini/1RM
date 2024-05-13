
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxCalculator(string weightLifted, string repsLifted) {
    int weight = stoi(weightLifted);
    int reps = stoi(repsLifted);

    vector<double> percs = {
            1.00,
            1.05,
            1.08,
            1.11,
            1.15,
            1.18,
            1.20,
            1.25,
            1.30,
            1.33,
            1.43,
            1.49
    };

    vector<double> percs2 = {
            1.00,
            0.95,
            0.93,
            0.90,
            0.87,
            0.85,
            0.83,
            0.80,
            0.77,
            0.75,
            0.70,
            0.67
    };

    double factor = percs[reps - 1];
    int max = weight * factor;

    int i;
    for (i = 0; i < percs.size(); i++) {
        if (i == 0) {
            cout << i + 1 << " Rep: " << max << endl;
        } else {
            cout << i + 1 << " Reps: " << int(max * percs2[i]) << endl;
        }
    }

    return max;
}

int main() {
    cout << "One-Rep Max Calculator" << endl;
    cout << " " << endl;

    cout << "Weight Lifted: " << endl;
    string weightLifted;
    getline(cin, weightLifted);

    int reps = 0;
    string repsLifted;

    while (true) {
        cout << "Reps Performed: " << endl;
        getline(cin, repsLifted);

        reps = stoi(repsLifted);

        if (reps <= 12 && reps >= 1) {
            break;
        } else {
            cout << "Please choose an amount of 12 or less" << endl;
        }
    }

    cout << " " << endl;

    maxCalculator(weightLifted, repsLifted);

    return 0;
}
