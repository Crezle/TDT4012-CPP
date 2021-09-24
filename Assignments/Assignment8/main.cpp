#include "class.h"
#include "Meeting.h"
#include "MeetingWindow.h"

int main()
{
	/* Car opel (1);

	Person Le ("Christian Le", "Cl@stud.ntnu.no", &opel);
	Person Pavlak ("Adrian Pavlak", "pavsMail");
	Person Jan ("Jan Kristian Alstergren", "jMail");
	Campus T = Campus::Trondheim;
	Meeting m(333,1600,2000,T, "C++", &Le);
	m.addParticipant(&Pavlak);
	m.addParticipant(&Jan);
	
	cout << m;

	cout << endl;

	cout << T; */

	MeetingWindow m(topLeft, w, h, "Meetings");

	gui_main();

	m.printVector();
}