#pragma once
#include <string>
enum Tokens_048
{
	FOR_048, LPRN, RPRN, OPR, UID, LCRBR, RCRBR, LSQRBR, RSQRBR, WHILE_048, DO_048, IF, ELSE, ELSE_IF, COUT, CIN, INT_048, CHAR_048,
	DOUBLE_048,
	STRING, NEW, NUM, VAR, FLOAT_048, INCREMENT, DECREMENT,
	PLUS, MINUS, DIVIDE, MULTIPLY, PLUS_EQUAL, MINUS_EQUAL, EQUAL,
	ASSIGNMENT, GREATER_THAN_EQUAL_TO, GREATER_THAN
	, LESS_THAN, OSTREAM, ISTREAM, LESS_THAN_EQUAL_TO, NOT_EQUAL_TO,
	EXCLAIMATION, SEMI_COLON, COLON, OPEN_BRACES,
	CLOSE_BRACES, OPEN_BRACKET, CLOSE_BRACKET, OPEN_SQUARE_BRACKET,
	CLOSE_SQUARE_BRCKET, BEGIN, END, OR, AND, CHECK_048
};
#ifndef ABDUL_ALI_TOKEN_TYPE_DEFINED 
#define ABDUL_ALI_TOKEN_TYPE_DEFINED
struct Abdul_Ali_Token_Type
{
	Tokens_048 Token_048;
	std::string Name_048;
	std::string words;
	int Values_048;
};
#endif
