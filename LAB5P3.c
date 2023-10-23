#include <stdio.h>
#include <string.h>

int main()
{
    char input[256];
    int letterCount[26] = {0}; // Array to store the count of each letter initialized to zeros

    printf("Enter text strings (press Enter on an empty line to exit):\n");

    while (1)
    {
        fgets(input, sizeof(input), stdin); // get the input from the user via keyboard

        // Check for an empty line to exit the loop
        if (strlen(input) == 1 && input[0] == '\n')
        {
            break;
        }

        // Iterate through the characters in the input
        for (int i = 0; input[i] != '\0'; i++)
        {
            char currentChar = input[i];

            if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z'))
            {
                // Convert the lowercase character to uppercase if needed
                if (currentChar >= 'a' && currentChar <= 'z')
                {
                    currentChar = currentChar - ('a' - 'A');
                }

                // Increment the corresponding count in the array
                letterCount[currentChar - 'A']++;
            }
        }
    }

    // Display the letter counts
    printf("Distribution of letters in the input:\n");
    for (char letter = 'A'; letter <= 'Z'; letter++)
    {
        printf("%c: %d ", letter, letterCount[letter - 'A']);
    }
    printf("\n");

    return 0;
}
