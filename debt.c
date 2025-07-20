//Name: Rodrigo Molero
//Unumber:72733446
//description: all functions related to operations on the list of students

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debt.h"

struct debt *add_to_list(struct debt *list){ //function to add to the list
  struct debt *new_node; //pointer to the new node that is going to be added to the list and that is going to include the details
  new_node = malloc(sizeof(struct debt)); //create space and print an error if it wasn't possible
  if (new_node == NULL) {
    printf("malloc failed in add_to_list\n");
    return list;
  }
  new_node->next = NULL;
  printf("Enter company name: ");
  read_line(new_node->company, NAME_LEN); //store the company, balance, etc. in the attributes of the new structure node
  printf("Enter balance: ");
  scanf("%lf", &new_node->balance);
  printf("Enter monthly minimum: ");
  scanf("%lf", &new_node->minimum);
  printf("Enter interest rate: ");
  scanf("%lf", &new_node->interest_rate);

  struct debt *prev=NULL;
  struct debt *cur=list;

  if(cur==NULL)
    return new_node; //if the list is empty then new node is the first node so we return it

  if(prev==NULL && cur==list && cur->next==NULL){ //there is only one element in list
    if(new_node->interest_rate>cur->interest_rate){ //if the new interest rate is greater than cur's rate then put is before it
      new_node->next=list;
      return new_node; //return new node which is followed by the previous element in list
    }
    else{ //if its not greater we put the new node after the element in list
      list->next=new_node; //the next node after the element in list in the new node and then we return list
      return list;
    }
  }

  while(cur!=NULL){ //if there are more than 1 element in list and till the pointer to cur is not empty
    if(new_node->interest_rate>cur->interest_rate){ //if the new node's rate is greater then the current one then place it before it
      new_node->next=cur; //new node before the current one
      if(prev==NULL){ //if we have to put new node in the head then prev would be null
        return new_node;
      }
      else{ //if new node is not going to be in the head but between two nodes
        prev->next=new_node; //new node after the previous one
        return list;
      }
    }
    else{ //if its not greater then we move both pointers prev and cur one position and check again for the rates
      prev=cur;
      cur=cur->next;
    }
  }
  if(prev!=NULL)
    prev->next = new_node; //if the rate is the smallest then it will be put in the end, when prev points to the last element
  new_node->next = NULL; //marks that new node is the end of the list and then returns list
  return list;
}

struct debt *delete_first(struct debt *list){
  if(list==NULL) //if the list is empty then return NULL
    return NULL;
  struct debt *temp=list; //temporary pointer to the first element in the list
  list=list->next; //list now pints to the second element
  free(temp); //free the first element
  return list; //return the list starting from the previous second element that is now the first element of list
}

void search_list(struct debt *list){ //function to search in the list bassed of the company name
  char company[NAME_LEN+1];
  int flag=0;
  printf("Enter company name: ");
  read_line(company, NAME_LEN);

  struct debt *temp=list; //tenporary pointer that points to the first element in list
  while (temp!= NULL){ //while there is something in the element of list we willchech if its company is the same as the one the user entered
    if(strcmp(company, temp->company)==0){ //if its the same then strcmp will be 0
      printf("%-28s%12.2f%12.2f%12.2f\n", temp->company, temp->balance, temp->minimum, temp->interest_rate);
      flag=1;
    }
    temp=temp->next; //go through the elements in list
  }
  if(flag==0){ //if its not been found then print message
    printf("not found\n");
  }
}

void print_list(struct debt *list){ //function to print elements in the list
  printf("company                          balance     minimum    interest\n");
  struct debt *temp=list;
  while(temp!=NULL){ //go through the list till there is no more elements and print the attributes
    printf("%-28s%12.2f%12.2f%12.2f\n", temp->company, temp->balance, temp->minimum, temp->interest_rate);
    temp=temp->next;
  }
}

void clear_list(struct debt *list){ //function to deallocate space
  struct debt *temp; //temporary pointer that will point to the node thats going to be eliminated while list stores the next node
  while(list!=NULL){ //,this way we avoid error
    temp=list;
    list=list->next;
    free(temp); 
  }
}

