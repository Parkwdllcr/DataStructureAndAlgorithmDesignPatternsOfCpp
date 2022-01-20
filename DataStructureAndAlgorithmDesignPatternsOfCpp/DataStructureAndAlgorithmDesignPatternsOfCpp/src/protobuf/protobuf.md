Windows C++

1、设置环境变量，新增protoc路径：…\ protoc-3.9.2-win32\bin\release

2、cmd 运行“protoc –version”，来确定已经配置正确和编译器版本

3、编写并编译***.proto文件

4、将protoc.exe和***.proto文件放在同一个文件夹下，再添加一个批处理文件build.bat，内容：protoc --cpp_out=./ ***.proto

在build.bat中
protoc --cpp_out=./ ***.proto

5、双击批处理文件build.bat，会在当前目录下生成：***.pb.h和***.pb.cc文件，即可添加使用了

目前Protobuf的稳定版本是3.9.2

源码操作：https://blog.csdn.net/hp_cpp/article/details/81561310

