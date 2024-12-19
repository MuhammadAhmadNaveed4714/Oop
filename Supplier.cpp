#ifndef SUPP_H
#define SUPP_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
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

#endif