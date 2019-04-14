# GA-self

This repositry is an compact example of self-built GA(genetic algorithm), which could be used to find out global maximum of function ShafferF6. 

<a href="https://www.codecogs.com/eqnedit.php?latex=$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" title="$$0.5 - \frac{\sin^2(\sqrt{x^2 + y^2})-0.5}{(1.0 + 0.001(x^2+y^2))^2}$$" /></a>

Well, principle of GA would not be list here, you can get the idea from the src code.

## ShafferF6
There is only one max point in ShafferF6 functional image site in (0.0), around which locate a loop of ridge. Finding of the max point will be easily got stack in the ridge. So this function is a good example to test whether slef-built GA can work correctly.

## Configure
Some of the parameters need to be specified. If you wanna use this GA, change the numbers in ```sga.conf```:  
```pop_size```: total amount of individuals use in evolution  
```generation_num```: generations of the evolution  
```variable_num```: numbers of variable used in functionals, here is 2, x and y  
```chrom_length```: each variable correspond with size of 20 int arrays    
```crossover_prob```: crossover probability  
```mutation_prob```: mutation probability  
```variable_down_1```: variable\_1, x here, lower limit  
```variable_up_1```: variable\_1 higher limit  
```variable_down_2```: variable\_2, y here, lower limit  
```variable_up_2```: variable\_2 higher limit  

## Usage
Folow next step, to use this GA for your problems:
```
apt -y install gcc <=> yum -y install gcc
git clone https://github.com/frnorth/GA-self.git ~/GA-self
cd ~/GA-self
make
make clean
./mysga
```
Executable file ```mysga``` would read the sga.conf, and get the parametes in, then start the evolution.

## Result
Evolution.txt list the best individual in each generation, and in the end is the global best individuals, which is the result we want.  
