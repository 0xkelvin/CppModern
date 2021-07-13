
1. Rule of Three
The rule of three (also known as the Law of The Big Three or The Big Three) is a rule of thumb in C++ (prior to C++11) that claims that if a class defines any of the following then it should probably explicitly define all three:[1]

destructor
copy constructor
copy assignment operator
These three functions are special member functions. If one of these functions is used without first being declared by the programmer it will be implicitly implemented by the compiler with the following default semantics:

Destructor – Call the destructors of all the object's class-type members
Copy constructor – Construct all the object's members from the corresponding members of the copy constructor's argument, calling the copy constructors of the object's class-type members, and doing a plain assignment of all non-class type (e.g., int or pointer) data members
Copy assignment operator – Assign all the object's members from the corresponding members of the assignment operator's argument, calling the copy assignment operators of the object's class-type members, and doing a plain assignment of all non-class type (e.g. int or pointer) data members.
The Rule of Three claims that if one of these had to be defined by the programmer, it means that the compiler-generated version does not fit the needs of the class in one case and it will probably not fit in the other cases either. The term "Rule of three" was coined by Marshall Cline in 1991.

An amendment to this rule is that if the class is designed in such a way that Resource Acquisition Is Initialization (RAII) is used for all its (nontrivial) members, the destructor may be left undefined (also known as The Law of The Big Two). A ready-to-go example of this approach is the use of smart pointers instead of plain ones.

Because implicitly-generated constructors and assignment operators simply copy all class data members ("shallow copy"),[4] one should define explicit copy constructors and copy assignment operators for classes that encapsulate complex data structures or have external references such as pointers, if you need to copy the objects pointed to by the class members. If the default behavior ("shallow copy") is actually the intended one, then an explicit definition, although redundant, will be "self-documenting code" indicating that it was an intention rather than an oversight. Modern C++ includes a syntax for expressly specifying that a default function is desired without having to type out the function body.


2.The Rule of Five
By adding both the move constructor and the move assignment operator to our MyMovableClass, we have adhered to the Rule of Five. This rule is an extension of the Rule of Three which we have already seen and exists since the introduction of the C++11 standard. The Rule of Five is especially important in resource management, where unnecessary copying needs to be avoided due to limited resources and performance reasons. Also, all the STL container classes such as std::vector implement the Rule of Five and use move semantics for increased efficiency.

The Rule of Five states that if you have to write one of the functions listed below then you should consider implementing all of them with a proper resource management policy in place. If you forget to implement one or more, the compiler will usually generate the missing ones (without a warning) but the default versions might not be suitable for the purpose you have in mind. The five functions are:

The destructor: Responsible for freeing the resource once the object it belongs to goes out of scope.

The assignment operator: The default assignment operation performs a member-wise shallow copy, which does not copy the content behind the resource handle. If a deep copy is needed, it has be implemented by the programmer.

The copy constructor: As with the assignment operator, the default copy constructor performs a shallow copy of the data members. If something else is needed, the programmer has to implement it accordingly.

The move constructor: Because copying objects can be an expensive operation which involves creating, copying and destroying temporary objects, rvalue references are used to bind to an rvalue. Using this mechanism, the move constructor transfers the ownership of a resource from a (temporary) rvalue object to a permanent lvalue object.

The move assignment operator: With this operator, ownership of a resource can be transferred from one object to another. The internal behavior is very similar to the move constructor.