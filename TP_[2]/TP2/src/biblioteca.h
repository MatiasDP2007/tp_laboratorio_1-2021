
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @param message
/// @param max
/// @param min
/// @return
int EnterNumberInt(char message[], int max, int min);

/// @param message
/// @param enteredString
void EnterString (char message[], char enteredString[]);

/// @param message
/// @return
float EnterNumberFloat (char message[]);

/// @param enteredNumber
/// @return
int ValidateNumberInt(char enteredNumber[]);

/// @param enteredString
/// @return
int ValidateString(char enteredString[]);

/// @param enteredNumber
/// @return
int ValidateNumberFloat(char enteredNumber[]);

/// @param enteredString
void NormalizeString(char enteredString[]);



#endif /* BIBLIOTECA_H_ */
