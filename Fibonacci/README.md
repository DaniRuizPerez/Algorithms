Fibonacci implementations running time empirical study
============


This is an empirical study of the running time of different Fibonacci implementations that I developed for the Algorithms course in my sophomore year of my BS in computer science at UDC (Spain). Implemented are the naive recursive version (fib1), the iterative version (fib2) and a more efficient version (fib3)



<p align="center">
<img src="https://github.com/DaniRuizPerez/Algorithms/blob/master/Fibonacci/alg.PNG" width="500">
</p>



For every version, we checked the running times of an upper bound , a lower bound and a tight bound as n grows. This table is one of the cases, where  t(n)/h(n) tends to infinity, t(n)/g(n) to a constant and t(n)/f(n) to 0 correspondingly.


   |    n   |     t(n)    |   t(n)/h(n)    |    t(n)/g(n)   |    t(n)/f(n)   |
   |--------|-------------|----------------|----------------|----------------|
   |    1000|    6.0016000|     0.0238928  |     0.0060016  |     0.0008688  |
   |   10000|   60.3425000|     0.0380735  |     0.0060342  |     0.0006552  |
   |  100000|  602.0000000|     0.0602000  |     0.0060200  |     0.0005229  |
   | 1000000| 6022.0000000|     0.0954423  |     0.0060220  |     0.0004359  |
   |10000000|60409.0000000|     0.1517405  |     0.0060409  |     0.0003748  |

   
More details can be seen in the file [Analysis](https://github.com/DaniRuizPerez/Algorithms/blob/master/Fibonacci/Analysis).

## Contact

Contact [Daniel Ruiz Perez](mailto:druiz072@fiu.edu) for requests, bug reports and good jokes.


## License

The software in this repository is available under the GNU General Public License, version 3. See the [LICENSE](https://github.com/DaniRuizPerez/AutomaticReasoning/blob/master/LICENSE) file for more information.
