#include <afxstr.h>
#include<iostream>
#include "../Calculator/LexicalAnalyzer.h"
#include <tchar.h>

int main()
{
	while (true)
	{
		LexicalAnalyzer lexicalAnalyzer(_T("1+2*34-8"));
		lexicalAnalyzer.GetNextToken();
	}

	return 0;
}