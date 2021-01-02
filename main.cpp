#include <iostream>
#include <fstream>
#include <string>

bool isLoggedIn(){
    // Read and compare saved usernames and passwords
    std::string username, password, usernameComparison, passwordComparison;
    std::cout << "Enter username: "; std::cin >> username;
    std::cout << "Enter password: "; std::cin >> password;

    std::ifstream read(username + ".txt");
    getline(read, usernameComparison);
    getline(read, passwordComparison);
    
    if(usernameComparison == username && passwordComparison == password) {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    int choice; // Choose to register or login
    std::cout << "1: Register \n2: Login \nYour choice: "; std::cin >> choice;
    if(choice == 1){
        std::string username, password;
        std::cout << "Select a username: "; std::cin >> username;
        std::cout << "Select a password: "; std::cin >> password;
        
        // Creating file and saving username and password in file
        std::ofstream file;
        file.open(username + ".txt");
        file << username << std::endl << password;
        file.close();

        main();
    }
    else if(choice == 2){
        // Check if username and password by running isLoggedIn function
        bool status = isLoggedIn();

        if(!status){
            std::cout << "False Login!" << std::endl;
            return 0;
        }
        else{
            std::cout << "Succesfully logged in!" << std::endl;
            return 1;
        }
    }
}