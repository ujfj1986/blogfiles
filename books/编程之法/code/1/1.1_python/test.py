#!/usr/bin/env python3
# -*- coding:utf-8 -*-

class A(object):
    name = "A"

    def __get__(self, ins, owner):
        print(self)
        print(ins)
        print(owner)
        return self.name

class B(object):
    a = A()

a = A()
print(a.name)
print(a)
b = B()
b.c = a
print(b.a)
print(b.c)