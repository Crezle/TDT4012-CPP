#include "std_lib_facilities.h"

// 3)

class CourseCatalog {
private:
    map<string, string> Subject;
public:
    CourseCatalog();
    void addCourse(string code, string name);
    void removeCourse(string code);
    string getCourse(string code);
    void saveData();
    void loadData();
    friend ostream& operator<<(ostream& os, const CourseCatalog& course);
};

void courses();