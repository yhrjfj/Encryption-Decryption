def transpose_text(text, key):
    num_columns = len(key)
    num_rows = len(text) // num_columns
    if len(text) % num_columns != 0:
        num_rows += 1

    # Pad the text with spaces if necessary
    text += ' ' * (num_rows * num_columns - len(text))

    # Create the transposition matrix
    matrix = []
    for i in range(num_rows):
        row = []
        for j in range(num_columns):
            row.append(text[i * num_columns + j])
        matrix.append(row)

    # Rearrange the columns according to the key
    sorted_key = sorted(range(num_columns), key=lambda k: key[k])
    transposed_matrix = []
    for i in range(num_rows):
        row = []
        for j in sorted_key:
            row.append(matrix[i][j])
        transposed_matrix.append(row)

    # Flatten the transposed matrix into a single string
    transposed_text = ''.join(''.join(row) for row in transposed_matrix)

    return transposed_text
