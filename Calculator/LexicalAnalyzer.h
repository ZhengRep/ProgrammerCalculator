#pragma once

#define	Operator			0
#define	Digit					1

typedef struct _TOKEN
{
	char Type;
	union Attribute
	{
		int Value;			//ֵ
		char Lexval;	//����
	};
	_TOKEN* Next;
}TOKEN, * PTOKEN;

class LexicalAnalyzer
{
public:
	LexicalAnalyzer(CString LexicalString);
	~LexicalAnalyzer();
	TOKEN GetNextToken();
	CString SliceACharater();

private:
	PTOKEN	SymbolTable;
	CString		m_LexicalString;

};

