import random
import string

def generate_random_text(length):
    # Define the characters to choose from
    characters = string.ascii_letters + string.digits + string.punctuation + ' '

    # Generate random text of specified length
    random_text = ''.join(random.choice(characters) for _ in range(length))
    return random_text

def save_to_txt(filename, text):
    with open(filename, 'w') as file:
        file.write(text)

# Generate random text of length 100
random_text = generate_random_text(100)

# Save the random text to a .txt file
file_name = "random_text.txt"
save_to_txt(file_name, random_text)
print(f"Random text saved to '{file_name}'.")
