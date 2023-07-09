# 2D-Strange-Attractors

Visualization of 2D strange attractors using C++ and SFML.

## Implemented Attractors
### Fractal Dream
$x_0=y_0=0.1$

$a, b \in [-3,3]$

$c, d \in [-0.5, 0.5]$

$x_{n+1}= \sin(y_n\cdot b)+c\cdot \sin(x_n\cdot b)$

$y_{n+1}= \sin(x_n\cdot a)+d\cdot \sin(y_n\cdot a)$

<img src=/images/examples/fractal_dream.png width=500>

$a=-0.966918,\text{ } b=2.879879,\text{ }  c=0.765145,\text{ }  d=0.744728$

### Clifford Attractor
$x_0=y_0=0.1$

$a, b, c, d \in [-3,3]$

$x_{n+1}= \sin(a \cdot y_n)+c\cdot \cos(a \cdot x_n)$

$y_{n+1}= \sin(b \cdot x_n)+d\cdot \cos(b \cdot y_n)$

<img src=/images/examples/clifford_attractor.png width=500>

$a=-1.7,\text{ } b=1.3,\text{ }  c=-0.1,\text{ }  d=-0.121$

### Bedhead Attractor
$x_0=y_0=1$

$a, b\in [-1,1]$

$x_{n+1}= \sin(\displaystyle \frac{x_n \cdot y_n}{b}) \cdot y_n + \cos(a \cdot x_n - y_n)$

$y_{n+1}= x_n + \displaystyle \frac{\sin(y_n)}{b}$

<img src=/images/examples/bedhead_attractor.png width=500>

$a=0.65343,\text{ } b=0.7345345$

