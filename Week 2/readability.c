#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = strlen(text);

    int count_letters = 0;
    int count_words = 0;
    int count_sentences = 0;

// loop everything
    for (int i = 0 ; i < letters ; i++)
    {
        // counting letters
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count_letters++;
        }

        // counting words
        if (text[i] == 32)
        {
            count_words++;
        }

        // counting sentences
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count_sentences++;
        }

    }

//return outputs
    printf("%i letters\n", count_letters);
    printf("%i words\n", count_words + 1);
    printf("%i sentences\n", count_sentences);

// apply the theorem
    float L = (float) count_letters * (100 / ((float) count_words + 1));
    float S = (float) count_sentences * (100 / ((float) count_words + 1));

    int index = round(0.0588 * L - 0.296 * S - 15.8);

//printf("L = %f\n", L);
//printf("S = %f\n", S);
//printf("index is %i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}