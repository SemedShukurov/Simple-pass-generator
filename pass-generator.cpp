#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::string generatePassword(int length) {
    const std::string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const std::string digits = "0123456789";
    const std::string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    const std::string allChars = upperCase + lowerCase + digits + specialChars;

    if (length < 8) {
        throw std::invalid_argument("Password length must be at least 8 characters for strong security.");
    }

    std::string password;
    password += upperCase[rand() % upperCase.size()];
    password += lowerCase[rand() % lowerCase.size()];
    password += digits[rand() % digits.size()];
    password += specialChars[rand() % specialChars.size()];

    for (int i = 4; i < length; ++i) {
        password += allChars[rand() % allChars.size()];
    }

    std::random_shuffle(password.begin(), password.end());
    return password;
}

int main() {
    std::srand(std::time(0));
    int length;

    std::cout << "Enter the desired password length (minimum 8): ";
    std::cin >> length;

    try {
        std::string password = generatePassword(length);
        std::cout << "Generated strong password: " << password << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    system("pause"); // Keeps the console window open after execution
    return 0;
}
