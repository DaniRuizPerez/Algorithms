Sorting algorithms running time empirical study
============


This is an empirical study of the running time of different Sorting algorithms that we developed given the pseudocode in the images for the Algorithms course in my sophomore year of my BS in computer science at UDC (Spain). 


For every version, we checked the running times of an upper bound, a lower bound and a tight bound as n grows and with different array initial conditions. This table is one of the cases, where  t(n)/h(n) tends to infinity, t(n)/g(n) to a constant and t(n)/f(n) to 0 correspondingly.

h(n) = pow(n,0.7)
g(n) = n
f(n) = pow(n,1.2)

  |    n    |    t(n)   |  t(n)/h(n)  |  t(n)/g(n)  |  t(n)/f(n)  |
  |---------|-----------|-------------|-------------|-------------|
  | *  1024 |      8.50 |    0.066444 |    0.008305 |    0.002076 |
  | *  2048 |     16.73 |    0.080467 |    0.008170 |    0.001778 |
  | *  4096 |     32.86 |    0.097270 |    0.008022 |    0.001520 |
  | *  8192 |     66.17 |    0.120584 |    0.008077 |    0.001332 |
  | * 16384 |    131.35 |    0.147348 |    0.008017 |    0.001151 |
  | * 32768 |    267.42 |    0.184665 |    0.008161 |    0.001020 |
  |   65536 |    503.00 |    0.213812 |    0.007675 |    0.000835 |




More details can be seen in the file [Analysis](https://github.com/DaniRuizPerez/Algorithms/blob/master/QuickSortInsertionSort/Analysis).

## Contact

Contact [Daniel Ruiz Perez](mailto:druiz072@fiu.edu) for requests, bug reports and good jokes.


## License

The software in this repository is available under the GNU General Public License, version 3. See the [LICENSE](https://github.com/DaniRuizPerez/AutomaticReasoning/blob/master/LICENSE) file for more information.
