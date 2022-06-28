#include "pch.h"
#include "Compiler.h"

Compiler::Compiler(CString InputString)
{
	m_CompileString = new char[InputString.GetLength()];
	sprintf(m_CompileString, "%s", InputString);
	TRACE(m_CompileString);
}
Compiler::~Compiler()
{
}
