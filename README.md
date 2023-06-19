# 4th order Runge-Kutta method for friction projectile motion in C++
This small project shows some scripting in C++, Python, and Bash to solve two simultaneous, second-order ordinary differential equations, just for the sake of comparing the effect of air resistance in the trajectory of a projectile.

Our equations are subject to the following initial conditions:

$x(t=0)=x_{o} \quad v_{x}(t=0)=v_{xo}$

$y(t=0)=y_{o} \quad v_{y}(t=0)=v_{yo}$

Recall that the force that air resistance opposes the movement is:
$$\overrightarrow{\mathbf{F}}=-km||\mathbf{\overrightarrow{v}}||^n \hat{\mathbf{v}}$$
where:
- $m$ is the mass of the object
- $k$ is a friction coefficient,
- $\mathbf{\overrightarrow{v}}=(v_{x},v_{y})$ is the velocity vector of the projectile
- $k$ is the friction coefficient, which depends on the medium where the object is moving and also it's geometr
- $n$ is the degree of friction.

