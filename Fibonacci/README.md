Fibonacci implementations running time empyrical study
============


This is an empyrical study of the running time of different Fibonacci implenentations that I developed for the Algorithms course in my sophomore year of my BS in computer science at UDC (Spain). Implemented are the naive recursive version (fib1), the iterative version (fib2) and a more efficient version (fib3)



<p align="center">
<img src="https://github.com/DaniRuizPerez/Algorithms/blob/master/Fibonacci/alg.PNG" width="500">
</p>


For every version, we checked the running times of an upper bound (sobreestimada), a lower bound (subestimada) and a tight bound (ajustada) as n grows. More details can be seen in the file [Analysis](https://github.com/DaniRuizPerez/Algorithms/blob/master/FIbonacci/Analysis).


			  |  subestimada   |    ajustada    |  sobreestimada |
   |    n   |     t(n)    |   t(n)/h(n)    |    t(n)/g(n)   |    t(n)/f(n)   |
   |--------|-------------|----------------|----------------|----------------|
   |    1000|    0.0825000|     0.0313896  |     0.0119431  |     0.0026089  |
   |   10000|    0.1046000|     0.0344662  |     0.0113568  |     0.0010460  |
   |  100000|    0.1207000|     0.0355725  |     0.0104839  |     0.0003817  |
   | 1000000|    0.1438000|     0.0386879  |     0.0104086  |     0.0001438  |
   |10000000|    0.2154000|     0.0536524  |     0.0133639  |     0.0000681  |

   |    1000|    0.1077000|     0.0409777  |     0.0155912  |     0.0034058  |
   |   10000|    0.1314000|     0.0432970  |     0.0142666  |     0.0013140  |
   |  100000|    0.1577000|     0.0464771  |     0.0136976  |     0.0004987  |
   | 1000000|    0.1726000|     0.0464363  |     0.0124932  |     0.0001726  |
   |10000000|    0.1693000|     0.0421697  |     0.0105037  |     0.0000535  |

   |    1000|    0.0825000|     0.0313896  |     0.0119431  |     0.0026089  |
   |   10000|    0.1011000|     0.0333130  |     0.0109768  |     0.0010110  |
   |  100000|    0.1214000|     0.0357788  |     0.0105447  |     0.0003839  |
   | 1000000|    0.1437000|     0.0386610  |     0.0104014  |     0.0001437  |
   |10000000|    0.1706000|     0.0424935  |     0.0105844  |     0.0000539  |


## Contact

Contact [Daniel Ruiz Perez](mailto:druiz072@fiu.edu) for requests, bug reports and good jokes.


## License

The software in this repository is available under the GNU General Public License, version 3. See the [LICENSE](https://github.com/DaniRuizPerez/AutomaticReasoning/blob/master/LICENSE) file for more information.
