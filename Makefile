
VPATH=./src/

obj = mysga.o random_list.o fitness.o

mysga: $(obj)
	cc -o mysga $(obj) -lm

mysga.o: mysga.c global_conf.h
	cc -c ./src/mysga.c
random_list.o: random_list.c global_conf.h
	cc -c ./src/random_list.c
fitness.o: fitness.c global_conf.h
	cc -c ./src/fitness.c

clean: 
	rm -rf $(obj)
