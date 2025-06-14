
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <iomanip>


struct LogIn {
    std::string email;
    std::string password;
};

void ExportData(std::string& email, std::string& password) {
    
    std::string line{}; 
    std::ofstream out_File{};
    out_File.open("C:\\Users\\lenar\\Documents\\LogInData.csv", std::ios::app | std::ios::out | std::ios::in);

    // Use a while loop together with the getline() function to read the file line by line
    if (out_File.is_open()) {
        // Output the text from the file
        out_File << "\n" << email << "," << password << std::endl;
    }

    // Close the file
    out_File.close();
}

bool isValidEmail(std::string& email) {
/*
This function checks to see if emails that are input into the system are actually valid. With a list of valid email address that is already predetermined.
If the user enters a @gmail.com email address that would be considered valid if anything that is not a known email then that will be considerd false.
*/
    std::vector<std::string> Valid_Emails{ "@gmail.com", "@hotmail.com", "@outlook.com", "@yahoo.com" };

    bool isValid = false;
    std::string email_check_string {};
    int at_Symbol_Count{0};

    //loop through the email string that has been entered
    for (int i = 0; i < email.length(); i++) {
        
        if (email[i] == '@') {
            //This will check the email string from the start of the '@' character and onward
            size_t position = email.find('@');
            email_check_string = email.substr(position, email.length());

            at_Symbol_Count++;

            //loop thorught the list of valid email addresses and check to see if the email provided matches one of the emails within the list
            for (int k = 0; k < Valid_Emails.size(); k++) {

                if (email_check_string == Valid_Emails[k] && at_Symbol_Count == 1) {
                    std::cout << "Is Valid: " + email_check_string << std::endl;
                    isValid = true;
                }
                else if (email_check_string != Valid_Emails[k] || at_Symbol_Count != 1) {
                    std::cout << "Is not Valid: " + email_check_string << std::endl;
                    isValid = false;
                }
                break;
            }
        }
    }

    return isValid;
}

bool isInSystem(std::string& email, std::string& password) {
    
    bool isInFile = false;
    std::ifstream in_File{};
    std::string line{};
    in_File.open("C:\\Users\\lenar\\Documents\\LogInData.csv", std::ios::app | std::ios::out | std::ios::in);

    if (in_File.is_open()) {
        int rows{0};

        while (getline(in_File, line)) {
            rows++;

            while (rows > 1) {
                int position = line.find(',');

                std::string emailstringcheck = line.substr(0, position);
                std::string passwordstringcheck = line.substr(position, line.length());

                if (email == emailstringcheck) {
                    if (password == passwordstringcheck) isInFile = true;
                    std::cout << "Log In: Success" << std::endl;
                    break;
                }

                if (email != emailstringcheck) {
                    isInFile = false;
                    std::cout << "Log In: Failed" << std::endl;
                    break;
                }
                break;
            }
        }
    }

    std::cin.ignore();
    in_File.close();

    return isInFile;
}

void CreateAccountSetUp_Func() {

    system("CLS");

    std::cout << "Create Account Setup" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Please enter a valid email below:" << std::endl;

    std::string email_input{};
    std::string password_input{};
    std::string confirmed_password_input{};

    std::cin >> email_input;
    isValidEmail(email_input);
    

    std::cout << "\nCreate Account Setup" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Please enter a valid password below:" << std::endl;
    std::cin >> password_input;

    std::cout << "Create Account Setup" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Confirm password:" << std::endl;
    std::cin >> confirmed_password_input;

    while (confirmed_password_input != password_input) {
        std::cout << "\n--------------------------" << std::endl;
        std::cout << "Please re-enter the password previously entered:" << std::endl;
        std::cin >> confirmed_password_input;
    }

    if (confirmed_password_input == password_input) {
        system("CLS");
        std::cout << "Create Account Setup" << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "Account Successfully Created" << std::endl;
        std::cout << "Email: " << email_input << std::endl;
        std::cout << "Password: " << confirmed_password_input << std::endl;

        ExportData(email_input,password_input);
    }

    std::cin.get();
}

void LogIn_Func() {
    system("CLS");

    std::string email_input{};
    std::string password_input{};

    std::cout << "Account Logg In" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Enter Email:" << std::endl;

    std::cin >> email_input;

    std::cout << "--------------------------" << std::endl;
    std::cout << "Enter Password:" << std::endl;

    std::cin >> password_input;

    isInSystem(email_input, password_input);
}

int main()
{
    std::cout << "Login Console App" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "1 = Create an Account" << std::endl;
    std::cout << "2 = Login" << std::endl;

    int num{};

    while (!(std::cin >> num)) {
        std::cout << "[SYSTEM_ERROR::INVLAID ENTRY]" << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        std::cout << "Please Enter a number into the system: ";
        std::cin >> num;
    }

    switch (num)
    {
    case 1:
        CreateAccountSetUp_Func();
        break;
    case 2:
        LogIn_Func();
        break;
    default:
        break;
    }

}
