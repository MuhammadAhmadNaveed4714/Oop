#ifndef FEETINCHES_H
#define FEETINCHES_H
class FeetInches
{
private:
	int feet;
	int inches;
	void simplify();
public:
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}
	void setFeet(int f)
	{
		feet = f;
	}
	void setInches(int i)
	{
		inches = i;
		simplify();
	}
	int getFeet() const
	{
		return feet;
	}
	int getInches() const
	{
		return inches;
	}
	void display();
	FeetInches operator + (const FeetInches&);
	FeetInches operator - (const FeetInches&);
};
#endif