# GA-self

This repositry is an compact example of self-built GA(genetic algorithm), which could be used to find out global maximum of function ShafferF6:

<a href="https://www.codecogs.com/eqnedit.php?latex=$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" title="$$0.5 - \frac{\sin^2(\sqrt{x^2 + y^2})-0.5}{(1.0 + 0.001(x^2+y^2))^2}$$" /></a>

## ShafferF6
There is only one max point in ShafferF6 functional image site in (0.0), around which locate a loop of ridge. Finding of the max point will be easily got stack in the ridge. So this function is a good example to test whether slef-built GA can work correctly.

## Configure
parameters of GA was in sga.conf:  
这是<label style="color:red">红色</label>字体: total amount of individuals use in evolution  
```generation_num```:      200
variable_num        2
chrom_length        60
crossover_prob      0.5
mutation_prob       0.02
variable_down_1     -100    variable_up_1       100
variable_down_2     -100    variable_up_2       100

./mysga 

