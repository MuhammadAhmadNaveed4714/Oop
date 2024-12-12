#ifndef WINDOWSPHONE_H
#define WINDOWSPHONE_H
#include<iostream>
#include<string>
#include"MobilePhone-header.cpp"
using namespace std;
class WindowsPhone : public MobilePhone
{
private:
	string productName;
	string buildNumber;
public:
	WindowsPhone()
	{
		cout << "\nHello, Windows!";
	}
	void launchFoundbite()
	{
		cout << "\nChecking Foundbite newsfeed. ";
	}
	void launchXboxGame()
	{
		cout << "\nPlaying Xbox game";
	}
	string getProductName()
	{
		return productName;
	}
	void setProductName(string name)
	{
		productName = name;
	}
	string getBuildNumber()
	{
		return buildNumber;
	}
	void setBuildNumber(string number)
	{
		buildNumber = number;
	}
	~WindowsPhone()
	{
		cout << "\nWindows phone destroyed...";
 }
};
#endif