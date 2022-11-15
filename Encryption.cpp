// @author: rishisant
// @date: 2022-14-11
// @version: 1.0

#include "Encryption.h"

#include <random>
#include <chrono>

using std::string, std::vector, std::ifstream, std::ofstream, std::istringstream, std::ostream_iterator, std::transform, std::back_inserter, std::function, std::isspace, std::stringstream, std::random_device, std::mt19937, std::uniform_int_distribution;

// Getters
string Encryptor::get_key() {
    return key;
}

// Setters
void Encryptor::set_key(string key) {
    this->key = key;
}

// Base command
string Encryptor::generate_encryption_key() {
    // Use rand() as well as Time(NULL) to generate a random encryption key made out of random string
    string key = "";
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        key += (char)(rand() % 26 + 65); // ASCII char mapping
    }
    return key;
}

// Encryption commands
string Encryptor::encrypt_text(string plaintext) {
    // Use XOR to encrypt the plaintext
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        ciphertext += (char)(plaintext[i] ^ key[i % key.length()]);
    }
    return ciphertext;
}

string Encryptor::decrypt_text(string ciphertext) {
    // Use XOR to decrypt the ciphertext
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += (char)(ciphertext[i] ^ key[i % key.length()]);
    }
    return plaintext;
}

// Encryption commands
string Encryptor::encrypt_text(string plaintext, string gkey) {
    // Use XOR to encrypt the plaintext
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        ciphertext += (char)(plaintext[i] ^ gkey[i % gkey.length()]);
    }
    return ciphertext;
}

string Encryptor::decrypt_text(string ciphertext, string gkey) {
    // Use XOR to decrypt the ciphertext
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += (char)(ciphertext[i] ^ gkey[i % gkey.length()]);
    }
    return plaintext;
}