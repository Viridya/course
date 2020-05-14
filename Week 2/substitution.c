#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(int argc, string argv[])
{
    // error checking
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        int key_count = strlen(argv[1]);

        // verify all characters are letters
        for (int i = 0; i < key_count ; i++)
        {
            if (argv[1][i] < 65 || argv[1][i] > 122)
            {
                printf("Numerical characters detected. Enter only alphabetical letters.\n");
                return 1;
            }
            else if (argv[1][i] > 90 && argv[1][i] < 97)
            {
                printf("Numerical characters detected. Enter only alphabetical letters.\n");
                return 1;
            }
        }

        // duplicate letters
        for (int i = 0; i < key_count ; i++)
        {
            for (int j = i + 1; j < key_count ; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Duplicated letters detected.\n");
                    return 1;
                }
            }
        }

        string plain = get_string("plaintext: ");
        printf("ciphertext: ");

        // Encipher - check each character
        for (int i = 0; i < strlen(plain); i++)
        {
            // Check if each actual character is upper
            if (plain[i] >= 65 && plain[i] <= 90)
            {
                char cipher = argv[1][plain[i] - 65];

                // Check against key location, if key is lower, if so, convert
                if (cipher >= 97 && cipher <= 122)
                {
                    cipher = argv[1][plain[i] - 65] - 32;
                }

                printf("%c", cipher);

            }
            // Check if each actual character is lower
            else if (plain[i] >= 97 && plain[i] <= 122)
            {
                char cipher = argv[1][plain[i] - 97];

                // Check against key location, if key is upper, if so, convert
                if (cipher >= 65 && cipher <= 90)
                {
                    cipher = argv[1][plain[i] - 97] + 32;
                }

                printf("%c", cipher);
            }
            // Any leftover non alphabet characters, leave them as they are
            else
            {
                char cipher = plain[i];
                printf("%c", cipher);
            }
        }

        // New line + return 0
        printf("\n");
        return 0;
    }

}