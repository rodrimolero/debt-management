//header file that contains struct debt declaration and prototypes for the functions in debt.c

#ifndef DEBT_H
#define DEBT_H

#define NAME_LEN 30

struct debt{
	char company[NAME_LEN+1]; //data stored in the structure
	double balance;
	double minimum;
	double interest_rate;
	struct debt *next; //pointer to the next node
};

struct debt *add_to_list(struct debt *list);
struct debt *delete_first(struct debt *list);
void search_list(struct debt *list);
void print_list(struct debt *list);
void clear_list(struct debt *list);
int read_line(char str[], int n);

#endif
