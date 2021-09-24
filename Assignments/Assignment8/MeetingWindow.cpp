#include "MeetingWindow.h"

// 4a, f og 5d)

MeetingWindow::MeetingWindow(Graph_lib::Point xy, int w, int h, const string& title): 
Window(xy, w, h, title),
quitBtn(qBtn, btnW, btnH, "Quit", cb_quit),
personName(InName, fieldW, fieldH, "Name"),
personEmail(InMail, fieldW, fieldH, "E-Mail"),
personNewBtn(addBtn, btnW, btnH, "Add person", cb_new_person)

{
    this->attach(quitBtn);
    this->attach(personName);
    this->attach(personEmail);
    this->attach(personNewBtn);
};

// 4d)

void MeetingWindow::cb_quit(Address, Address pw) {
    reference_to<MeetingWindow>(pw).hide();
}

// 5b)

void MeetingWindow::addPerson() {
    string pName = personName.get_string();
    string pEmail = personEmail.get_string();
    if (!pName.empty() && !pEmail.empty()) {
        people.push_back(new Person{pName,pEmail});
    }
    personName.clear_value();
    personEmail.clear_value();
}

// 5c)

MeetingWindow::~MeetingWindow() {
    for (auto person : people) {
        delete person;
    }
};

// 5d)

void MeetingWindow::cb_new_person(Address, Address pw) {
    reference_to<MeetingWindow>(pw).addPerson();
}

// 5e)

void MeetingWindow::printVector() {
    for (auto person : people) {
        cout << *person << '\n';
    }
}