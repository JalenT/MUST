# MUST - Mostly Used for Saving Time

## Table of Contents
* [Overview](#user-content-overview)
* [Motivation](#user-content-motivation)
* [Usage](#user-content-usage)
* [Examples](#user-content-examples)

## Overview
[Back to Top](#)

This repository is a collection of generic data structures in the C programming language.

This is under the MIT License. Feel free to use this repository wherever you desire.

## Motivation
[Back to Top](#)

I hope for this library for me to learn, and to save time if data structures are needed in a project in C.
Even though the intent is mostly for my purposes, feel free to include this in any project you're working on, or submit a pull request.

## Usage
[Back to Top](#)

Before you know how to use the project, you should have a basic overview of how it works.

### How It Works
[Back to Top](#)

There are a variety of different ways of implementing generic data structures in C, but the two ways I was thinking about when making this repository are:
1. ```void*``` (How data structures are traditionally implemented in C)
2. Macros (Similar to C++ templates)

There are advantages & disadvantages to both of these options, which I'll share some below.
* Using macros, it would increase the size of your binary, because you need multiple versions of a data structures that are identical except for the type.
* Using ```void*```, you circumvent the type system in C.
* Using ```void*```, it's more complicated to use data structures, especially with non-pointer types.

Because I want type safety & simplicity in my data structures, I'm using macros to implement the data structures.

### How To Use
[Back to Top](#)

Usage of the data structures is similar to C++ templates, just with functions instead of methods.

For example, a pointer to a singly linked list of integers would be declared like this.
```C
must_slist_node(int) *slist;
```
But you could also declare it like this.
```C
must_slist_node_int *slist;
```
And both of these would be the same.

Another example, you could allocate the singly linked list shown above like this.
```C
slist = must_slist_node_new(int)();
```
Or like this.
```C
slist = must_slist_node_new_int();
```
And other functions are called similar to the one above.

## Examples
[Back to Top](#)

Also, in all of the data structures, there is an example folder, with a Makefile and example source code.
Everything can be compiled into object files, and static libraries, will shared object support on Windows coming soon.
