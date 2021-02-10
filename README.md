# duopy
## Ditching Derivatives with duopy
This is a work in progress for a `Python` module written in `C++`. It will provide users an efficient and accessible interface for working with dual numbers. Currently, the `C++` code runs and enables basic dual number arithmetic. (for a working example please use the `autograd.py` and the `math_.py` scripts; be aware of slow performance)

**What are dual numbers?**
Dual numbers are a creation of the *Autograd* world of machine learning. They are similar to complex numbers, in that they extend the number system by adding an orthogonal plane to the real number plane. This new plane is called the dual `e` (epsilon), where `e^2 = 0`. A dual number is thus a composite of a real part and a dual part and is written like so:

`u + u'e`

where `u` is the real part and `u'` is the dual part.

With this knowledge, we can do simple dual number arithmetic. Let `u + u'e` and `v + v'e` be two dual numbers:

Addition: `(u + u'e) + (v + v'e) = (u + v) + e(u' + v')`

Subtraction: `(u + u'e) - (v + v'e) = (u - v) + e(u' - v')`

Multiplication: `(u + u'e) * (v + v'e) = uv + u've + uv'e + u'v'e^2 = uv + e(u'v + uv')`

Division: `(u + u'e) / (v + v'e) = ((u + u'e) * (v - v'e)) / ((v + v'e) * (v - v'e)) = (uv + u've - v'ue - u'v'e^2) / v^2 = u/v + e(u'v - uv') / v^2`

**Why would you use this?**
As it turns out, the dual component of a dual number is the derivative of the function it has been passed through, while the real part is the original function output. Pretty neat, eh? Let us consider the applying the `tanh` function over a range of dual numbers:

![tanh](https://github.com/BenTenmann/duopy/blob/main/dual_.png)

As we can see, we get both the result for `tanh` and for its derivative in one go -- i.e. we compute the derivative of each function instantaneously. This makes adding and removing layers and swapping activation functions in neural networks very easy, as we do not need to re-formulate their derivatives by hand.


### Work in progress
 Missing: effective wrap for the `C++` code for `Python` interface. Currently exploring options: manual wrapping via `Python` API; `SWIG` wrapping; `pybind11` wrapping;
 
![logo](https://github.com/BenTenmann/PyHMM/blob/main/outtadabox.png)

