#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include<iostream>
#include<string>
using namespace std;
class Textbook
{
private:
	string title;
	string author;
	string publisher;
public:
	Textbook()
	{
		title = "t";
		author = "a";
		publisher = "p";
	}
	void set(string tit, string auth, string pub)
	{
		title = tit;
		author = auth;
		publisher = pub;
	}
	void print() const
	{
		cout << "\nTitle : " << title;
		cout << "\nAuthor : " << author;
		cout << "\nPublisher : " << publisher;
	}
};
#endif
