#include <iostream>
#include <vector>
#include <algorithm>

std::string transposeText(const std::string& text, const std::vector<int>& key) {
    int numColumns = key.size();
    int numRows = text.length() / numColumns;
    if (text.length() % numColumns != 0) {
        numRows += 1;
    }

    // Pad the text with spaces if necessary
    std::string paddedText = text;
    paddedText.append(numRows * numColumns - text.length(), ' ');

    // Create the transposition matrix
    std::vector<std::vector<char>> matrix;
    for (int i = 0; i < numRows; i++) {
        std::vector<char> row;
        for (int j = 0; j < numColumns; j++) {
            row.push_back(paddedText[i * numColumns + j]);
        }
        matrix.push_back(row);
    }

    // Rearrange the columns according to the key
    std::vector<int> sortedKey = key;
    std::sort(sortedKey.begin(), sortedKey.end());
    std::vector<std::vector<char>> transposedMatrix;
    for (int i = 0; i < numRows; i++) {
        std::vector<char> row;
        for (int j : sortedKey) {
            row.push_back(matrix[i][j]);
        }
        transposedMatrix.push_back(row);
    }

    // Flatten the transposed matrix into a single string
    std::string transposedText;
    for (const auto& row : transposedMatrix) {
        transposedText.append(row.begin(), row.end());
    }

    return transposedText;
}
