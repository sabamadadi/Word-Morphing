# Word Morphing

This program implements the Word Morphing algorithm in C++. It finds the shortest sequence of word transformations between a given start word and end word using a breadth-first search approach. The algorithm ensures that each intermediate word is a valid English word by checking against a word dictionary.

## Usage

1. Compile the code using a C++ compiler.
2. Run the compiled program.
3. Enter the start word and end word when prompted.
4. The program will display the shortest word path if a valid transformation sequence is found.

## Dependencies

The code relies on the following C++ standard libraries:

- iostream
- queue
- unordered_set
- unordered_map
- vector

Make sure you have a C++ compiler installed on your system.

## Customization

You can customize the word dictionary, start word, and end word in the `main` function to suit your needs. Modify the `wordDict`, `startWord`, and `endWord` variables accordingly.
