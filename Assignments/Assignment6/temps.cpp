#include "temps.h"

// 4b)

istream& operator>>(istream& is, Temps& t) {
    return is >> t.max >> t.min;
}

// 4c)

vector<Temps> readTemps(string textfile) {
    ifstream t;
    vector<Temps> temps;
    t.open(textfile);
    Temps data;
    while (t >> data) {
        temps.push_back(data);
    }
    return temps;
}

void printVector(vector<Temps> t) {
    int vectorsize = static_cast<int>(t.size());
    for (int i = 0; i < vectorsize; i++) {
        cout << setw(6) << t[i].max << setw(6) << t[i].min << '\n';
    }
}

// 4d)

void tempStats(vector<Temps> t) {
    int vectorsize = static_cast<int>(t.size());
    double max_record = 0;
    int max_index;
    double min_record = 0;
    int min_index;

    for (int i = 0; i < vectorsize; i++) {
        if (t[i].max > max_record) {
            max_record = t[i].max;
            max_index = i;
        }
        if (t[i].min < min_record) {
            min_record = t[i].min;
            min_index = i;
        }
    }

    cout << "Day number " << max_index << " from 3. february 2018 had the highest temperature at " << max_record << " degrees celsius. \n";
    cout << "while day number " << min_index << " had the lowest temperature at " << min_record << " degrees celsius. \n\n";
}