#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool islog_IN(){
    string username;
    string password;
    string username_compare;
    string password_compare;
    cout<< "Enter Username: "<<endl;
    cin>> username;
    cout<< "Enter Password: "<<endl;
    cin>> password;
    // I want to be able to read the file lines 17- 27
    ifstream read("data\\"+username+".txt");
    getline(read, username_compare);
    getline(read, password_compare);
    if(username_compare== username&& password_compare== password)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int choice;
    cout << "1= Register information"<<endl;
    cout << "2= Login"<<endl;
    cin>> choice;
    if(choice==1){
        string username;
        string password;
        cout << "Please Select a username"<<endl;
        cin >> username;
        cout << "Please Select a password"<<endl;
        cin >> password;
        ofstream file; //Useless comment here ignore... this line creates a "file " file and our goal would be to open said file
        file.open("data\\"+username+".txt"); // note .txt can be whatever you want
        file << username << endl<< password << endl;
        file.close();

        main(); // I want to register another user right away after I register
    }
    else if (choice ==2){
        bool status = islog_IN();
        if (!status){
            cout << "Incorrect Login" << endl;
            system("PUASE");
            return 0;
        }
        else{
            cout << "Successfull Login" << endl;
            system("PAUSE");
            return 1;
        }
    }
    return 0;
}