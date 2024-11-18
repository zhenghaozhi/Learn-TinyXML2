所有测试源码均保存于test.cpp中，可根据PPT中源码框下的标识完成#define进行测试



所有测试所需文件命名格式为fileload_test_*.xml，具体文件请同样参照PPT中文件框下的标识
----------------------------
特别注意！！！
请一定将待测试的文件拷贝至/重命名为"test.xml"后进行测试！！！
（所有的测试代码中引用的文件均为"test.xml"，如此保存仅为区分不同xml测试文件）
----------------------------



注：目录下附tinyxml2.cpp与tinyxml2.h均为添加了改进功能的版本！！！（并非原版）

其额外实现了：
XMLElement* NewElement_BY_XML(const char* xml);
XMLElement* NewElement(const XMLElement* ele);

头文件引用此两文件不影响其他任何功能测试，
但在进行_TEST_4_和_TEST_5_改进功能测试时请务必使用这两个文件而非原版两文件！





辛苦了！谢谢！！！