#pragma once
#include "std_lib_facilities.h"
#include "class.h"

// 3a)

enum class Campus {
    Trondheim,
    Ålesund,
    Gjøvik
};

ostream& operator<<(ostream& o, const Campus& c);

// 3b, c, d, e, f, g, h og i)

class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    static inline set<const Meeting*> meetings{};
public:
    Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader);
    ~Meeting();
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    string getLeader() const;
    void addParticipant(Person* person);
    vector<string> getParticipantList() const;
    vector<const Person*> findPotentialCoDriving(); 
};

ostream& operator<<(ostream& o, const Meeting& m);