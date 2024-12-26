//#include<iostream>
//using namespace std;
//class Person
//{
//private:
//    string name;
//    string cnic;
//public:
//    Person()
//    {
//        name = "";
//        cnic = "";
//    }
//    Person(string n,string c)
//    {
//        name = n;
//        cnic = c;
//    }
//    void setName(string n)
//    {
//        name = n;
//    }
//    void setCnic(string n)
//    {
//        cnic = n;
//    }
//    void displayPerson()
//    {
//        cout << "\n\nPerson's Details : \n";
//        cout << "\nName : " << name;
//        cout << "\nCnic : " << cnic<<"\n";
//    }
//};
//class Address
//{
//private:
//    string town;
//    string city;
//    Person per;
//public:
//    Address()
//    {
//        town = "";
//        city = "";
//    }
//    Address(string n, string c,string a,string b)
//    {
//        town = n;
//        city = c;
//        per.setName(a),
//        per.setCnic(c);
//    }
//    void setTown(string n)
//    {
//        town = n;
//    }
//    void setCity(string n)
//    {
//        city = n;
//    }
//    string getTown()
//    {
//        return town;
//    }
//    string getCity()
//    {
//        return city;
//    }
//    void displayAddress()
//    {
//        cout << "\n\nAddress Details : \n";
//        cout << "\nTown : " << town;
//        cout << "\nCity : " << city << "\n";
//        per.displayPerson();
//    }
//};
//int main() 
//{
//    Address ad("Anarkali", "Lahore", "M.Ahmad", "36502");
//    ad.displayAddress();
//    return 0;
//}
