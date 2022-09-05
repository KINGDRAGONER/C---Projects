#include <iostream>
using namespace std;
struct Person {
string name;
string address;
string phone_number;

void details(string name, string address, string phone_number){
    

    cout << "Name: " << name <<"\n" <<"Address: "<<address<<"\nphone number: " << phone_number <<endl;
}
};
ostream& operator<<(ostream& os, const Person& person) {
    return os <<endl;
}
int main(){
string name_input = "";
string address_input = "";
string phone_number_input = "";
Person Human;

getline(cin, name_input);
getline(cin, address_input);
getline(cin, phone_number_input);

Human.details(name_input, address_input, phone_number_input);

cout<<Human<<endl;
    return 0;
}
