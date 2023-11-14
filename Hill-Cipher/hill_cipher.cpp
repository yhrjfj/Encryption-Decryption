#include <iostream>
#include <vector>

using namespace std;

// Function to encrypt a message using Hill Cipher
string encrypt(const vector<vector<int>>& key, const string& message, int n) {
    int len = message.length();

    // Padding the message with 'X' if its length is not a multiple of n
    string paddedMessage = message;
    while (paddedMessage.length() % n != 0) {
        paddedMessage += 'X';
    }

    string encryptedMessage = "";
    for (int i = 0; i < paddedMessage.length(); i += n) {
        vector<int> block(n, 0);
        for (int j = 0; j < n; j++) {
            block[j] = paddedMessage[i + j] - 'A';
        }

        // Matrix multiplication
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += key[j][k] * block[k];
            }
            encryptedMessage += static_cast<char>((sum % 26) + 'A');
        }
    }

    return encryptedMessage;
}

// Function to decrypt a message using Hill Cipher
string decrypt(const vector<vector<int>>& key, const string& encryptedMessage, int n) {
    string decryptedMessage = "";
    for (int i = 0; i < encryptedMessage.length(); i += n) {
        vector<int> block(n, 0);
        for (int j = 0; j < n; j++) {
            block[j] = encryptedMessage[i + j] - 'A';
        }

        // Matrix multiplication
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += key[j][k] * block[k];
            }
            decryptedMessage += static_cast<char>((sum % 26) + 'A');
        }
    }

    // Remove any padding 'X' characters
    while (decryptedMessage.back() == 'X') {
        decryptedMessage.pop_back();
    }

    return decryptedMessage;
}

#include <cstdlib>
#include <ctime>

/**
 * The main function of the Hill Cipher program.
 * It prompts the user to input a message to be encrypted or decrypted, generates a random key matrix,
 * prompts the user to choose between encryption and decryption, and displays the result.
 *
 * @return 0 if the program runs successfully.
 */
int main() {
    // Input the message to be encrypted or decrypted
    string message;
    cout << "Enter the message (in uppercase): ";
    cin >> message;

    // Determine the size of the key matrix based on the length of the message
    int n = 2;
    while (n * n < message.length()) {
        n++;
    }

    // Generate a random key matrix of the determined size
    vector<vector<int>> key(n, vector<int>(n, 0));
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            key[i][j] = rand() % 26;
        }
    }

    // Prompt the user to choose between encryption and decryption
    int choice;
    cout << "Enter 1 to encrypt the message, or 2 to decrypt the message: ";
    cin >> choice;

    // Encrypt or decrypt the message using Hill Cipher
    string result;
    if (choice == 1) {
        result = encrypt(key, message, n);
    } else if (choice == 2) {
        result = decrypt(key, message, n);
    } else {
        cout << "Invalid choice." << endl;
        return 0;
    }

    // Display the result
    if (choice == 1) {
        cout << "Encrypted Message: " << result << endl;
    } else {
        cout << "Decrypted Message: " << result << endl;
    }

    return 0;
}