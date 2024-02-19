#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class account_query
{
    char account_number[20];
    char firstName[10];
    char lastName[15];
    float total_balance;
public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void seaarch_rec();
    void edit_rec();
    void delete_rec();
};

void account_query::read_data()
{
    cout<<"\n Enter Account Number: ";
    cin>>account_number;
    cout<<"\n Enter First Name";
    cin>>firstName;
    cout<<"\n Enter Last Name";
    cin>>lastName;
    cout<<"\n Enter Balance";
    cin>>total_balance;
    cout<<endl;
}

void account_query::show_data()
{
    cout<<"Account Number: "<<account_number<<endl;
    cout<<"FIrst Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Current Balance: "<<total_balance<<endl;
}

void account_query::write_rec()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this),sizeof(*this));
    outfile.close();
}

void account_query::read_rec()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n***Data from file***"<<endl;
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char *>(this), sizeof(*this))>0)
        {
            show_data();
        }
    }
    infile.close();
}

void account_query::seaarch_rec()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg/sizeof(*this);
    cout<<"\n There are "<<count<<"record in the file";
    cout<<"\n Enter record number to search: ";
    cin>>n;
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}

void account_query::edit_rec()
{
    
}