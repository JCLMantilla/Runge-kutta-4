# 4th order Runge-Kutta method for friction proyectile motion in C++
This small project shows some scripting in C++, Python, and some Bash to solve two simultaneous, second-order ordinary differential equations, just for the sake of comparing the effect of air resistance in the trajectory of a projectile.

Our equations are subject to the following initial conditions:

$x(t=0)=x_{o}$,
$v_{x}(t=0)=v_{xo}$

$y(t=0)=y_{o}$,
$v_{y}(t=0)=v_{yo}$

$$\overrightarrow{\mathbf{F}}=-km||\mathbf{\overrightarrow{v}}||^n \hat{\mathbf{v}}$$
