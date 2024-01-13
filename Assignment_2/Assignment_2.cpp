/*Code for inventory management system with add, print and search feature */

#include<iostream>
#include<string>
#include<limits>

//Inventory Size
#define MAX_ITEMS 2

using namespace std;
void printMenu();
void clearInputBuffer();

//Class for Implementation Of Individual Item.
class Item{
    private:
        long id;
        float cost;
        int quantity;
        string name;
    public:
        void setProperties();
        void print();
        //Getter function for ID
        long getId(){return id;};
        //Getter function for Name
        string getName(){return name;};
};
//Class for Storage of Items And Actions On them
class Inventory{
    private:
        Item items[MAX_ITEMS];
        int count;
    public:
        Inventory(){count=0;}
        void addItem();
        void print();
        void searchItem(int search_key, int id, string name);
};

//Item Class Methods
//START

//Setting Item Object Properties
void Item::setProperties(){
    cout << endl<<endl<<"Please Enter The Item Details"<<endl;
    
    do{
        clearInputBuffer();
        cout << "Enter ID: ";
    }while(!(cin>>id) && cout<<"Please Enter valid Number for Id"<<endl<<endl);

    cout << "Enter Name: ";
    cin >> name;
    
    do{
        clearInputBuffer();
        cout << "Enter Cost: ";
    }while(!(cin >> cost) && cout<<"Please Enter valid Number For Cost"<<endl);
    
     do{
        clearInputBuffer();
        cout << "Enter Quantity: ";
    }while(!(cin >> quantity) && cout<<"Please Enter valid Number For Quantity"<<endl);

}


//Printing Item Details
void Item::print(){
    cout << " **Item Details** "<<endl;
    cout << "  Items ID: " << id<<endl;
    cout << "  Enter Name: "<<name<<endl;
    cout << "  Enter Cost: $"<<cost<<endl;
    cout << "  Enter Quantity: "<<quantity<<endl;
}

//END
//Item Class Methods


//Inventory Class Methods
//START
//Adds An Item To The Inventory
void Inventory::addItem(){
    if(count >= MAX_ITEMS){
        cout <<"Inventory got full"<<endl;
    }
    else{
        items[count].setProperties();
        count++;
    }
}

//Prints The Inventory
void Inventory::print(){
    cout<<endl<<endl<<"---------------------------"<<endl;
    cout<<"INVENTORY DETAILS"<<endl;
    
  
    for (int i = 0 ; i < count; i++){
        
        items[i].print();
        cout<<"-----------------------------"<<endl<<endl;
    }
}

//Search for an item by name Or Id
void Inventory::searchItem(int search_key, int id, string name){
    bool itemFound = false;
    for (int i=0 ; i< count; i++){
        if (search_key == 3){
            if(items[i].getId() == id){
                items[i].print();
                itemFound = true;
                break;
            }
        }
        else{
            if(items[i].getName().compare(name) == 0){
                items[i].print();
                itemFound = true;
                break;
            }
        }
    }
    if(!itemFound) cout<<endl<< "Item Not Found" << endl<<endl;
}

//END
//Inventory Class Methods


//Prints The Inventory System Menu
void printMenu(){
    cout << "                       ############ INVENTORY MANAGEMENT SYSTEM MENU ############"<<endl;
    cout <<"1. Add New Item"<<endl;
    cout <<"2. Print Item List"<<endl;
    cout <<"3. Find Item By Id"<<endl;
    cout <<"4. Find Item By Name"<<endl;
    cout <<"5. Quit"<<endl;
    cout<< "Select:_";
}

//Clearing Buffer
void clearInputBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int main(){

    Inventory inventory;
    int user_input = 0, search_id;
    string name_search;

    while(user_input!=5){

        printMenu();

        //Catching Invalid Option
        if(!(cin>> user_input)){
            cout <<" INVALID MENU"<<endl<<endl;
            clearInputBuffer();
            continue;
        }
        switch(user_input){
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.print();
                break;
            case 3:
                do{
                    clearInputBuffer();
                    cout << "Enter The Item Id: ";
                }while(!(cin >> search_id) && cout <<"  Please Enter valid Number "<<endl );

                inventory.searchItem(user_input, search_id, name_search);
                break;
            case 4:

                cout << "Enter The Name Of The Item: ";
                cin >> name_search;

                inventory.searchItem(user_input, search_id, name_search);

                break;
            case 5:

                cout <<" The Application is terminated"<<endl;
                break;    
            default:
            
                cout <<"Please select only from Menu"<<endl;   
        }
    }

}