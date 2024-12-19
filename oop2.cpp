#include<iostream>
#include<fstream>
#include<string>
#include"medicine.cpp"
#include"supplier.cpp"
using namespace std;








int main()
{
    Medicine* medicines[100];  // Array to store up to 100 medicines
    int count = 0;

    // Load existing data from file
    Medicine::loadFromFile(medicines, count);
    Supplier* suppliers[100];  // Array to store up to 100 suppliers
    int co = 0;

    // Load existing data from file
    Supplier::loadFromFile(suppliers, count);

    

    

    int choice;
    do
    {
        cout << "\nMenu: \n";
        cout << "1. Add Medicine\n";
        cout << "2. Edit Medicine\n";
        cout << "3. Delete Medicine\n";
        cout << "4. Search Medicine\n";
        cout << "5. Display All Medicines\n";
        cout << "6. Add Stock\n";
        cout << "7. Deduct Stock\n";
        cout << "8. Add Supplier\n";
        cout << "9. Edit Supplier\n";
        cout << "10. Delete Supplier\n";
        cout << "11. Search Supplier\n";
        cout << "12. Display All Suppliers\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Medicine::addMedicine(medicines, count);
            break;
        }
        case 2:
        {
            Medicine::editMedicine(medicines, count);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter Medicine ID to delete: ";
            cin >> id;
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter Medicine ID to search: ";
            cin >> id;
            Medicine::searchMedicine(medicines, count, id);
            break;
        }
        case 5:
        {
            for (int i = 0; i < count; i++)
            {
                medicines[i]->display();
            }
            break;
        }
        case 6:
        {
            int id, quantity;
            cout << "Enter Medicine ID to add stock: ";
            cin >> id;
            Medicine::deleteMedicine(medicines, count, id);
            cin >> id;
            cout << "Enter quantity to add: ";
            cin >> quantity;
            Medicine::searchMedicine(medicines, count, id);
            for (int i = 0; i < count; i++)
            {
                if (medicines[i]->getID() == id)
                {
                    (*medicines[i]) + quantity;
                }
            }
            break;
        }
        case 7:
        {
            int id, quantity;
            cout << "Enter Medicine ID to deduct stock: ";
            cin >> id;
            cout << "Enter quantity to deduct: ";
            cin >> quantity;
            Medicine::searchMedicine(medicines, count, id);
            for (int i = 0; i < count; i++)
            {
                if (medicines[i]->getID() == id)
                {
                    (*medicines[i]) - quantity;
                }
            }
            break;
        }
        case 8:
        {
            Supplier::addSupplier(suppliers, count);
            break;
        }
        case 9:
        {
            Supplier::editSupplier(suppliers, count);
            break;
        }
        case 10:
        {
            int id;
            cout << "Enter Supplier ID to delete: ";
            cin >> id;
            Supplier::deleteSupplier(suppliers, count, id);
            break;
        }
        case 11:
        {
            int id;
            cout << "Enter Supplier ID to search: ";
            cin >> id;
            Supplier::searchSupplier(suppliers, count, id);
            break;
        }
        case 12:
        {
            for (int i = 0; i < count; i++)
            {
                suppliers[i]->display();
            }
            break;
        }
        
       
        case 13:

            cout << "Exiting program...\n";
            break;

        default:

            cout << "Invalid choice.\n";
        }
    } while (choice != 13);

    // Cleanup memory
    for (int i = 0; i < count; i++)
    {
        delete medicines[i];
    }
    // Cleanup memory
    for (int i = 0; i < co; i++)
    {
        delete suppliers[i];
    }


    
    return 0;
}
