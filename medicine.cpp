#ifndef MEDI_H
#define MEDI_H
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
#endif