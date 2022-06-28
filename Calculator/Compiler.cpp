#include "pch.h"
#include "Compiler.h"

Compiler::Compiler(CString InputString)
{
	m_CompileString = new char[InputString.GetLength()];
	m_CompileString = (LPSTR)(LPCTSTR)InputString;
	TRACE(m_CompileString);
}
Compiler::~Compiler()
{
}
