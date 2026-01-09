/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3
 Casting

 Create a branch named Part3

 do not remove anything from main().  you'll be revising your main() to work with these new code changes.

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type

 2) remove any getValue() functions if you added them

 3) move all of your add/subtract/multiply/divide implementations out of the class.

 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
        REMEMBER: if a member function doesn't modify any member variables of the class it exists in, what qualifier can we add to that function's signature?

 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function

 6) make sure it compiles & runs without errors.

 7) use your knowledge of casting to remove any conversion warnings.

 8) insert 'part3();' before the 'good to go' at the end of your main();
        move this part3 function to before main()

 9) click the [run] button.  Clear up any errors or warnings as best you can.

 */


struct A
{

};

struct HeapA
{
    A* aPtr;
    HeapA()
    {
        aPtr = new A();
    }
    ~HeapA()
    {
        delete aPtr;
	}
};

/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!





*/

#include <iostream>
struct DoubleType;
struct IntType;

struct FloatType
{
    FloatType( float val )
    {
        *value = val;
	}
	FloatType& add(float rhs)
    {
        *value += rhs;
        return *this;
	}
    FloatType& subtract(float rhs)
    {
        *value -= rhs;
        return *this;
	}
    FloatType& multiply(float rhs)
    {
        *value *= rhs;
        return *this;
    }
    FloatType& divide(float rhs)
    {
        *value /= rhs;
        return *this;
	}
	//overloaded functions
    //FloatType
    FloatType& add(const FloatType& rhs)
    {
		return add(*rhs.value);
    }
    FloatType& subtract(const FloatType& rhs)
	{
        return subtract(*rhs.value);
    }
    FloatType& multiply(const FloatType& rhs)
    {
        return multiply(*rhs.value);
    }
    FloatType& divide(const FloatType& rhs)
    {
        return divide(*rhs.value);
	}
	//DoubleType
    FloatType& add(const DoubleType& rhs);
    FloatType& subtract(const DoubleType& rhs);
    FloatType& multiply(const DoubleType& rhs);
    FloatType& divide(const DoubleType& rhs);
    //IntType
    FloatType& add(const IntType& rhs);
    FloatType& subtract(const IntType& rhs);
    FloatType& multiply(const IntType& rhs);
    FloatType& divide(const IntType& rhs);
	float* value = new float;
    ~FloatType()
    {
        delete value;
	}
};

struct DoubleType
{
    DoubleType( double val )
    {
		*value = val;
	}
    DoubleType& add(double rhs)
    {
		*value += rhs;
		return *this;
    }
    DoubleType& subtract(double rhs)
	{
        *value -= rhs;
        return *this;
    }
    DoubleType& multiply(double rhs)
    {
        *value *= rhs;
        return *this;
    }
    DoubleType& divide(double rhs)
    {
        *value /= rhs;
        return *this;
	}
	//overloaded functions
    //FloatType
    DoubleType& add(const FloatType& rhs)
    {
        return add(*rhs.value);
    }
    DoubleType& subtract(const FloatType& rhs)
    {
        return subtract(*rhs.value);
    }
    DoubleType& multiply(const FloatType& rhs)
    {
        return multiply(*rhs.value);
    }
    DoubleType& divide(const FloatType& rhs)
    {
        return divide(*rhs.value);
	}
	//DoubleType
    DoubleType& add(const DoubleType& rhs)
    {
        return add(*rhs.value);
    }
    DoubleType& subtract(const DoubleType& rhs)
    {
        return subtract(*rhs.value);
    }
    DoubleType& multiply(const DoubleType& rhs)
    {
        return multiply(*rhs.value);
    }
    DoubleType& divide(const DoubleType& rhs)
    {
        return divide(*rhs.value);
    }
    //IntType
    DoubleType& add(const IntType& rhs);
    DoubleType& subtract(const IntType& rhs);
    DoubleType& multiply(const IntType& rhs);
    DoubleType& divide(const IntType& rhs);
	double* value = new double;
    ~DoubleType()
    {
        delete value;
	}
};

struct IntType
{
    IntType( int val )
    {
        *value = val;
	}
    IntType& add(int rhs)
    {
        *value += rhs;
        return *this;
    }
    IntType& subtract(int rhs)
    {
        *value -= rhs;
        return *this;
	}
    IntType& multiply(int rhs)
    {
        *value *= rhs;
        return *this;
    }
    IntType& divide(int rhs)
    {
        if (rhs == 0)
        {
            std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
            return *this;
		}
        *value /= rhs;
		return *this;
    }
	//overloaded functions
	//FloatType
    IntType& add(FloatType& rhs)
    {
        return add(*rhs.value);
    }
    IntType& subtract(FloatType& rhs)
    {
        return subtract(*rhs.value);
	}
    IntType& multiply(FloatType& rhs)
    {
        return multiply(*rhs.value);
	}
    IntType& divide(FloatType& rhs)
    {
		return divide(*rhs.value);
	}
	//DoubleType
    IntType& add(DoubleType& rhs)
    {
        return add(*rhs.value);
	}
    IntType& subtract(DoubleType& rhs)
    {
		return subtract(*rhs.value);
	}
    IntType& multiply(DoubleType& rhs)
    {
		return multiply(*rhs.value);
	}
    IntType& divide(DoubleType& rhs)
	{
		return divide(*rhs.value);
	}
	//IntType
    IntType& add(IntType& rhs)
    {
		return add(*rhs.value);
	}
    IntType& subtract(IntType& rhs)
    {
		return subtract(*rhs.value);
	}
    IntType& multiply(IntType& rhs)
	{
		return multiply(*rhs.value);
	}
    IntType& divide(IntType& rhs)
	{
		return divide(*rhs.value);
	}
    int* value = new int;
    ~IntType()
    {
        delete value;
	}
};
// Remaining implementations of overloaded functions
//FloatType
FloatType& FloatType::add(const DoubleType& rhs)
{
    return add(*rhs.value);
}
FloatType& FloatType::subtract(const DoubleType& rhs)
{
    return subtract(*rhs.value);
}
FloatType& FloatType::multiply(const DoubleType& rhs)
{
    return multiply(*rhs.value);
}
FloatType& FloatType::divide(const DoubleType& rhs)
{
    return divide(*rhs.value);
}
FloatType& FloatType::add(const IntType& rhs)
{
    return add(*rhs.value);
}
FloatType& FloatType::subtract(const IntType& rhs)
{
    return subtract(*rhs.value);
}
FloatType& FloatType::multiply(const IntType& rhs)
{
    return multiply(*rhs.value);
}
FloatType& FloatType::divide(const IntType& rhs)
{
    return divide(*rhs.value);
}
//DoubleType
DoubleType& DoubleType::add(const IntType& rhs)
{
    return add(*rhs.value);
}
DoubleType& DoubleType::subtract(const IntType& rhs)
{
    return subtract(*rhs.value);
}
DoubleType& DoubleType::multiply(const IntType& rhs)
{
    return multiply(*rhs.value);
}
DoubleType& DoubleType::divide(const IntType& rhs)
{
    return divide(*rhs.value);
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output.
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments)
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!





*/

#include <iostream>

int main()
{
    //testing instruction 0
    HeapA heapA;

    //assign heap primitives
    FloatType ft(2.0f);
    DoubleType dt(2);
    IntType it(2);

    std::cout << "FloatType add result=" << *ft.add(2.0f).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract(2.0f).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply(2.0f).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide(16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << *(it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

    // FloatType object instanciation and method tests
// --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *ft.add(3.0f).multiply(1.5f).divide(5.0f).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *(dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl;

    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    std::cout << "good to go!\n";

    return 0;
}

