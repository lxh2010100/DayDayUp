# encoding=utf-8
import unittest
import os
from ddt import ddt, data, unpack, file_data
import json

dict = {'key1': 'ls', 'key2': 'pwd',
        'key3': 'tree', 'key4': 'ls -alh', 'key5': 'cp --help'}

dict_copy = dict.copy()

dict2 = '''{"key1": "ls",
            "key2": "pwd",
            "key3": "tree", 
            "key4": "ls -alh", 
            "key5": "cp --help"}'''


@ddt
class test_suite (unittest.TestCase):

    # 这里很多教程会用 @unpack 其实不需要的打包好数据再重新放入test_info中
    @data(*(json.loads(dict2, strict=False)))
    # @data({"name1": "peter", "age1": 16, "addr1": "chengdu", "name2": "lily", "age2": 17, "addr2": "chengdu"})
    # @ unpack
    def test_case(self, key):
        print(key, dict_copy[key])
        os.system(dict_copy[key])
        print(type(dict2))


if __name__ == '__main__':
    unittest.main()
