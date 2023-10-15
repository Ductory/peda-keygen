#if __STDC_VERSION__ < 199901L || defined(__TINYC__)
#define STATIC
#else
#define STATIC static
#endif

#ifdef _COMPILE_CLI
#include <stdio.h>
#include <time.h>
#define GC_API static
#else
#define GC_API __stdcall
#endif

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum {
	PROD_POLY,
	PROD_POLYPRO,
	PROD_GRAFEQ,
	PROD_TESS
} PRODUCT;

#define randbyte() (rand() % 256)

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

static void gen_spec(const char *name, uint8_t spec[STATIC 10], PRODUCT prod, int copies)
{
	static const uint8_t prod_magic[][5] = {
		{0xC4, 0x19, 0x4D, 0x4E, 0x03}, // poly
		{0x3E, 0x1C, 0x65, 0xDE, 0x7E}, // poly pro
		{0x5D, 0x22, 0x4F, 0x4E, 0xFC}, // grafeq
		{0x6D, 0xF3, 0x5C, 0x09, 0x61}  // tess
	};
	static const uint8_t map[] = {2, 3, 5, 8, 9};
	char *tuname = strtrimupr(name);
	size_t len = strlen(tuname);
	spec[0] = randbyte();
	spec[1] = randbyte();
	spec[4] = copies >> 8 ? randbyte() : copies ^ spec[0];
	spec[6] = randbyte();
	spec[7] = randbyte();
	uint8_t t[] = {spec[0], spec[1], spec[4], spec[6], spec[7]};
	for (int i = 0; i < 5; ++i) {
		uint8_t m = prod_magic[prod][i];
		for (size_t j = 0; j < len; ++j)
			m += (t[(i + j) % 5] + i * 17) | tuname[j];
		spec[map[i]] = m;
	}
	free(tuname);
}

/* main function */
GC_API void gen_code(const char *name, char code[STATIC 17], PRODUCT prod, int copies)
{
	static const char table[] = "Y5E7UZ9XP23QWKMN6A+TSC!4VFGHJR-D";
	uint8_t spec[10];
	gen_spec(name, spec, prod, copies);
	for (int i = 0; i < 16; ++i) {
		int a = i * 5 >> 3, b = i * 5 & 7;
		code[i] = table[(spec[a] >> b | spec[a + 1] << (8 - b)) & 0x1F];
	}
	code[16] = '\0';
}

/* CLI interface */
#ifdef _COMPILE_CLI
static const char STR_HELP[] = "Pedagoguery Software KeyGen - Made by Dangfer\n";
static const char STR_NAME[] = "please input your name(1~255 bytes):";
static const char STR_PROD[] =
	"please input the product:\n"
	"\t0: Poly, 1: Poly Pro, 2: GrafEq, 3: Tess";
static const char STR_COPIES[] = 
	"please input the maximum number of copies:\n"
	"\t0 and 1: for use on one computer\n"
	"\t2 to 254: for use on up to N computers within the licensed site\n"
	"\t255: for use on all computers within the licensed site\n"
	"\totherwise: generate the number randomly";

int main(void)
{
	srand((unsigned)time(NULL));
	puts(STR_HELP);

	char name[256];
	puts(STR_NAME);
	scanf("%256s", name);
	int prod;
	puts(STR_PROD);
	scanf("%d", &prod);
	int copies;
	puts(STR_COPIES);
	scanf("%d", &copies);
	char code[17];
	gen_code(name, code, prod, copies);
	printf("code: %s\n", code);
}
#endif
