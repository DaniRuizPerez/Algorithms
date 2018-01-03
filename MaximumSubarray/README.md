Maximum Subarray implementations running time empirical study
============


This is an empirical study of the running time of different Maximum Subarray implementations that I developed for the Algorithms course in my sophomore year of my BS in computer science at UDC (Spain).


<p align="center">
<img src="https://github.com/DaniRuizPerez/Algorithms/blob/master/MaximumSubarray/sum.PNG" width="500">
</p>


For every version, we checked the running times of an upper bound , a lower bound and a tight bound as n grows. This table is one of the cases, where  t(n)/h(n) tends to infinity, t(n)/g(n) to a constant and t(n)/f(n) to 0 correspondingly.

h(n) = pow(n,1.8)
g(n) = pow (n,2)
f(n) = pow(n,2.2)

  |    n    |    t(n)   |  t(n)/h(n)  |  t(n)/g(n)  |  t(n)/f(n)  |
  |---------|-----------|-------------|-------------|-------------|
  |     500 |   1361.00 |    0.065389 |    0.005444 |    0.001571 |
  |    1000 |   5439.00 |    0.086202 |    0.005439 |    0.001366 |
  |    2000 |  10693.00 |    0.055905 |    0.002673 |    0.000585 |
  |    4000 |  38106.00 |    0.065720 |    0.002382 |    0.000453 |
  |    8000 | 152505.00 |    0.086764 |    0.002383 |    0.000395 |
  |   16000 | 606014.00 |    0.113734 |    0.002367 |    0.000342 |
  |   32000 |2430785.00 |    0.150490 |    0.002374 |    0.000298 |



More details can be seen in the file [Analysis](https://github.com/DaniRuizPerez/Algorithms/blob/master/MaximumSubarray/Analysis).

## Contact

Contact [Daniel Ruiz Perez](mailto:druiz072@fiu.edu) for requests, bug reports and good jokes.


## License

The software in this repository is available under the GNU General Public License, version 3. See the [LICENSE](https://github.com/DaniRuizPerez/AutomaticReasoning/blob/master/LICENSE) file for more information.
