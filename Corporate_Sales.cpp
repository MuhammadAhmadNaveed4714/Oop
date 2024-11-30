#include <iostream>
using namespace std;
class DivSales 
{
private:
    double sales[4];
    static double totalCorporateSales;
public:
    void inputSales(double q1, double q2, double q3, double q4)
    {
        sales[0] = q1;
        sales[1] = q2;
        sales[2] = q3;
        sales[3] = q4;
        totalCorporateSales += (q1 + q2 + q3 + q4);
    }
    double getSales(int quarter) const
    {
        if (quarter >= 0 && quarter <= 3) 
        {
            return sales[quarter];
        }
        return -1; 
    }
    static double getTotalCorporateSales()
    {
        return totalCorporateSales;
    }
};
double DivSales::totalCorporateSales = 0.0;
int main() 
{
    DivSales divisions[6];
    double q1, q2, q3, q4;
    for (int i = 0; i < 6; i++) 
    {
        cout << "\nEnter sales for Division " << i + 1 << " (for 4 quarters):\n\n";
        do
        {
            cout << "Enter sales for Q1: ";
            cin >> q1;
        } while (q1 <= 0);
        do
        {
            cout << "Enter sales for Q2: ";
            cin >> q2;
        } while (q2 <= 0);
        do
        {
            cout << "Enter sales for Q3: ";
            cin >> q3;
        } while (q3 <= 0);
        do
        {
            cout << "Enter sales for Q4: ";
            cin >> q4;
        } while (q4 <= 0);
        divisions[i].inputSales(q1, q2, q3, q4);
    }
    cout << "\nDivision Sales Data (by Quarter):\n\n";
    cout << "Division\tQ1\tQ2\tQ3\tQ4\n\n";
    for (int i = 0; i < 6; i++) 
    {
        cout << "Division " << i + 1 << "\t";
        for (int j = 0; j < 4; j++)
        {
            cout << divisions[i].getSales(j) << "\t";
        }
        cout << endl;
    }
    cout << "\nTotal Corporate Sales for the Year: " << DivSales::getTotalCorporateSales() << endl;
    return 0;
}
