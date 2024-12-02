#include <iostream>
using namespace std;
class FeetInches 
{
private:
    int feet;
    int inches;
public:
    FeetInches(int f = 0, int i = 0) : feet(f), inches(i) 
    {
        if (inches >= 12)
        {
            feet += inches / 12;
            inches = inches % 12;
        }
    }
    void setFeet(int val) 
    {
        feet = val;
    }
    void setInches(int val)
    {
        inches = val;
        if (inches >= 12) 
        {
            feet += inches / 12;
            inches = inches % 12;
        }
    }
    int getFeet() const 
    {
        return feet;
    }
    int getInches() const 
    {
        return inches;
    }
    int toInches() const 
    {
        return feet * 12 + inches;
    }
};
class BoxDimension 
{
public:
    FeetInches length;
    FeetInches width;
    FeetInches height;
    BoxDimension(FeetInches l, FeetInches w, FeetInches h) : length(l), width(w), height(h) {}
    int calculateAreaInInches() 
    {
        int lengthInches = length.toInches();
        int widthInches = width.toInches();
        int heightInches = height.toInches();  
        return 2 * (lengthInches * widthInches + lengthInches * heightInches + widthInches * heightInches);
    }
};
class BoxWrapping 
{
private:
    BoxDimension box;
    float costPerSquareFoot;
public:
    BoxWrapping(BoxDimension b, float cost) : box(b), costPerSquareFoot(cost) {}
    float calculateTotalCost()
    {  
        int surfaceAreaInInches = box.calculateAreaInInches();

        
        float surfaceAreaInFeet = surfaceAreaInInches / 144.0;

        
        return surfaceAreaInFeet * costPerSquareFoot;
    }
};
int main()
{    
    int lengthFeet, lengthInches, widthFeet, widthInches, heightFeet, heightInches;
    cout << "Enter the length (feet and inches): ";
    cin >> lengthFeet >> lengthInches;
    cout << "Enter the width (feet and inches): ";
    cin >> widthFeet >> widthInches;
    cout << "Enter the height (feet and inches): ";
    cin >> heightFeet >> heightInches;
    FeetInches length(lengthFeet, lengthInches);
    FeetInches width(widthFeet, widthInches);
    FeetInches height(heightFeet, heightInches);
    BoxDimension box(length, width, height);
    float costPerSquareFoot;
    cout << "Enter the cost of material per square foot: $";
    cin >> costPerSquareFoot;
    BoxWrapping wrapping(box, costPerSquareFoot);
    float totalCost = wrapping.calculateTotalCost();
    cout << "The total cost to wrap the box is: $" << totalCost << endl;
    return 0;
}
