#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char * filename = "pr22.dat";

bool isVowel(char);

/* Read in a string and determine if the last
 * letter of the string is a vowel. Print
 * out "Vowel" or "No Vowel". AEIOU are
 * considered vowels.
 */

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int input_line_count;
	fscanf(fp, "%i", &input_line_count);

	char line_text[100];
	for (int i=0; i<input_line_count; i++) {
		fscanf(fp, "%s", &line_text);

		// get the last character in the string
		size_t line_text_char_count = strlen(line_text);
		char last_char = line_text[line_text_char_count-1];

		printf("%s\n", isVowel(last_char) ? "Vowel" : "No Vowel");
	}
}

// assumes all characters are printable besides '\0' kinda
bool isVowel(char x) {
	// make x uppercase if it is lowercase
	if (x >= 'a') { x -= 32; }

	switch (x) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
			break;
		default:
			return false;
	}
}

