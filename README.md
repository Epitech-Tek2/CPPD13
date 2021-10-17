## B3 - C++ Pool

## B-CPP-

# Day 13

## A Game of Toys

```
2.
```

# Day 13

```
language : C++
```
- The totality of your source files, except all useless files (binary, temp files, obj
    files,...), must be included in your delivery.

All your exercises will be compiled with **g++and the-Wall -Wextra -Werrorflags** , unless specified otherwise.

All output goes to the standard output, and must be ended by a newline, unless specified otherwise.

```
None of your files must contain amainfunction, unless specified otherwise.
We will use our ownmainfunctions to compile and test your code. It will include your
header files.
```
For each exercise, the files must be turned-in in a separate directory called **exXX** where XX is the exercise
number (for instanceex01), unless specified otherwise.

```
Read the examples CAREFULLY. They might require things that weren’t mentioned in
the subject...
```
If you do half the exercises because you have comprehension problems, it’s okay, it happens. But if you do
half the exercices because you’re lazy, and leave at 2PM, you **WILL** have problems.
Do not tempt the devil.

```
The*alloc,free,*printf,openandfopenfunctions, as well as theusing namespacekey-
word, are forbidden in C++.
By the way,friendis forbidden too, as well as any library except the standard one.
```

## Unit Tests

It is highly recommended to test your functions as you implement them. It is common practice to create
and use what are called **unit tests**.

From now on, we expect you to write unit tests for your functions (when possible). To do so, please follow
the instructions in the **“How to write Unit Tests”** document on the intranet, available here.


## Exercise 0 - Encapsulation

**Turn in** :Picture.hpp,Picture.cpp,Toy.hpp,Toy.cpp

You are going to create some basic toys for you to play with, each with a picture (so you can know what it
looks like!).
More features will be added to these toys in the following exercises.

Start by creating aPictureclass to represent our toys’ illustrations.
It must contain, publicly:

1. std:: string data;

Our toy’s ASCII art.

2. bool getPictureFromFile(const std:: string &file);

Setsdata’s value to the content offile.
If an error occurs,datamust be set to _“ERROR”_ and the function must returnfalse.
Otherwise, it returnstrue.

3. Picture(const std:: string &file);

Creates aPictureobject by loading the content offile.
If an error occurs,datamust be set to _“ERROR”_.
Creating aPicturewithout a filename as parameter setsdatato an empty string.

Now, create aToyclass.
It must contain aToyTypeenumeration with two fields:BASIC_TOYandALIEN.

TheToyclass must contain a type, a name and a picture, as well as the following member functions:

- getType, a getter for the toy’s type (there is no setter, as the type will never change),
- getName,
- setName,
- setAsciithat takes a filename as parameter and sets the toy’s picture to the file’s content.
    Returnstrueif it succeeds,falseotherwise,
- getAsciithat returns the toy’s picture as astring,
- a constructor taking no parameter, setting the toy’s type toBASIC_TOY, its name to _“toy”_ and its picture
    to an emptystring,
- a constructor taking three parameters: theToyType, astringcontaining the toy’s name, and astring
    containing the picture’s filename.


Here is a samplemainfunction and its expected output:

#include <iostream >
#include "Toy.hpp"

int main()
{
Toy toto;
Toy ET(Toy::ALIEN , "green", "./ alien.txt");

```
toto.setName("TOTO !");
```
if (toto.getType () == Toy:: BASIC_TOY)
std::cout << "basic toy: " << toto.getName () << std::endl
<< toto.getAscii () << std::endl;
if (ET.getType () == Toy:: ALIEN)
std::cout << "this alien is: " << ET.getName () << std::endl
<< ET.getAscii () << std::endl;
return 0;
}

### ∇ Terminal - + x

```
∼/B-CPP-300> ./a.out
basic toy: TOTO!
```
```
this alien is: green
_|_
,_.-_' _ '_-._,
\ (.)(.)(.) /
_, `\_-===-_/` ,_
> |----"""""----| <
`""`--/ _-@-\--`""`
|=== L_I ===|
\ /
_\__|__/_
`""""`""""`
```

## Exercise 1 - Canonical form

**Turn in** :Picture.hpp,Picture.cpp,Toy.hpp,Toy.cpp

Re-use the two classes from the previous exercise and make them comply with the canonical form.

```
This may imply more than meets the eye...
```
## Exercise 2 - Simple inheritance

**Turn in** :Picture.hpp/cpp,Toy.hpp/cpp,Buzz.hpp/.cpp,Woody.hpp/cpp

Add two values to theToyTypeenumeration:BUZZandWOODY, and create two newBuzzandWoodyclasses.

These two classes inherit fromToy, and set their parent’s attributes to the corresponding values upon con-
struction:

- type:BUZZandWOODY, respectively
- name: passed as parameter
- ascii: optionally passed as parameter.
    If no filename is provided, the objects will respectively load their picture from the _“buzz.txt”_ and
    _“woody.txt”_ files.

```
It shouldn’t be possible to createBuzzorWoodyobjects without a name.
```

## Exercise 3 - Ponymorphism

**Turn in** :Picture.hpp/cpp,Toy.hpp/cpp,Buzz.hpp/.cpp,Woody.hpp/cpp

We’d like our toys to be able to speak.
Add aspeakmethod to theToyclass, taking the statement to say as a parameter.

This method displays the toy’s name, followed by a space and the statement passed as parameter.

```
[NAME] "[ STATEMENT ]"
```
Overload this method in theBuzzandWoodyclasses in order to display (respectively):

```
BUZZ: [NAME] "[ STATEMENT ]"
WOODY: [NAME] "[ STATEMENT ]"
```
```
In all three cases, [NAME] is to be replaced with the toy’s name and [STATEMENT] with
thestringpassed as parameter.
```
```
The double quotes in the examples must be printed.
```
Thespeakmethod must **not** beconst.
You’ll understand why in the following exercises.

Here is a samplemainfunction and its expected output:

#include <iostream >
#include <memory >
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main()
{
std:: unique_ptr <Toy > b(new Buzz("buzziiiii"));
std:: unique_ptr <Toy > w(new Woody("wood"));
std:: unique_ptr <Toy > t(new Toy(Toy::ALIEN , "ET", "alien.txt"));

b->speak("To the code , and beyond !!!!!!!!");
w->speak("There's a snake in my boot.");
t->speak("the claaaaaaw");
}

### ∇ Terminal - + x

```
∼/B-CPP-300> ./a.out
BUZZ: buzziiiii “To the code, and beyond !!!!!!!!”
WOODY: wood “There’s a snake in my boot.”
ET “the claaaaaaw”
```

## Exercise 4 - Operators

**Turn in** :Picture.hpp/cpp,Toy.hpp/cpp,Buzz.hpp/.cpp,Woody.hpp/cpp

You will now add two operator overloads.

A first overload of the<<operator, between anstd::ostreamand aToy.
This operator will print the toy’s name, followed by its picture, on the givenstd::ostream.
The name and picture will have to be followed by a newline.

A second overload the<<operator, between aToyand astring.
This operator will replace theToy’s picture with thestring.

Here is a samplemainfunction and its expected output:

#include <iostream >
#include "Toy.hpp"

int main()
{
Toy a(Toy::BASIC_TOY , "REX", "rex.txt");

std::cout << a;
a << "\\o/";
std::cout << a;
}

### ∇ Terminal - + x

```
∼/B-CPP-300> ./a.out
REX
_
| |
| |
| __| '__/ _ \ \/ /
| |_| | | __/> <
\__|_| \___/_/\_\
REX
\o/
```

## Exercise 5 - Nesting

**Turn in** :Picture.hpp/cpp,Toy.hpp/cpp,Buzz.hpp/.cpp,Woody.hpp/cpp

We know some toys have several options: for example, our Buzz Lightyear toy can speak spanish!
To illustrate this, add aspeak_esmethod to theToyclass, with the same signature asspeak.
In theBuzzclass, this method must have the same behavior asspeakbut must add _“senorita”_ before and
after the statement:

BUZZ: name senorita "statement" senorita

However, some toys don’t speak spanish, so we have to handle this case.
For every toy that can’t speak spanish, thespeak_esmethod doesn’t display anything and returnsfalse.

Let’s make the most of our error handling in theToyclass.
We currently have two possible error causes:

- setAscii
- speak_es

Both returnfalsein the event an error occured.

Create a nestedErrorclass inToythat contains two methods and a public attribute:

- what: returns the error message:
    - _“bad new illustration”_ if the error happened insetAscii
    - _“wrong mode”_ if the error happend inspeak_es
- where: returns the name of the function where the error occured,
- type: holds the error type.

Moreover,Errormust contain anErrorTypeenum with the different error types:

- UNKNOWN
- PICTURE
- SPEAK

Add agetLastErrorto theToyclass that will return anErrorobject containing information about the last
error that occured.
If no error happened,getLastErrorreturns anErrorinstance with two empty strings forwhatandwhere, and
hasUNKNOWNas its type.


Here is a samplemainfunction and its expected output:

#include <iostream >
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main()
{
Woody w("wood");

```
if (w.setAscii("file_who_does_not_exist.txt") == false)
{
auto e = w.getLastError ();
if (e.type == Toy:: Error:: PICTURE)
{
std::cout << "Error in " << e.where() << ": " << e.what() <<
std::endl;
}
}
```
```
if (w.speak_es("Woody does not have spanish mode") == false)
{
auto e = w.getLastError ();
if (e.type == Toy:: Error:: SPEAK)
{
std::cout << "Error in " << e.where() << ": " << e.what() <<
std::endl;
}
}
```
if (w.speak_es("Woody does not have spanish mode") == false)
{
auto e = w.getLastError ();
if (e.type == Toy:: Error:: SPEAK)
{
std::cout << "Error in " << e.where() << ": " << e.what() <<
std::endl;
}
}
}

### ∇ Terminal - + x

```
∼/B-CPP-300> ./a.out
Error in setAscii: bad new illustration
Error in speak_es: wrong mode
Error in speak_es: wrong mode
```

## Exercise 6 - A Toy Story

**Turn in** :Picture.hpp/cpp,Toy.hpp/cpp,Buzz.hpp/.cpp,Woody.hpp/cpp,ToyStory.hpp/cpp

Create aToyStoryclass which tells stories about two toys.

ToyStorycontains atellMeAStoryclass function that takes 5 parameters:

- a filename containing the story,
- the firstToy, which we’ll calltoy1,
- aToymethod pointer taking astringas parameter and returning a boolean, which we’ll callfunc1,
- the secondToy, which we’ll calltoy2,
- aToymethod pointer taking astringas parameter and returning a boolean, which we’ll callfunc2.

TheseToyinstances and method pointers are respectively associated.
toy1is associated withfunc1andtoy2is associated withfunc2.

ThetellMeAStoryfunction starts by printing the twoToys’ pictures, each followed by a newline.
It then reads the file given as parameter, and for each line in it, calls the method pointer associated to the
toy.
The toys will be called on a rotating basis:

- the first line will be sent tofunc1ontoy1,
- the second tofunc2ontoy2,
- the third tofunc1ontoy1,
-...

If the line starts with _“picture:”_ , it changes the picture of the toy which was supposed to be called.
The toy’s new picture is then set to the content of the file specified after the _“picture:”_ mention.
The toy’s picture is then displayed.


For instance, with the following file:

### ∇ Terminal - + x

```
∼/B-CPP-300> cat story.txt
hi
picture:ham.txt
nothing special
CU
```
The actions must be the following:

- printtoy1’s picture followed by a newline,
- printtoy2’s picture followed by a newline,
- callfunc1ontoy1with _“hi”_ ,
- settoy2’s picture to the content of the _“ham.txt”_ file,
- printtoy2’s picture,
- callfunc2ontoy2with _“nothing special”_ ,
- callfunc1ontoy1with _“CU”_.

tellMeAStorystops as soon as it encounters an error (if it fails to change a toy’s picture, for instance).
If an error occurs, print information about it using the following format:

where: what

wheremust be replaced with the error’swhereproperty, andwhatmust be replaced with the error’swhatprop-
erty.

If the file passed as parameter cannot be opened or read, print _“Bad Story”_ to the standard output.

Here is a samplemainfunction:

#include <iostream >
#include "Toy.hpp"
#include "ToyStory.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main()
{
Buzz b("buzzi");
Woody w("wood");

ToyStory :: tellMeAStory("superStory.txt", b, &Toy::speak_es , w, &Toy::speak);
}


