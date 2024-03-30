import unittest
from ex5 import VigenereCipher
import sys  # Import sys to handle command-line arguments
import os
from pycipher import Vigenere as PyCipherVigenere

def key_list_to_string(keys):
    # The ASCII value for 'A' is 65. Adding an integer from 0-25 to it will give us letters from 'A' to 'Z'.
    return ''.join(chr(key+65) for key in keys)

class TestVigenereCipher(unittest.TestCase):

    def key_list_to_string(keys):
        # The ASCII value for 'A' is 65. Adding an integer from 0-25 to it will give us letters from 'A' to 'Z'.
        return ''.join(chr(key + 65) for key in keys)
    
    def setUp(self):
        self.key = 1
        self.keys = [0, 1, 2, 3]
        self.test_string = 'HELLOWORLD'
        self.cipher = VigenereCipher(self.keys)
        self.pycipher = PyCipherVigenere(key_list_to_string(self.keys))

    def test_encrypt(self):
        # Encrypt with your implementation
        encrypted = self.cipher.encrypt(self.test_string)
        # Encrypt with pycipher
        expected_encrypted = self.pycipher.encipher(self.test_string)
        self.assertEqual(encrypted, expected_encrypted)

    def test_decrypt(self):
        # Encrypt with pycipher then decrypt with your implementation
        encrypted = self.pycipher.encipher(self.test_string)
        decrypted = self.cipher.decrypt(encrypted)
        self.assertEqual(decrypted, self.test_string)

    # Additional tests can be added for edge cases, such as:
    # - Empty strings
    # - Non-alphabetic characters
    # - Lowercase characters
    # - Very long strings
    # - Repeating patterns in keys and messages



def encrypt_files_in_folder(folder_path, key_string):
    key = [ord(k) - ord('A') for k in key_string.upper()]  # Convert key string to list of shifts

    for filename in os.listdir(folder_path):
        if filename.endswith('.txt'):
            file_path = os.path.join(folder_path, filename)

            with open(file_path, 'r') as file:
                file_content = file.read()

            encrypted_content = ''
            key_index = 0  # Initialize key index

            for char in file_content:
                if char.isalpha():
                    # Calculate the shift for the current character using the key
                    shift = key[key_index % len(key)]
                    
                    # Perform the shift, taking into account the character case
                    base = ord('A') if char.isupper() else ord('a')
                    encrypted_char = chr((ord(char) - base + shift) % 26 + base)

                    key_index += 1  # Advance the key index for the next alphabetic character
                else:
                    # Keep non-alphabetic characters as is
                    encrypted_char = char

                encrypted_content += encrypted_char

            output_filename = filename[:-4] + '.out'
            output_file_path = os.path.join(folder_path, output_filename)

            with open(output_file_path, 'w') as output_file:
                output_file.write(encrypted_content)
# Example usage
def run_tests():
    unittest.main()



if __name__ == '__main__':
    if len(sys.argv) > 1:
        # Check if the first command-line argument is "encrypt"
        if sys.argv[1] == 'encrypt':
            # Remove the first argument ("encrypt"), as unittest.main() doesn't expect it
            sys.argv.pop(1)
            
            # Call encrypt_files_in_folder function
            folder_path = '/home/zohar/MTM/EX5'  # Replace with the path to your folder
            key = key_list_to_string([ 9, 18, 14, 13, 10, 4, 24, 22, 8, 19, 7, 13, 14, 13, 0, 11, 15, 7, 0, 2, 7, 0, 17, 18 ])  # Replace with your Vigenere cipher key
            print("they key is: "+key)
            encrypt_files_in_folder(folder_path, key)
        else:
            print("Invalid command. Use 'encrypt' to encrypt files.")
    else:
        # Run tests if no command-line argument is provided
        run_tests()






