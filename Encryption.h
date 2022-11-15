#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryptor {
    private:
    string key;
    
    public:
    Encryptor() : key(generate_encryption_key()) {}
    Encryptor(string key) : key(key) {}

    // All decrypt and encrypt functions
    string encrypt_text(string plaintext);
    string decrypt_text(string ciphertext);
    string encrypt_text(string plaintext, string gkey);
    string decrypt_text(string ciphertext, string gkey);

    // To generate the key if one isn't already given
    string generate_encryption_key();

    // Getters
    string get_key();

    // Setters
    void set_key(string key);
};

#endif