
#ifndef _RANDOM_LIST_
#define _RANDOM_LIST_

void random_int_list_init(int *c_list, int c_length, int c_down, int c_up);
double random_int_list_correspond(int *c_list, int c_length, int c_bit, double c_down, double c_up);
void random_int_list_crossover(int *c_list1, int *c_list2, int c_length, int c_xsite);
void random_int_list_mutation(int *c_list, int c_length, int c_bit, double c_prob);
void random_int_list_print(int *c_list, int c_length, int c_xsite);
int random_double_list_find(double *c_list,int c_length,double c_x);

#endif /* _RANDOM_LIST_ */
