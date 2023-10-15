/*
registration.c - Dangfer
The main code of Registration.

Some redundant and thunk code have been discarded. The code can have a further
optimization, but it may cause obfuscation when you read the assembly code, so
I take a version more close to the origin. It's succinct enough, and is easy to
match the assembly code.
*/

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum {
	PROD_POLY,
	PROD_POLYPRO,
	PROD_GRAFEQ,
	PROD_TESS,
} PRODUCT;


uint8_t feature[5];

/**
 * trim and uppercase the string. only trim spaces.
 * @return an allocated string
 */
static char *strtrimupr(const char *str)
{
	str += strspn(str, " ");
	const char *p;
	for (p = str + strlen(str) - 1; *p == ' '; --p);
	size_t len = p - str + 1;
	char *s = malloc(len + 1);
	memcpy(s, str, len);
	s[len] = '\0';
	return strupr(s);
}

/**
 * get the char's index from the table
 * @return index
 */
static uint8_t mapping(char c)
{
	static const char table[] = "Y5E7UZ9XP23QWKMN6A+TSC!4VFGHJR-D";
	c = toupper(c);
	for (unsigned a = 0; a < 0x20; ++a)
		if (c == table[a])
			return a;
	return 0;
}

static void gen_spec(const char *code, uint8_t *spec)
{
	uint32_t a = 0x50, c = 0, j = 0, k = 0, v=0;
	do {
		int i = (27 - c) / 5 + 1;
		c += i * 5;
		for (; i; --i) {
			v = mapping(code[j++]) << 27 | v >> 5;
			a -= 5;
		}
		for (int i = c >> 3; i; --i) {
			spec[k++] = v >> (0x20 - c);
			c -= 8;
		}
	} while (a);
}

static bool check_spec(const char *tuname, uint8_t *spec, PRODUCT prod)
{
	static const uint8_t prod_magic[][5] = {
		{0xC4, 0x19, 0x4D, 0x4E, 0x03}, // poly
		{0x3E, 0x1C, 0x65, 0xDE, 0x7E}, // poly pro
		{0x5D, 0x22, 0x4F, 0x4E, 0xFC}, // grafeq
		{0x6D, 0xF3, 0x5C, 0x09, 0x61}, // tess
	};
	static const uint8_t map[] = {2, 3, 5, 8, 9};
	uint8_t t[] = {spec[0], spec[1], spec[4], spec[6], spec[7]};
	int len = strlen(tuname);
	for (int i = 0; i < 5; ++i) {
		uint8_t m = prod_magic[prod][i];
		for (size_t j = 0; j < len; ++j)
			m += (t[(i + j) % 5] + i * 17) | tuname[j];
		if (spec[map[i]] != m) // registeration failed
			return false;
	}
	/* register successfully */
	*(uint32_t*)feature = *(uint32_t*)t;
	feature[4] = t[4];
	return true;
}

/* main function */
bool verify(const char *name, const char *code, PRODUCT prod)
{
	char *tuname = strtrimupr(name);
	char *tucode = strtrimupr(code);
	uint8_t spec[10];
	bool b = false;
	if (strlen(tucode) == 16) {
		gen_spec(code, spec);
		b = check_spec(tuname, spec, prod);
	}
	free(tucode);
	free(tuname);
	return b;
}

/*
short copies;

void Sub(void)
{
	// ...
	copies = feature[0] ^ feature[2];
	// ...
}
*/