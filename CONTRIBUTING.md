# How To Contribute

## Table Of Contents
* [Setting Up Environment](#setting-up-environment)
* [Style Guide](#style-guide)
* [Final Words](#final-words)

## Setting Up Environment
All you need is a compiler in C, and clang format (I talk more about that in the [Style Guide](#style-guide).
If you're using Windows, I would recommend going to [winlibs.com](http://winlibs.com/).
They have a MinGW installation that's easy to install, and also comes with the LLVM toolkit if you want, which includes clang-format.
It's easy to use, doesn't need Cygwin or MSYS2 like most other installations, and is what I am personally using at the time of writing.

## Style Guide
We are using C11 for this project, mainly because C99 is not really fully implemented anywhere, and C89 would be a pain to program in, especially with declaring all variables at the start of a block.
Also, C11 comes with ```static_assert```, which is a cool upgrade from ```assert```.

The rest of the style guide is in the [.clang-format](.clang-format) file in the root of the project.
I would recommend downloading clang-format, and using it before committing a pull request.
If not already done, I will set up something to make sure that everything is still conforming to the style guide in the [.clang-format](.clang-format) file.

## Final Words
Feel free to make a pull request, I'll try to get back to you as soon as I can.
