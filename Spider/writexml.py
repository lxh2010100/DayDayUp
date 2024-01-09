
import xml.etree.ElementTree as ET
import xml.dom.minidom as md
root = ET.Element('students')   # 创建根元素
student1 = ET.SubElement(root, 'student', id='001')   # 创建子元素并添加属性
name1 = ET.SubElement(student1, 'name')   # 创建子元素
name1.text = 'Tom'   # 设置子元素文本
name1 = ET.SubElement(student1, 'name2')   # 创建子元素
name1.text = 'Tom3'   # 设置子元素文本
age1 = ET.SubElement(student1, 'age')
age1.text = '12'
student2 = ET.SubElement(root, 'student', id='002')
name2 = ET.SubElement(student2, 'name')
name2.text = 'Jerry'
age2 = ET.SubElement(student2, 'age')
age2.text = '13'
tree = ET.ElementTree(root)   # 创建 ElementTree 对象
tree.write('example.xml')     # 写入 XML 文件

with open('example.xml') as f:
    uglyxml = f.read()
    beautiful_xml = md.parseString(uglyxml).toprettyxml()
    with open('example_beautiful.xml', 'w') as f:
        f.write(beautiful_xml)
