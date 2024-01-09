#!/usr/bin/python3
"Defining from_json_string function"""


import json


def from_json_string(my_str):
    """return Json string"""
    return json.load(my_str)

