#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

// Function to encrypt using the Polybius cipher
void polybius_encryptor() {
    string no1, no2, no3, no4, no5, message, encrypted;

    // Get user input for the message
    cout << "Enter your message (letters only): " << endl;
    getline(cin, message);

    bool check = false;

    // Validate the input message (letters and spaces only)
    while (true) {
        for (int i = 0; i < message.size(); i++) {
            if (!isalpha(message[i]) && !isspace(message[i])) {
                check = false;
                break;
            } else {
                check = true;
            }
        }

        if (check) {
            break;
        } else {
            cout << "Enter a valid message" << endl;
            cin.clear();
            getline(cin, message);
        }
    }

    // Convert the message to lowercase
    transform(message.begin(), message.end(), message.begin(), ::tolower);

    // Get user input for the encryption sequence
    while(true){
        cout << "Enter 5 digit encryption sequence" << endl;
        cin >> no1 >> no2 >> no3 >> no4 >> no5;
        try{
            int test;
            test=stoi(no1);
            test=stoi(no2);
            test=stoi(no3);
            test=stoi(no4);
            test=stoi(no5);
            break;
        }
        catch(...){
        cout<<"Invalid input"<<endl;}
    }
    // Define the Polybius cipher map
    unordered_map<char, string> ENCRYPT = {
        {'a', no1 + no1}, {'b', no1 + no2}, {'c', no1 + no3}, {'d', no1 + no4}, {'e', no1 + no5},
        {'f', no2 + no1}, {'g', no2 + no2}, {'h', no2 + no3}, {'i', no2 + no4}, {'j', no2 + no4}, {'k', no2 + no5},
        {'l', no3 + no1}, {'m', no3 + no2}, {'n', no3 + no3}, {'o', no3 + no4}, {'p', no3 + no5},
        {'q', no4 + no1}, {'r', no4 + no2}, {'s', no4 + no3}, {'t', no4 + no4}, {'u', no4 + no5},
        {'v', no5 + no1}, {'w', no5 + no2}, {'x', no5 + no3}, {'y', no5 + no4}, {'z', no5 + no5}
    };

    // Encrypt the message using the Polybius cipher
    for (int i = 0; i < message.size(); i++) {
        char temp = message[i];
        if (temp == ' ') {
            encrypted = encrypted + " ";
        } else {
            encrypted = encrypted + ENCRYPT[temp];
        }
    }

    // Display the encrypted message
    cout << encrypted << endl;
}

// Function to decrypt using the Polybius cipher
void polybius_decryptor() {
    string no1, no2, no3, no4, no5, message, decrypted;
    bool check = false;

    // Get user input for the encrypted message
    cout << "Enter encrypted message (numbers only): " << endl;
    getline(cin, message);
    // Validate the input message (digits and spaces only)
    while (true) {
        for (int i = 0; i < message.size(); i++) {
            if (!isdigit(message[i]) && !isspace(message[i])) {
                check = false;
                break;
            } else {
                check = true;
            }
        }

        if (check) {
            break;
        } else {
            cout << "Enter a valid message" << endl;
            cin.clear();
            getline(cin, message);
        }
    }

    // Get user input for the decryption sequence

    while(true){
        cout << "Enter 5 digit encryption sequence" << endl;
        cin >> no1 >> no2 >> no3 >> no4 >> no5;
        try{
            int test;
            test=stoi(no1);
            test=stoi(no2);
            test=stoi(no3);
            test=stoi(no4);
            test=stoi(no5);
            break;
        }
        catch(...){
        cout<<"Invalid input"<<endl;}
    }

    // Define the Polybius decryption map
    unordered_map<string, char> DECRYPT = {
        {no1 + no1, 'a'}, {no1 + no2, 'b'}, {no1 + no3, 'c'}, {no1 + no4, 'd'}, {no1 + no5, 'e'},
        {no2 + no1, 'f'}, {no2 + no2, 'g'}, {no2 + no3, 'h'}, {no2 + no4, 'i'}, {no2 + no5, 'k'},
        {no3 + no1, 'l'}, {no3 + no2, 'm'}, {no3 + no3, 'n'}, {no3 + no4, 'o'}, {no3 + no5, 'p'},
        {no4 + no1, 'q'}, {no4 + no2, 'r'}, {no4 + no3, 's'}, {no4 + no4, 't'}, {no4 + no5, 'u'},
        {no5 + no1, 'v'}, {no5 + no2, 'w'}, {no5 + no3, 'x'}, {no5 + no4, 'y'}, {no5 + no5, 'z'}
    };

    int i = 0;
    while (i < message.size()) {
        char temp1 = message[i];
        char temp2 = message[i + 1];
        auto temp3 = string(1, temp1) + temp2;

        if (temp1 == ' ') {
            decrypted = decrypted + " ";
            i++;
            continue;
        } else {
            decrypted = decrypted + DECRYPT[temp3];
            i += 2;
        }
    }

    // Display the decrypted message
    cout << decrypted << endl;
}

// Function to encrypt using the Route cipher
void route_encryptor() {
    string message, key;

    // Get user input for the message
    cout << "Enter message you wish to encrypt: " << endl;
    getline(cin, message);

    // Convert the message to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    // Get user input for the key (1 digit)
    cout << "Enter 1 digit key: " << endl;
    cin >> key;

    // Validate the input key (1 digit)
    while (cin.fail() || key.size() > 2 || !isdigit(key[0])) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter a valid input: " << endl;
        cin >> key;
    }

    // Convert the key to an integer
    int temp = stoi(key);
    const int columns = temp;
    int counter = 0;

    // Count the number of alphabetic characters in the message
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i])) {
            counter++;
        }
    }

    // Calculate the number of rows based on the key and counter
    if (counter % columns == 0) {
        temp = counter / columns;
    } else {
        temp = counter / columns + 1;
    }

    const int rows = temp;

    // Define the 2D array for the Route cipher
    char route[rows][columns];

    int k = 0;

    // Fill the 2D array with characters from the message
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            while (message[k] == ' ') {
                k++;
            }
            if (k < message.size()) {
                route[i][j] = message[k];
                k++;
            } else {
                route[i][j] = '*';
            }
        }
    }

    // Initialize variables for traversing the 2D array
    int row_start, row_end, col_start, col_end;
    row_start = 0;
    row_end = rows - 1;
    col_start = 0;
    col_end = columns - 1;

    // Traverse the 2D array in a spiral manner and print the characters
    while ((row_start < row_end) || (col_start < col_end)) {
        for (int i = 0; i <= row_end; i++) {
            if (route[i][col_end] != ' ') {
                cout << route[i][col_end];
                route[i][col_end] = ' ';
            }
        }

        for (int i = col_end; i >= 0; i--) {
            if (route[row_end][i] != ' ') {
                cout << route[row_end][i];
                route[row_end][i] = ' ';
            }
        }

        for (int i = row_end; i >= 0; i--) {
            if (route[i][col_start] != ' ') {
                cout << route[i][col_start];
                route[i][col_start] = ' ';
            }
        }

        for (int i = 0; i <= col_end; i++) {
            if (route[row_start][i] != ' ') {
                cout << route[row_start][i];
                route[row_start][i] = ' ';
            }
        }

        row_start++;
        row_end--;
        col_start++;
        col_end--;
    }

    cout << endl;
}

// Function to decrypt using the Route cipher
void route_decryptor() {
    string message, key;

    // Get user input for the message
    cout << "Enter message you wish to decrypt: " << endl;
    getline(cin, message);

    // Convert the message to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    // Get user input for the key (1 digit)
    cout << "Enter 1 digit key: " << endl;
    cin >> key;

    // Validate the input key (1 digit)
    while (cin.fail() || key.size() > 2 || !isdigit(key[0])) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter a valid input: " << endl;
        cin >> key;
    }

    // Convert the key to an integer
    int temp = stoi(key);
    const int columns = temp;
    int counter = 0;

    // Count the number of alphabetic characters in the message
    for (int i = 0; i <= message.size(); i++) {
        if (isalpha(message[i])) {
            counter++;
        }
    }

    // Calculate the number of rows based on the key and counter
    if (counter % columns == 0) {
        temp = counter / columns;
    } else {
        temp = counter / columns + 1;
    }

    const int rows = temp;

    // Define the 2D array for the Route cipher
    char route[rows][columns];

    // Initialize the 2D array with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            route[i][j] = ' ';
        }
    }

    // Initialize variables for traversing the 2D array
    int row_start, row_end, col_start, col_end;
    row_start = 0;
    row_end = rows - 1;
    col_start = 0;
    col_end = columns - 1;
    int k = 0;

    // Traverse the 2D array in a spiral manner and fill it with characters from the message
    while (k < message.size() - 1) {
        for (int i = 0; i <= row_end; i++) {
            if (k == message.size())
                break;
            while (message[k] == ' ') {
                k++;
            }
            if (route[i][col_end] == ' ') {
                route[i][col_end] = message[k];
                k++;
            }
        }

        for (int i = col_end; i >= 0; i--) {
            if (k == message.size())
                break;
            while (message[k] == ' ') {
                k++;
            }
            if (route[row_end][i] == ' ') {
                route[row_end][i] = message[k];
                k++;
            }
        }

        for (int i = row_end; i >= 0; i--) {
            if (k == message.size())
                break;
            while (message[k] == ' ') {
                k++;
            }
            if (route[i][col_start] == ' ') {
                route[i][col_start] = message[k];
                k++;
            }
        }

        for (int i = 0; i <= col_end; i++) {
            if (k == message.size())
                break;
            while (message[k] == ' ') {
                k++;
            }
            if (route[row_start][i] == ' ') {
                route[row_start][i] = message[k];
                k++;
            }
        }

        row_start++;
        row_end--;
        col_start++;
        col_end--;
    }

    // Display the decrypted message
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << route[i][j];
        }
    }

    cout << endl;
}

// Function to generate the cipher alphabet for the Simple Substitution cipher
auto generate_cipher_alphabet(string key) {
    // Convert key to lowercase
    string key_message = key;
    string cipher_alphabet = key_message;
    string remaining_letters = "abcdefghijklmnopqrstuvwxyz";

    // Remove letters in the key from the remaining letters
    for (auto letter : key_message) {
        size_t pos = remaining_letters.find(letter);
        if (pos != string::npos) {
            remaining_letters.erase(pos, 1);
        }
    }

    // Add the remaining letters after the key letters in order
    cipher_alphabet += remaining_letters;
    return cipher_alphabet;
}

// Function to encrypt using the Simple Substitution cipher
string smpl_sub_encrypt(string message, string key) {
    // Generate the cipher alphabet using the key
    string cipher_alphabet = generate_cipher_alphabet(key);
    string encrypted_message = "";

    // Encrypt each character of the message
    for (auto letter : message) {
        if (isalpha(letter)) {
            if (islower(letter)) {
                encrypted_message += tolower(cipher_alphabet[letter - 'a']);
            } else {
                encrypted_message += toupper(cipher_alphabet[letter - 'A']);
            }
        } else {
            encrypted_message += letter;
        }
    }
    return encrypted_message;
}

// Function to decrypt using the Simple Substitution cipher
auto smpl_sub_decrypt(string encrypted_message, string key) {
    // Generate the cipher alphabet using the key
    string cipher_alphabet = generate_cipher_alphabet(key);
    string decrypted_message = "";

    // Decrypt each character of the message
    for (auto letter : encrypted_message) {
        if (isalpha(letter)) {
            if (islower(letter)) {
                decrypted_message += tolower('a' + cipher_alphabet.find(tolower(letter)));
            } else {
                decrypted_message += toupper('A' + cipher_alphabet.find(toupper(letter)));
            }
        } else {
            decrypted_message += letter;
        }
    }
    return decrypted_message;
}


void baconian_encryptor(){
    string message, encrypted;

    // Prompting the user to enter a message
    cout << "Enter your message (letters only): " << endl;
    getline(cin, message);

    bool check = false;

    // Validating the input message
    while (true) {
        for (int i = 0; i < message.size(); i++) {
            // Checking if each character is either a letter or a space
            if (!isalpha(message[i]) && !isspace(message[i])) {
                check = false;
                break;
            } else {
                check = true;
            }
        }
        // If the message is valid, exit the loop
        if (check) {
            break;
        } else {
            // If the message is not valid, prompt the user to enter a valid message
            cout << "Enter a valid message" << endl;
            cin.clear();
            getline(cin, message);
        }
    }

    // Converting the message to lowercase
    transform(message.begin(), message.end(), message.begin(), ::tolower);

    // Mapping each letter to its corresponding encrypted string
    unordered_map<char, string> ENCRYPT = {
        {'a', "aaaaa"}, {'b', "aaaab"}, {'c', "aaaba"}, {'d', "aaabb"}, {'e', "aabaa"},
        {'f', "aabab"}, {'g', "aabba"}, {'h', "aabbb"}, {'i', "abaaa"}, {'j', "abaab"},
        {'k', "ababa"}, {'l', "ababb"}, {'m', "abbaa"}, {'n', "abbab"}, {'o', "abbba"},
        {'p', "abbbb"}, {'q', "baaaa"}, {'r', "baaab"}, {'s', "baaba"}, {'t', "baabb"},
        {'u', "babaa"}, {'v', "babab"}, {'w', "babba"}, {'x', "babbb"}, {'y', "bbaaa"},
        {'z', "bbaab"}
    };

    // Encrypting the message
    for (int i = 0; i < message.size(); i++) {
        char temp = message[i];
        if (temp != ' ') {
            encrypted = encrypted + ENCRYPT[temp] + "  "; // Adding two spaces after each encrypted letter
        }
    }

    // Outputting the encrypted message
    cout << "Encrypted message: " << encrypted << endl;
}


void baconian_decryptor(){
     // Variables declaration
    string message, refurbrished_message = "", decrypted, temp;
    bool check = false;

    // Prompt user to enter encrypted Baconian message
    cout << "Enter encrypted Baconian message: " << endl;
    getline(cin, message);

    // Validate the input message
    while (true) {
        for (int i = 0; i < message.size(); i++) {
            // Check if each character is alphanumeric or space
            if (!isalnum(message[i]) && !isspace(message[i])) {
                check = false;
                break;
            } else {
                check = true;
            }
        }
        // If input message is valid, exit the loop
        if (check) {
            break;
        } else {
            // If input message is invalid, prompt the user again
            cout << "Enter a valid message" << endl;
            cin.clear();
            getline(cin, message);
        }
    }

    // Reformat the message to only include 'a' and 'b' characters
    for (int i = 0; i < message.size(); i++) {
        if (message[i] == '0') {
            refurbrished_message += "a";
        } else if (message[i] == '1') {
            refurbrished_message += "b";
        } else {
            refurbrished_message += message[i];
        }
    }

    // Convert the message to lowercase
    transform(message.begin(), message.end(), message.begin(), ::tolower);

    // Mapping for decrypting Baconian cipher
    unordered_map<string, char> DECRYPT = {
        {"aaaaa", 'a'}, {"aaaab", 'b'}, {"aaaba", 'c'}, {"aaabb", 'd'}, {"aabaa", 'e'},
        {"aabab", 'f'}, {"aabba", 'g'}, {"aabbb", 'h'}, {"abaaa", 'i'}, {"abaab", 'j'},
        {"ababa", 'k'}, {"ababb", 'l'}, {"abbaa", 'm'}, {"abbab", 'n'}, {"abbba", 'o'},
        {"abbbb", 'p'}, {"baaaa", 'q'}, {"baaab", 'r'}, {"baaba", 's'}, {"baabb", 't'},
        {"babaa", 'u'}, {"babab", 'v'}, {"babba", 'w'}, {"babbb", 'x'}, {"bbaaa", 'y'},
        {"bbaab", 'z'}
    };

    // Decrypt the message
    for (int i = 0; i < refurbrished_message.size(); i++) {
        if (isspace(refurbrished_message[i])) {
            // If it's a space, find corresponding character and add it to decrypted
            decrypted += DECRYPT[temp];
            // Reset temporary variable
            temp = "";
        } else if (i == refurbrished_message.size() - 1) {
            // If it's the last character, add it to the temporary variable and find the corresponding character
            temp += refurbrished_message[i];
            decrypted += DECRYPT[temp];
        } else {
            // If it's not a space or the last character, add it to the temporary variable
            temp += refurbrished_message[i];
        }
    }

    // Convert the decrypted message to uppercase
    transform(decrypted.begin(), decrypted.end(), decrypted.begin(), ::toupper);

    // Print the decrypted message
    cout << decrypted << endl;
}


void morse_encryptor(){
    // Variables declaration
    string message, encrypted;
    // Prompt the user to enter a message containing letters only
    cout << "Enter your message (letters only): " << endl;
    getline(cin, message);

    bool check = false;
    // Validate the input message
    while (true) {
        for (int i = 0; i < message.size(); i++) {
            // Check if each character is either an alphabet letter or space
            if (!isalpha(message[i]) && !isspace(message[i])) {
                check = false;
                break;
            } else {
                check = true;
            }
        }
        // If the message is valid, exit the loop
        if (check) {
            break;
        } else {
            // If the message is invalid, prompt the user to enter a valid message
            cout << "Enter a valid message" << endl;
            cin.clear();
            getline(cin, message);
        }
    }

    // Convert the message to lowercase
    transform(message.begin(), message.end(), message.begin(), ::tolower);

    // Mapping for encrypting the message using Morse code
    unordered_map<char, string> ENCRYPT = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
        {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"},
        {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
        {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"},
        {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}
    };

    // Encrypt the message using Morse code
    for (int i = 0; i < message.size(); i++) {
        char temp = message[i];
        if (temp != ' ') {
            // Add the Morse code representation of each letter to the encrypted message
            encrypted = encrypted + ENCRYPT[temp] + "  ";
        }
    }

    // Print the encrypted message
    cout << encrypted << endl;
}


void morse_decryptor(){
     // Variables declaration
    string message, decrypted, temp;
    bool check = false;

    // Prompt user to enter encrypted message
    cout << "Enter encrypted message: " << endl;
    getline(cin, message);

    // Validate the input message
    while (true) {
        for (int i = 0; i < message.size(); i++) {
            // Check if each character is either '.' (dot), '-' (dash), or space
            if (message[i] != '.' && message[i] != '-' && !isspace(message[i])) {
                check = false;
                break;
            } else {
                check = true;
            }
        }
        // If the message is valid, exit the loop
        if (check) {
            break;
        } else {
            // If the message is invalid, prompt the user to enter a valid message
            cout << "Enter a valid message" << endl;
            cin.clear();
            getline(cin, message);
        }
    }

    // Mapping for decrypting the message from Morse code
    unordered_map<string, char> DECRYPT = {
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'},
        {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'},
        {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'},
        {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
        {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'},
        {"--..", 'z'}
    };

    // Decrypt the message
    for (int i = 0; i < message.size(); i++) {
        if (isspace(message[i])) {
            // If it's a space, find corresponding character and add it to decrypted
            decrypted += DECRYPT[temp];
            // Reset temporary variable
            temp = "";
        } else if (i == message.size() - 1) {
            // If it's the last character, add it to the temporary variable and find the corresponding character
            temp += message[i];
            decrypted += DECRYPT[temp];
        } else {
            // If it's not a space or the last character, add it to the temporary variable
            temp += message[i];
        }
    }

    // Print the decrypted message
    cout << decrypted << endl;
}


// Function for Vigenere encryption
void vignere_encryptor() {
    // Variables declaration
    string message, keyword, encrypt;

    // Prompt user to enter message and keyword
    cout << "Please enter your message: ";
    getline(cin, message);
    // Convert message to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);
    cin.clear(); // Clear cin buffer
    cout << "Please enter The Keyword: ";
    getline(cin, keyword);
    // Convert keyword to uppercase
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);

    // Encryption process
    for (int i = 0; i <= message.length(); i++) {
        int j = i % keyword.length(); // Calculate index for keyword
        if (isalpha(message[i])) { // Check if character is alphabetic
            // Encryption formula
            int newchar = (message[i] + keyword[j]) % 26 + 65;
            encrypt.push_back(char(newchar)); // Append encrypted character to result
        } else {
            encrypt.push_back(message[i]); // Append non-alphabetic characters as they are
        }
    }

    // Print the encrypted message
    cout << encrypt <<endl;
}

// Function for Vigenere decryption
void vignere_decryptor() {
    // Variables declaration
    string message, key, decrypted_message;
    int used, decrypted_ascii;

    // Prompt user to enter message and key
    cout << "Enter message you would like to decrypt (MAX 80 characters): " << endl;
    getline(cin, message);
    // Validate message length
    while (message.size() > 81) {
        cout << "Please enter a message which is maximum 80 characters: " << endl;
        cin.clear();
        getline(cin, message);
    }
    cin.clear(); // Clear cin buffer
    cout << "Enter key (MAX 8 characters): " << endl;
    getline(cin, key);
    // Validate key length
    while (key.size() > 9) {
        cout << "Please enter a key which is maximum 8 characters: " << endl;
        cin.clear();
        getline(cin, key);
    }

    // Convert message and key to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Decryption process
    for (int i = 0; i < message.size(); i++) {
        used = i % key.size(); // Calculate index for key
        int temp;
        if (isalpha(message[i])) { // Check if character is alphabetic
            temp = message[i] - 65;
            // Decryption formula
            if ((temp + 130 - key[used]) > 64) {
                temp += 130;
            } else {
                temp += 156;
            }
            decrypted_ascii = temp - key[used]; // Calculate ASCII value of decrypted character
            decrypted_message += char(decrypted_ascii); // Append decrypted character to result
        } else {
            decrypted_message += message[i]; // Append non-alphabetic characters as they are
        }
    }

    // Print the decrypted message
    cout << decrypted_message;
}

// Function for Rail Fence encryption
void railfence_encryptor() {
    // Variables declaration
    string e1, e2, e3, message, refurbrished_message;

    // Prompt user to enter message
    cout << "Message: " << endl;
    getline(cin, message);

    // Remove spaces from the message
    for(int i = 0; i < message.size(); i++) {
        if (!isspace(message[i])) {
            refurbrished_message += message[i];
        }
    }
    // Convert the message to uppercase
    transform(refurbrished_message.begin(), refurbrished_message.end(), refurbrished_message.begin(), ::toupper);

    // Encryption process
    for(int i = 0; i < refurbrished_message.size(); i++) {
        if(i % 4 == 0) {
            // First rail
            e1 += refurbrished_message[i];
            // Fill the other rails with dots to maintain the rail fence pattern
            e2 += '.';
            e3 += '.';
        } else if((i - 1) % 2 == 0) {
            // Second rail
            e1 += '.';
            e2 += refurbrished_message[i];
            e3 += '.';
        } else {
            // Third rail
            e1 += '.';
            e2 += '.';
            e3 += refurbrished_message[i];
        }
    }
    // Print the encrypted message
    for(int i = 0; i < e1.size(); i++) {
        // Output non-dot characters from the first rail
        if(e1[i] != '.') {
            cout << e1[i];
        }
    }
    for(int i = 0; i < e2.size(); i++) {
        // Output non-dot characters from the second rail
        if(e2[i] != '.') {
            cout << e2[i];
        }
    }
    for(int i = 0; i < e3.size(); i++) {
        // Output non-dot characters from the third rail
        if(e3[i] != '.') {
            cout << e3[i];
        }
    }
}


// Function for Rail Fence decryption
void railfence_decryptor() {
    // Variables declaration
    string message, d1, d2, d3;
    int n, start = 0, j = 0;

    // Prompt user to enter message
    cout << "Message: ";
    getline(cin, message);

    // Decryption process
    if (message.size() <= 3) {
        // If the message has 3 or fewer characters, distribute them directly to the rails
        d1 += message[0];
        d2 += message[1];
        d3 += message[2];
    } else if (message.size() % 3 == 0) {
        // If the message size is divisible by 3
        n = (message.size() - 2) / 4;
        // Assign characters to the rails according to the rail fence pattern
        for (int i = 0; i < n + 1; i++) {
            d1 += message[start];
            start++;
        }
        for (int i = 0; i < (2 * n + 1); i++) {
            d2 += message[start];
            start++;
        }
        for (int i = 0; i < n; i++) {
            d3 += message[start];
            start++;
        }
    } else if (message.size() % 3 == 2) {
        // If the message size leaves a remainder of 2 when divided by 3
        n = (message.size() - 1) / 4;
        // Assign characters to the rails according to the rail fence pattern
        for (int i = 0; i < n + 1; i++) {
            d1 += message[start];
            start++;
        }
        for (int i = 0; i < 2 * n; i++) {
            d2 += message[start];
            start++;
        }
        for (int i = 0; i < n; i++) {
            d3 += message[start];
            start++;
        }
    } else {
        // If the message size does not fit any of the above cases
        if ((message.size() + 1) % 4 == 0) {
            n = (message.size() + 1) / 4;
            // Assign characters to the rails according to the rail fence pattern
            for (int i = 0; i < n; i++) {
                d1 += message[start];
                start++;
            }
            for (int i = 0; i < (2 * n - 1); i++) {
                d2 += message[start];
                start++;
            }
            for (int i = 0; i < n; i++) {
                d3 += message[start];
                start++;
            }
        } else {
            n = message.size() / 4;
            // Assign characters to the rails according to the rail fence pattern
            for (int i = 0; i < n; i++) {
                d1 += message[start];
                start++;
            }
            for (int i = 0; i < 2 * n; i++) {
                d2 += message[start];
                start++;
            }
            for (int i = 0; i < n; i++) {
                d3 += message[start];
                start++;
            }
        }
    }

    // Output the decrypted message by reading characters from each rail in order
    for (int i = 0; i < d2.size(); i++) {
        if (i < d1.size()) cout << d1[i]; // Output characters from the first rail
        if (j < d2.size()) cout << d2[j++]; // Output characters from the second rail
        if (i < d3.size()) cout << d3[i]; // Output characters from the third rail
        if (j < d2.size()) cout << d2[j++]; // Output characters from the second rail again
    }
}

// Function for Atbash encryption
void atbash_encryptor() {
    // Variables declaration
    string s, cleaned_message = "", cipher_text = "";

    // Prompt user to enter message to cipher
    cout << "ENTER A MESSAGE TO CIPHER\n";
    getline(cin, s);

    // Clean the message (remove non-alphabetic characters and convert to uppercase)
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            cleaned_message += toupper(s[i]);
        } else if(isspace(s[i])) {
            cleaned_message += s[i];
        } else {
            continue;
        }
    }

    // Atbash encryption process
    for(int i = 0; i < cleaned_message.size(); i++) {
        if(isalpha(cleaned_message[i])) {
            // Encrypt alphabetic characters using Atbash cipher
            cipher_text += char(90 - (cleaned_message[i] - 65));
        } else {
            // Preserve non-alphabetic characters
            cipher_text += cleaned_message[i];
        }
    }

    // Output the ciphered text
    cout << cipher_text << "\n";
}


// Function for Atbash decryption
void atbash_decryptor() {
    // Prompt user to enter message to decrypt
    cout << "ENTER A MESSAGE TO DECRYPT\n";
    string s;
    getline(cin, s);

    string cleaned_message = "";
    string decrypt_text = "";

    // Clean the message (remove non-alphabetic characters and convert to uppercase)
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            cleaned_message += toupper(s[i]);
        } else if (isspace(s[i])) {
            cleaned_message += s[i];
        }
    }

    // Decrypt the cleaned message
    for (int j = 0; j < cleaned_message.size(); j++) {
        if (isalpha(cleaned_message[j])) {
            // Calculate the shift needed for decryption
            int shift = cleaned_message[j] - 65;
            // Decrypt the character using the Atbash cipher
            char decrypted_char = 90 - shift;
            // Handle wrapping around the alphabet
            if (decrypted_char < 65) {
                decrypted_char += 26;
            }
            // Append the decrypted character to the decrypted text
            decrypt_text += decrypted_char;
        } else {
            // Preserve non-alphabetic characters
            decrypt_text += cleaned_message[j];
        }
    }

    // Output the decrypted text
    cout << "Decrypted Text: " << decrypt_text << endl;
}


int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
// Function for Affine encryption
void affine_encryptor() {
    // Variables declaration
    string message = "";
    string prepared_message = "";
    string ciphertext = "";

    // Prompt user to enter message to encrypt
    cout << "Please enter message to encrypt: " << endl;
    getline(cin, message);

    // Variables for the key
    int a, b;
    // Prompt user to enter key values
    cout << "Enter values for a and b (integers): ";
    cin >> a >> b;
    cin.ignore(); // Clear the input buffer

    // Encrypt the message
    for (int i = 0; i < message.size(); i++) {
        // Filter out alphabetic characters and convert to uppercase
        if (isalpha(message[i])) {
            prepared_message += toupper(message[i]);
        }
    }

    // Encryption process
    for (int i = 0; i < prepared_message.size(); i++) {
        int x = int(prepared_message[i]) - 65; // Convert character to its corresponding numerical value (0-25)
        int z = (a * x + b) % 26; // Apply the affine transformation
        ciphertext += char(z + 65); // Convert back to character and append to the ciphertext
    }

    // Output the ciphertext
    cout << "Ciphertext: " << ciphertext << endl;
}

// Function for Affine decryption
void affine_decryptor() {
    // Variables declaration
    string message = "";
    string decrypt_text = "";

    // Prompt user to enter message to decrypt
    cout << "Please enter the message to decrypt: " << endl;
    getline(cin, message);

    // Variables for the key
    int a, b, c;

    // Prompt user to enter key values
    cout << "Enter values for a, b, and c: ";
    cin >> a >> b >> c;
    cin.ignore(); // Clear the input buffer

    // Decrypt the message
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        cout << "Error: 'a' has no modular inverse modulo 26." << endl;
    }

    for (int j = 0; j < message.size(); j++) {
        int y = int(message[j]) - 65;
        int m = a_inv * (y - b + 26) % 26;
        decrypt_text += char(m + 65);
    }

    cout << "Decrypted text: " << decrypt_text << endl;
}
// Function for XOR encryption
auto XOR_encryptor() {
    // Variables declaration
    string message;
    string key;

    // Prompt user to enter the message
    cout << "Please enter a message (text): ";
    getline(cin, message);

    // Prompt user to enter the key
    cout << "Please enter the key: ";
    getline(cin, key);

    // Encrypt the message using XOR
    string encrypt_Hexa = "";
    int Key_Itr = 0;
    stringstream res;
    for (int i = 0; i < message.size(); i++) {
        int temp = message[i] ^ key[Key_Itr]; // XOR operation

        // Convert the result to hexadecimal
        res << hex << setfill('0') << setw(2) << (int)temp;
        Key_Itr++;

        if (Key_Itr >= key.size()) {
            Key_Itr = 0; // Reset the key iterator if it exceeds the key size
        }
    }

    // Extract the encrypted text in hexadecimal format
    res >> encrypt_Hexa;

    // Output the encrypted text in hexadecimal format
    cout << "Encrypted Text in Hexadecimal: " << encrypt_Hexa << endl;

    // Encrypt the message using XOR and output the result
    string cipher_text = "";
    while (key.size() < message.size()) {
        key += key; // Extend the key if its length is less than the message length
    }

    for (int i = 0; i < message.size(); i++) {
        cipher_text += message[i] ^ key[i]; // XOR operation
    }

    // Output the encrypted text
    cout << "Encrypted text is (text): " << cipher_text << endl;
}



// Function for XOR decryption
auto XOR_decryptor() {
    // Variables declaration
    string message;
    string key;

    // Prompt user to enter the message in hexadecimal format
    cout << "Please enter a message (in Hexadecimal): ";
    getline(cin, message);

    // Prompt user to enter the key
    cout << "Please enter the key: ";
    getline(cin, key);

    // Convert hexadecimal message to text
    string Hexa_to_text = "";
    for (int j = 0; j < message.size() - 1; j += 2) {
        string split_Hexa = message.substr(j, 2);
        // Convert each pair of hexadecimal characters to decimal
        int decimal = strtol(split_Hexa.c_str(), NULL, 16);
        // Append the corresponding character to the text
        Hexa_to_text += (char)decimal;
    }

    // Decrypt the message using XOR
    string decrypt_Hexa = "";
    int Key_Itr = 0;
    for (int i = 0; i < Hexa_to_text.size(); i++) {
        int temp = Hexa_to_text[i] ^ key[Key_Itr]; // XOR operation
        decrypt_Hexa += (char)temp; // Append the decrypted character
        Key_Itr++;

        if (Key_Itr >= key.size()) {
            Key_Itr = 0; // Reset the key iterator if it exceeds the key size
        }
    }

    // Output the decrypted message
    cout << "Decrypted message from Hexadecimal to text: " << decrypt_Hexa << endl;
}



// Function to continue or exit the program
bool cont() {
    string cont;
    cout << "a) Continue \nb) Exit to menu" << endl;
    cin >> cont;
    transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
    while ((cont != "b")) {
        if (cont == "a") {
            break;
        } else {
            cout << "please choose just a or b" <<endl;
            cout << "a) Continue \nb) Exit to menu" << endl;
            cin >> cont;
        }
    }
    if (cont == "a") {
        return true;
    } else {
        return false;
    }
}

// Main function to choose and execute ciphers
int main() {
    int choice1, choice2;
    bool to_menu = false;


    cout << "** Welcome to the encryption software **" <<endl <<endl;

    // Main loop to choose a cipher or exit
    cout << "Please choose a cipher(1-11): " << endl<< endl;
    while (true) {
        cout << "1) Polybius cipher\n2) Route cipher\n3) Simple Substitution cipher\n4) Baconian cipher\n5) Morse cipher\n";
        cout<<"6) Vignere cipher\n7) Rail Fence cipher\n8) Atbash cipher\n9) Affine cipher \n10) XOR cipher \n11) Exit \n\nchoose a number: ";
        cin >> choice1;
        cout <<endl;

        // Validate the input choice
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX , '\n');
            cout << "Please enter a valid choice: " << endl;
            continue;
        }

        // Switch to the chosen cipher
        switch (choice1) {
            case 1:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for Polybius cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\nchoose a number: " << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX , '\n');
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen Polybius cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                polybius_encryptor();
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                polybius_decryptor();
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;

            case 2:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for Route cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\nchoose a number: ";
                    cin >> choice2;
                    cout << endl;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX , '\n');
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen Route cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                route_encryptor();
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                route_decryptor();
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;

            case 3:
                do{
                        string key, message;
                        bool check= true;
                        // Main loop for encryption and decryption
                        while (true) {
                                check=true;
                                // Input key from user
                                cout << "Please enter the key: ";
                                cin >> key;
                                transform(key.begin(), key.end(),key.begin(), ::tolower);

                                // Check if the key contains only alphabets
                                // If key is invalid, ask the user to enter again
                                for(auto i : key){
                                    if ((isalpha(i) && islower(i)) || isspace(i)){}
                                    else{
                                    cout << "Please enter a key with no digits, spaces, or symbols." << endl;
                                    cin.clear();
                                    cin.ignore(INT_MAX,'\n');
                                    check=false;
                                    break;

                                    }

                                }
                                if(check){
                                break;
                                }
                        }
                        cin.ignore();
                        while(true){
                            // Input message from user
                            cout << "Enter the message: ";
                            getline(cin, message);
                            transform(message.begin(), message.end(),message.begin(), ::tolower);


                            // Check if the message contains only alphabets
                            // If message is invalid, ask the user to enter again
                            check=true;
                            for(auto j : message){
                                if ((isalpha(j) && islower(j)) || isspace(j)){}
                                else{
                                    cout << "Please enter a message with no digits, spaces, or symbols." << endl;
                                    cin.clear();
                                    check=false;
                                    break;
                                }
                            }
                            if(check){
                            break;
                            }
                        }


                        // Encrypt the message using the provided key
                        string encrypted_message = smpl_sub_encrypt(message, key);
                        cout << "Encrypted message: " << encrypted_message << endl << endl;

                        // Inner loop for decryption or exit option
                        while (true) {
                            string choice_message;
                            cout << "If you want to decrypt the message, enter 'decrypt' and If you want to exit, enter 'no': ";
                            cin >> choice_message;
                            transform(choice_message.begin(), choice_message.end(),choice_message.begin(), ::tolower);

                            // Decrypt the message if requested
                            if (choice_message == "decrypt") {
                                string decrypted_message = smpl_sub_decrypt(encrypted_message, key);
                                cout << "Encrypted message: " << encrypted_message << endl;
                                cout << "Decrypted message: " << decrypted_message << endl<<endl;
                                break;
                            }
                            else if (choice_message == "no") {
                                // Exit the program if requested
                                cout<<endl;
                                break;
                            }
                            else {
                                // ask the user to enter a valid choice
                                cin.clear();
                                cin.ignore();
                                cout << "Please enter 'decrypt' to decrypt the message or 'No' to exit." << endl;
                                continue;
                            }
                        }
            }while(cont());
            break;

            case 4:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for baconian cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\n" << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen baconian cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                baconian_encryptor();
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                baconian_decryptor();
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;

                case 5:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for morse cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\n" << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen morse cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                morse_encryptor();
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                morse_decryptor();
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;

                case 6:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for vignere cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\n" << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen vignere cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                vignere_encryptor();
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                vignere_decryptor();
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;
                case 7:

                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for rail fence cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\n" << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen rail cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                railfence_encryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                railfence_decryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;
                case 8:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for atbash cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\n" << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen atbash cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                atbash_encryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                atbash_decryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;

                case 9:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for affine cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\n" << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen affine cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                affine_encryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                affine_decryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;

                case 10:
                cin.clear();
                cin.ignore();
                cout << "Choose an option: " << endl;

                // Inner loop for XOR cipher options
                while (true) {
                    to_menu = false;
                    cout << "1) Encrypt \n2) Decrypt \n3) Exit to cipher menu\n" << endl;
                    cin >> choice2;

                    // Validate the input choice
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(INT_MAX , '\n');
                        cout << "Please enter a valid choice: " << endl;
                        continue;
                    }

                    // Switch to the chosen XOR cipher option
                    switch (choice2) {
                        case 1:
                            do {
                                cin.clear();
                                cin.ignore();
                                XOR_encryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 2:
                            do {
                                cin.clear();
                                cin.ignore();
                                XOR_decryptor();
                                cout<<endl;
                            } while (cont());
                            break;
                        case 3:
                            to_menu = true;
                            break;
                        default:
                            cout << "Please enter a valid choice: " << endl;
                            break;
                    }

                    if (to_menu) break;
                }
                break;

                case 11:
                    cout<<"Exiting...";
                    exit(0);

                default:
                    cout << "Please enter a valid choice: " << endl;
                    break;
        }
    }

    return 0;
}
