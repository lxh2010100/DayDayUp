#!encoding=UTF-8
import unittest
import sys
from vector import Vector
import os

from ddt import data, ddt
# import HTMLTestRunner

list1 = [1, 2, 3, 4, 5]


@ddt
class TestVector(unittest.TestCase):
    def setUp(self):
        print("begin")

    def tearDown(self):
        print("end")

    # @unittest.skipIf(i % 2, "you can skip this test")
    @data(*list1)
    def test_add_1(self, list1):
        print(list1)
        obj = Vector(list1, 2)
        # self.assertEqual(obj.add(), 3)
        print("test run ..................")
        print("list1+2=" + str(list1))

    # @unittest.skipIf(False, "you can skip this test")
    # def test_add_2(self):
    #     obj = Vector(1, 2)
    #     self.assertEqual(obj.add(), 3)
    #     print("test run 222 ..................")

    # def test_sub_1(self):
    #     obj = Vector(5, 2)
    #     self.assertEqual(obj.sub(), 3)


if __name__ == '__main__':
    unittest.main()
