# GA-self

This repositry is an compact example of self-built GA(genetic algorithm), which could be used to find out global maximum of function ShafferF6:

<a href="https://www.codecogs.com/eqnedit.php?latex=$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" title="$$0.5 - \frac{\sin^2(\sqrt{x^2 + y^2})-0.5}{(1.0 + 0.001(x^2+y^2))^2}$$" /></a>

## ShafferF6
There is only one max point in ShafferF6 functional image site in (0.0), around which locate a loop of ridge. Finding of the max point will be easily got stack in the ridge. So this function is a good example to test whether slef-built GA can work correctly.

## Configure
Some of the parameters need to be specified. If you wanna use this GA, change the numbers in <font face=#00008B>sga.conf</font>:  
<font face=#00008B>pop\_size</font>: total amount of individuals use in evolution  
<font face=#00008B>generation\_num</font>: generations of the evolution  
<font face=#00008B>variable\_num</font>: numbers of variable used in functionals, here is 2, x and y  
<font face=#00008B>chrom\_length</font>: each variable correspond with size of 20 int arrays    
<font face=#00008B>crossover\_prob</font>: crossover probability  
<font face=#00008B>mutation\_prob</font>: mutation probability  
<font face=#00008B>variable\_down\_1</font>: variable\_1, x here, lower limit
<font face=#00008B>variable\_up\_1</font>: variable\_1 higher limit
<font face=#00008B>variable\_down\_2</font>: variable\_2, y here, lower limit
<font face=#00008B>variable\_up\_2</font>: variable\_2 higher limit

./mysga 

