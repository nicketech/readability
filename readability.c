#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main(void)
{
    string str = get_string("Text: ");
    printf("%s\n",str);


    double count_letters = 0;
    double count_words = 1;
    double count_sentences = 0;

    for (int a = 0; a < strlen(str); a++) {
        char b = str[a];

        if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z')) {
            count_letters++;
        }

        if (b == ' ') {
            count_words++;
        }

        if (b == '.' || b == '?' || b == '!') {
            count_sentences++;
        }
    }

    // Average of letters per 100 words
    double l = count_letters / count_words * 100;
    
    // Average of sentences per 100 words
    double s = count_sentences / count_words * 100;
    
    // Round doubles to int
    int intL = round(l);
    int intS = round(s);
    
    
    int intLetter = round(count_letters);
    int intWord = round(count_words);
    int intSentence = round(count_sentences);


    // printf("%i\n", intLetter);
    // printf("%i\n", intWord);
    // printf("%i\n", intSentence);
    // printf("%i\n", intL);
    // printf("%i\n", intS);
    
    // Compute the index
    double index = 0.0588 * l - 0.296 * s - 15.8;
    int intIndex = round(index);
    
    // Print the output
    if (intIndex < 1) {
        printf("Before Grade 1\n");
    }
    else if (intIndex > 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %i\n", intIndex);
    }
}
