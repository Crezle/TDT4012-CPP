#include "Course.h"

// 3a)

CourseCatalog::CourseCatalog() {
}

ostream& operator<<(ostream& os, const CourseCatalog& course) {
    for (auto const& [code,name] : course.Subject) {
        os << "Code: " << code << " Name: " << name << endl;
    }

    return os;
}

// 3b og d)

void CourseCatalog::addCourse(string code, string name) {
    for (auto const& [eXcode,eXname] : Subject) {
        if (eXcode == code) {
            Subject[code] = name;
            cout << code << " successfully changed name to: " << name << "\n";
            return;
        }
    }
    Subject[code] = name;
    cout << "Subject successfully assigned to subject code. \n\n";
}

void CourseCatalog::removeCourse(string code) {
    int removed;
    for (auto const& [eXcode,eXname] : Subject) {
        if (eXcode == code) {
            Subject.erase(code);
            cout << code << " successfully removed. \n";
            removed = 1;
            break;
        }
    }
    if (removed != 1) {
        cout << code << " was not in subject list. \n\n";
    }
}

string CourseCatalog::getCourse(string code) {
    return Subject[code];
}

// 3e)

void CourseCatalog::saveData() {
    ofstream saveData;
    saveData.open("CourseCatalog.txt");
    if (!saveData.is_open()) {
        cout << "A problem occured, please check 'CourseCatalog.txt' for errors. \n";
        return;
    }
    for (auto const& [code,name] : Subject) {
        saveData << code << "," << name << "\n";
    }
    saveData.close();
    cout << "Changes saved successfully! \n\n";
}
void CourseCatalog::loadData() {
    ifstream loadData;
    loadData.open("CourseCatalog.txt");
    if (!loadData.is_open()) {
        cout << "A problem occured, please check 'CourseCatalog.txt' for errors. \n";
        return;
    }
    string line;
    vector<string> data;
    while (getline(loadData,line)) {
        stringstream ss(line);
        while (ss.good()) {
            string info;
            getline(ss, info, ',');
            data.push_back(info);
        }
        Subject.insert({data[0], data[1]});
        data.clear();
    }
}

void courses() {
    CourseCatalog Courses;
    Courses.loadData();
    int ans = -1;

    while (ans != 0) {
        cout << "What do you wish to do?: \n\n";
        cout << "1: View list of subjects. \n";
        cout << "2: Add course to list. \n";
        cout << "3: Remove course from list. \n";
        cout << "4: Check course code. \n";
        cout << "5: Save changes. \n";
        cout << "0: Close program. \n\n";

        cin >> ans;
        cout << "\n";

        if (ans == 1) {
            cout << Courses << "\n\n";
        }
        else if (ans == 2) {
            cout << "Please, enter subject code: \n";
            string code;
            string name;
            cin >> code;
            cout << "Please, enter subject name: \n";
            cin.ignore(INT_MAX, '\n'); // \n betyr "enter".
            getline(cin,name);
            Courses.addCourse(code, name);
        }
        else if (ans == 3) {
            cout << "Please, enter subject code: \n";
            string code;
            cin >> code;
            Courses.removeCourse(code);
        }
        else if (ans == 4) {
            cout << "Please, enter subject code: \n";
            string code;
            cin >> code;
            cout << "The corresponding subject is: " << Courses.getCourse(code) << "\n\n";
        }
        else if (ans == 5) {
            Courses.saveData();
        }
    }
}

