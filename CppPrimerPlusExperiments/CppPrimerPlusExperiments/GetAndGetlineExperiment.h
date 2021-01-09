/**
	@author: xuekt
	@date: 2021.1.9
	C++ �����е����� cin.get(), cin.getline()
	1. cin.get
	��1�����뵥���ַ���cin.get()������ʽ
		
		int get();
			��ָ��������������ȡһ���ַ��������հ��ַ����������ķ���ֵ���Ƕ�����ַ��� 
		�������������е��ļ�������������ֵ�����ļ�������־EOF(End Of File)��һ��
		��-1����EOF����-1������0����ֵ���ǿ��ǵ������ַ���ASCII�������������ͬ��
		C++ϵͳ���õ�EOFֵ�п��ܲ�ͬ��
			���cin.get()���Դ�����������������еĻ��з�
		
		istream& get (char& c);
			���������ж�ȡһ���ַ��������ַ�����ch�������ȡ�ɹ���������true(��)��
		��ʧ��(���ļ�������) ��������false(��)��

	(2) ����C����ַ���������ʽ
		istream& get (char* s, streamsize n);
		istream& get (char* s, streamsize n, char delim);
			��ȡ���е�s�У�ֱ������n����ȡn-1���ַ��������������з���������������delim�ַ������ǻ�ѻ��з�
		�����������֮�У�������ȥ������з��������Ҫ����cin.get()����ȡ������з���
		֮����ܼ������룬

	(3) ����streambuf������ʽ
		istream& get (streambuf& sb);
		istream& get (streambuf& sb, char delim);
	
	2. cin.getline
		��ȡ����C����ַ���
		istream& getline (char* s, streamsize n );
		istream& getline (char* s, streamsize n, char delim );
		������cin.get��ȡC����ַ�����ͬ������������
		��1��cin.get��ѻ��з���������������У�cin.getline�ѻ��з���ȡ��ת����'\0'
		��2����������е�ʱ��
			-- cin.get������failbit��֮�����е����붼�ᱻ��ϣ���Ҫ��cin.clear()�ָ�����,
			��ʱ�����з��Ա������������֮�У���Ҫ�ٵ���һ��cin.get();
			-- cin.getline��ѻ��з���ȡ������'\n'�洢���ַ�����
		��3���ڶ�ȡ�����ݳ���n��ʱ�򣬶�������ضϡ�
			-- cin.get��ѽض�֮������ݶ���������������У���˿��Լ���cin.get��ȡʣ�������
			-- cin.getline����ʧЧλ��֮���ٵ���cin.getlineֻ�ܶ�ȡ���ַ�����
			��Ҫ��cin.clear()���ܼ�����ȡ�ض�ʣ������ݡ�
			���磺
				char s[10]; cin.get(s, 10); cin.getline(s, 10);
				����Ϊ��1234567890
				����cin.get(s, 10)��
					��һ�Σ�cin.get(s, 10); ��� 123456789
					�ڶ��Σ�cin.get(s, 10); ��� 0
					֮���һֱ������ַ�������Ϊcin.get����Խ�������Ļ��з�'\n'
					��Ҫ����һ��cin.get()���ܼ���
				����cin.getline(s, 10):
					��һ�Σ�cin.getline(s, 10); ��� 123456789
					֮���һֱ������ַ�������ΪʧЧλ
					��Ҫ����һ��cin.clear()���ܼ���
					cin.clear()֮����һ�Σ�cin.getline(s, 10); ��� 0

	3. getline (string)	
		ʹ��ʱ����Ҫ#include <iostream> ��Ҫ#include <string>
		istream& getline (istream&  is, string& str, char delim);
		istream& getline (istream&& is, string& str, char delim);
		istream& getline (istream&  is, string& str);
		istream& getline (istream&& is, string& str);
**/

#ifndef GETANDGETLINEEXPERIMENT_H
#define GETANDGETLINEEXPERIMENT_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void testCinGet() {
	cout << "testing cin.get\n" << endl;
	
	int i;
	char c;
	char s[10];

	/*
	//test1: int get();
	cout << "test1: int get();" << endl;
	cout << "enter a sentence" << endl;
	//while((i = cin.get()) != EOF) {
	while((i = cin.get()) != '\n') {
		cout.put(i);
	}
	cout << "test1 end\n" << endl;

	//test2: istream& get (char& c);
	cout << "test2: istream& get (char& c);" << endl;
	cout << "enter a sentence" << endl;
	while(cin.get(c)) {
		cout.put(c);
	}
	cout << "test2 end\n" << endl;
	*/

	//test3: istream& get (char* s, streamsize n);
	cout << "test3: istream& get (char* s, streamsize n);" << endl;
	cout << "enter a sentence" << endl;
	cin.get(s, 10);
	cout << s << endl;
	cout << "test3 end\n" << endl;
	
	cout << "test cin.get end\n\n" << endl;
}

void testCinGetline() {
	cout << "testing cin.getline\n" << endl;

	char s[10];

	//test: istream& getline (char* s, streamsize n);
	cout << "test: istream& getline (char* s, streamsize n);" << endl;
	cout << "enter a sentence" << endl;
	cin.getline(s, 10);
	cout << s << endl;
	cout << "test end\n" << endl;
	
	cout << "test cin.getline end\n\n" << endl;
}

void testGetAndGetline() {
	testCinGet();
	testCinGetline();
}
#endif // ~GETANDGETLINEEXPERIMENT_H