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
	char character = SliceACharater();
	//char peek = (char)(m_LexicalString.Left(1)); //No Analysize Lexical Error e.g. ** (*, later to sytax analysize
	/*switch (character)
	{
	case :
	{

		break;
	}
	default:
		break;
	}*/

	
}

char LexicalAnalyzer::SliceACharater()
{
	/*if (m_LexicalString) return ;
	CString str(m_LexicalString.Left(1));	
	m_LexicalString.Delete(0, 1);
	return str;*/
	
}