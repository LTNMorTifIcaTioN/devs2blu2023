#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* SearchingChallenge(char* str)
{
    int max_repeated_letters = 0;
    char* max_repeated_word = NULL;
    char* word = strtok(str, " ");

    while (word != NULL)
    {
        int len = strlen(word);
        int freq[26] = {0};
        int repeated_letters = 0;

        for (int i = 0; i < len; i++)
        {
            if (isalpha(word[i]))
            {
                freq[tolower(word[i]) - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 1)
            {
                repeated_letters += freq[i];
            }
        }

        if (repeated_letters > max_repeated_letters)
        {
            max_repeated_letters = repeated_letters;
            max_repeated_word = word;
        }

        word = strtok(NULL, " ");
    }

    if (max_repeated_word == NULL)
    {
        return "-1";
    }
    else
    {
        return max_repeated_word;
    }
}

int main()
{
    char str[50];
    printf("Informe uma String: \n");
    fgets (str, 50, stdin);

    char* result = SearchingChallenge(str);
    printf("%s\n", result);

    char ChallengeToken[] = "1wxgtmhbo47";
    int len = strlen(result) + strlen(ChallengeToken);
    char output[len + 1];
    sprintf(output, "%s%s", result, ChallengeToken);

    for (int i = 2; i < len; i += 3)
    {
        output[i] = 'X';
    }

    printf("%s\n", output);
    return 0;
}
