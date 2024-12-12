#ifndef APPLEPHONE_H
#define APPLEPHONE_H
#include<iostream>
#include<string>
#include"MobilePhone-header.cpp"
using namespace std;
class ApplePhone : public MobilePhone
{
private:
	string iOSVersion;
public:
	ApplePhone()
	{
		cout << "\nHello, Apple!";
	}
	void launchSiri()
	{
		cout << "\nTalking to Siri.";
	}
	void launchPaper()
	{
		cout << "\nUsing Paper app";
	}
	string getiOSVersion()
	{
		return iOSVersion;
	}
	void setiOSVersion(string version)
	{
		iOSVersion = version;
	}
	~ApplePhone()
	{
		cout << "\nApple phone destroyed...";
	}
};
#endif