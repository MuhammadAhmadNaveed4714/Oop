#ifndef ANDROIDPHONE_H
#define ANDROIDPHONE_H
#include<iostream>
#include<string>
#include"MobilePhone-header.cpp"
using namespace std;
class AndroidPhone : public MobilePhone
{
private:
	string kernelVersion;
	string androidVersion;
public:
	AndroidPhone()
	{
		cout << "\nHello, Android!";
	}
	void launchSubwaySurfers()
	{
		cout << "\nPlaying Subway Surfers.";
	}
	void launchFlynx()
	{
		cout << "\nUsing Flynx browser.";
	}
	string getKernelVersion()
	{
		return kernelVersion;
	}
	void setKernelVersion(string version)
	{
		kernelVersion = version;
	}
	string getiOSVersion()
	{
		return androidVersion;
	}
	void setAndroidVersion(string version)
	{
		androidVersion = version;
	}
	~AndroidPhone()
	{
		cout << "\nAndroid phone destroyed...";
	}
};
#endif
