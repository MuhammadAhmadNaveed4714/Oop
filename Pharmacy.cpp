#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Medicine class
class Medicine
{
private:
    string id, name, potency, manufacturer;
    int quantity;
    float price;

public:
    // Constructor
    Medicine(string id = "", string name = "", string potency = "", string manufacturer = "", int quantity = 0, float price = 0.0) 
    {
        this->id = id;
        this->name = name;
        this->potency = potency;
        this->manufacturer = manufacturer;
        this->quantity = quantity;
        this->price = price;
    }

    // Getter and Setter methods
    string getId() const
    { return id; }
    void setId(const string& id) 
    { this->id = id; }

    string getName() const 
    { return name; }
    void setName(const string& name) 
    { this->name = name; }

    string getPotency() const
    { return potency; }
    void setPotency(const string& potency) 
    { this->potency = potency; }

    string getManufacturer() const
    { return manufacturer; }
    void setManufacturer(const string& manufacturer)
    { this->manufacturer = manufacturer; }

    int getQuantity() const
    { return quantity; }
    void setQuantity(int quantity) 
    { this->quantity = quantity; }

    float getPrice() const
    { return price; }
    void setPrice(float price) 
    { this->price = price; }

    // Overload + operator to add stock
    Medicine operator+(int addedQuantity) 
    {
        Medicine temp = *this;
        temp.quantity += addedQuantity;
        return temp;
    }

    // Overload - operator to deduct stock
    Medicine operator-(int soldQuantity) 
    {
        Medicine temp = *this;
        temp.quantity -= soldQuantity;
        return temp;
    }

    // Overload == operator to compare IDs
    bool operator==(const Medicine& other) const
    {
        return this->id == (other.id);
    }

    // Friend function to calculate total price
    friend float calculateTotal(const Medicine& med, int quantity) 
    {
        return med.price * quantity;
    }

    // Save medicine data to file
    void saveToFile(const string& filename) 
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << id << "," << name << "," << potency << "," << manufacturer << "," << quantity << "," << price << endl;
            file.close();
        }
        else 
        {
            cout << "Unable to open file";
        }
    }

    // Load medicine data from file
    static Medicine loadFromFile(const string& filename) 
    {
        Medicine med;
        ifstream file(filename);
        if (file.is_open()) 
        {
            string line;
            getline(file, line);
            size_t pos = 0;
            string token;
            int count = 0;
            while ((pos = line.find(",")) != string::npos)
            {
                token = line.substr(0, pos);
                if (count == 0) (med.id) = token;
                if (count == 1) med.name = token;
                if (count == 2) med.potency = token;
                if (count == 3) med.manufacturer = token;
                if (count == 4) med.quantity = stoi(token);
                if (count == 5) med.price = stof(token);
                line.erase(0, pos + 1);
                count++;
            }
            file.close();
        }
        else 
        {
            cout << "Unable to open file";
        }
        return med;
    }
};



// Supplier class
class Supplier 
{
private:
    string id, companyName, representativeName, address, description;

public:
    // Constructor
    Supplier(string id = "", string companyName = "", string representativeName = "", string address = "", string description = "") 
    {
        this->id = id;
        this->companyName = companyName;
        this->representativeName = representativeName;
        this->address = address;
        this->description = description;
    }

    // Getter and Setter methods
    string getId() const 
    { return id; }
    void setId(const string& id) 
    { this->id = id; }

    string getCompanyName() const
    { return companyName; }
    void setCompanyName(const string& companyName) 
    { this->companyName = companyName; }

    string getRepresentativeName() const
    { return representativeName; }
    void setRepresentativeName(const string& representativeName) 
    { this->representativeName = representativeName; }

    string getAddress() const 
    { return address; }
    void setAddress(const string& address)
    { this->address = address; }

    string getDescription() const 
    { return description; }
    void setDescription(const string& description)
    { this->description = description; }

    // Overload == operator to compare IDs
    bool operator==(const Supplier& other) const 
    {
        return this->id == (other.id);
    }

    // Save supplier data to file
    void saveToFile(const string& filename) 
    {
        ofstream file(filename, ios::app);
        if (file.is_open()) 
        {
            file << id << "," << companyName << "," << representativeName << "," << address << "," << description << endl;
            file.close();
        }
        else
        {
            cout << "Unable to open file";
        }
    }

    // Load supplier data from file
    static Supplier loadFromFile(const string& filename) 
    {
        Supplier sup;
        ifstream file(filename);
        if (file.is_open()) 
        {
            string line;
            getline(file, line);
            size_t pos = 0;
            string token;
            int count = 0;
            while ((pos = line.find(",")) != string::npos)
            {
                token = line.substr(0, pos);
                if (count == 0) (sup.id) = token;
                if (count == 1) sup.companyName = token;
                if (count == 2) sup.representativeName = token;
                if (count == 3) sup.address = token;
                line.erase(0, pos + 1);
                count++;
            }
            file.close();
        }
        else 
        {
            cout << "Unable to open file";
        }
        return sup;
    }
};

int main() {
    string id, name, potency, manufacturer, companyName, representativeName, address, description;
    int quantity;
    float price;

    // Get medicine details from user
    cout << "Enter medicine ID: ";
    cin >> id;
    cout << "Enter medicine name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter medicine potency: ";
    getline(cin, potency);
    cout << "Enter medicine manufacturer: ";
    getline(cin, manufacturer);
    cout << "Enter medicine quantity: ";
    cin >> quantity;
    cout << "Enter medicine price: ";
    cin >> price;

    // Create medicine object
    Medicine med(id, name, potency, manufacturer, quantity, price);

    // Save medicine data to file
    med.saveToFile("medicine.txt");

    // Load medicine data from file
    Medicine loadedMed = Medicine::loadFromFile("medicine.txt");

    // Display loaded medicine data
    cout << "\nLoaded Medicine Data:" << endl;
    cout << "ID: " << loadedMed.getId() << endl;
    cout << "Name: " << loadedMed.getName() << endl;
    cout << "Potency: " << loadedMed.getPotency() << endl;
    cout << "Manufacturer: " << loadedMed.getManufacturer() << endl;
    cout << "Quantity: " << loadedMed.getQuantity() << endl;
    cout << "Price: " << loadedMed.getPrice() << endl;

    // Get supplier details from user
    cout << "\nEnter supplier ID: ";
    cin >> id;
    cout << "Enter supplier company name: ";
    cin.ignore();
    getline(cin, companyName);
    cout << "Enter supplier representative name: ";
    getline(cin, representativeName);
    cout << "Enter supplier address: ";
    getline(cin, address);
    cout << "Enter supplier description: ";
    getline(cin, description);

    // Create supplier object
    Supplier sup(id, companyName, representativeName, address, description);

    // Save supplier data to file
    sup.saveToFile("supplier.txt");

    // Load supplier data from file
    Supplier loadedSup = Supplier::loadFromFile("supplier.txt");

    // Display loaded supplier data
    cout << "\nLoaded Supplier Data:" << endl;
    cout << "ID: " << loadedSup.getId() << endl;
    cout << "Company Name: " << loadedSup.getCompanyName() << endl;
    cout << "Representative Name: " << loadedSup.getRepresentativeName() << endl;
    cout << "Address: " << loadedSup.getAddress() << endl;
    cout << "Description: " << loadedSup.getDescription() << endl;

    return 0;
}
 