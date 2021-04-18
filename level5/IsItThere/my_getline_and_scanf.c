/* if *n == 0 && *lineptr == NULL: getline will allocate memory for lineptr and put the length into n
 * otherwise (i.e. *n > 0): getline assumes lineptr is already allocated to length of n
 */
int getline(char **lineptr, unsigned int *n, int fd) {
	if (*n == 0 && *lineptr == NULL) {
		// allocate *lineptr
	}
}

// if fscanf returns -1 then you supplied wrong format
// NOTICE: this is not a bi-implication.
// NOTE: please do not use this code...like, ever.
int fscanf(int fd, const char *format, ...) {
	va_list argp;
	va_start(argp, format);

	// TODO: still need that malloc bruh...
	//char wtf[10240]; // "what to [look] for" ofc

	// "%d:%d %s"
	// fscanf(fp, "%d:%d %s", &n, &m, str) where str is type: char * || const char *
	// e.g. "5:6 mystringhere"

	// "%d:%d"
	// e.g. "5:6 7:11 9:12"

	// TODO: implement contract: max_size is at least strlen(format)
	const size_t max_size = 1000000; //TODO: figure out a good size for buffer
	char file_buffer[max_size] = {0};
	read(fd, file_buffer, max_size);
	
	int format_idx = 0;
	int buffer_idx = 0;
	while (file_buffer[buffer_idx] != '\0') {
		if (format[format_idx] == '%') {
			format_idx++;
			if (format[format_idx] == '%') {
				format_idx++;
				// we are looking for a literal %
			} else if (format[format_idx] == 's') {
				format_idx++;

				// we take in a string i.e. read characters until whitespace occurs
				char *str = va_arg(argp, char*);
				while (file_buffer[buffer_idx] != ' ' && file_buffer[buffer_idx] != '\t') {
					*str = file_buffer[buffer_idx];
					str++;
					buffer_idx++;
				}
				*str = '\0'
			} else if (format[format_idx] == 'd') {
				format_idx++;

				int *num = va_arg(argp, int*);

				int is_neg = 0;
				if (file_buffer[buffer_idx] == '-') {
					is_neg = 1;
					buffer_idx++;
				}
				
				int sum = 0; // naming convention: b/c you want to eat a lot of apple sauce and a SUM is made up of lots of operands
				while (file_buffer[buffer_idx] <= '9' && file_buffer[buffer_idx] >= '0') {
					int current_char_value = file_buffer[buffer_idx] - '0';
					sum *= 10;
					sum += current_char_value;
					buffer_idx++;
				}
				*num = isneg ? -sum : sum;
			} else { // If we get here that means we have been supplied an incorrect format
				return -1; }
		} else {
			format_idx++;
		}
	}
	va_end(argp);
	return 0;
}
