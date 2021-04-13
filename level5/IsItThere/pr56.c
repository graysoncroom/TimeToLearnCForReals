#include <unistd.h> //read, for example
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //open

const char *filename = "pr56.dat";

#define EXIT_CODE_ERR -1

// contract: str must be NULL terminated
int strlen(const char *str) {
	int count = 0;
	for (int i=0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}

void err(const char *str) {
	write(2, str, strlen(str));
}

void printn(const char *str, int n) {
	write(1, str, n);
}

void printnln(const char *str, int n) {
	printn(str, n);
	printn("\n", 1);
}

void print(const char *str) {
	printn(str, strlen(str));
}

void println(const char *str) {
	print(str);
	print("\n");
}

void errln(const char *str) {
	err(str);
	err("\n");
}

int stoi(const char *str) {
	int sum = 0;
	int is_negative = 0;
	int i = 0;

	if (str[0] == '-') {
		str++;
		is_negative = 1;
	}

	while (str[i] != '\0') {
		int current_digit = str[i] - '0';
		sum *= 10;
		sum += current_digit;
		i++;
	}

	return is_negative ? -sum : sum;
}

void get_nth_word(const char *buf, int s_idx, int e_idx, int nth, char *word) {
	int word_idx = 0;

	char not_there_str[] = "NOT THERE";

	if (nth < 0) {
		for (int i=0; not_there_str[i] != '\0'; i++) {
			word[i] = not_there_str[i];
		}
		return;
	}

	while (s_idx < e_idx && word_idx != nth) {
		if (buf[s_idx] == ' ') {
			word_idx++;
		}
		else if (buf[s_idx] == '\n') {
			word_idx++;
			if (word_idx > nth) {
				for (int i=0; not_there_str[i] != '\0'; i++) {
					word[i] = not_there_str[i];
				}
				return;
			}
		}
		s_idx++;
	}
	int i = 0;
	while (buf[s_idx] != ' ') {
		word[i] = buf[s_idx];
		i++;
		s_idx++;
	}
}

struct pair {
	int start_index;
	int end_index;
};

struct input_group {
	struct pair str_pair;
	char num_str[20];
};

int main(int argc, char **argv) {
	const int fd = open(filename, O_RDONLY);

	if (fd == -1) {
		return EXIT_CODE_ERR;
	}

	struct stat sb;
	fstat(fd, &sb);

	if (sb.st_size > 90000000) { // TODO: multiple of 2 at some point
		errln("I refuse.");
	}

	//char *buffer = malloc(sb.st_size);
	char buffer[sb.st_size];

	if (!buffer) {
		close(fd);
		return EXIT_CODE_ERR;
	}

	// TODO: err check the read
	read(fd, buffer, sb.st_size);


	int input_groups_size = sb.st_size / 2 + 1;
	struct input_group input_groups[input_groups_size];

	int start_index = 0;
	int current_input_group_elm_index = 0;
	for (int i=0; i<sb.st_size; i++) {
		if (buffer[i] == '\n') {
			struct input_group current_input_group = {{0,0}, {0}};
			struct pair current_pair;
			current_pair.start_index = start_index;
			current_pair.end_index = i - 1; // i-1 b/c you are at the newline rn
			current_input_group.str_pair = current_pair;

			// i is at newline index on prev line
			i++;
			
			int j=0;
			while (buffer[i+j] != '\n') {
				current_input_group.num_str[j] = buffer[i+j];
				j++;
			}
			i += j;
			start_index = i + 1;
			input_groups[current_input_group_elm_index++] = current_input_group;
		}
	}

	int total_input_groups = current_input_group_elm_index;

	for (int i=0; i<total_input_groups; i++) {
		struct input_group current_input_group = input_groups[i];
		int n = stoi(current_input_group.num_str);

		//printnln(buffer + current_input_group.str_pair.start_index, 
		//		current_input_group.str_pair.end_index - current_input_group.str_pair.start_index + 1);

		char word[100] = {0};

		get_nth_word(buffer, current_input_group.str_pair.start_index, 
				current_input_group.str_pair.end_index, n, word);

		println(word);
	}

	//free(buffer);
	close(fd);

	return 0;
}

