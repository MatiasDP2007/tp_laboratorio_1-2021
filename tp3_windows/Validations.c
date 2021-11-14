#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Validations.h"


/// @param message
/// @param max
/// @param min
/// @return
int EnterNumberInt (char message[], char errorMessage[],  int max, int min)
{
    char enteredNumber [51];
    int isNaN;
    int validatedNumber;
    int flag = 1;
    do
    {
        if(flag==0)
        {
            printf("%s", errorMessage);
        }

        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberInt(enteredNumber);

        while(isNaN ==-1)
        {
        printf("%s", errorMessage);
        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberInt(enteredNumber);
        }

        validatedNumber = atoi(enteredNumber);
    flag=0;
    }while (validatedNumber < min || validatedNumber > max);

    return validatedNumber;
}

/// @param message
/// @param enteredString
void EnterString (char message[], char enteredString[])
{
    int isString;

    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", enteredString);

    isString = ValidateString (enteredString);
    while(isString == -1)
    {
    printf(" %s", message);
    fflush(stdin);
    scanf("%[^\n]", enteredString);
    isString = ValidateString (enteredString);

    }

    NormalizeString(enteredString);

}
/// @param message
/// @return
float EnterNumberFloat (char message[])
{
    char enteredNumber [51];
    int isNaN;
    float validatedNumber;
    int flag = 1;
    do
    {
        if(flag==0)
        {
            printf("Error.");
        }
        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberFloat(enteredNumber);

        while(isNaN ==-1)
        {
        printf("Error. %s", message);
        fflush(stdin);
        scanf("%[^\n]",enteredNumber);
        isNaN = ValidateNumberFloat(enteredNumber);
        }

        validatedNumber = atof(enteredNumber);
        flag = 0;
    }while (validatedNumber <= 0);

    return validatedNumber;
}

/// @param enteredNumber
/// @return
int ValidateNumberInt(char enteredNumber[])
{
    int validatedNumber = 0;
    for(int i=0; i < strlen(enteredNumber); i++)
    {
        if ((isdigit(enteredNumber[i])==0))
        {
        validatedNumber = -1;
        break;
        }
    }
 return validatedNumber;
}

/// @param enteredString
/// @return
int ValidateString(char enteredString[])
{
    int validatedString = 0;
    for(int i=0; i < strlen(enteredString); i++)
    {
         if (enteredString[0] == ' ')
        {
            validatedString = -1;
            printf("No se admiten espacio como nombres.");
            break;
        }
        else if (enteredString[i] == '-')
        {
       	validatedString = 0;
      	break;
        }
        else if (isalpha(enteredString[i])==0 && enteredString[i] != ' ' )
        {
        validatedString = -1;
        printf("No se admiten numeros/signos como nombres.");
        break;
        }
        else if (enteredString[i] == ' ' && enteredString[i+1] == ' ')
        {
            validatedString = -1;
            printf("No se admiten mas de dos espacios seguidos.");
            break;
        }

    }
    return validatedString;
}

/// @param enteredNumber
/// @return
int ValidateNumberFloat(char enteredNumber[])
{
    int validatedNumber;
    int flag=1;

    for(int i = 0; i< strlen(enteredNumber); i++)
    {
        if (flag && enteredNumber[i] == '.')
        {
                flag = 0;
        }else if(isdigit(enteredNumber[i])==0)
            {
                validatedNumber = -1;
                break;
            }

    }
    return validatedNumber;
}

/// @param enteredString
void NormalizeString(char enteredString[])
{

    int flagNormalize = 1;
    for(int i=0;i<strlen(enteredString);i++)
    {
        if(enteredString[i]== ' ')
        {
        flagNormalize = 1;
        }

         else if (flagNormalize && enteredString[i]!= ' ')
        {
            enteredString[i] = toupper(enteredString[i]);
            flagNormalize = 0;

        }

        else
        {
        enteredString[i] = tolower(enteredString[i]);
        }

    }
}
