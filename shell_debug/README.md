Shell脚本进行Debug调试的三种方法如下：

1. 在调用脚本的时候开启deubg

```shell
sh -x shell.sh
```
2. 在脚本文件首行开启deubg
```shell
#!/bin/bash -x  
```
3. 使用set开启deubg
```shell
set -x
```
4. -v 显示脚本所有行，详细模式，在脚本嵌套调用时比较有用
```shell
```sh -v shell.sh
```
5. -n 检查脚本的语法，不执行脚本的命令 登录后复制
```shell
sh -n shell.sh
```

PS1~4原是shell中内置的环境变量，我们来查看一下：

```shell
node2:~ # echo $PS4
+
node2:~ # set | grep PS4
PS4='+ '
node2:~ # 
```
因此我们就可以增加一些内置变量来重新定义$PS4的值，增强-x选项的输出信息。例如在我们的代码内部可以这样写：

```shell
set -x xtrace
_ps4=$PS4
export PS4='+{\$LINENO:${FUNCNAME[0]}} '
#执行我们的代码
....
```
配合-x选项来执行脚本，就能在每一条实际执行的命令前面显示其行号以及所属的函数名。
