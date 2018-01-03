Prim MST running time empirical study
============

This is an empirical study of the running time of different Prim's algorithm that we developed for the Algorithms course in my sophomore year of my BS in computer science at UDC (Spain). The given pseudocode is the following:



<p align="center">
<img src="https://github.com/DaniRuizPerez/Algorithms/blob/master/Prim/Prim.PNG" width="500">
</p>




We checked the running times of an upper bound, a lower bound and a tight bound as n grows and with different array initial conditions. This table is the resulting case, where  t(n)/h(n) tends to infinity, t(n)/g(n) to a constant and t(n)/f(n) to 0 correspondingly.

h(n) = pow(n,1.93);
g(n) = pow(n,2.065);
f(n) = pow(n,2.5);

  |    n    |    t(n)   |  t(n)/h(n)  |  t(n)/g(n)  |  t(n)/f(n)  |
  |---------|-----------|-------------|-------------|-------------|
  | *   128 |    209.24 |    0.017936 |    0.009317 |    0.001129 |
  |     256 |    874.00 |    0.019661 |    0.009300 |    0.000834 |
  |     512 |   3584.00 |    0.021158 |    0.009114 |    0.000604 |
  |    1024 |  27820.00 |    0.043100 |    0.016908 |    0.000829 |
  |    2048 | 129287.00 |    0.052564 |    0.018778 |    0.000681 |
  |    4096 | 551767.00 |    0.058871 |    0.019153 |    0.000514 |
  |    8192 |2311672.00 |    0.064727 |    0.019177 |    0.000381 |




More details can be seen in the file [Analysis](https://github.com/DaniRuizPerez/Algorithms/blob/master/Prim/Analysis).

## Contact

Contact [Daniel Ruiz Perez](mailto:druiz072@fiu.edu) for requests, bug reports and good jokes.


## License

The software in this repository is available under the GNU General Public License, version 3. See the [LICENSE](https://github.com/DaniRuizPerez/AutomaticReasoning/blob/master/LICENSE) file for more information.
