/*
The main code of Registration.

Some redundant code have been discarded, like some judgements have already 
taken in parent routine. The code can have a further optimization, but it may 
cause obfuscation when you read the assembly code, so I take a version more 
close to the origin. It's succint enough, and is easy to match the assembly 
code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/* function prototype */
char *TrimUpper(const char *str);
/* return a new string, which is trimmed and is converted to uppercase. */

/* global variable declaration */
unsigned success[1];

unsigned map(char c)
{
	static const char table[] = "Y5E7UZ9XP23QWKMN6A+TSC!4VFGHJR-D";
	c = toupper(c);
	for (unsigned a = 0; a < 0x20; ++a)
		if (c == table[a])
			return a;
	return 0;
}

void func1(const char *szCode, unsigned char *spec)
{
	unsigned a = 0x50, b = 0, c = 0, i = 0, j = 0x50;
	do
	{
		unsigned k = (0x1B - i) / 5 + 1;
		i += k * 5;
		for (; k; --k)
		{
			j = map(szCode[c++]) << 0x1B | j >> 5;
			a -= 5;
		}
		for (unsigned l = i >> 3; l; --l)
		{
			spec[b++] = j >> (0x20 - i);
			i -= 8;
		}
	} while (a > 0);
}

bool func2(const char *szUpperName, unsigned char *spec)
{
	static const char table[] = {0x5D, 0x22, 0x4F, 0x4E, 0xFC};
	static const char table2[] = {2, 3, 5, 8, 9};
	unsigned char t[5] = {spec[0], spec[1], spec[4], spec[6], spec[7]};
	int len = strlen(szUpperName);
	for (unsigned i = 0; i < 5; ++i)
	{
		unsigned char v = table[i];
		char *p = (char*)szUpperName;
		for (unsigned j = len; j; --j)
		{
			int d4 = ((unsigned)p++ + i - (unsigned)szUpperName) % 5;
			v += (t[d4] + i * 0x11) | p[-1];
		}
		if (spec[table2[i]] != v)
			return false;
	}
	/* register successfully */
	success[0] = *(unsigned*)t;
	success[1] = t[4];
	return true;
}

bool Register(const char *szName, const char *szCode)
{
	char *szTUName = TrimUpper(szName);
	char *szTUCode = TrimUpper(szCode);
	unsigned char spec[10];
	bool r = false;
	if (strlen(szTUCode) == 16)
	{
		func1(szCode, spec);
		r = func2(szTUName, spec);
	}
	free(szTUCode);
	free(szTUName);
	return r;
}