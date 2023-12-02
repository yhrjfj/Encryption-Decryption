#include <iostream>
#include <string>
#include <cmath>

std::string encryptText(const std::string& text, const std::string& key) {
    int numRows = std::ceil(static_cast<double>(text.length()) / key.length());
    int numCols = key.length();
    int numBlanks = numRows * numCols - text.length();

    std::string encryptedText;

    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            int index = row * numCols + col;
            if (row == numRows - 1 && col >= numCols - numBlanks) {
                encryptedText += ' ';
            } else {
                encryptedText += text[index];
            }
        }
    }

    return encryptedText;
}

int main() {
    std::string text;
    std::string key;

    std::cout << "Enter the text to encrypt: ";
    std::getline(std::cin, text);

    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    std::string encryptedText = encryptText(text, key);

    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    return 0;
}

