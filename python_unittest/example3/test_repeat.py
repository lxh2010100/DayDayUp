# encoding=utf-8
import unittest
from ddt import data, ddt


@ddt
class test_suite (unittest.TestCase):
    global test_info
    # 这里可以修改和添加test_info变量的内容和属性

    test_info = []
    for i in range(100):
        test_data = (i, i+1)
        test_info.append(test_data)

    @data(*test_info)  # 这里很多教程会用 @unpack 其实不需要的打包好数据再重新放入test_info中
    def test_case(self, test_info):
        print(test_info)


if __name__ == '__main__':
    unittest.main()
