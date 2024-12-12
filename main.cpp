#include<iostream>
#include<string>
#include "WindowsPhone-header.cpp"
#include "AndroidPhone-header.cpp"
#include "MobilePhone-header.cpp"
#include "ApplePhone-header.cpp.cpp"
using namespace std;
int main()
{
	ApplePhone ap;
	ap.turnOn();
	ap.makeVoiceCall(12345);
	ap.launchPaper();
	ap.recordAudio();
	ap.turnOff();

	AndroidPhone andp;
	andp.turnOn();
	andp.launchFlynx();
	andp.makeVoiceCall(67890);
	andp.launchSubwaySurfers();
	andp.turnOff();

	WindowsPhone wp;
	wp.turnOn();
	wp.launchXboxGame();
	wp.sendSMS("Text messaging not allowed in lab!", 02323);
	wp.turnOff();
	return 0;
}