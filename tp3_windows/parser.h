/*
 * parser.h
 *
 *  Created on: 11 nov. 2021
 *      Author: Ryzen 3
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
//int generateIdFile(char* FILE);

#endif /* PARSER_H_ */
