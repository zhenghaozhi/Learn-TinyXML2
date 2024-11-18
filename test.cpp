#include "tinyxml2.h"
#include "iostream"
using namespace std;
using namespace tinyxml2;

int main() {
    
    #ifdef _TEST_1_
    XMLDocument doc; // ����һ��XML�ĵ�����
    doc.LoadFile("test.xml"); // �ӱ����ļ���ȡxml 
    if (doc.Error()) {
        std::cerr << "Error parsing XML: ";
        std::cerr << doc.ErrorStr() << std::endl;
        return -1;
    }
    else std::cout << "File load completed" << std::endl;
    // ���xml�ļ���ʽ�Ƿ���ȷ
    #endif

    #ifdef _TEST_2_
    XMLDocument doc; // ����һ��XML�ĵ�����
    doc.LoadFile("test.xml"); // �ӱ����ļ���ȡxml 

    XMLDeclaration* decl = doc.NewDeclaration("xml version=\"0.1\" encoding=\"UTF-8\"");
    doc.InsertFirstChild(decl);  // ���ʼ���XML����

    XMLComment* cmt = doc.NewComment("Welcome to THU Lib-XML system");
    doc.InsertEndChild(cmt); // ��������XMLע��

    doc.SaveFile("output.xml"); // ��XMLDocument���󱣴�Ϊxml�ļ�
    #endif

    #ifdef _TEST_3_
    XMLDocument doc; // ����һ��XML�ĵ�����
    doc.LoadFile("test.xml"); // �ӱ����ļ���ȡxml 
    XMLElement* root = doc.RootElement(); // ��ȡ���ڵ�
    XMLElement* newBook = doc.NewElement("book");
    newBook->SetAttribute("category", "dictionary");
    XMLElement* newTitle = doc.NewElement("title");
    newTitle->SetAttribute("lang", "zh");
    newTitle->SetText("�»��ֵ�");
    newBook->InsertEndChild(newTitle);
    XMLElement* newPublisher = doc.NewElement("publisher");
    newPublisher->SetText("����ӡ���");
    newBook->InsertEndChild(newPublisher);
    XMLElement* newYear = doc.NewElement("year");
    newYear->SetText("1953");
    newBook->InsertEndChild(newYear);
    XMLElement* newStatus = doc.NewElement("status");
    newStatus->SetText("available");
    newBook->InsertEndChild(newStatus);
    root->InsertEndChild(newBook); // �������

    XMLPrinter printer;
    doc.Print(&printer);
    std::cout << printer.CStr() << std::endl; // ��ӡXML����
    #endif

    #ifdef _TEST_4_
    XMLDocument doc; // ����XML����
    doc.LoadFile("test.xml"); // �ӱ����ļ���ȡxml 
    const char* newXml = R"(
        <book category="dictionary">
            <title lang="zh">�»��ֵ�</title>
            <publisher>����ӡ���</publisher>
            <year>1953</year>
            <status>available</status>
        </book>
    )"; // ���� NewElement_BY_XML ����

    XMLElement* newElement = doc.NewElement_BY_XML(newXml);
    if (!newElement) {
        std::cerr << "Error creating new element from XML" << std::endl;
        return -1;
    } // �쳣�������

    // ���µ�Ԫ����ӵ���Ԫ��
    XMLElement* root = doc.RootElement();
    root->InsertEndChild(newElement);

    // ��ӡ�޸ĺ��XML����
    XMLPrinter printer;
    doc.Print(&printer);
    std::cout << printer.CStr() << std::endl;
    #endif

    #ifdef _TEST_5_

    // Ϊ��������������ȥ�쳣�������

    XMLDocument doc, tmp; // ����XML����
    doc.LoadFile("test.xml"); // �ӱ����ļ���ȡxml 
    const char* newXml = R"(
        <book category="dictionary">
            <title lang="zh">�»��ֵ�</title>
            <publisher>����ӡ���</publisher>
            <year>1953</year>
            <status>available</status>
        </book>
    )"; // ���� NewElement_BY_XML ����
    tmp.Parse(newXml); // ͨ��tmp���Element����

    // ��������Element
    XMLElement* copiedElement = doc.NewElement(tmp.FirstChildElement());

    // ���µ�Ԫ����ӵ���Ԫ��
    XMLElement* root = doc.RootElement();
    root->InsertEndChild(copiedElement);

    // ��ӡ�޸ĺ��XML����
    XMLPrinter printer;
    doc.Print(&printer);
    std::cout << printer.CStr() << std::endl;
    #endif

    return 0;
}