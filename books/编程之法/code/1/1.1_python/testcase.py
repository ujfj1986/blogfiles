#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
########################
# @file: testcase.py
# @author: Jiejing Shan
# @descripte: 这个文件实现了从TestCase.json文件中导入测试case的功能
# @date:
#
########################

import sys
import json
import os

class TestCase (object):
    name = "TestCase"
    def __init__(self):
        self._params = {}
        self._result = None

    def get(self, prop:str):
        if prop in self._params:
            return self._params[prop]
        return None

    def result(self):
        return self._result;

    def __set__(self, instance, value):

class TestCase1_1(TestCase):
    def __init__(self):



def loadTestCases(fpath:str):
    with open(fpath) as fp:
        jsondata = json.load(fp)
        version = jsondata["version"]
        if not version or version != 0.1:
            return None
        case_len = len(jsondata["cases"])


