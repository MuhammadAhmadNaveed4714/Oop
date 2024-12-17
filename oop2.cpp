#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Medicine
{
private:
    int ID;
    string Name;
    string Potency;
    string Manufacturer;
    int Quantity;
    double PricePerUnit;

public:
    //Default constructor
    Medicine() : ID(0), Quantity(0), PricePerUnit(0.0)
    {
    }

    //Parameterized constructor
    Medicine(int id, const string& name, const string& potency, const string& manufacturer, int quantity, double price)
        : ID(id), Name(name), Potency(potency), Manufacturer(manufacturer), Quantity(quantity), PricePerUnit(price)
    {
    }

    // Getter functions
    int getID() const
    {
        return ID;
    }
    string getName() const
    {
        return Name;
    }
    string getPotency() const
    {
        return Potency;
    }
    string getManufacturer() const
    {
        return Manufacturer;
    }
    int getQuantity() const
    {
        return Quantity;
    }
    double getPricePerUnit() const
    {
        return PricePerUnit;
    }

    // Setter functions
    void setID(int id)
    {
        ID = id;
    }
    void setName(const string& name)
    {
        Name = name;
    }
    void setPotency(const string& potency)
    {
        Potency = potency;
    }
    void setManufacturer(const string& manufacturer)
    {
        Manufacturer = manufacturer;
    }
    void setQuantity(int quantity)
    {
        Quantity = quantity;
    }
    void setPricePerUnit(double price)
    {
        PricePerUnit = price;
    }

    // Display the details of the medicine
    void display() const
    {
        cout << "ID: " << ID << ", Name: " << Name << ", Potency: " << Potency
            << ", Manufacturer: " << Manufacturer << ", Quantity: " << Quantity
            << ", Price per Unit: " << PricePerUnit << endl;
    }

    // Overload + operator to add stock
    Medicine operator+(int quantity)
    {
        Quantity += quantity;
        return *this;
    }

    // Overload - operator to deduct stock
    Medicine operator-(int quantity)
    {
        if (Quantity >= quantity)
        {
            Quantity -= quantity;
            return *this;
        }
        else
        {
            cout << "Not enough stock to deduct." << endl;
        }
    }

    //Function to add a new medicine
    static void addMedicine(Medicine* medicines[], int& count)
    {
        int id;
        cout << "Enter Medicine ID: ";
        cin >> id;

        //Check if medicine with this ID already exists
        for (int i = 0; i < count; i++)
        {
            if (medicines[i]->getID() == id)
            {
                cout << "Medicine with this ID already exists. Use the Edit option to modify details." << endl;
                return;
            }
        }

        //Add a new medicine
        cout << "Enter Name: ";
        cin.ignore();
        string name;
        getline(cin, name);

        cout << "Enter Potency: ";
        string potency;
        getline(cin, potency);

        cout << "Enter Manufacturer: ";
        string manufacturer;
        getline(cin, manufacturer);

        cout << "Enter Quantity: ";
        int quantity;
        cin >> quantity;

        cout << "Enter Price per Unit: ";
        double price;
        cin >> price;

        medicines[count] = new Medicine(id, name, potency, manufacturer, quantity, price);
        count++;
        cout << "Medicine added successfully." << endl;
        saveToFile(medicines, count);  // Save the updated data to file
    }

    //Function to edit an existing medicine
    static void editMedicine(Medicine* medicines[], int count)
    {
        int id;
        cout << "Enter Medicine ID to edit: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (medicines[i]->getID() == id)
            {
                cout << "Editing details for Medicine ID: " << id << endl;
                // Edit existing details
                string name, potency, manufacturer;
                int quantity;
                double price;
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, name);
                medicines[i]->setName(name);

                cout << "Enter New Potency: ";
                getline(cin, potency);
                medicines[i]->setPotency(potency);

                cout << "Enter New Manufacturer: ";
                getline(cin, manufacturer);
                medicines[i]->setManufacturer(manufacturer);

                cout << "Enter New Quantity: ";
                cin >> quantity;
                medicines[i]->setQuantity(quantity);

                cout << "Enter New Price per Unit: ";
                cin >> price;
                medicines[i]->setPricePerUnit(price);

                cout << "Medicine details updated." << endl;
                saveToFile(medicines, count);  // Save the updated data to file
                return;
            }
        }
        cout << "Medicine with this ID not found." << endl;
    }

    //Function to delete a medicine
    static void deleteMedicine(Medicine* medicines[], int& count, int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (medicines[i]->getID() == id)
            {
                delete medicines[i];
                for (int j = i; j < count - 1; j++)
                {
                    medicines[j] = medicines[j + 1];
                }
                count--;
                cout << "Medicine deleted." << endl;
                saveToFile(medicines, count);  // Save the updated data to file
                return;
            }
        }
        cout << "Medicine not found." << endl;
    }

    //Function to search for a medicine by ID
    static void searchMedicine(Medicine* medicines[], int count, int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (medicines[i]->getID() == id)
            {
                medicines[i]->display();
                return;
            }
        }
        cout << "Medicine not found." << endl;
    }

    //Function to save data to a file
    static void saveToFile(Medicine* medicines[], int count)
    {
        ofstream file("MInfo.txt");
        if (!file.is_open())
        {
            cout << "Error opening file for writing." << endl;
            return;
        }
        //Write all medicines to the file
        for (int i = 0; i < count; i++)
        {
            file << medicines[i]->getID() << ","
                << medicines[i]->getName() << ","
                << medicines[i]->getPotency() << ","
                << medicines[i]->getManufacturer() << ","
                << medicines[i]->getQuantity() << ","
                << medicines[i]->getPricePerUnit() << endl;
        }
        file.close();
    }

    //Function to load data from a file
    static void loadFromFile(Medicine* medicines[], int& count)
    {
        ifstream file("MInfo.txt");
        if (!file.is_open())
        {
            cout << "File not found, starting with empty data." << endl;
            return;  // If file doesn't exist, simply return without errors
        }

        while (file)
        {
            int id, quantity;
            double price;
            string name, potency, manufacturer;
            char comma;

            file >> id >> comma;
            getline(file, name, ',');
            getline(file, potency, ',');
            getline(file, manufacturer, ',');
            file >> quantity >> comma >> price;

            if (file) {
                medicines[count] = new Medicine(id, name, potency, manufacturer, quantity, price);
                count++;
            }
        }
        file.close();
    }
};
class Supplier
{
private:
    int SID;
    string SCompanyName;
    string SRepresentativeName;
    string SAddress;
    string SDescription;

public:
    // Default constructor
    Supplier() : SID(0)
    {
    }

    //Parameterized constructor
    Supplier(int id, const string& companyName, const string& repName, const string& address, const string& description)
        : SID(id), SCompanyName(companyName), SRepresentativeName(repName), SAddress(address), SDescription(description)
    {
    }

    //Getter functions
    int getID() const
    {
        return SID;
    }
    string getCompanyName() const
    {
        return SCompanyName;
    }
    string getRepresentativeName() const
    {
        return SRepresentativeName;
    }
    string getAddress() const
    {
        return SAddress;
    }
    string getDescription() const
    {
        return SDescription;
    }

    //Setter functions
    void setID(int id)
    {
        SID = id;
    }
    void setCompanyName(const string& companyName)
    {
        SCompanyName = companyName;
    }
    void setRepresentativeName(const string& repName)
    {
        SRepresentativeName = repName;
    }
    void setAddress(const string& address)
    {
        SAddress = address;
    }
    void setDescription(const string& description)
    {
        SDescription = description;
    }

    //Function to display supplier details
    void display() const
    {
        cout << "ID: " << SID << "\nCompany Name: " << SCompanyName
            << "\nRepresentative Name: " << SRepresentativeName
            << "\nAddress: " << SAddress
            << "\nDescription: " << SDescription << endl;
    }

    //Function to add a new supplier
    static void addSupplier(Supplier* suppliers[], int& count)
    {
        int id;
        cout << "Enter Supplier ID: ";
        cin >> id;

        //Check if supplier with this ID already exists
        for (int i = 0; i < count; i++)
        {
            if (suppliers[i]->getID() == id)
            {
                cout << "Supplier with this ID already exists. Use the Edit option." << endl;
                return;
            }
        }

        // Add a new supplier
        cout << "Enter Company Name: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        string companyName;
        getline(cin, companyName);

        cout << "Enter Representative Name: ";
        string repName;
        getline(cin, repName);

        cout << "Enter Address: ";
        string address;
        getline(cin, address);

        cout << "Enter Description: ";
        string description;
        getline(cin, description);

        suppliers[count] = new Supplier(id, companyName, repName, address, description);
        count++;
        cout << "Supplier added successfully." << endl;
        saveToFile(suppliers, count);  // Save the updated data to file
    }

    //Function to edit an existing supplier
    static void editSupplier(Supplier* suppliers[], int co)
    {
        int id;
        cout << "Enter Supplier ID to edit: ";
        cin >> id;

        for (int i = 0; i < co; i++)
        {
            if (suppliers[i]->getID() == id)
            {
                cout << "Editing details for Supplier ID: " << id << endl;
                //Edit existing details
                string companyName, repName, address, description;
                cout << "Enter New Company Name: ";
                cin.ignore();
                getline(cin, companyName);
                suppliers[i]->setCompanyName(companyName);

                cout << "Enter New Representative Name: ";
                getline(cin, repName);
                suppliers[i]->setRepresentativeName(repName);

                cout << "Enter New Address: ";
                getline(cin, address);
                suppliers[i]->setAddress(address);

                cout << "Enter New Description: ";
                getline(cin, description);
                suppliers[i]->setDescription(description);

                cout << "Supplier details updated." << endl;
                saveToFile(suppliers, co);  // Save the updated data to file
                return;
            }
        }
        cout << "Supplier with this ID not found." << endl;
    }

    // Function to delete a supplier
    static void deleteSupplier(Supplier* suppliers[], int& co, int id)
    {
        for (int i = 0; i < co; i++)
        {
            if (suppliers[i]->getID() == id)
            {
                delete suppliers[i];
                for (int j = i; j < co - 1; j++)
                {
                    suppliers[j] = suppliers[j + 1];
                }
                co--;
                cout << "Supplier deleted." << endl;
                saveToFile(suppliers, co);  // Save the updated data to file
                return;
            }
        }
        cout << "Supplier not found." << endl;
    }

    // Function to search for a supplier by ID
    static void searchSupplier(Supplier* suppliers[], int co, int id)
    {
        for (int i = 0; i < co; i++)
        {
            if (suppliers[i]->getID() == id)
            {
                suppliers[i]->display();
                return;
            }
        }
        cout << "Supplier not found." << endl;
    }

    // Function to save supplier data to a file
    static void saveToFile(Supplier* suppliers[], int co)
    {
        ofstream file("SInfo.txt");
        if (!file.is_open())
        {
            cout << "Error opening file for writing." << endl;
            return;
        }
        // Write all suppliers to the file
        for (int i = 0; i < co; i++)
        {
            file << suppliers[i]->getID() << ","
                << suppliers[i]->getCompanyName() << ","
                << suppliers[i]->getRepresentativeName() << ","
                << suppliers[i]->getAddress() << ","
                << suppliers[i]->getDescription() << endl;
        }
        file.close();
    }

    //Function to load supplier data from a file
    static void loadFromFile(Supplier* suppliers[], int& co)
    {
        ifstream file("SInfo.txt");
        if (!file.is_open())
        {
            cout << "File not found, starting with empty data." << endl;
            return;  // If file doesn't exist, simply return without errors
        }

        while (file)
        {
            int id;
            string companyName, repName, address, description;
            char comma;

            file >> id >> comma;
            getline(file, companyName, ',');
            getline(file, repName, ',');
            getline(file, address, ',');
            getline(file, description);

            if (file)
            {
                suppliers[co] = new Supplier(id, companyName, repName, address, description);
                co++;
            }
        }
        file.close();
    }
};







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
