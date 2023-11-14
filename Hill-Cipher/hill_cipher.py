import numpy as np
from sympy import Matrix

def encrypt(message, K):
    # Convert message to vector
    message_vector = [ord(i) - 65 for i in message]
    message_vector = np.transpose([message_vector])

    # Calculate cipher text vector
    cipher_vector = np.dot(K, message_vector) % 26

    # Convert cipher vector to text
    cipher_text = [chr(i + 65) for i in list(cipher_vector.flatten())]

    return ''.join(cipher_text)

def decrypt(cipher_text, K_inv):
    # Convert cipher text to vector
    cipher_vector = [ord(i) - 65 for i in cipher_text]
    cipher_vector = np.transpose([cipher_vector])

    # Calculate message vector
    message_vector = np.dot(K_inv, cipher_vector) % 26

    # Convert message vector to text
    message_text = [chr(i + 65) for i in list(message_vector.flatten())]

    return ''.join(message_text)

# Define 2x2 key matrix (ensure it's invertible)
K = np.array([[6, 24], [1, 2]])

# Calculate inverse of K
K_inv = Matrix(K).inv_mod(26)

# Test the algorithm
message = 'HELLO'
cipher_text = encrypt(message, K)
decrypted_text = decrypt(cipher_text, K_inv)

print('Message:', message)
print('Cipher Text:', cipher_text)
print('Decrypted Text:', decrypted_text)