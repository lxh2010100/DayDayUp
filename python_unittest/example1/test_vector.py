#!encoding=UTF-8
import unittest
import sys
from vector import Vector
import os


class TestVector(unittest.TestCase):
    def setUp(self):
        print("begin")

    def tearDown(self):
        print("end")

    def test_add_1(self):
        obj = Vector(1, 2)
        self.assertEqual(obj.add(), 3)

    def test_add_2(self):
        obj = Vector(3, 2)
        self.assertEqual(obj.add(), 5)

    def test_sub_1(self):
        obj = Vector(5, 2)
        self.assertEqual(obj.sub(), 3)


if __name__ == '__main__':
    unittest.main()
