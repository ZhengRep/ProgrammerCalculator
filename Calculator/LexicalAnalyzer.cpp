#include "pch.h"
#include "LexicalAnalyzer.h"

int LexicalAnalyzer::m_IdValue = 0;

LexicalAnalyzer::LexicalAnalyzer(CString LexicalString)
{
	m_LexicalString = LexicalString;
}

LexicalAnalyzer::~LexicalAnalyzer()
{
}

PTOKEN LexicalAnalyzer::GetNextToken()
{
	//Add Token to SymbolTable
	PTOKEN ptoken = new TOKEN;
	PSYMBOLNODE psymbolNode = new SYMBOLNODE;
	char character = SliceACharater();
	if (!isdigit(character))
	{
		ptoken->Type = Operator;
		//recognize * / + - £¨ £©
		switch (character)
		{
		case '*':
		{
			ptoken->Attribute.Lexval = '*';
			break;
		}
		case '/':
		{
			ptoken->Attribute.Lexval = '/';
			break;
		}
		case '-':
		{
			ptoken->Attribute.Lexval = '-';
			break;
		}
		case '+':
		{
			ptoken->Attribute.Lexval = '+';
			break;
		}
		case '(':
		{
			ptoken->Attribute.Lexval = '(';
			break;
		}
		case ')':
		{
			ptoken->Attribute.Lexval = ')';
			break;
		}
		default:

			break;
		}
	}
	else
	{
		ptoken->Type = Digit;
		int v = 0;
		char peek = (char)(LPCTSTR) m_LexicalString.Left(1);
		while (isdigit(peek))
		{
			v *= 10;
			v += atoi((const char*)character);
			character = SliceACharater();
		}
		ptoken->Attribute.Value = v;
	}
	psymbolNode->id = GetTokenId();
	psymbolNode->token = ptoken;
	psymbolNode->Next = nullptr;
	InsertNodeToSymbolTable(psymbolNode);
	return ptoken;
}

char* LexicalAnalyzer::SliceACharater()
{
	if (!m_LexicalString.GetLength()) return '!'; //ÓÃ¸ÐÌ¾×Ö·û
	CStringA str(m_LexicalString.Left(1));	
	m_LexicalString.Delete(0, 1);
	const char* str2 = str;
	return str2;
}

int LexicalAnalyzer::GetTokenId()
{
	return ++m_IdValue;
}

void LexicalAnalyzer::InsertNodeToSymbolTable(PSYMBOLNODE pSymbolNode)
{
	PSYMBOLNODE p = SymbolTableHeader;
	while (p  && p->Next) p = p->Next;
	p->Next = pSymbolNode;
}
