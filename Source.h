#pragma once
#include<string>
#include"tokens.h"

struct Abdul_Ali_Symbol_Table;

void UNGET_TOKEN_LEXICAL();

Abdul_Ali_Token_Type GET_TOKEN_LEXICAl1(int i);
typedef enum { opk, constk, idk } expkind;
typedef enum { ifk, assignk, dok, whilek }stmtkind;
typedef enum { stmtk, expk }nodekind1;
#ifndef TREENODE_DEFINED 
#define TREENODE_DEFINED
struct treenode
{
	nodekind1 nodek;
	stmtkind stmtk;
	expkind expk;
	Abdul_Ali_Token_Type token1;
	int value;
	std::string name;
	treenode* leftchild;
	treenode* rightchild;
	treenode* middlechild;

	treenode* sibling;
};
#endif
extern std::string path;
treenode* fileopener(std::string parth);
treenode* expression();
treenode* term();
treenode* factor();
treenode* expression();
treenode* term();
treenode* factor();
treenode* statement();
treenode* program();
treenode* statement_list();
treenode* statement();
void Token_Passing(std::string chk);
Abdul_Ali_Token_Type* getrecord(int index);
bool Check_048(std::string temp);

Abdul_Ali_Token_Type Lexical_048(int i);
bool Abdul_Ali1();
bool Abdul_Ali2();
bool Abdul_Ali3();
bool Abdul_Ali4();
bool Abdul_Ali5();
bool Abdul_Ali6();
bool Abdul_Ali7();
bool Abdul_Ali8();
bool Program();
bool Statementlist();
bool Statement();
bool FORMAT();
bool PARSERCHECHER();
bool parserstart();

void Tree();
