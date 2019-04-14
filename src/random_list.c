
#include"global_conf.h"


void random_int_list_init(int *c_list, int c_length, int c_down, int c_up) {
	int l=c_up-c_down+1;
	int i=0;
	for (i = 0; i < c_length; i++)
		c_list[i] = rand()%l+c_down;
}

double random_int_list_correspond(int *c_list, int c_length, int c_bit, double c_down, double c_up) {
	double sum = 0;
	int i=0;
	for (i=0;i<c_length;i++) {
		sum += (double)c_list[i] * pow((double)c_bit, (double)i);
	}
	double max = pow((double)c_bit, (double)c_length);
	double correspond_num = c_down + (c_up - c_down)*sum / max;
	return correspond_num;
}

void random_int_list_crossover(int *c_list1, int *c_list2, int c_length, int c_xsite) {
	int num3;
	int i=0;
	for (i = c_xsite; i < c_length; i++) {
		num3 = c_list1[i];
		c_list1[i] = c_list2[i];
		c_list2[i] = num3;
	}
}

void random_int_list_mutation(int *c_list, int c_length, int c_bit, double c_prob) {
	int i=0;
	for (i = 0; i < c_length; i++) {
		double rand_num=((double)(rand()%10000))/10000.0;
		if (rand_num < c_prob)
			c_list[i] = c_bit - 1 - c_list[i];
	}
}

void random_int_list_print(int *c_list, int c_length, int c_xsite) {
		int i=0;
		for (i = 0; i < c_xsite; i++)
			printf("%d",c_list[i]);
		printf(" ");
		for (i = c_xsite; i < c_length; i++)
			printf("%d",c_list[i]);
}

int random_double_list_find(double *c_list,int c_length, double c_x) {
	/* find x in which area, if x<list[0]:return 0, if i<x<j:return j */
	/* if(c_x<c_list[end-1]+0.0000001) instead of c_x<=c_list[end-1]? */
	if(c_x<=c_list[0])
		return 0;
	else{
		int left=0;
		int right=c_length-1;
		while(right-left>1){
			int middle=(left+right)/2;
			if(c_x>c_list[middle])
				left=middle;
			if(c_x<=c_list[middle])
				right=middle;
		}
		return right;
	}
}
