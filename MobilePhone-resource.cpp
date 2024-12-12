#include<iostream>
#include<string>
#include"MobilePhone-header.cpp"
using namespace std;
MobilePhone::MobilePhone()
{
	state = false;
	cout << "\nPhone made by the factory ! ";
}
MobilePhone::MobilePhone(int id,string date,string name)
{
	mfgID = id;
	mfgDate = date;
	mfgName = name;
	state = false;
	cout << "\nPhone made by the factory ! ";
}
void MobilePhone::setMfgID(int id)
{
	mfgID = id;
}
void MobilePhone::setMfgDate(string date)
{
	mfgDate = date;
}
void MobilePhone::setMfgName(string name)
{
	mfgName = name;
}
void MobilePhone::getMfgID() const
{
	cout << "Manufacturer ID: " << mfgID << endl; 
}
void MobilePhone::getMfgDate() const
{
	cout << "Manufacturer Date: " << mfgDate << endl;
}
void MobilePhone::getMfgName() const
{
	cout << "Manufacturer Name: " << mfgName << endl;
}
bool MobilePhone:: turnOn()
{
	state = true;
	cout << "Phone turned on." << endl;
	return state;
}
void MobilePhone::makeVoiceCall(int phoneNumber) 
{
	if (state)
	{
		cout << "Calling to " << phoneNumber << "..." << endl;
	}
	else
	{
		cout << "Phone is off, cannot make a call." << endl;
	}
}
void MobilePhone::sendSMS(string message, int recipient)
{
	if (state)
	{
		cout << "\nThe message has been sent to " << recipient << " : " << message << "\n";
	}
	else
	{
		cout << "\nPhone is off,cannot send SMS.\n";
	}
}
void MobilePhone::recordAudio()
{
	if (state)
	{
		cout << "\nSpeak into the microphone.";
	}
	else
	{
		cout << "\nPhone is off,cannot record audio. ";
	}
}
void MobilePhone::turnOff()
{
	state = false;
	cout << "\nPhone turned off.\n";
}
MobilePhone::~MobilePhone()
{
	cout << "\nPhone destroyed...\n";
}
