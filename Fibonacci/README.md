Fibonacci implementations running time empyrical study
============


This is an empyrical study of the running time of different Fibonacci implenentations that I developed for the Algorithms course in my sophomore year of my BS in computer science at UDC (Spain). Implemented are the naive recursive version (fib1), the iterative version (fib2) and a more efficient version (fib3)



<p align="center">
<img src="https://github.com/DaniRuizPerez/Algorithms/blob/master/Fibonacci/alg.PNG" width="500">
</p>

   |  subestimada         |    ajustada    |  sobreestimada |			


For every version, we checked the running times of an upper bound (sobreestimada), a lower bound (subestimada) and a tight bound (ajustada) as n grows. This table is one of the cases, where  the bound tends to infinity, a constant and 0 correspondingly.


   |    n   |     t(n)    |   t(n)/h(n)    |    t(n)/g(n)   |    t(n)/f(n)   |
   |--------|-------------|----------------|----------------|----------------|
   |    1000|    6.0123000|     0.0239354  |     0.0060123  |     0.0008704  |
   |   10000|   60.5628000|     0.0382125  |     0.0060563  |     0.0006576  |
   |  100000|  605.0000000|     0.0605000  |     0.0060500  |     0.0005255  |
   | 1000000| 6107.0000000|     0.0967894  |     0.0061070  |     0.0004420  |
   |10000000|59875.0000000|     0.1503992  |     0.0059875  |     0.0003715  |

   |    1000|    6.0016000|     0.0238928  |     0.0060016  |     0.0008688  |
   |   10000|   60.3425000|     0.0380735  |     0.0060342  |     0.0006552  |
   |  100000|  602.0000000|     0.0602000  |     0.0060200  |     0.0005229  |
   | 1000000| 6022.0000000|     0.0954423  |     0.0060220  |     0.0004359  |
   |10000000|60409.0000000|     0.1517405  |     0.0060409  |     0.0003748  |

   |    1000|    5.9833000|     0.0238199  |     0.0059833  |     0.0008662  |
   |   10000|   60.2475000|     0.0380136  |     0.0060248  |     0.0006541  |
   |  100000|  609.0000000|     0.0609000  |     0.0060900  |     0.0005290  |
   | 1000000| 6018.0000000|     0.0953789  |     0.0060180  |     0.0004356  |
   |10000000|60446.0000000|     0.1518335  |     0.0060446  |     0.0003750  |

More details can be seen in the file [Analysis](https://github.com/DaniRuizPerez/Algorithms/blob/master/FIbonacci/Analysis).

## Contact

Contact [Daniel Ruiz Perez](mailto:druiz072@fiu.edu) for requests, bug reports and good jokes.


## License

The software in this repository is available under the GNU General Public License, version 3. See the [LICENSE](https://github.com/DaniRuizPerez/AutomaticReasoning/blob/master/LICENSE) file for more information.
