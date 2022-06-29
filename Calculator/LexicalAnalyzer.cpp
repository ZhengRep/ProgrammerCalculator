#include "pch.h"
#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(CString LexicalString)
{
	m_LexicalString = LexicalString;
}

LexicalAnalyzer::~LexicalAnalyzer()
{
}

TOKEN LexicalAnalyzer::GetNextToken()
{
	//Add Token to SymbolTable
	TOKEN token;
	SYMBOLNODE symbolNode;
	char character = SliceACharater();
	if (!isdigit(character))
	{
		token.Type = Operator;
		//recognize * / + - £¨ £©
		switch (character)
		{
		case '*':
		{
			token.Attribute.Lexval = '*';
			break;
		}
		case '/':
		{
			token.Attribute.Lexval = '/';
			break;
		}
		case '-':
		{
			token.Attribute.Lexval = '-';
			break;
		}
		case '+':
		{
			token.Attribute.Lexval = '+';
			break;
		}
		case '(':
		{
			token.Attribute.Lexval = '(';
			break;
		}
		case ')':
		{
			token.Attribute.Lexval = ')';
			break;
		}
		default:

			break;
		}
	}
	else
	{
		token.Type = Digit;
		int v = 0;
		char peek = (char)(LPCTSTR) m_LexicalString.Left(1);
		while (isdigit(peek))
		{
			v *= 10;
			v += atoi((const char*)character);
			character = SliceACharater();
		}
		token.Attribute.Value = v;
	}
	symbolNode.id = GetTokenId();
	symbolNode.token = token;
	symbolNode.Next = nullptr;
	InsertNodeToSymbolTable(&symbolNode);
	return token;
}

char LexicalAnalyzer::SliceACharater()
{
	if (!m_LexicalString.GetLength()) return '!'; //ÓÃ¸ÐÌ¾×Ö·û
	CString str(m_LexicalString.Left(1));	
	m_LexicalString.Delete(0, 1);
	return (char)(LPCTSTR)str;
}

int LexicalAnalyzer::GetTokenId()
{
	return ++m_IdValue;
}

void LexicalAnalyzer::InsertNodeToSymbolTable(PSYMBOLNODE pSymbolNode)
{
	PSYMBOLNODE p = SymbolTableHeader;
	while (!p->Next) p = p->Next;
	p->Next = pSymbolNode;
}
