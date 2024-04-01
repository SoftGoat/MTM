class CaesarCipher:
    TOTAL_ALPHABET = 26
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    # Constructor
    def __init__(self, key):
        self.key = key
    
    
    def encrypt(self, message):
        incremented_string = ""
        for char in message:
            if char.isalpha() and char.islower():
                    incremented_char = self.alphabet[(self.alphabet.index(char) + self.key) % self.TOTAL_ALPHABET]
            elif char.isalpha() and char.isupper():
                    incremented_char = self.ALPHABET[(self.ALPHABET.index(char) + self.key) % self.TOTAL_ALPHABET]
            else:
                incremented_char = char
            incremented_string += incremented_char

        return incremented_string

    # Decrypts an encrypted message
    def decrypt(self, encrypted_message):
        decremented_string = ""
        for char in encrypted_message:
            if char.isalpha():
                base = ord('A') if char.isupper() else ord('a')
                decremented_char = chr((ord(char) - base - self.key) % self.TOTAL_ALPHABET + base)
            else:
                decremented_char = char
            decremented_string += decremented_char

        return decremented_string


    def key_shift(self, shift):
        self.key +=shift



class VigenereCipher:
    TOTAL_ALPHABET = 26
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    def __init__(self, key):
        self.key = key

    def encrypt(self, message):
        encrypted_string = ""
        key_index = 0
        for char in message:
            if char.isalpha() and char.islower():
                key_value = self.key[key_index % len(self.key)]  # Get the key shift value for this position
                encrypted_char = self.alphabet[(self.alphabet.index(char) + key_value) % self.TOTAL_ALPHABET]
                key_index += 1
            elif char.isalpha() and char.isupper():
                key_value = self.key[key_index % len(self.key)]
                encrypted_char = self.ALPHABET[(self.ALPHABET.index(char) + key_value) % self.TOTAL_ALPHABET]
                key_index += 1  
            else:
                encrypted_char = char
            encrypted_string += encrypted_char
        return encrypted_string

    def decrypt(self, encrypted_message):
        decrypted_string = ""
        key_index = 0
        for char in encrypted_message:
            if char.isalpha() and char.islower():
                key_value = self.key[key_index % len(self.key)]  # Get the key shift value for this position
                decrypted_char = self.alphabet[(self.alphabet.index(char) - key_value) % self.TOTAL_ALPHABET]
                key_index += 1  # Only increment key_index if an alphabet was encountered
            elif char.isalpha() and char.isupper():
                key_value = self.key[key_index % len(self.key)]
                decrypted_char = self.ALPHABET[(self.ALPHABET.index(char) - key_value) % self.TOTAL_ALPHABET]
                key_index += 1
            else:
                decrypted_char = char
            decrypted_string += decrypted_char
        return decrypted_string


import os
import json
def loadEncryptionSystem(dir_path, plaintext_suffix):
    # Check if the directory exists
    
    if not os.path.isdir(dir_path):
        print("Error: Directory does not exist.")
        return None
    
    script_dir = os.path.dirname(os.path.realpath(__file__))
    try:
        # Try to locate the config.json file
        config_file = os.path.join(script_dir, "config.json")
    except IOError:
        print(f"Error: Unable to open or read {config_file}.")
        return None
    except ValueError:
        print("Error: Unable to parse JSON from config file.")
        return None 
   
    if not os.path.isfile(config_file):
        print("Error: config.json not found in the directory.")
        return None
    
    # Load the content of config.json
    with open(config_file, 'r') as f:
        config_data = json.load(f)
    
    # Extract the encryption type, encryption status, and key from the config data
    encryption_type = config_data.get("type")
    encrypt = config_data.get("encrypt")
    key = config_data.get("key")

    file_directory = os.path.dirname(config_file)

    for filename in os.listdir(file_directory):
        file_path = os.path.join(file_directory, filename)
        try:
            if encrypt:
                if filename.endswith(".txt"):
                    with open(file_path, 'r') as file:
                        text = file.read()
                        if encryption_type == "Caesar":
                            cipher = CaesarCipher(key)
                            encrypted_text = cipher.encrypt(text)
                        elif encryption_type == "Vigenere":
                            cipher = VigenereCipher(key)
                            encrypted_text = cipher.encrypt(text)
                        else:
                            print("Error: Unsupported encryption type.")
                            return None
                    # Write the decrypted content to a new .txt file
                    new_filename = filename[:-len(plaintext_suffix)] + "enc"
                    new_file_path = os.path.join(file_directory, new_filename)
                    with open(new_file_path, 'w') as new_file:
                        new_file.write(encrypted_text)

        
            else:
                if filename.endswith(".enc"):
                    with open(file_path, 'r') as file:
                        encrypted_text = file.read()
                        if encryption_type == "Caesar":
                            cipher = CaesarCipher(key)
                            decrypted_text = cipher.decrypt(encrypted_text)
                        elif encryption_type == "Vigenere":
                            cipher = VigenereCipher(key)
                            decrypted_text = cipher.decrypt(encrypted_text)
                        else:
                            print("Error: Unsupported decryption type.")
                            return None
                    # Write the decrypted content to a new .txt file
                    new_filename = filename[:-len(plaintext_suffix)] + "txt"
                    new_file_path = os.path.join(file_directory, new_filename)
                    with open(new_file_path, 'w') as new_file:
                        new_file.write(decrypted_text)
        except IOError:
            print("Error: File not found.")
            continue

    