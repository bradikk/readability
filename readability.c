#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);

int main(void)
{
    // Get & print user input
    string text = get_string("Text: ");

    // Create ints & functions
    int letter = letter_count(text);
    int word = word_count(text);
    int sentence = sentence_count(text);

    // CLI formula variables
    double L, S;
    L = letter / (float)word * 100;
    S = sentence / (float)word * 100;

    // CLI formula
    int grade = round((0.0588 * L) - (0.296 * S) - 15.8);

    // Print grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Count the number of uppercase and lowercase letters in a text.
int letter_count(string text)
{
    // Keep track of letter count
    int letter = 0;
    // Loop through the string
    for (int i = 0; i < strlen(text); i++)
    {
        // Count chars
        if (isalpha(text[i]))
        {
            letter++;
        }
    }
    return letter;
}

int word_count(string text)
{
    // TODO Count the number of words in a sentence.
    // A word = any sequence of chars separated by a " "
    // Loop through to find the amount of spaces in the string.
    // Then do spaces + 1 after all words have been counted/looped.

    int word = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            word++;
        }
    }
    word++;

    return word;

}

int sentence_count(string text)
{
    // TODO Count the number of sentences.
    // Sentence = any . ! or ? indicates a sentence.
    // Go throught the string and +1 every time .!? appears

    int sentence = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}