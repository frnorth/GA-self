#include"global_conf.h"
#include"random_list.h"
#include"fitness.h"
#include"mysga.h"

char* char_char(char *c1, char *c2) {
	char *two = (char *)malloc(strlen(c1)+strlen(c2)); 
	strcpy(two, c1); 
	strcat(two, c2); 
	return two; 
}

int main(int argc, char **argv) {

	int t0=time(0);

//	if(argc < 2) {
//		printf("where is the work place?\n"); 
//		exit(-1); 		
//	}
	char hahac[100]; 
	int hahad; 
	double hahalf; 
	int i, j, k; 
	int gen; 
	srand((unsigned)time(NULL)); 

	/* work path and conf_path which contains of the parameter*/
	char *path = NULL;//argv[1];
	if (argc < 2)
		path = get_current_dir_name();
	else if (argc == 2)
		path = argv[1];
	else {
		printf("too many parameters, or - parameters");
		exit(-1);
	}
	char *sga_conf_path = char_char(path, "/sga.conf"); 
	char *sga_evolution_path = char_char(path, "/evolution.txt"); 
	printf("wotk path: %s\n", path); 
	printf("conf path: %s\n", sga_conf_path); 
	printf("evolution path: %s\n", sga_evolution_path); 

	/* base parameter */
	/* size of the population */
	int pop_size; 
	/* how many generation you want*/
	int generation_num; 
	/* howmany variable used in the problem*/
	int variable_num; 
	/* lenth of the chrom of one individual */
	int chrom_length; 
	/* length of one cheom */
	int chrom_one_length; 
	/* probability of crossover */
	double crossover_prob; 
	/* probability of mutation */
	double mutation_prob;     

	/* arraies used in sga */
	/* chromosomes */
	int *chrom_one, **chrom_parent, **chrom_child; 
	/* variables */
	double **variable, *variable_down, *variable_up; 
	/* fitness */
	double *fitness, *fitness_multi; 
	/* index of parent and cosssite */
	int *parent, *xsite; 

	/* arraies used in statistic */
	/* best child site in one generation and all */
	int gen_best_pop_site, global_best_gen_site; 
	/* best fitness appear in each gen, with the variables */
	double gen_best_fitness, *gen_best_variable; 
	/* best fitness appear in global, with the variables */
	double global_best_fitness, *global_best_variable; 

	/* file contains the parameter */
	FILE *fsga; 
	fsga = fopen(sga_conf_path, "r"); 

	/* fscanf will scan one raw twice? */
	fscanf(fsga, "%8s%d", hahac, &hahad); 
	pop_size = hahad; 
	printf("%s\t%d\n", hahac, pop_size); 

	fscanf(fsga, "%14s%d", hahac, &hahad); 
	generation_num = hahad; 
	printf("%s\t%d\n", hahac, generation_num); 

	fscanf(fsga, "%12s%d", hahac, &hahad); 
	variable_num = hahad; 
	printf("%s\t%d\n", hahac, variable_num); 

	fscanf(fsga, "%12s%d", hahac, &hahad); 
	chrom_length = hahad; 
	printf("%s\t%d\n", hahac, chrom_length); 

	fscanf(fsga, "%14s%lf", hahac, &hahalf); 
	crossover_prob = hahalf; 
	printf("%s\t%lf\n", hahac, crossover_prob); 

	fscanf(fsga, "%13s%lf", hahac, &hahalf); 
	mutation_prob = hahalf; 
	printf("%s\t%lf\n", hahac, mutation_prob); 

	/* malloc for the population */
	/* chomeosomes */
	chrom_one_length = chrom_length/variable_num; 
	chrom_one = (int *)malloc(sizeof(int)*chrom_one_length); 
	chrom_parent = (int **)malloc(sizeof(int*)*pop_size); 
	chrom_child = (int **)malloc(sizeof(int*)*pop_size); 
	variable = (double **)malloc(sizeof(double*)*pop_size); 
	for(i = 0; i < pop_size; i++) {
		chrom_parent[i] = (int *)malloc(sizeof(int)*chrom_length); 
		chrom_child[i] = (int *)malloc(sizeof(int)*chrom_length); 
		variable[i] = (double *)malloc(sizeof(double)*variable_num); 
	}

	/* variables */
	variable_down = (double *)malloc(sizeof(double)*variable_num); 
	variable_up = (double *)malloc(sizeof(double)*variable_num); 
	gen_best_variable = (double *)malloc(sizeof(double)*variable_num); 
	global_best_variable = (double *)malloc(sizeof(double)*variable_num); 

	/* fitnesses */
	fitness = (double *)malloc(sizeof(double)*pop_size); 
	fitness_multi = (double *)malloc(sizeof(double)*pop_size); 
	parent = (int *)malloc(sizeof(int)*pop_size); 
	xsite = (int *)malloc(sizeof(int)*pop_size); 

	/* read in variable range */
	for(i = 0; i < variable_num; i++) {
		fscanf(fsga, "%15s%lf", hahac, &hahalf); 
		variable_down[i] = hahalf; 
		printf("%s\t%lf\t", hahac, variable_down[i]); 
		fscanf(fsga, "%13s%lf", hahac, &hahalf); 
		variable_up[i] = hahalf; 
		printf("%s\t%lf\n", hahac, variable_up[i]); 
	}
	fclose(fsga); 

	/* initialize */
	/*******************************************************************************************/
	for(i = 0; i < pop_size; i++) {
		random_int_list_init(chrom_parent[i], chrom_length, 0, 1); 
		for(j = 0; j < variable_num; j++) {
			for(k = 0; k < chrom_one_length; k++)
				chrom_one[k] = chrom_parent[i][chrom_one_length*j + k]; 
			variable[i][j] = random_int_list_correspond
				(chrom_one, chrom_one_length, 2, variable_down[j], variable_up[j]); 
		}
		/* refer to fitness_call in fo.c */
		fitness[i] = fitness_cal(variable[i]);
	}
	gen_best_fitness = fitness[0];
	global_best_fitness = gen_best_fitness;
	fsga = fopen(sga_evolution_path, "w"); 
	fprintf(fsga,"%5s%20s","gen","gen_best_fitness");
	for (i = 0; i < variable_num; i++) 
		fprintf(fsga,"%15s%d","variable",i);
	fprintf(fsga,"\n");

	/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

	/* print the chrom variable fitness*/
//	printf("\nInitialized\n");
//	for(i=0;i<pop_size;i++){
//		printf("%5d ",i);
//		random_int_list_print(chrom_parent[i],chrom_length,xsite[i]);
//		for(j=0;j<variable_num;j++){
//			printf("%10.5lf",variable[i][j]);
//		}
//		printf("%10.5lf\n",fitness[i]);
//	}
//	printf("\n");

	/* the evolution */
	/*******************************************************************************************/
	for(gen = 0; gen < generation_num; gen++) {
		if(gen%10==0)
			/* if printf horizontally without '\n', gen will not be print along with evolution */
			printf("%5d\n",gen);

		/* calculate the variable's value and fitness */
		for(i = 0; i < pop_size; i++) {
			for(j = 0; j < variable_num; j++) {
				for(k = 0; k < chrom_one_length; k++)
					chrom_one[k] = chrom_parent[i][chrom_one_length*j + k]; 
				variable[i][j] = random_int_list_correspond
					(chrom_one, chrom_one_length, 2, variable_down[j], variable_up[j]); 
			}
			/* refer to fitness_call in fo.c */
			fitness[i] = fitness_cal(variable[i]);
		}

		/* calculate the fitness_multi */
		fitness_multi[0] = fitness[0];
		for (i = 1; i < pop_size; i++) {
			fitness_multi[i] = fitness_multi[i - 1] + fitness[i];
		}

		/* select */
		for (i = 0; i < pop_size; i++) {
			double select_prob = ((double)(rand()%10000))/10000.0;
			double fitness_select = fitness_multi[pop_size - 1] * select_prob;
//			int count = 0;
//			while (fitness_multi[count] < fitness_select)
//				count++;
//			parent[i] = count;
			parent[i] = random_double_list_find(fitness_multi,pop_size,fitness_select);
		}

		/* match the child */
		for (i = 0; i < pop_size; i++) {
			for (j = 0; j < chrom_length; j++)
				chrom_child[i][j] = chrom_parent[parent[i]][j];
		}

		/* crossover */
		for (i = 0; i < pop_size; i += 2) {
			double cross_prob = ((double)(rand()%10000))/10000.0;
			if (cross_prob < crossover_prob) {
				xsite[i] = rand()%(chrom_length-2)+1;
				xsite[i + 1] = xsite[i];
				/* refer to random_int_list_crossover in random_list.c */
				random_int_list_crossover(chrom_child[i], chrom_child[i + 1], chrom_length, xsite[i]);
			}
			else {
				xsite[i] = 0;
				xsite[i + 1] = 0;
			}
		}

		/* mutation */
		for (i = 0; i < pop_size; i++) {
			/* refer to random_int_list_mutation in random_list.c */
			random_int_list_mutation(chrom_child[i], chrom_length, 2, mutation_prob);
		}
		
		/* print the chrom variable fitness*/
//		printf("\nGeneration %d\n",gen);
//		for(i=0;i<pop_size;i++){
//			printf("%5d ",i);
//			random_int_list_print(chrom_parent[i],chrom_length,xsite[i]);
//			for(j=0;j<variable_num;j++){
//				printf("%10.5lf",variable[i][j]);
//			}
//			printf("%10.5lf",fitness[i]);
//			printf("%5d  ",parent[i]);
//			random_int_list_print(chrom_parent[parent[i]],chrom_length,xsite[i]);
//			printf("%4d  ",xsite[i]);
//			random_int_list_print(chrom_child[i],chrom_length,xsite[i]);
//			printf("\n");
//		}
//		printf("\n");

		/* statistic */
		gen_best_fitness = fitness[0];

		for (i = 0; i < pop_size; i++) {
			if (fitness[i] > gen_best_fitness) {
				gen_best_fitness = fitness[i];
				gen_best_pop_site = i;
			}
		}

		for (i = 0; i < variable_num; i++) {
			gen_best_variable[i] = variable[gen_best_pop_site][i];
		}

		if (gen_best_fitness > global_best_fitness) {
			global_best_fitness = gen_best_fitness;
			global_best_gen_site = gen;
			for (j = 0; j < variable_num; j++)
				global_best_variable[j] = gen_best_variable[j];
		}

		/* print the evoltion into a file */
		fprintf(fsga,"%5d%20.5lf",gen,gen_best_fitness);

		for (i = 0; i < variable_num; i++) {
			fprintf(fsga,"%15.5lf",gen_best_variable[i]);
		}

		fprintf(fsga,"\n");

		/* child-->parent */
		for (i = 0; i < pop_size; i++) {
			for (j = 0; j < chrom_length; j++)
				chrom_parent[i][j] = chrom_child[i][j];
		}

	}
	/*******************************************************************************************/
	/////////////////////////////////////////////////////////////////////////////////////////////

	/* output the best child */
	fprintf(fsga,"\nthe best\n");
	fprintf(fsga,"%5d%20.5lf",global_best_gen_site,global_best_fitness);
	for (i = 0; i < variable_num; i++) {
		fprintf(fsga,"%15.5lf",global_best_variable[i]);
	}
	fclose(fsga);


	/* free chomeosomes */
	free(chrom_one);
	for(i = 0; i < pop_size; i++) {
		free(chrom_parent[i]);
		free(chrom_child[i]);
		free(variable[i]);
	}
	free(chrom_parent);
	free(chrom_child);
	free(variable);

	/* free variables */
	free(variable_down);
	free(variable_up);
	free(gen_best_variable);
	free(global_best_variable);

	/* free fitnesses */
	free(fitness);
	free(fitness_multi);
	free(parent);
	free(xsite);

	/* free the path */
	free(sga_conf_path); 
	free(sga_evolution_path);

	printf("\n%d\n",time(0)-t0); 
	return 0; 

}
