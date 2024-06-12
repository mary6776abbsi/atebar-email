#include <iostream>
#include <string>
using namespace std;

// Structure to hold the email address
struct Email {
    string address;
};

// Function to validate if the email address is in a proper format
bool isValidEmail(const Email& email) {
    // Find the position of '@' and '.'
    size_t atPos = email.address.find('@');
    size_t dotPos = email.address.find('.', atPos);

    // Check if '@' is present and not at the start or end
    if (atPos == string::npos || atPos == 0 || atPos == email.address.length() - 1) {
        return false;
    }

    // Check if '.' is present and appears after '@'
    if (dotPos == string::npos || dotPos <= atPos + 1 || dotPos == email.address.length() - 1) {
        return false;
    }

    // Check if there are no consecutive dots
    if (email.address.find("..") != string::npos) {
        return false;
    }

    // Check if the email doesn't start or end with a special character
    if (email.address.front() == '.' || email.address.back() == '.') {
        return false;
    }

    return true;
}

int main() {
    Email email;

    cout << "Enter your email address: ";
    cin >> email.address;

    if (isValidEmail(email)) {
        cout << "The email address " << email.address << " is valid." << endl;
    }
    else {
        cout << "The email address " << email.address << " is invalid." << endl;
    }

    return 0;
}
