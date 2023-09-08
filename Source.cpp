#pragma once
#include<iostream>

#include<fstream>

#include"Source.h"
using namespace std;




struct Abdul_Ali_Symbol_Table
{
	int Table_No_00;
	string Name_048;
	int Values_048;
};

Abdul_Ali_Token_Type* tRecord = new Abdul_Ali_Token_Type[1000];
bool flag = 1;
Abdul_Ali_Token_Type TKR, Current_TKR;
Abdul_Ali_Symbol_Table* sTable = new Abdul_Ali_Symbol_Table[1000]; int I_048 = 0,
J_048 = 0;

fstream file[2];

treenode* fileopener(string parth) {
	file[0].open(parth, fstream::in);
	file[1].open(parth, fstream::in);
	if (file[0].is_open()) {
		cout << "File Opened!";
		treenode* root = program();
		return root;
	}
	else
		cout << "File not found!";
}









treenode* t1;

treenode* expression()
{
	treenode* t;
	treenode* p = new treenode;
	int flage = 0;
	do
	{
		t = term();
		if (flage)
		{
			p->rightchild = t;
			p->middlechild = NULL;
			p->sibling = NULL;
			flage = 0;
			t = p;
		}
		TKR = GET_TOKEN_LEXICAl1(0);
		if (TKR.Token_048 == PLUS || TKR.Token_048 == MINUS)
		{
			
			p = new treenode;
			p->expk = opk;
			if (TKR.Token_048 == PLUS) {
				p->name = "+";
			}
			else if (TKR.Token_048 == MINUS) {
				p->name = "-";
			}
			p->token1 = TKR;
			p->leftchild = t;
			flage = 1;
		}
		else if (TKR.Token_048 == GREATER_THAN || TKR.Token_048 == LESS_THAN) {
			p = new treenode;
			p->expk = opk;
			if (TKR.Token_048 == GREATER_THAN)
				p->name = ">";
			else if (TKR.Token_048 == LESS_THAN)
				p->name = "<";
			p->token1 = TKR;
			p->leftchild = t;
			flage = 1;
		}
	} while (TKR.Token_048 == PLUS || TKR.Token_048 == MINUS || TKR.Token_048 == GREATER_THAN || TKR.Token_048 == LESS_THAN);
	UNGET_TOKEN_LEXICAL();
	return (t);
}

treenode* term()
{
	treenode* t;
	treenode* p = new treenode;
	int flage = 0;
	do
	{
		t = factor();
		if (flage)
		{
			p->rightchild = t;
			flage = 0;
			t = p;
		}
		TKR = GET_TOKEN_LEXICAl1(0);
		if (TKR.Token_048 == MULTIPLY || TKR.Token_048 == DIVIDE)
		{
			p = new treenode;
			p->expk = opk;
			p->name = "*";
			p->token1 = TKR;
			p->leftchild = t;
			flage = 1;
		}
	} while (TKR.Token_048 == MULTIPLY || TKR.Token_048 == DIVIDE);
	UNGET_TOKEN_LEXICAL();
	return (t);

}



treenode* factor()
{
	treenode* t = new treenode;
	treenode* p;

	TKR = GET_TOKEN_LEXICAl1(0);
	switch (TKR.Token_048)
	{
	case NUM:
		t = new treenode();
		t->expk = constk;
		t->value = TKR.Values_048;
		t->name = "";
		//t->opr=NUL;
		t->leftchild = NULL;
		t->rightchild = NULL;
		return(t);
		break;
	case VAR:
		t = new treenode();
		t->expk = idk;
		//t->value=atoi(tok.name);
		t->name = TKR.Name_048;
		//t->opr=NUL;
		t->leftchild = NULL;
		t->rightchild = NULL;
		return(t);
		break;
	case  LPRN:
		return(t);
		break;
	}
	UNGET_TOKEN_LEXICAL();
	return t;
}







treenode* statement_list()  // statement list 
{
	treenode* stree;
	treenode* prevtree;
	treenode* stmttree;
	if (prevtree = statement())
	{
		prevtree->sibling = NULL;
		stmttree = prevtree;
		stmttree->sibling = NULL;
		do
		{
			TKR = GET_TOKEN_LEXICAl1(0);
			if (TKR.Token_048 == IF || TKR.Token_048 == DO_048 || TKR.Token_048 == VAR)
			{
				UNGET_TOKEN_LEXICAL();
				if ((stree = statement()) == NULL)   // NOT TRUE
					return NULL;

				stree->sibling = NULL;
				prevtree->sibling = stree;
				prevtree = stree;
			}
			else
			{
				UNGET_TOKEN_LEXICAL();
				break;
			}

		} while (1);
		//return true; // if , not, uid not equal then may be else
		return (stmttree);
	}
	return NULL; //otherwise false

}




//..........................tree structure..................................


treenode* statement()
{
	treenode* t1;
	treenode* tree;
	int r = 0;
	TKR = GET_TOKEN_LEXICAl1(0);
	if (TKR.Token_048 == VAR)
	{
		tree = new treenode;  // node for statement
		tree->nodek = stmtk;
		tree->stmtk = assignk;
		tree->name = TKR.Name_048;
		TKR = GET_TOKEN_LEXICAl1(0);
		if (TKR.Token_048 == EQUAL)
		{
			if (t1 = expression())
			{
				t1->name = "=";
				tree->leftchild = t1;
				tree->rightchild = NULL;
				tree->middlechild = NULL;
				tree->sibling = NULL;
				TKR = GET_TOKEN_LEXICAl1(0);
				if (TKR.Token_048 == SEMI_COLON)
					return  (tree);

			}
		}
	}
	else if (TKR.Token_048 == IF) {
		tree = new treenode;
		tree->nodek = stmtk;
		tree->stmtk = ifk;
		tree->name = "if";
		tree->token1 = TKR;
		TKR = GET_TOKEN_LEXICAl1(0);
		if (TKR.Token_048 == OPEN_BRACES) {
			TKR = GET_TOKEN_LEXICAl1(0);
			UNGET_TOKEN_LEXICAL();
			if (t1 = expression()) {
				tree->leftchild = t1;
				
				TKR = GET_TOKEN_LEXICAl1(0);
				if (TKR.Token_048 == CLOSE_BRACES) {
					TKR = GET_TOKEN_LEXICAl1(0);
					if (TKR.Token_048 == OPEN_BRACKET) {
						t1 = NULL;
						if (t1 = statement_list()) {
							tree->middlechild = t1;
							TKR = GET_TOKEN_LEXICAl1(0);
							if (TKR.Token_048 == CLOSE_BRACKET) {
								TKR = GET_TOKEN_LEXICAl1(0);
								if (TKR.Token_048 == ELSE) {
									t1 = NULL;
									if (t1 = statement_list()) {
										tree->rightchild = t1;
										TKR = GET_TOKEN_LEXICAl1(0);
										if (TKR.Token_048 == CLOSE_BRACKET) {
											return tree;
										}
									}
									
								}
								else {
									tree->rightchild = NULL;
									UNGET_TOKEN_LEXICAL();
									return tree;
								}
							}
						}
						else {
							tree->middlechild = NULL;
							tree->leftchild = NULL;
							return tree;
						}
					}
				}
			}
		}
	}
}


void recorder(Abdul_Ali_Token_Type tk) {
	tRecord[I_048] = tk;
}
Abdul_Ali_Token_Type* getrecord(int index) {
	return &tRecord[index];
}
void Token_Passing(string chk)
{
	sTable[J_048].Table_No_00 = J_048;
	sTable[J_048].Name_048 = chk;
	tRecord[J_048].Values_048 = 0;
	J_048++;
}
bool Check_048(string temp)
{
	for (int i = 0; i < J_048; i++)
	{
		if (temp == sTable[i].Name_048)
		{
			return false;
		}
	}
	return true;
}
Abdul_Ali_Token_Type Lexical_048(int i)
{
	char Charater_048; Abdul_Ali_Token_Type TR;
	while (file[i].get(Charater_048))
	{
		if (Charater_048 == ' ' || Charater_048 == '\n' || Charater_048 ==
			'\t')
		{
		}
		else if (isdigit(Charater_048))
		{
			string chk = ""; int temp;
			do
			{
				chk += Charater_048;
				file[i].get(Charater_048);
			} while (isdigit(Charater_048));
			file[i].putback(Charater_048);
			TR.Name_048 = "Digit";
			TR.words = "Digit";
			TR.Token_048 = NUM;
			temp = stoi(chk);
			TR.Values_048 = temp;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (isalpha(Charater_048) || Charater_048 == '_')
		{
			string chk = ""; bool flag = 0;
			do
			{
				chk += Charater_048;
				file[i].get(Charater_048);
			} while ((isalpha(Charater_048) || Charater_048 ==
				'_' || isdigit(Charater_048)) && !file[i].eof());
			file[i].putback(Charater_048);
			if (chk == "for")
			{
				TR.Name_048 = "for";
				TR.words = "loop";
				TR.Token_048 = FOR_048;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "while")
			{
				TR.Name_048 = "while";
				TR.words = "loop";
				TR.Token_048 = WHILE_048;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}

			else if (chk == "cout")
			{
				TR.Name_048 = "cout";
				TR.words = "print";
				TR.Token_048 = COUT;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "cin")
			{
				TR.Name_048 = "cin";
				TR.words = "Input";
				TR.Token_048 = CIN;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "new")
			{
				TR.Name_048 = "new";
				TR.words = "Dynamic Allocation";
				TR.Token_048 = NEW;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "if")
			{
				TR.Name_048 = "if";
				TR.words = "Condition";
				TR.Token_048 = IF;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "else")
			{
				TR.Name_048 = "else";
				TR.words = "Condition";
				TR.Token_048 = ELSE;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "elseif")
			{
				TR.Name_048 = "elseif";
				TR.words = "Condition";
				TR.Token_048 = ELSE_IF;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "do")
			{
				TR.Name_048 = "do";
				TR.words = "Loop";
				TR.Token_048 = DO_048;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "int")
			{
				TR.Name_048 = "int";
				TR.words = "Variable Type";
				TR.Token_048 = INT_048;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "string")
			{
				TR.Name_048 = "string";
				TR.words = "Variable Type";
				TR.Token_048 = STRING;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "begin")
			{
				TR.Name_048 = "begin";
				TR.words = "Variable Type";
				TR.Token_048 = BEGIN;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "end")
			{
				TR.Name_048 = "end";
				TR.words = "program end";
				TR.Token_048 = END;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "char")
			{
				TR.Name_048 = "char";
				TR.words = "Variable Type";
				TR.Token_048 = CHAR_048;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (chk == "float")
			{
				TR.Name_048 = "float";
				TR.words = "Variable Type";
				TR.Token_048 = FLOAT_048;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else
			{
				if (chk == "Check_048") {
					Token_Passing(chk);
				}
				TR.Name_048 = chk;
				TR.words = "Variable";
				TR.Token_048 = VAR;
				TR.Values_048 = 0;
				recorder(TR);
				return TR;
			}
		}
		else if (Charater_048 == '+')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '+')
			{
				TR.Name_048 = "+";
				TR.words = "Increment";
				TR.Token_048 = INCREMENT;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (Charater_048 == '=')
			{
				TR.Name_048 = "+=";
				TR.words = "Plus Equal";
				TR.Token_048 = PLUS_EQUAL;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else {
				file[i].putback(Charater_048);
				TR.Name_048 = "+";
				TR.words = "Plus";
				TR.Token_048 = PLUS;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
		}
		else if (Charater_048 == '-')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '-')
			{
				TR.Name_048 = "--";
				TR.words = "Decrement";
				TR.Token_048 = DECREMENT;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (Charater_048 == '=')
			{
				TR.Name_048 = "-=";
				TR.words = "Minus Equal";
				TR.Token_048 = MINUS_EQUAL;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else
			{
				file[i].putback(Charater_048);
				TR.Token_048 = MINUS;
				TR.words = "Minus";
				TR.Name_048 = "-";
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
		}
		else if (Charater_048 == '<')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '=')
			{
				TR.Name_048 = "<=";
				TR.words = "Less Than Or Equal To";
				TR.Token_048 = LESS_THAN_EQUAL_TO;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (Charater_048 == '<')
			{
				TR.Name_048 = "<<";
				TR.words = "Ostream";
				TR.Token_048 = OSTREAM;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else
			{
				file[i].putback(Charater_048);
				TR.Name_048 = "<";
				TR.words = "Less Than";
				TR.Token_048 = LESS_THAN;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
		}
		else if (Charater_048 == '>')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '=')
			{
				TR.Name_048 = ">=";
				TR.words = "Greater Than Equal To";
				TR.Token_048 = GREATER_THAN_EQUAL_TO;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else if (Charater_048 == '>')
			{
				TR.Name_048 = ">>";
				TR.words = "Istream";
				TR.Token_048 = ISTREAM;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else
			{
				file[i].putback(Charater_048);
				TR.Name_048 = ">";
				TR.words = "Greater Than";
				TR.Token_048 = GREATER_THAN;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
		}
		else if (Charater_048 == '!')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '=')
			{
				TR.Name_048 = "!=";
				TR.words = "Not Equal To";
				TR.Token_048 = NOT_EQUAL_TO;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else
			{
				file[i].putback(Charater_048);
				TR.Name_048 = "!";
				TR.words = "Not Operator";
				TR.Token_048 = EXCLAIMATION;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
		}
		else if (Charater_048 == ';')
		{
			TR.Name_048 = ";";
			TR.words = "Semi Colon";
			TR.Token_048 = SEMI_COLON;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == ':')
		{
			TR.Name_048 = ":";
			TR.words = "Colon";
			TR.Token_048 = COLON;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == '*')
		{
			TR.Name_048 = "*";
			TR.words = "Multiply";
			TR.Token_048 = MULTIPLY;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == '=')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '=')
			{
				TR.Name_048 = "==";
				TR.words = "Assignment";
				TR.Token_048 = ASSIGNMENT;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
			else
			{
				file[i].putback(Charater_048);
				TR.Name_048 = "=";
				TR.words = "Equal";
				TR.Token_048 = EQUAL;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
		}
		else if (Charater_048 == '(')
		{
			TR.Name_048 = "(";
			TR.words = "Open Braces";
			TR.Token_048 = OPEN_BRACES;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == ')')
		{
			TR.Name_048 = ")";
			TR.words = "Close Braces";
			TR.Token_048 = CLOSE_BRACES;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == '{')
		{
			TR.Name_048 = "{";
			TR.words = "Open Bracket";
			TR.Token_048 = OPEN_BRACKET;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == '}')
		{
			TR.Name_048 = "}";
			TR.words = "Close Bracket";
			TR.Token_048 = CLOSE_BRACKET;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == '[')
		{
			TR.Name_048 = "[";
			TR.words = "Open Square Bracket";
			TR.Token_048 = OPEN_SQUARE_BRACKET;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == ']')
		{
			TR.Name_048 = "]";
			TR.words = "Close Square Bracket";
			TR.Token_048 = CLOSE_SQUARE_BRCKET;
			TR.Values_048 = 0;
			recorder(TR);
			I_048++;
			return TR;
		}
		else if (Charater_048 == '|')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '|')
			{
				while (Charater_048 != '\n')
				{
					TR.Name_048 = "||";
					TR.words = "OR Operator";
					TR.Token_048 = OR;
					TR.Values_048 = 0;
					recorder(TR);
					I_048++;
					return TR;
				}
			}
		}
		else if (Charater_048 == '&')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '&')
			{
				while (Charater_048 != '\n')
				{
					TR.Name_048 = "&&";
					TR.words = "AND Operator";
					TR.Token_048 = AND;
					TR.Values_048 = 0;
					recorder(TR);
					I_048++;
				}
			}
		}
		else if (Charater_048 == '/')
		{
			file[i].get(Charater_048);
			if (Charater_048 == '/')
			{
				while (Charater_048 != '\n')
				{
					file[i].get(Charater_048);
				}
			}
			else if (Charater_048 == '*')
			{
				do {
					file[i].get(Charater_048);
				} while (Charater_048 != '*');
				if (Charater_048 == '/') {}
			}
			else
			{
				TR.Name_048 = "/";
				TR.words = "Divide";
				TR.Token_048 = DIVIDE;
				TR.Values_048 = 0;
				recorder(TR);
				I_048++;
				return TR;
			}
		}
		else
		{
			cout << Charater_048;
			return TR;
		}
	}
	return TR;
}
/*
void Tokendisplay()
{
cout << " ----------------------------" << endl;
cout << "|NAME" << " \t " << "TOKEN NO" << " \t" << "Value|" << endl;
cout << " ----------------------------" << endl;
for (int i = 0; i < I_048; i++)
{
cout << tRecord[i].Name_048 << "\t";
cout << tRecord[i].Token_048 << "\t";
cout << tRecord[i].Values_048 << endl;
}
}
*/
void DISPLAY_TOKEN_VALUE()
{
	cout << " ---------------" << endl;
	cout << "|SrNo#" << " \t" << "Name" << " \t|" << endl;
	cout << " ---------------" << endl;
	for (int i = 0; i < J_048; i++)
	{
		cout << sTable[i].Table_No_00 << "\t";
		cout << sTable[i].Name_048 << "\t";
		cout << endl;
	}
}
//Get Token Function 
Abdul_Ali_Token_Type GET_TOKEN_LEXICAl1(int i)
{
	if (!flag)
	{
		Abdul_Ali_Token_Type tk;
		tk = Lexical_048(i);
		Current_TKR = tk;
		return tk;
	}
	else
	{
		flag = 0;
		return Current_TKR;
	}
}
//UNGET Token Function 
void UNGET_TOKEN_LEXICAL()
{
	flag = 1;

}
// Parser Function Definations 

/*
bool E();
bool F();
bool T();
*/
//int main()
//{
//	if (file[i].is_open()) {
//		program();
//	}
//	else {
//		cout << "File Not found!";
//	}
//	//Abdul_Ali1();
//	//DISPLAY_TOKEN_VALUE();
//	system("pause");
//	return 0;
//}
bool Abdul_Ali1()
{
	TKR = GET_TOKEN_LEXICAl1(1);
	UNGET_TOKEN_LEXICAL();
		do
		{
			if (!Abdul_Ali2())
			{
				return false;
			}
			TKR = GET_TOKEN_LEXICAl1(1);
		} while (TKR.Token_048 == OR);
		
		
			UNGET_TOKEN_LEXICAL();
			return true;
		
	
}
bool Abdul_Ali2()
{
	do
	{
		if (!Abdul_Ali3())
		{
			return false;
		}
		TKR = GET_TOKEN_LEXICAl1(1);
	} while (TKR.Token_048 == AND);
	UNGET_TOKEN_LEXICAL();
	return true;
}
bool Abdul_Ali3()
{
	do
	{
		if (!Abdul_Ali4())
		{
			return false;
		}
		TKR = GET_TOKEN_LEXICAl1(1);
	} while (TKR.Token_048 == EQUAL || TKR.Token_048 == NOT_EQUAL_TO || TKR.Token_048 == GREATER_THAN_EQUAL_TO
		|| TKR.Token_048 == LESS_THAN_EQUAL_TO || TKR.Token_048 == PLUS_EQUAL || TKR.Token_048 == MINUS_EQUAL || TKR.Token_048 == ASSIGNMENT);
	UNGET_TOKEN_LEXICAL();
	return true;
}
bool Abdul_Ali4()
{
	do
	{
		if (!Abdul_Ali5())
			return false;
		TKR = GET_TOKEN_LEXICAl1(1);
	} while (TKR.Token_048 == GREATER_THAN || TKR.Token_048 == GREATER_THAN_EQUAL_TO ||
		TKR.Token_048 == LESS_THAN || TKR.Token_048 == LESS_THAN_EQUAL_TO);
	UNGET_TOKEN_LEXICAL();
	return true;
}
bool Abdul_Ali5()
{
	do
	{
		if (!Abdul_Ali6())
		{
			return false;
		}
		TKR = GET_TOKEN_LEXICAl1(1);
	} while (TKR.Token_048 == ISTREAM || TKR.Token_048 == OSTREAM);
	UNGET_TOKEN_LEXICAL();
	return true;
}
bool Abdul_Ali6()
{
	do
	{
		if (!Abdul_Ali7())
		{
			return false;
		}
		TKR = GET_TOKEN_LEXICAl1(1);
	} while (TKR.Token_048 == PLUS || TKR.Token_048 == MINUS);
	UNGET_TOKEN_LEXICAL();
	return true;
}
bool Abdul_Ali7()
{
	do
	{
		if (!Abdul_Ali8())
		{
			return false;
		}
		TKR = GET_TOKEN_LEXICAl1(1);
	} while (TKR.Token_048 == MULTIPLY || TKR.Token_048 == DIVIDE);
	UNGET_TOKEN_LEXICAL();
	return true;
}
bool Abdul_Ali8()
{
	TKR = GET_TOKEN_LEXICAl1(1);
	if (TKR.Token_048 == VAR || TKR.Token_048 == NUM)
	{
		return true;
	}
	else if (TKR.Token_048 == OPEN_BRACES)
	{
		if (Abdul_Ali1())
		{
			TKR = GET_TOKEN_LEXICAl1(1);
			if (TKR.Token_048 == CLOSE_BRACES)
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return false;
	}
}
bool if_t()
{
	TKR = GET_TOKEN_LEXICAl1(1);
	if (TKR.Token_048 == IF)
	{
		TKR = GET_TOKEN_LEXICAl1(1);
		if (TKR.Token_048 == OPEN_BRACES)
		{
			if (!Abdul_Ali1())
			{
				return false;
			}
			TKR = GET_TOKEN_LEXICAl1(1);
			if (TKR.Token_048 == CLOSE_BRACES)
			{
				TKR = GET_TOKEN_LEXICAl1(1);
				if (TKR.Token_048 == OPEN_BRACKET)
				{

					if (!FORMAT())
					{
						return false;
					}
					TKR = GET_TOKEN_LEXICAl1(1);
					if (TKR.Token_048 == CLOSE_BRACKET)
					{
						TKR = GET_TOKEN_LEXICAl1(1);
						if (TKR.Token_048 == ELSE)
						{
							TKR = GET_TOKEN_LEXICAl1(1);
							if (TKR.Token_048 == OPEN_BRACKET)
							{

								if (!FORMAT())
								{
									return false;
								}
								TKR = GET_TOKEN_LEXICAl1(1);
								if (TKR.Token_048 == CLOSE_BRACKET)
								{
									return true;
								}

							}




						}
						else
						{
							UNGET_TOKEN_LEXICAL();
							return true;
						}
					}

				}
			}
		}
	}
	return false;
}

bool do_while()
{
	TKR = GET_TOKEN_LEXICAl1(1);
	if (TKR.Token_048 == DO_048)
	{
		TKR = GET_TOKEN_LEXICAl1(1);
		if (TKR.Token_048 == OPEN_BRACKET)
		{
			if (!Statementlist())
			{
				return true;
			}
			TKR = GET_TOKEN_LEXICAl1(1);
			if (TKR.Token_048 == CLOSE_BRACKET)
			{
				TKR = GET_TOKEN_LEXICAl1(1);
				if (TKR.Token_048 == WHILE_048)
				{
					TKR = GET_TOKEN_LEXICAl1(1);
					if (TKR.Token_048 == OPEN_BRACES)
					{
						if (!PARSERCHECHER())
						{
							return false;
						}
						TKR = GET_TOKEN_LEXICAl1(1);
						if (TKR.Token_048 == CLOSE_BRACES)
						{
							TKR = GET_TOKEN_LEXICAl1(1);
							if (TKR.Token_048 == SEMI_COLON)
							{
								return true;
							}
							return  false;
						}
					}
				}
			}
		}
	}
	return false;
}

bool while_t()
{
	TKR = GET_TOKEN_LEXICAl1(1);
	if (TKR.Token_048 == WHILE_048)
	{
		TKR = GET_TOKEN_LEXICAl1(1);
		if (TKR.Token_048 == OPEN_BRACES)
		{
			if (!PARSERCHECHER())
			{
				return false;
			}
			TKR = GET_TOKEN_LEXICAl1(1);
			if (TKR.Token_048 == CLOSE_BRACES)
			{
				TKR = GET_TOKEN_LEXICAl1(1);
				if (!Statement())
				{
					return false;
				}
				TKR = GET_TOKEN_LEXICAl1(1);
				if (TKR.Token_048 == CLOSE_BRACKET)
				{
					return true;
				}

			}
		}
	}
	return false;
}

bool Program()
{
	TKR = GET_TOKEN_LEXICAl1(1);
	if (TKR.Token_048 == BEGIN)
	{
		if (Statementlist())
		{
			TKR = GET_TOKEN_LEXICAl1(1);
			if (TKR.Token_048 == END)
			{
				return true;
			}
		}
	}
	return false;
}
bool Statementlist()
{

	if (Statement())
	{
		while (true)
		{
			TKR = GET_TOKEN_LEXICAl1(1);
			if (TKR.Token_048 == IF || TKR.Token_048 == DO_048 || TKR.Token_048 == VAR || TKR.Token_048 == WHILE_048)
			{
				UNGET_TOKEN_LEXICAL();
				if (!Statement())
				{
					return false;
				}
			}
			else
			{
				UNGET_TOKEN_LEXICAL();
				break;
			}
		}
		return true;
	}
	return false;
}

bool Statement()
{
	
		TKR = GET_TOKEN_LEXICAl1(1);
		if (TKR.Token_048 == VAR)
		{
			UNGET_TOKEN_LEXICAL();
			return FORMAT();
		}
		if (TKR.Token_048 == NUM) {
			UNGET_TOKEN_LEXICAL();
			return Abdul_Ali1();
		}
		if (TKR.Token_048 == IF)
		{
			UNGET_TOKEN_LEXICAL();
			return if_t();
		}
		if (TKR.Token_048 == DO_048)
		{
			UNGET_TOKEN_LEXICAL();
			return do_while();
		}
		if (TKR.Token_048 == WHILE_048)
		{
			UNGET_TOKEN_LEXICAL();
			return while_t();
		}
		
			
		
	

	return false;
}
bool parserstart() {
	TKR = GET_TOKEN_LEXICAl1(1);
	if (TKR.Token_048 == BEGIN)
	{
		if (PARSERCHECHER()) {
			TKR = GET_TOKEN_LEXICAl1(1);
			if (TKR.Token_048 == END) {
				return true;
			}
		}
		else
			return false;
	}
	else
		return false;
}
bool FORMAT()
{
	TKR = GET_TOKEN_LEXICAl1(1);
	if (TKR.Token_048 == VAR)
	{
		TKR = GET_TOKEN_LEXICAl1(1);
		if (TKR.Token_048 == EQUAL)
		{
			if (PARSERCHECHER())
			{
				TKR = GET_TOKEN_LEXICAl1(1);
				if (TKR.Token_048 == SEMI_COLON)
				{

					
							
							return true;
						
					
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool PARSERCHECHER()
{
	return Statementlist();
}



void Tree() {
	while (TKR.Token_048 != NUM) {
		TKR = GET_TOKEN_LEXICAl1(0);
	}
	UNGET_TOKEN_LEXICAL();
	treenode* F = expression();
	

}

treenode* program()
{
	treenode* fulltree;
	TKR = GET_TOKEN_LEXICAl1(0);
	TKR = GET_TOKEN_LEXICAl1(0);
	if (TKR.Token_048 == BEGIN)
	{
		if ((fulltree = statement_list()) != NULL)
		{
			
			TKR = GET_TOKEN_LEXICAl1(0);
			if (TKR.Token_048 == END) {
				return fulltree;
			}
		}
	}
	return false;

}
