#include "Budget.cpp" 
// Definition of corpBudget static member variable 
double Budget::corpBudget = 0;
void Budget::mainOffice(double moffice)
{
     corpBudget += moffice;
}