#include <iostream> 
using namespace std;
class Budget
{
private:
	static double corpBudget;  // Static member variable 
	double divisionBudget;    // Instance member variable 
public:
	Budget()
	{
		divisionBudget = 0;
	}
	void addBudget(double b)
	{
		divisionBudget += b;
		corpBudget += b;
	}
	double getDivisionBudget() const
	{
		return divisionBudget;
	}
	double getCorpBudget() const
	{
		return corpBudget;
	}
	static void mainOffice(double);
};
double Budget::corpBudget = 0;
void Budget::mainOffice(double moffice)
{
	      corpBudget += moffice;
}
  int main()
  {
	      int count=0;                   // Loop counter 
	      double mainOfficeRequest=0;     // Main office budget request 
	      const int NUM_DIVISIONS = 3;  // Number of divisions 
		      // Get the main office's budget request. 
		      // Note that no instances of the Budget class have been defined. 
		      cout << "Enter the main office's budget request: ";
	      cin >> mainOfficeRequest;
	      Budget::mainOffice(mainOfficeRequest);
		  Budget divisions[NUM_DIVISIONS]; // An array of Budget objects. 
			        // Get the budget requests for each division.
					  double budgetAmount=0;
			        for (count = 0; count < NUM_DIVISIONS; count++)
			        {
			            cout << "Enter the budget request for division ";
			            cout << (count + 1) << ": ";
			            cin >> budgetAmount;
			            divisions[count].addBudget(budgetAmount);
			        }
			        // Display the budget requests and the corporate budget. 
		        cout << "\nHere are the division budget requests:\n";
		        for (count = 0; count < NUM_DIVISIONS; count++)
			        {
			            cout << "\tDivision " << (count + 1) << "\t$ ";
			            cout << divisions[count].getDivisionBudget() << endl;
			        }
		        cout << "\tTotal Budget Requests:\t$ ";
		        cout << divisions[0].getCorpBudget() << endl;
				return 0;
  }