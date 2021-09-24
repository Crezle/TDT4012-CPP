#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include "class.h"
#include "Meeting.h"

using namespace Graph_lib;

// 4a og d)

class MeetingWindow: public Window {
private:
    Button quitBtn;
    In_box personName;
    In_box personEmail;
    vector<Person*> people;
    Button personNewBtn;
public:
    MeetingWindow(Graph_lib::Point xy, int w, int h, const string& title);
    ~MeetingWindow();
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    void addPerson();
    void printVector();
};

// 4c)

static constexpr int x = 100;
static constexpr int y = 100;
static constexpr int w = 1080;
static constexpr int h = 540;
static constexpr int pad = 50;
static constexpr int btnW = 200;
static constexpr int btnH = 70;
static constexpr int fieldW = 600;
static constexpr int fieldH = 70;
static constexpr int fieldPad = 100;

static constexpr Point topLeft = {x, y};
static constexpr Point qBtn = {w - pad - btnW, pad};
static constexpr Point InName = {fieldPad, pad};
static constexpr Point InMail = {fieldPad, 2*pad + fieldH};
static constexpr Point addBtn = {fieldPad, 3*pad + 2*fieldH};