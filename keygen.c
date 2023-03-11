#include <stdlib.h>
#include <string.h>

__declspec(dllexport) void genSpec(const char *szUpperName, unsigned char *spec, int maxCopies)
{
	static const char table[] = {0x5D, 0x22, 0x4F, 0x4E, 0xFC};
	static const char table2[] = {2, 3, 5, 8, 9};
	unsigned char t[5];
	int len = strlen(szUpperName);
	spec[0] = t[0] = rand() % 256;
	spec[1] = t[1] = rand() % 256;
	spec[4] = t[2] = maxCopies >= 0 && maxCopies <= 255? maxCopies ^ t[0] : rand() % 256;
	spec[6] = t[3] = rand() % 256;
	spec[7] = t[4] = rand() % 256;
	for (int i = 0; i < 5; ++i)
	{
		unsigned char loc7 = table[i];
		for (int j = 0; j < len; ++j)
			loc7 += (t[(j + i) % 5] + i * 0x11) | szUpperName[j];
		spec[table2[i]] = loc7;
	}
}

__declspec(dllexport) void genCode(unsigned char *code, const unsigned char *spec)
{
	static const char table[] = "Y5E7UZ9XP23QWKMN6A+TSC!4VFGHJR-D";
	code[0] = table[spec[0] & 0x1F];
	code[1] = table[spec[0] >> 5 | (spec[1] & 3) << 3];
	code[2] = table[(spec[1] & 0x7F) >> 2];
	code[3] = table[spec[1] >> 7 | (spec[2] & 0xF) << 1];
	code[4] = table[spec[2] >> 4 | (spec[3] & 1) << 4];
	code[5] = table[(spec[3] & 0x3F) >> 1];
	code[6] = table[spec[3] >> 6 | (spec[4] & 7) << 2];
	code[7] = table[spec[4] >> 3];
	code[8] = table[spec[5] & 0x1F];
	code[9] = table[spec[5] >> 5 | (spec[6] & 3) << 3];
	code[10] = table[(spec[6] & 0x7F) >> 2];
	code[11] = table[spec[6] >> 7 | (spec[7] & 0xF) << 1];
	code[12] = table[spec[7] >> 4 | (spec[8] & 1) << 4];
	code[13] = table[(spec[8] & 0x3F) >> 1];
	code[14] = table[spec[8] >> 6 | (spec[9] & 7) << 2];
	code[15] = table[spec[9] >> 3];
	code[16] = '\0';
}