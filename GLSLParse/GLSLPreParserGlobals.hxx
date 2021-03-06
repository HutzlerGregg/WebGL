//--------------------------------------------------------------
//
// Microsoft Edge Implementation
// Copyright(c) Microsoft Corporation
// All rights reserved.
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files(the ""Software""),
// to deal in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
// OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//--------------------------------------------------------------
#pragma once

// Defined in GLSLPreParser.cxx, used to avoid including PreParser.hxx in flex output
int GLSLPreInput(__in CGLSLPreParser* pOutput, __out_ecount(1) char* buf, int max_size);
void GLSLPreUpdateLocation(__in CGLSLPreParser* pParser, __in YYLTYPE* pLocation, int lineNo, int tokenLength);

// Input handling
#define YY_INPUT(buf, result, max_size) { result = GLSLPreInput(yyextra, buf, max_size); }

// Location tracking
#define YY_USER_ACTION GLSLPreUpdateLocation(yyextra, yylloc, yylineno, yyleng);

// Error handling
void GLSLPreerror(__in YYLTYPE* pLocation, yyscan_t scanner, __in_z_opt const char* error);

extern "C" int GLSLPrewrap(yyscan_t scanner);
