#pragma once

#define	Operator			0
#define	Digit					1

typedef struct _TOKEN
{
	char Type;
	union _Attribute
	{
		char Lexval;			//¥ Àÿ
		int Value;				//÷µ
	}Attribute;
}TOKEN, * PTOKEN;

typedef struct _SYMBOLNODE
{
	int id;
	TOKEN token;
	_SYMBOLNODE* Next;
}SYMBOLNODE, *PSYMBOLNODE;

class LexicalAnalyzer
{
public:
	LexicalAnalyzer(CString LexicalString);
	~LexicalAnalyzer();
	TOKEN GetNextToken();


	PSYMBOLNODE	SymbolTableHeader;

private:
	char SliceACharater();
	int GetTokenId();
	void InsertNodeToSymbolTable(PSYMBOLNODE pSymbolNode);

	CString		m_LexicalString;
	static int m_IdValue;
};

int LexicalAnalyzer::m_IdValue = 0;
