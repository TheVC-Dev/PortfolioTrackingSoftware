#include "Client.h"

using namespace std;

int main(){
    ClientManager Manager("clients.txt");
    

    int choice;
    bool running = true;

    while(running){
        displayMenu();
        cin >> choice;

        if (choice = 1){
            //TODO: create Menu interface
        } else if(choice = 2){
            //TODO: create Menu interface
        }
        else{
            cout << "invalid choice." << endl;
        }
    }
    
    //save Client positions before exiting 

    return 0;
}
