@[TOC](文章目录)

 



# Linux下基本指令  





# 1. 学习 Linux 终端命令的原因



- Linux 刚面世时并没有图形界面，所有的操作全靠命令完成，如 **磁盘操作**、**文件存取**、**目录操作**、**进程管理**、**文件权限** 设定等

- 在职场中，大量的 **服务器维护工作** 都是在 **远程** 通过 **SSH 客户端** 来完成的，并没有图形界面，所有的维护工作都需要通过命令来完成

- 在职场中，作为后端程序员，必须要或多或少的掌握一些 Linux 常用的终端命令

- Linux 发行版本的命令大概有 200 多个，但是常用的命令只有 10 多个而已



学习终端命令的技巧：

- 不需要死记硬背，对于常用命令，用的多了，自然就记住了

- 不要尝试一次学会所有的命令，有些命令是非常不常用的，临时遇到，临时百度就可以



---

**常用命令汇总**

| 序号 | 命令           | 对应英文             | 作用                     |
| ---- | -------------- | -------------------- | ------------------------ |
| 01   | ls             | list                 | 查看当前文件夹下的内容   |
| 02   | pwd            | print work directory | 查看当前所在文件夹       |
| 03   | cd [目录名]    | change directory     | 切换文件夹               |
| 04   | touch [文件名] | touch                | 如果文件不存在，新建文件 |
| 05   | mkdir [目录名] | make directory       | 创建目录                 |
| 06   | rm [文件名]    | remove               | 删除指定的文件名         |
| 07   | clear          | clear                | 清屏                     |



----





# 2.ls 指令  

**语法**： ls [选项] [目录或文件]
**功能**：对于目录，该命令列出该目录下的所有子目录与文件。对于文件，将列出文件名以及其他信息。  



| 选项 | 功能                                                         |
| ---- | ------------------------------------------------------------ |
| -a   | 列出目录下的所有文件，包括以 . 开头的隐含文件。              |
| -d   | 将目录象文件一样显示，而不是显示其下的文件。 如： ls –d 指定目录 |
| -i   | 输出文件的 i 节点的索引信息。 如 ls –ai 指定文件             |
| -k   | 以 k 字节的形式表示文件的大小。 ls –alk 指定文件             |
| -l   | 列出文件的详细信息。                                         |
| -r   | 对目录反向排序  。                                           |
| -t   | 以时间排序。                                                 |
| -s   | 在l文件名后输出该文件的大小。（大小排序，如何找到目录下最大的文件） |
| -R   | 列出所有子目录下的文件。 (递归)                              |



**注意选项是可以一次多个组合使用的，比如ls -sr  是对文件排序大小后反向输出**

```shell
[root@Centos7 ~]# ls
b  dir  hdm  install.sh  test.txt
[root@Centos7 ~]# ls -s    ## 这个是大小排序
  0 b    4 dir    4 hdm    4 install.sh  168 test.txt
[root@Centos7 ~]# ls -rs   ## 加-r后反向输出
168 test.txt    4 install.sh    4 hdm    4 dir    0 b

```



----



# 3.pwd命令  



**语法**: pwd
**功能**：显示用户当前所在的目录  

常用选项：  **无**



![image-20221001145800550](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210011458332.png)





----

# 4.cd 指令  

**语法**:cd 目录名
功能：**改变工作目录。将当前工作目录改变到指定的目录下。**  





Linux系统中，磁盘上的文件和目录被组成一棵目录树，每个节点都是目录或文件。  



![image-20221001150038010](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210011500220.png)





```shell
cd .. : 返回上级目录
cd /home/litao/linux/ : 绝对路径
cd ../day02/ : 相对路径
cd ~：进入用户家目
cd -：返回最近访问目录
```





----



# 5. touch指令  

**语法**:touch [选项]... 文件...
**功能**： **touch命令参数可更改文档或目录的日期时间，包括存取时间和更改时间，或者新建一个不存在的文件。**





| 选项 | 功能                                                         |
| ---- | ------------------------------------------------------------ |
| -a   | 或--time=atime或--time=access或--time=use只更改存取时间      |
| -c   | 或--no-create 不建立任何文档                                 |
| -d   | 使用指定的日期时间，而非现在的时间                           |
| -t   | 把指定文档或目录的日期时间，统统设成和参考文档或目录的日期时间相同 |



比如：创建一个普通文件test.c 



```shell
[root@Centos7 hdm]# touch test.c
[root@Centos7 hdm]# ls
test.c
```







----



# 6. mkdir指令（重要）



**语法**： mkdir [选项] dirname...
**功能**：在当前目录下创建一个名为 “dirname”的目录
常用选项：  



| 选项 | 功能                                                         |
| ---- | ------------------------------------------------------------ |
| -p   | --parents 可以是一个路径名称。此时若路径中的某些目录尚不存在,加上此选项后,系统将自动建立好那些尚不存在的目录,即一次可以建立多个目录 |



比如：创建一个目录mydir（文件夹）



```shell
[root@Centos7 hdm]# mkdir mydir
[root@Centos7 hdm]# ls
 mydir

```



```shell
[root@Centos7 mydir]# mkdir  -p  a/b/c/d  ## 递归建立多个目录
[root@Centos7 mydir]# tree . ## 以树状结构递归展示当前目录下的文件
.
└── a
    └── b
        └── c
            └── d

4 directories, 0 files

```





----



# 7. rmdir指令 && rm 指令（重要）  





**rmdir是一个与mkdir相对应的命令。 mkdir是建立目录，而rmdir是删除命令。**
**语法**： rmdir [-p] [dirName]
**适用对象**：具有当前目录操作权限的所有使用者
**功能**：删除空目录

| 常用选项 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| -p       | 当子目录被删除后如果父目录也变成空目录的话，就连带父目录一起删除。 |



```shell
[root@Centos7 c]# tree .
.
└── d

1 directory, 0 files
[root@Centos7 c]# rmdir d
[root@Centos7 c]# tree .
.

0 directories, 0 files

```



**注意**：rmdir只能删除空目录

例如：

```shell
[root@Centos7 mydir]# tree .
.
└── a
    └── b
        └── c

3 directories, 0 files
[root@Centos7 mydir]# rmdir -p a
rmdir: failed to remove ‘a’: Directory not empty  ##提示目录不为空，无法删除 

```

**正确的做法**：要删除非空的目录，需要用到**rm命令**





**rm命令可以同时删除文件或目录**
** 语法** ： rm [-f-i-r-v] [dirName/dir]
**适用对象 **：所有使用者
**功能**：删除文件或目录  



| 常用选项 | 功能                                     |
| -------- | ---------------------------------------- |
| -f       | 即使文件属性为只读(即写保护)，亦直接删除 |
| -i       | 删除前逐一询问确认                       |
| -r       | 删除目录及其下所有文件                   |



例如

```shell
[root@Centos7 mydir]# tree .
.
└── a
    └── b
        └── c

3 directories, 0 files
[root@Centos7 mydir]# rm -rf a ## -rf强制递归删除目录，不用提示
[root@Centos7 mydir]# tree .
.

0 directories, 0 files

```



---





# 8. man指令（重要）  



Linux的命令有很多参数，我们不可能全记住，我们可以通过查看联机手册获取帮助。访问Linux手册页的命令是
man **语法**: man [选项] 命令  

| 常用选项 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| -k       | 根据关键字搜索联机帮助                                       |
| num      | 只在第num章节找  例如：man 3  printf （则在第3章找printf函数） |
| -a       | 将所有章节的都显示出来，比如 man printf 它缺省从第一章开始搜索，知道就停止，用a选项，当按<br/>下q退出，他会继续往后面搜索，直到所有章节都搜索完毕 |

注意：**进入手册后按q退出**

面手册分为8章  



1. 是普通的命令

2. 是系统调用,如open,write之类的(通过这个，至少可以很方便的查到调用这个函数，需要加什么头文
   件)

3. 是库函数,如printf,fread4是特殊文件,也就是/dev下的各种设备文件

5. 是指文件的格式,比如passwd, 就会说明这个文件中各个字段的含义

6. 是给游戏留的,由各个游戏自己定义

7. 是附件还有一些变量,比如向environ这种全局变量在这里就有说明

8. 是系统管理用的命令,这些命令只能由root使用,如ifconfig  





---





# 9. cp指令（重要）  





**语法**： cp [选项] 源文件或目录 目标文件或目录
**功能**: 复制文件或目录
**说明**: cp指令用于复制文件或目录，如同时指定两个以上的文件或目录，且最后的目的地是一个已经存在的目录，
则它会把前面指定的所有文件或目录复制到此目录中。若同时指定多个文件或目录，而最后的目的地并非一个已存
在的目录，则会出现错误信息  





| 常用选项 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| -f       | 或 --force 强行复制文件或目录， 不论目的文件或目录是否已经存在 |
| -i       | 或 --interactive 覆盖文件之前先询问用户                      |
| -r       | 递归处理，将指定目录下的文件与子目录一并处理。若源文件或目录的形态，不属于目录或符号链<br/>接，则一律视为普通文件处理 |
| -R       | 或 --recursive递归处理，将指定目录下的文件及子目录一并处理   |

列如：

```shell
[root@Centos7 mydir]# tree .
.
├── a
│   └── b
│       └── c
│           └── d
└── testdir

5 directories, 0 files
[root@Centos7 mydir]# cp -r a testdir ## 将a中的所有文件递归拷贝到testdir中
[root@Centos7 mydir]# tree .
.
├── a
│   └── b
│       └── c
│           └── d
└── testdir
    └── a
        └── b
            └── c
                └── d

9 directories, 0 files

```





---



# 10. mv指令（重要）  



1. **视mv命令中第二个参数类型的不同（是目标文件还是目标目录）， mv命令将文件重命名或将其移至一个新的
   目录中。**

2. **当第二个参数类型是文件时， mv命令完成文件重命名，此时，源文件只能有一个（也可以是源目录名），它
   将所给的源文件或目录重命名为给定的目标文件名。**

3. **当第二个参数是已存在的目录名称时，源文件或目录参数可以有多个， mv命令将各参数指定的源文件均移至
   目标目录中。  **



| 常用选项 | 功能                                                       |
| -------- | ---------------------------------------------------------- |
| -f       | force 强制的意思，如果目标文件已经存在，不会询问而直接覆盖 |
| -i       | 若目标文件 (destination) 已经存在时，就会询问是否覆盖      |



列如：

```shell
[root@Centos7 mydir]# ls
a  testdir
[root@Centos7 mydir]# mv a .. ## 将mydir中的a文件夹移动到上级目录
[root@Centos7 mydir]# cd ..
[root@Centos7 hdm]# ls 
a   mydir  
[root@Centos7 hdm]# tree mydir ## 再次查看mydir可以看到a文件夹已经不存在了
mydir
└── testdir
    └── a
        └── b
            └── c
                └── d

5 directories, 0 files
```









# 11. cat指令  



**语法**： cat [选项] [文件]
**功能**： 查看目标文件的内容  





| 常用选项 | 功能               |
| -------- | ------------------ |
| -b       | 对非空输出行编号   |
| -n       | 对输出的所有行编号 |
| -s       | 不输出多行空行     |



---



# 12. more指令  





**语法**： more [选项] [文件]
**功能**： more命令，功能类似 cat  





注意：**按q  退出more**  





----



# 13. less指令（重要）  

**语法**： less [参数] 文件
**功能**：
less与more类似，但使用less可以随意浏览文件，而more仅能向前移动，却不能向后移动，而且less在查看之前
不会加载整个文件。  





>less 工具也是对文件或其它输出进行分页显示的工具，应该说是linux正统查看文件内容的工具，功能极
>其强大。
>less 的用法比起 more 更加的有弹性。在 more 的时候，我们并没有办法向前面翻， 只能往后面看
>但若使用了 less 时，就可以使用 [pageup] [pagedown] 等按键的功能来往前往后翻看文件，更容易用
>来查看一个文件的内容！
>除此之外，在 less 里头可以拥有更多的搜索功能，不止可以向下搜，也可以向上搜  







| 常用选项 | 功能                                 |
| -------- | ------------------------------------ |
| -i       | 忽略搜索时的大小写                   |
| -N       | 显示每行的行号                       |
| /字符串  | 向下搜索“字符串”的功能               |
| n        | 重复前一个搜索（与 / 或 ? 有关）     |
| N        | 反向重复前一个搜索（与 / 或 ? 有关） |
| q        | quit                                 |





----



# 14. head指令  





head 与 tail 就像它的名字一样的浅显易懂，它是用来显示开头或结尾某个数量的文字区块， head 用来显示档案的
开头至标准输出中，而 tail 想当然尔就是看档案的结尾。
**语法**： head [参数]... [文件]...
**功能**：
head 用来显示档案的开头至标准输出中，默认head命令打印其相应文件的开头10行。



| 常用选项 | 功能              |
| -------- | ----------------- |
| -n       | <行数> 显示的行数 |







----



# 15. tail指令  



tail 命令从指定点开始将文件写到标准输出.使用tail命令的-f选项可以方便的查阅正在改变的日志文件,tail -f filename会把filename里最尾部的内容显示在屏幕上,并且不但刷新,使你看到最新的文件内容.
**语法**： tail[必要参数] [选择参数] [文件]
**功能**： 用于显示指定文件末尾内容，不指定文件时，作为输入信息进行处理。常用查看日志文件。  



| 常用选项 | 功能     |
| -------- | -------- |
| -f       | 循环读取 |
| -n<行数> | 显示行数 |







------





# 16. 时间相关的指令  





1.**date显示**  



date 指定格式显示时间： date +%Y:%m:%d
date 用法： date [OPTION]... [+FORMAT]  



**1.在显示方面，使用者可以设定欲显示的格式，格式设定为一个加号后接数个标记，其中常用的标记列表如下  **



| 常用选项 | 功能                  |
| -------- | --------------------- |
| %H       | 小时(00..23)          |
| %M :     | 分钟(00..59)          |
| %S       | 秒(00..61)            |
| %X       | 相当于 %H:%M:%S       |
| %d       | 日 (01..31            |
| %m       | 月份 (01..12)         |
| %Y       | 完整年份 (0000..9999) |
| %F       | 相当于 %Y-%m-%d       |



```shell
[root@Centos7 ~]# date +%Y
2022
[root@Centos7 ~]# date +%Y/%m/%d/%H/%M/%S
2022/10/01/19/39/31
```



2.**在设定时间方面**





| date -s                            | 设置当前时间，只有root权限才能设置，其他只能查看       |
| ---------------------------------- | ------------------------------------------------------ |
| **date -s 20080523  **             | **设置成20080523，这样会把具体时间设置成空00:00:00  ** |
| **date -s 01:01:01   **            | **设置具体时间，不会对日期做更改  **                   |
| **date -s “01:01:01 2008-05-23  ** | **这样可以设置全部时间  **                             |
| **date -s “01:01:01 20080523  **   | **这样可以设置全部时间  **                             |
| **date -s “2008-05-23 01:01:01  ** | **这样可以设置全部时间  **                             |
| **date -s “20080523 01:01:01 **    | **这样可以设置全部时间  **                             |

  



3.**时间戳 **

时间->时间戳： date +%s
时间戳->时间： date -d@1508749502
Unix时间戳（英文为Unix epoch, Unix time, POSIX time 或 Unix timestamp）是从1970年1月1日（UTC/GMT的
午夜）开始所经过的秒数，不考虑闰秒  



```shell
[root@centos7 ~]# date -d@0
Thu Jan  1 00:00:00 UTC 1970
```







---



# 17. Cal指令 





cal命令可以用来显示公历（阳历）日历。公历是现在国际通用的历法，又称格列历，通称阳历。 “阳历”又名“太阳
历”，系以地球绕行太阳一周为一年，为西方各国所通用，故又名“西历”。   





**命令格式**： cal [参数] [月份] [年份]
**功能**： 用于查看日历等时间信息，如只有一个参数，则表示年份(1-9999)，如有两个参数，则表示月份和年份  



| 常用选项 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| -3       | 显示系统前一个月，当前月，下一个月的月历                     |
| -j       | 显示在当年中的第几天（一年日期按天算，从1月1号算起，默认显示当前月在一年中的天数） |
| -y       | 显示当前年份的日历                                           |





```shell
[root@Centos7 ~]# cal -y               ##显示当前年份的日历
                               2022                               

       January               February                 March       
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
                   1          1  2  3  4  5          1  2  3  4  5
 2  3  4  5  6  7  8    6  7  8  9 10 11 12    6  7  8  9 10 11 12
 9 10 11 12 13 14 15   13 14 15 16 17 18 19   13 14 15 16 17 18 19
16 17 18 19 20 21 22   20 21 22 23 24 25 26   20 21 22 23 24 25 26
23 24 25 26 27 28 29   27 28                  27 28 29 30 31
30 31
        April                   May                   June        
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
                1  2    1  2  3  4  5  6  7             1  2  3  4
 3  4  5  6  7  8  9    8  9 10 11 12 13 14    5  6  7  8  9 10 11
10 11 12 13 14 15 16   15 16 17 18 19 20 21   12 13 14 15 16 17 18
17 18 19 20 21 22 23   22 23 24 25 26 27 28   19 20 21 22 23 24 25
24 25 26 27 28 29 30   29 30 31               26 27 28 29 30

        July                  August                September     
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
                1  2       1  2  3  4  5  6                1  2  3
 3  4  5  6  7  8  9    7  8  9 10 11 12 13    4  5  6  7  8  9 10
10 11 12 13 14 15 16   14 15 16 17 18 19 20   11 12 13 14 15 16 17
17 18 19 20 21 22 23   21 22 23 24 25 26 27   18 19 20 21 22 23 24
24 25 26 27 28 29 30   28 29 30 31            25 26 27 28 29 30
31
       October               November               December      
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
                   1          1  2  3  4  5                1  2  3
 2  3  4  5  6  7  8    6  7  8  9 10 11 12    4  5  6  7  8  9 10
 9 10 11 12 13 14 15   13 14 15 16 17 18 19   11 12 13 14 15 16 17
16 17 18 19 20 21 22   20 21 22 23 24 25 26   18 19 20 21 22 23 24
23 24 25 26 27 28 29   27 28 29 30            25 26 27 28 29 30 31
30 31
```







----



# 18. find指令  

**语法**： find pathname -options
**功能**： 用于在文件树种查找文件，并作出相应的处理（可能访问磁盘）  



| -name | 按照文件名查找文件 |
| ----- | ------------------ |



>Linux下find命令在目录结构中搜索文件，并执行指定的操作。
>Linux下find命令提供了相当多的查找条件，功能很强大。由于find具有强大的功能，所以它的选项也很
>多，其中大部分选项都值得我们花时间来了解一下。
>即使系统中含有网络文件系统( NFS)， find命令在该文件系统中同样有效，只你具有相应的权限。
>在运行一个非常消耗资源的find命令时，很多人都倾向于把它放在后台执行，因为遍历一个大的文件系
>统可能会花费很长的时间(这里是指30G字节以上的文件系统)  









-----



# 19. grep指令  



**语法**： grep [选项] 搜寻字符串 文件
**功能**： 在文件中搜索字符串，将找到的行打印出来  



| 常用选项 | 功能                                               |
| -------- | -------------------------------------------------- |
| -i       | 忽略大小写的不同，所以大小写视为相同               |
| -n       | 顺便输出行号                                       |
| -v       | 反向选择，亦即显示出没有 '搜寻字符串' 内容的那一行 |



```shell
[root@Centos7 ~]# grep 9999 test1
  9999	hello linux [9998]
 10000	hello linux [9999]
```



----





# 20. zip/unzip指令  



**语法**： zip 压缩文件.zip 目录或文件
**功能**： 将目录或文件压缩成zip格式

| -r   | 递归处理，将指定目录下的所有文件和子目录一并处理 |
| ---- | ------------------------------------------------ |



>将test2目录压缩： zip test2.zip test2/*
>解压到tmp目录： unzip test2.zip -d /tmp  

例如



```shell
[root@Centos7 ~]# zip -r test.zip dir     ##将dir文件夹压缩成test.zip
   adding: dir/ (stored 0%)
  adding: dir/a/ (stored 0%)
  adding: dir/a/b/ (stored 0%)
  adding: dir/a/b/c/ (stored 0%)
  adding: dir/a/b/c/d/ (stored 0%)
[root@Centos7 ~]# ls
  dir   test.zip
  
  
  ## unzip 
  [root@Centos7 ~]# ls
 dir  testdir    test.zip
[root@Centos7 ~]# unzip test.zip -d testdir    ##将test.zip解压到testdir中
Archive:  test.zip
   creating: testdir/dir/
   creating: testdir/dir/a/
   creating: testdir/dir/a/b/
   creating: testdir/dir/a/b/c/
   creating: testdir/dir/a/b/c/d/
[root@Centos7 ~]# tree testdir
testdir
└── dir
    └── a
        └── b
            └── c
                └── d

5 directories, 0 files

```



---





# 21. tar指令（重要）  



tar指令：打包/解包，不打开它，直接看内容



**tar [-cxtzjvf] 文件与目录 .... 参数**



| 常用选项 | 功能                                                       |
| -------- | ---------------------------------------------------------- |
| -c       | 建立一个压缩文件的参数指令(create 的意思)                  |
| -x       | 解开一个压缩文件的参数指令                                 |
| -t       | 查看 tarfile 里面的文件                                    |
| -z       | 是否同时具有 gzip 的属性？亦即是否需要用 gzip 压缩？       |
| -j       | 是否同时具有 bzip2 的属性？亦即是否需要用 bzip2 压缩？     |
| -v       | 压缩的过程中显示文件！这个常用，但不建议用在背景执行过程！ |
| -f       | 使用档名，请留意，在 f 之后要立即接档名喔！不要再加参数！  |
| -C       | 解压到指定目录                                             |



>特别注意，在参数 f 之后的文件档名是自己取的，我们习惯上都用 .tar 来作为辨识。
>如果加 **z 参数**，则以 .**tar.gz** 或 **.tgz **来代表 gzip 压缩过的 tar file ～
>如果加 **j 参数**，则以 **.tar.bz2 **来作为附档名啊  



列如

```shell
[hdm@centos7 ~]$ ls
a  test.c
[hdm@centos7 ~]$ tar -czf a.tgz a  ## 压缩文件,以gzip格式压缩
[hdm@centos7 ~]$ ls
a  a.tgz  test.c
[hdm@centos7 ~]$ rm -rf a
[hdm@centos7 ~]$ ls
a.tgz  test.c
[hdm@centos7 ~]$ tar -xzf a.tgz   ## 解压文件，以gzip格式解压
[hdm@centos7 ~]$ ls
a  a.tgz  test.c
```



```shell
[hdm@centos7 ~]$ ls
a  test.c
[hdm@centos7 ~]$ tar -cjf a.bz2 a  ## 压缩文件,以bzip2格式压缩
[hdm@centos7 ~]$ ls
a  a.bz2  test.c
[hdm@centos7 ~]$ rm -rf a
[hdm@centos7 ~]$ ls
a.bz2  test.c 
[hdm@centos7 ~]$ tar -xjf a.bz2   ## ## 解压文件，以bzip2格式解压
[hdm@centos7 ~]$ ls
a  a.bz2  test.c
```



-----





# 21. bc指令(计算器)



bc命令可以很方便的进行浮点运算  （也是Linux中的计算器）





```shell
[hdm@centos7 ~]$ bc
bc 1.06.95
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'. 
1+1
2
30*30
900
^C          ## 按键盘中的Ctrl+c退出
(interrupt) Exiting bc.
```







----





# 22. uname指令  



**语法**： uname [选项]
**功能**： uname用来获取电脑和操作系统的相关信息。
**补充说明**： uname可显示linux主机所用的操作系统的版本、硬件的名称等基本信息  



| -a  或–all | 详细输出所有信息，依次为内核名称，主机名，内核版本号，内核版本，硬件名，处理器类  型，硬件平台类型，操作系统名称 |
| ---------- | ------------------------------------------------------------ |
| **-r**     | **显示Linux内核的版本信息**                                  |



```shell
[hdm@centos7 ~]$ uname -r
3.10.0-1160.53.1.el7.x86_64
[hdm@centos7 ~]$ uname 
Linux
[hdm@centos7 ~]$ uname -a
Linux centos7 3.10.0-1160.53.1.el7.x86_64 #1 SMP Fri Jan 14 13:59:45 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
```



----



# 23.shutdown  （关机）指令



**语法**： shutdown [选项]  

| 常用选项 | 功能                                                         |
| -------- | ------------------------------------------------------------ |
| -h       | 将系统的服务停掉后，立即关机                                 |
| -r       | 在将系统的服务停掉之后就重新启动                             |
| -t sec   | -t 后面加秒数，亦即『过几秒后关机』的意思  ，例如shutdown -t 10   （10秒后关机） |





---





# 24. 一些零散却有用的指令+快捷键



lscpu：查看CPU信息



lsmem：查看内存信息



df -h： 查看硬盘使用情况



who：查看当前Linux在线用户



whoami ： 查看当前账号用户名



## 快捷键

tab 命令自动补全（常用）



Ctrl + c 终止前台异常程序



Ctrl + d 退出当前用户，退出一层



Ctrl + r  搜索历史命令，左右可选中







