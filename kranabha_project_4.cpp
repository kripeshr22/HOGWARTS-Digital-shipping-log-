//
//  main.cpp
//  Project4
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//
//include header files here
#include "Owl.h"
#include "Griffin.h"
#include "VanishingCabinet.h"

//all includes here
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void print_menu();  //prints the menu
size_t get_selection(); //gets selection from the user
void schedule_new_delivery(vector<Delivery*>&); //adds a new delivery
string generate_id(int);    //generates a random id according to the shipment type
string timestamp(); //registers the timestamp
void rem_delivery(vector<Delivery*>&);  //removes a delivery
void load_deliveries(vector<Delivery*>&);   //loads deliveries from file
void save_deliveries(vector<Delivery*>);    //saves deliveries to file
void display_all(vector<Delivery*>);    //displays all scheduled deliveries
void display_type(vector<Delivery*>);   //displays deliveries by type
bool duplicate_checkfor_id(vector<Delivery*>, string);  //checks for duplicate id
void sort_deliveries(vector<Delivery*>&);   //sorts deliveries in Owl, grffin, vanishing order
void shuffle_deliveries(vector<Delivery*>&);    //randomly shuffles deliveries

int main()
{
    vector<Delivery*> objects; //stores the pointers to the objects created
    
    size_t index_call;  //stroes returned value from get_selection
    
    //do while loop that controls the program
    do
    {
        print_menu();
        index_call = get_selection();
        switch(index_call)
        {
            case 1: //schedules a new delivery
                schedule_new_delivery(objects);
                break;
                
            case 2: //removes a delivery
                rem_delivery(objects);
                break;
                
            case 3: //loads deliveries from file
                load_deliveries(objects);
                break;
                
            case 4: //saves deliveries to file
                save_deliveries(objects);
                break;
                
            case 5: //sorts deliveries in Owl, Griffin, Vanishing order
                sort_deliveries(objects);
                break;
                
            case 6: //randomly shuffles deliveries
                shuffle_deliveries(objects);
                break;
                
            case 7: //displays all scehduled deliveries
                display_all(objects);
                break;
                
            case 8: //displays deliveiries by type
                display_type(objects);
                break;
        }
    }
    while (index_call != 9);
    for (int i = 0; i < objects.size(); i++)
    {
        objects.pop_back();
        delete objects[i];  //clearing up memory after exiting program
    }
    
    cout << "Thank you for using HOGWARTS !" << endl;
    return 0;
}

//displaying menu
void print_menu()
{
    cout << endl;
    cout << "Please select from the following choices:" << endl;
    cout << "\t (1) Schedule a new delivery" << endl;
    cout << "\t (2) Remove a delivery" << endl;
    cout << "\t (3) Load deliveries from file" << endl;
    cout << "\t (4) Save deliveries to file" << endl;
    cout << "\t (5) Sort Deliveries" << endl;
    cout << "\t (6) Shuffle Deliveries" << endl;
    cout << "\t (7) Print all scheduled deliveries" << endl;
    cout << "\t (8) Print deliveries by transportation type" << endl;
    cout << "\t (9) Quit" << endl;
    cout << "Selection: ";
}

//getting selection from the user
size_t get_selection()
{
    size_t index = 0;
    do
    {
        cin >> index;
        if (index <= 0 || index > 9)    //Input validation loop
        {
            cout << "Invalid Data. Please enter a number between 1 and 10" << endl;
            cout << endl;
            print_menu();
        }
    }
    while (index <= 0 || index > 9);
    return index;
}

void schedule_new_delivery(vector<Delivery*>&objects)
{
    char shipping;  //stores y or n
    string name_of_sender;  //stores name of sender
    double weight;  //stores weight
    
    cout << endl;
    cout << "\t Schedule a new delivery" << endl;
    cout << "---------------------------" << endl;
    cout << "\t Please enter the sender's name: ";
    cin.ignore();
    getline(cin, name_of_sender);   //getting sender name
    
    cout << "\t Standard Shipping (Y/N)? ";
    cin >> shipping;
    cout << "\t Enter weight (kgs): ";
    cin >> weight;
    
    while (weight <= 0)
    {
        if(weight <= 0)
        {
            cout <<"\t Invalid Data :: Enter again: ";
            cin >> weight;
        }
    }
    
    if (tolower(shipping) == 'n')   //condition for vanishing cabinet
    {
        int type = 1;
        string time_stamp = timestamp();
        string id;
     
//generating id making sure it does not match with an already created id   
        do
        {
            id = generate_id(type);
        }
        while (duplicate_checkfor_id(objects, id) == true);
     
//storing all the information of the object   
        VanishingCabinet* obj = new VanishingCabinet(name_of_sender, time_stamp, weight, id);
        objects.push_back(obj);
    }
    
    else if (tolower(shipping) == 'y') //condition for standard shipping
    {
        if(weight <= 1.58)  //condition for owl
        {
            int type = 2;
            string id;
            string time_stamp = timestamp();
            
            do
            {
                id = generate_id(type);
            }
            while(duplicate_checkfor_id(objects, id) == true);
            
            Owl* obj = new Owl(name_of_sender, time_stamp, weight, id);
            objects.push_back(obj);
        }
        
        else    //condition for Griffin
        {
            int type = 3;
            string id;
            string time_stamp = timestamp();
            
            do
            {
                id = generate_id(type);
            }
            while(duplicate_checkfor_id(objects, id) == true);
            
            Griffin* obj = new Griffin(name_of_sender, time_stamp, weight, id);
            objects.push_back(obj);
        }
    }
}

//generates a unique id for every shipment according to shipment type
string generate_id(int type)
{
    srand(time(NULL));
    
    if (type == 2)  //generating id for owl
    {
        string ret_id = "o";
        for (int i = 0; i < 3; i++)
        {
            int num_id = rand()% 10;
            stringstream ss;
            ss << num_id;
            string st_id = ss.str();
            ret_id.append(st_id);
        }
        return ret_id;
    }
    
    else if (type == 3) //generating id for griffin
    {
        string ret_id = "g";
        for (int i = 0; i < 7; i++)
        {
            int num_id = rand() % 10;
            stringstream ss;
            ss << num_id;
            string st_id = ss.str();
            ret_id.append(st_id);
        }
        return ret_id;
    }
    
    else    //generating id for Vanishing Cabinet
    {
        string hyphen = "-";
        string ret_id;
        for (int i = 0; i < 8; i++)
        {
            int num_id = rand() % 10;
            stringstream ss;
            ss << num_id;
            string first8 = ss.str();
            ret_id.append(first8);
        }
        
        ret_id.append(hyphen);
        
        for (int i =0; i < 8; i++)
        {
            int num_id = rand() % 10;
            stringstream ss;
            ss << num_id;
            string second8 = ss.str();
            ret_id.append(second8);
        }
        
        return ret_id;
    }
}

//function to check for duplicate ids
bool duplicate_checkfor_id(vector<Delivery*> objects, string id)
{
    for (int i = 0; i < objects.size(); i++)
    {
        if (id == (objects[i]->get_id()))
        {
            return true;
        }
    }
    return false;
}

//displays all deliveries
void display_all(vector<Delivery*> objects)
{
    cout << "All Deliveries" << endl;
    cout << "--------------------" << endl;
    
    if (objects.size() == 0)
    {
        cout << "\t Nothing Scheduled" << endl;
    }
    
    for (int i = 0; i < objects.size(); i++)
    {
        cout << "[" << i << "]";
        (objects[i]->print_info());
    }
}

//displays deliveries by type
void display_type(vector<Delivery*> objects)
{
    size_t option_navigator = 0;
    
    cout << "All Deliveries" << endl;
    cout << "------------------" << endl;
    cout << endl;
    
    if (objects.size() == 0)
    {
        cout << "\t Nothing Scheduled" << endl;
    }
    
    do
    {
        cout << "Which type (1) Griffin, (2) Owl, (3) Vanishing Cabinet? ";
        cin >> option_navigator;
        
        switch(option_navigator)
        {
            case 1: //for griffin
                for (int i = 0; i < objects.size(); i++)
                {
                    if (objects[i]->get_id()[0] == 'g')
                    {
                        cout << "[" << i << "]";
                        (objects[i]->print_info());
                    }
                }
                break;
                
            case 2: //for owl
                for (int i = 0; i < objects.size(); i++)
                {
                    if (objects[i]->get_id()[0] == 'o')
                    {
                        cout << "[" << i << "]";
                        (objects[i]->print_info());
                    }
                }
                break;
                
            case 3: //for Vanishing Cabinet
                for (int i = 0; i < objects.size(); i++)
                {
                    if (objects[i]->get_id()[0] != 'o' && objects[i]->get_id()[0] != 'g')
                    {
                        cout << "[" << i << "]";
                        (objects[i]->print_info());
                    }
                }
                break;
        }
    } while(!((option_navigator < 4) && (option_navigator > 0)));
}

//removes a delivery
void rem_delivery(vector<Delivery*>& objects)
{
    int option = 0;
    cout << "Remove a Delivery" << endl;
    cout << "------------------------" << endl;
    
    if (objects.size() == 0) //condition if there is no scheduled deliveires
    {
        cout << "\t ERROR : Nothing to remove" << endl;
    }
    
    else
    {
        display_all(objects);
        cout << endl;
        
        cout << "\t Which would you like to remove (enter the index) : ";
        cin >> option;
        
        if(option < 0 || option > objects.size() - 1)
        {
            cout << "\t Invalid Data. Please enter a valid index from 0 to " << objects.size() - 1 << endl;
        }
        delete objects[option];
        
    //assigning the data to its preceding index     
        for (int i = option; i < objects.size(); i++)
        {
            objects[i] = objects[i+1];
        }
    }
}

//loads deliveries from file
void load_deliveries(vector<Delivery*>& objects)
{
    cout << "LOADING DELIVERIES FROM FILE" << endl;
    cout << "--------------------------" << endl;
    ifstream delivery;
    
    string file;
    
    cout << "\t Enter the name of the file you want to load";
    cin.ignore();
    getline(cin, file);
    cout << endl;
    delivery.open(file.c_str());
    
    if(delivery.fail()) //checking to see if the file exists
    {
        cout << "\t The file does not exist" << endl;
        return;
    }
    
    string line;    //string to store the contents of the file by line
    string delimeter = ","; //assigning the delimeter
    size_t pos = 0; //initializing position of the delimeter
    string token;   //string that stores the parsed data
    string name;
    string id;
    double weight;
    string timestamp;
    
    while(true)
    {
        getline(delivery, line);
        if (delivery.eof()) //break if program reaches end of file
        {
            break;
        }
        while ((pos = line.find(delimeter)) != string::npos)
        {
            //for id
            token = line.substr(0, pos);
            id = token;
            pos = line.find(delimeter);
            line.erase(0,pos+delimeter.length());
            
            //for name
            pos = line.find(delimeter);
            token = line.substr(0, pos);
            name = token;
            pos = line.find(delimeter);
            line.erase(0,pos+delimeter.length());
            
            //for weight
            pos = line.find(delimeter);
            token = line.substr(0, pos);
            double wt;
            stringstream ss;
            ss << token;
            ss >> wt;
            weight = wt;
            pos = line.find(delimeter);
            line.erase(0,pos+delimeter.length());
            pos = line.find(delimeter);
            line.erase(0,pos+delimeter.length());
            
            //for timestamp
            pos = line.find(delimeter);
            token = line.substr(0, pos);
            timestamp = token;
            line.erase(0, pos+delimeter.length());
            
            if (id[0] == 'o')
            {
                Owl* obj= new Owl(name, timestamp, weight, id);
                objects.push_back(obj);
            }
            
            else if (id[0] == 'g')
            {
                Griffin* obj = new Griffin(name, timestamp, weight, id);
                objects.push_back(obj);
            }
            
            else
            {
                VanishingCabinet* obj = new VanishingCabinet(name, timestamp, weight, id);
                objects.push_back(obj);
            }
        }
    }
            
            delivery.close();
            cout << "\t DELIVERIES SUCCESSFULLY LOADED FROM FILE" << endl;
}

//saves deliveries to file
void save_deliveries(vector<Delivery*>objects)
{
    cout << "SAVING DELIVERIES TO FILE" << endl;
    cout << "----------------------------" << endl;
    ofstream delivery;
    string file;
    cout << "\t Enter the name of the file in which you want to save the data: ";
    cin.ignore();
    getline(cin, file);
    cout << endl;
    delivery.open(file.c_str());
    
    for (int i =0; i < objects.size(); i++)
    {
        if (objects[i]->get_id()[0] == 'g')
        {
            delivery << (objects[i]->get_id());
            delivery << "," << (objects[i]->get_sender_name());
            delivery << "," << (objects[i]->get_weight());
            delivery << "," << "Standard-Griffin";
            delivery << "," << (objects[i]->get_time_stamp()) << endl;
        }
        
        else if (objects[i]->get_id()[0] == 'o')
        {
            delivery << (objects[i]->get_id());
            delivery << "," << (objects[i]->get_sender_name());
            delivery << "," << (objects[i]->get_weight());
            delivery << "," << "Standard-Owl";
            delivery << "," << (objects[i]->get_time_stamp()) << endl;
        }
        
        else
        {
            delivery << (objects[i]->get_id());
            delivery << "," << (objects[i]->get_sender_name());
            delivery << "," << (objects[i]->get_weight());
            delivery << "," << "Vanishing Cabinet";
            delivery << "," << (objects[i]->get_time_stamp()) << endl;
        }
    }
    
    delivery.close();
    cout << "\t DELIVERIES SUCCESSFULLY SAVED IN FILE" << endl;
}

//timestamp
string timestamp()
{
 //registering a timstamp   
    time_t rawtime;
    tm * timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    string time_stamp = asctime(timeinfo);
    return time_stamp.substr(0, time_stamp.length() - 1);
}

//sorting deliveries in Owl:Grffin:Vanishing Cabinet order 
void sort_deliveries(vector<Delivery*> &objects)
{

    int j=0;
    int k;
    Delivery* temp;
    //FOR OWL ID STARTING WITH AN 'o'
    for(int i=0;i<objects.size();i++)
    {
        char id= (*objects[i]).get_id()[0];
        
        if(id=='o') //checking for 'o' in id which comes first
        {
            temp= objects[j];
            objects[j]=objects[i];
            objects[i]=temp;
            
            if(j>0) //condition for more than one owl ids
            {
                for(k=0;k<j;k++)
                {   //if more than one owl, comparing digits after 'o'
                    if((*objects[j]).get_id()<(*objects[k]).get_id())
                    {
                        temp= objects[j];
                        objects[j]=objects[k];
                        objects[k]=temp;
                    }
                    
                }
            }
            j++;
        }
    }

    //FOR GRFFIN ID STARTING WITH A 'g'
    int c=j;
    for(int i=0;i<objects.size();i++)
    {
        char id=(*objects[i]).get_id()[0];
     //checking for 'g' at the beginning of id to sort   
        if(id=='g')
        {
            temp=objects[j];
            objects[j]=objects[i];
            objects[i]=temp;
            //for more than one griffin id's comparing digits after 'g'
            if(j>c)
            {
                for(k=c;k<j;k++)
                {
                    if((*objects[j]).get_id()<(*objects[k]).get_id())
                    {
                        temp= objects[j];
                        objects[j]=objects[k];
                        objects[k]=temp;
                    }
                }
            }
            j++;
        }
    }
 
//FOR VANISHING CABINET ID    
    c=j;
    for(int i=0;i<objects.size();i++)
    {
        char id= (*objects[i]).get_id()[0];
       //if id doesn't begin with an 'o' or a 'g' execute this code
        if(id!='o'&& id!='g')
        {
            temp= objects[j];
            objects[j]=objects[i];
            objects[i]=temp;
         
        //if there are more than one Vanishing cabinet ids comparing digits   
            if(j>c)
            {
                for(k=c;k<j;k++)
                {
                    if((*objects[j]).get_id()<(*objects[k]).get_id())
                    {
                        temp=objects[j];
                        objects[j]=objects[k];
                        objects[k]=temp;
                    }
                }
            }
            j++;
        }
    }
}

//randomly shuffling scheduled deliveries
void shuffle_deliveries(vector<Delivery*>& objects)
{
//assigning random positions to the deliveries to shuffle
    for (int i = 0; i < objects.size(); i++)
    {
        int j = rand() % (objects.size()); //generating random numbers
        Delivery* temp = objects[i];
        objects[i] = objects[j];
        objects[j] = temp;
    }
}


