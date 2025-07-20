//Name: Rodrigo Molero
//Unumber: 72733446
//Description: contains the main function

#include <stdio.h>
#include "debt.h"
#include "read_line.h"

int main(void)
{
  char code;

  struct debt *debt_list = NULL;  
  printf("Operation Code: a for adding to the list, d for deleting the first debt, s"
         "for searching, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) { //switch between the different operation codes
      case 'a': debt_list = add_to_list(debt_list);
                break;
      case 's': search_list(debt_list);
                break;
      case 'd': debt_list=delete_first(debt_list);
		break;
      case 'p': print_list(debt_list);
                break;
      case 'q': clear_list(debt_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

