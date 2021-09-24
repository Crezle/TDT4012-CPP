#include "Meeting.h"

// 3a)

ostream& operator<<(ostream& o, const Campus& c) {
    switch(c) {
        case Campus::Trondheim  : o << "Trondheim"; 
        break;
        case Campus::Ålesund    : o << "Ålesund"; 
        break;
        case Campus::Gjøvik     : o << "Gjøvik";
        break;
    }
    return o;
}

// 3b)

int Meeting::getDay() const {
    return day;
}
int Meeting::getStartTime() const {
    return startTime;
}
int Meeting::getEndTime() const {
    return endTime;
}
Campus Meeting::getLocation() const {
    return location;
}
string Meeting::getSubject() const {
    return subject;
}
string Meeting::getLeader() const {
    return leader->getName();
}
void Meeting::addParticipant(Person* person) {
    participants.insert(person);
}

// 3e)

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader):
day{day},
startTime{startTime},
endTime{endTime},
location{location},
subject{subject},
leader{leader} 
{
    addParticipant(leader);
    meetings.insert(this);
};

// 3f)

Meeting::~Meeting() {
    for (auto m : meetings) {
        delete m;
    }
}

// 3g)

vector<string> Meeting::getParticipantList() const{
    vector<string> listOfParticipants;
    for (auto p : participants) {
        listOfParticipants.push_back(p->getName());
    }
    return listOfParticipants;
}

// 3h)

ostream& operator<<(ostream& o, const Meeting& m) {
    o << "Subject: " << m.getSubject() << '\n';
    o << "Location: " << m.getLocation() << '\n';
    o << "Start Time: " << m.getStartTime() << '\n';
    o << "End Time: " << m.getEndTime() << '\n';
    o << "Leader: " << m.getLeader() << '\n';
    vector<string> participantList = m.getParticipantList();
    o << "List of participants: \n";
    for (int i = 0; i < static_cast<int>(size(participantList)); i++) {
        o << participantList[i] << '\n';
    }
    return o;
}

// 3i)

vector<const Person*> Meeting::findPotentialCoDriving() {
    vector<const Person*> availableCoDrivers;
    for (auto meeting : meetings) {
        for (auto participant : meeting->participants) {
            if (participant->getCar()->hasFreeSeats() 
            && this->day == meeting->day 
            && this->location == meeting->location
            && abs(this->startTime - meeting->startTime) <= 100
            && abs(this->endTime - meeting->endTime) <= 100) {
                availableCoDrivers.push_back(participant);
            } 
        }
    }
    return availableCoDrivers;
}