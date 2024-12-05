#include <iostream> 
#include "Budget.cpp"
#include "Auxil.cpp"
using namespace std;
  int main()
  {
	      int count;                    // Loop counter 
	      double mainOfficeRequest;     // Main office budget request 
	      const int NUM_DIVISIONS = 3;  // Number of divisions 
	      // Get the main office's budget request. 
		  cout << "Enter the main office's budget request: ";
	      cin >> mainOfficeRequest;
	      Budget::mainOffice(mainOfficeRequest);
		  Budget divisions[NUM_DIVISIONS];  // Array of Budget objects 
	      AuxiliaryOffice auxOffices[3];    // Array of AuxiliaryOffice 
		      // Get the budget requests for each division 
		      // and their auxiliary offices. 
		  for (count = 0; count < NUM_DIVISIONS; count++)
		  {
		          double budgetAmount; // To hold input 
			          // Get the request for the division office. 
			          cout << "Enter the budget request for division ";
		          cout << (count + 1) << ": ";
		          cin >> budgetAmount;
		          divisions[count].addBudget(budgetAmount);
			          // Get the request for the auxiliary office. 
			          cout << "Enter the budget request for that division's\n";
		          cout << "auxiliary office: ";
		          cin >> budgetAmount;
		          auxOffices[count].addBudget(budgetAmount, divisions[count]);
		  }
	      cout << "\nHere are the division budget requests:\n";
	    for (count = 0; count < NUM_DIVISIONS; count++)
		{
		          cout << "\tDivision " << (count + 1) << "\t\t$";
		          cout << divisions[count].getDivisionBudget() << endl;
		          cout << "\tAuxiliary office:\t$";
		          cout << auxOffices[count].getDivisionBudget() << endl << endl;
		}
	      cout << "Total Budget Requests:\t$ ";
	      cout << divisions[0].getCorpBudget() << endl;
	      return 0;
	  }