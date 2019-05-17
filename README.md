# GA-self

This repositry is an compact example of self-built GA(genetic algorithm) with chromosome binary coded, which would be used to find out global maximum of function ShafferF6.  
> 这个仓库存放的是一个简洁的遗传算法代码示例, 可以用来求解ShafferF6函数的最大值, 其染色体编码采用二进制.  

<a href="https://www.codecogs.com/eqnedit.php?latex=$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$0.5&space;-&space;\frac{\sin^2(\sqrt{x^2&space;&plus;&space;y^2})-0.5}{(1.0&space;&plus;&space;0.001(x^2&plus;y^2))^2}$$" title="$$0.5 - \frac{\sin^2(\sqrt{x^2 + y^2})-0.5}{(1.0 + 0.001(x^2+y^2))^2}$$" /></a>

Well, principle of GA would not be list here, you can get the idea from the code in ./src/.  
> 这里就不再多说遗传算发的原理了, 不过可以通过./src/下面的代码了解之.  

## ShafferF6
There is only one global maximum point in ShafferF6 functional image site in (0.0), the value of which is +1. Around the maximum point locate a loop of ridge with equal altitude, the value of which is approximate to 0.99028. Finding of the max point will be easily retained at the ridge. So this function is a good example to test whether self-built GA can work correctly.  
> ShafferF6h函数只有一个全局最大值 1, 坐标为(0.0), 但是其周围有一圈值为0.99028的登高山脊. 我们在寻找其最大值得时侯, 容易被滞留在大山里. 正如此, 自己构建的遗传算法是否能很好的工作, 可以用Shaffer函数来检测.  

## Configure
Some of the parameters need to be specified. If you wanna use this GA, change the numbers in ```sga.conf```:  
> 一些参数要指明, 这些都放在了```sga.conf```中, 如果你想使用这个仓库, 可以将参数后面的数值替换.  
```pop_size```:			total amount of individuals use in evolution 人口数  
```generation_num```:	generations of the evolution 遗传代数  
```variable_num```:		numbers of variable used in functionals, here is 2, x and y 变量数, 这里是2  
```chrom_length```:		total length of the chromosome, 40 here means: each variable correspond with size of 20 int arrays 染色体总长度, 这里是40, 对应每个变量占20  
```crossover_prob```:	crossover probability 交叉概率  
```mutation_prob```:	mutation probability 变异概率  
```variable_down_1```:	variable\_1, x here, lower limit 变量1下限  
```variable_up_1```:	variable\_1 higher limit 变量1上限  
```variable_down_2```:	variable\_2, y here, lower limit 变量2下限  
```variable_up_2```:	variable\_2 higher limit 变量2上限  

## Usage
Folow next step, to use this self-built GA (apt for Ubuntu, yum for Centos):  
> 按照下面的步骤, 就可以使用这个GA了(apt 用于Ubuntu, yum 用于Centos):  
```
sudo apt -y install gcc git (or) sudo yum -y install gcc git
git clone https://github.com/frnorth/GA-self.git ~/GA-self
cd ~/GA-self
make
make clean
./mysga
```
Executable file ```mysga``` would read the ```sga.conf```, and get the parameters in, then start the evolution.  
> 可执行文件 ```mysga``` 会读取 ```sga.conf``` 文件中的参数, 而后开始遗传进化计算.  

## Result
The best individual in each generation would be list in ```evolution.txt```, and the global best individual would be in the end, which is the result we want.  
> ```evolution.txt``` 列出了每一代的最优个体, 并在后列出了全局最优的个体, 而全局最优的个体就是我们想要的.  

## Note
1. From the instruction of ```evolution.txt```, the individuals possessing execllent fitness(not retained in the ridge) will not live long, only appear in a few generation. The maximum calculated would be fall into 0.99028 finally.  
> 从 ```evolution.txt``` 中可以看到, 拥有特别优秀的属性的个体并没有存活的很长久, 最大值最终还是会回到0.99028.  
2. Coding chromosome by floating type, eoptimizing of the evolution, elitism, et al were not implemented.  
> 浮点型编码, 遗传操作优化, 精英主义等都没应用到这里.  
