#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Client.h"
#include "Portfolio.h"
#include "Stock.h"

using namespace std;

//client helper
Client* findClient(vector<Client>& clients, int id){
    for (size_t i = 0; i < clients.size(); ++i){
        if (clients[i].getId() == id) {
            return &clients[i];
        }
    }
    return nullptr;
}

int main(){
    vector<Client> clients;

    int choice;
    bool running = true;

    while(running){
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Manage Clients" << endl;
        cout << "2. Manage Portfolios" << endl;
        cout << "0. Exit"; << endl;
        cout << "Enter Choice";

        if(!(cin >> choice)){
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }

        if (choice == 1){
            int clientSubChoice;

            cout << "\n--- Client Management --- "<< endl;
            cout << "1. Add Client" << endl;
            cout << "2. Delete Client" << endl;
            cout << "3.Veiw All Clients" << endl;
            cout << "Enter Choice: " << endl;
            cin >> clientSubChoice;

            if(clientSubChoice == 1){
                string name;
                int id;
                cout << "Enter Client Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter unique Client ID: ";
                cin >> id;
                clients.push_back(Client(name,id));
                cout << "Client Added!\n";

            }else if(clientSubChoice == 2){
                int id;
                cout << "Enter Client ID to delete: ";
                cin >> id;

                for (auto it = clients.begin(); it != clients.end(); ++it){
                    if (it -> getId() == id){
                        cout << "Client: " << it->getName() << " removed" << endl; 
                        clients.erase(it);
                    }
                }
            }else if(clientSubChoice == 3){
                if(clients.empty()) {
                    cout << "No clients to display." << endl;
                } else {
                    for (const auto& client : clients){
                        cout << "Clients: " << endl;
                        for (const auto& client : clients) {
                            cout << "ID: " << client.getId() << " Name: " << client.getName() << endl;
                        }
                    }
                }
            }















        } else if(choice == 2){
            //TODO: create Menu interface
        }
        else{
            cout << "invalid choice." << endl;
        }
    }
    
    //save Client positions before exiting 

    return 0;
}
