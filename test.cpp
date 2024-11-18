#include "tinyxml2.h"
#include "iostream"
using namespace std;
using namespace tinyxml2;

int main() {
    
    #ifdef _TEST_1_
    XMLDocument doc; // 创建一个XML文档对象
    doc.LoadFile("test.xml"); // 从本地文件读取xml 
    if (doc.Error()) {
        std::cerr << "Error parsing XML: ";
        std::cerr << doc.ErrorStr() << std::endl;
        return -1;
    }
    else std::cout << "File load completed" << std::endl;
    // 检查xml文件格式是否正确
    #endif

    #ifdef _TEST_2_
    XMLDocument doc; // 创建一个XML文档对象
    doc.LoadFile("test.xml"); // 从本地文件读取xml 

    XMLDeclaration* decl = doc.NewDeclaration("xml version=\"0.1\" encoding=\"UTF-8\"");
    doc.InsertFirstChild(decl);  // 在最开始添加XML声明

    XMLComment* cmt = doc.NewComment("Welcome to THU Lib-XML system");
    doc.InsertEndChild(cmt); // 在最后添加XML注释

    doc.SaveFile("output.xml"); // 将XMLDocument对象保存为xml文件
    #endif

    #ifdef _TEST_3_
    XMLDocument doc; // 创建一个XML文档对象
    doc.LoadFile("test.xml"); // 从本地文件读取xml 
    XMLElement* root = doc.RootElement(); // 获取根节点
    XMLElement* newBook = doc.NewElement("book");
    newBook->SetAttribute("category", "dictionary");
    XMLElement* newTitle = doc.NewElement("title");
    newTitle->SetAttribute("lang", "zh");
    newTitle->SetText("新华字典");
    newBook->InsertEndChild(newTitle);
    XMLElement* newPublisher = doc.NewElement("publisher");
    newPublisher->SetText("商务印书馆");
    newBook->InsertEndChild(newPublisher);
    XMLElement* newYear = doc.NewElement("year");
    newYear->SetText("1953");
    newBook->InsertEndChild(newYear);
    XMLElement* newStatus = doc.NewElement("status");
    newStatus->SetText("available");
    newBook->InsertEndChild(newStatus);
    root->InsertEndChild(newBook); // 添加新书

    XMLPrinter printer;
    doc.Print(&printer);
    std::cout << printer.CStr() << std::endl; // 打印XML内容
    #endif

    #ifdef _TEST_4_
    XMLDocument doc; // 加载XML内容
    doc.LoadFile("test.xml"); // 从本地文件读取xml 
    const char* newXml = R"(
        <book category="dictionary">
            <title lang="zh">新华字典</title>
            <publisher>商务印书馆</publisher>
            <year>1953</year>
            <status>available</status>
        </book>
    )"; // 测试 NewElement_BY_XML 方法

    XMLElement* newElement = doc.NewElement_BY_XML(newXml);
    if (!newElement) {
        std::cerr << "Error creating new element from XML" << std::endl;
        return -1;
    } // 异常情况处理

    // 将新的元素添加到根元素
    XMLElement* root = doc.RootElement();
    root->InsertEndChild(newElement);

    // 打印修改后的XML内容
    XMLPrinter printer;
    doc.Print(&printer);
    std::cout << printer.CStr() << std::endl;
    #endif

    #ifdef _TEST_5_

    // 为避免代码过长故略去异常情况处理

    XMLDocument doc, tmp; // 加载XML内容
    doc.LoadFile("test.xml"); // 从本地文件读取xml 
    const char* newXml = R"(
        <book category="dictionary">
            <title lang="zh">新华字典</title>
            <publisher>商务印书馆</publisher>
            <year>1953</year>
            <status>available</status>
        </book>
    )"; // 测试 NewElement_BY_XML 方法
    tmp.Parse(newXml); // 通过tmp获得Element对象

    // 复用已有Element
    XMLElement* copiedElement = doc.NewElement(tmp.FirstChildElement());

    // 将新的元素添加到根元素
    XMLElement* root = doc.RootElement();
    root->InsertEndChild(copiedElement);

    // 打印修改后的XML内容
    XMLPrinter printer;
    doc.Print(&printer);
    std::cout << printer.CStr() << std::endl;
    #endif

    return 0;
}