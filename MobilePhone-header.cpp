#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H
#include<iostream>
#include<string>
using namespace std;
class MobilePhone
{
private:
	int mfgID;
	string mfgDate;
	string mfgName;
	bool state;
public:
	MobilePhone();
	MobilePhone(int, string, string);
	void setMfgID(int);
	void setMfgDate(string);
	void setMfgName(string);
	void getMfgID() const;
	void getMfgDate() const;
	void getMfgName() const;
	bool turnOn();
	void makeVoiceCall(int);
	void recordAudio();
	void sendSMS(string, int);
	void turnOff();
	~MobilePhone();
};
#endif