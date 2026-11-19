# B2 – Adversarial Input and Memory Safety Testing

## 1. Objective
To test the program using long names, invalid inputs and missing files.

## 2. scanf() vs fgets()

- scanf() with a width limit reads a single word safely.
- fgets() reads a full name containing spaces.
- fgets() is suitable for complete donor names.

## 3. File Error Handling

The program uses fopen() to open files.

If the file cannot be opened, perror() displays the error message.

Test cases:
- Missing file
- Valid file
- File without write permission

## 4. Command-Line Testing

Test cases:
- No arguments
- name-scanf
- name-fgets
- filecheck with a missing filename
- Incorrect command

## 5. Memory Safety

The program can be compiled using AddressSanitizer.

Compile command:

gcc -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer B2.c -o B2

Actual result:
[Write your observed result after testing.]

## 6. Conclusion

Input validation and proper file error handling improve program reliability. fgets() is useful for reading full donor names, while AddressSanitizer helps identify memory errors.
