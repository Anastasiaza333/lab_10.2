#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* fname) // ��������� ����� � �������� �����
{
    ofstream fout(fname); // ������� ���� ��� ������
    char ch; // ������� ����������� � �� ������������ ��������
    string s; // �������� ������������ �����
    do
    {
        cin.get(); // ������� ����� ��������� � ��� �� ���� �������
        cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
        cout << "enter line: "; getline(cin, s); // ����� �����
        fout << s << endl; // �������� ���� � ����
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}
void PrintTXT(char* fname) // ��������� ����� �� �����
{
    ifstream fin(fname); // ������� ���� ��� ����������
    string s; // ���������� �����
    while (getline(fin, s)) // ���� ����� ��������� �����
    {
        cout << s << endl; // �������� ���� �� �����
    }
    cout << endl;
}
int ProcessTXT1(char* fname) // ���������� �������� ���������� ,�� ����������� � ����� �b�  =
{
    ifstream fin(fname); // ������� ���� ��� ����������
    string s; // ���������� �����
    int k = 0; // �������� ������� ������� ,�� ����������� � ����� �b� =
    while (getline(fin, s)) // ���� ����� ��������� �����
    { // ������� ���� � ���������� ������� ��� ,�� ����������� � ����� �b�  =
        for (unsigned i = 0; i < s.length(); i++)
            if (s[i] == ' ' && s[i + 1] == 'b')
                k++;
    }
    return k;
}

void SortTXT(char* fname, char* gname) // ���������� ����� ���������� �����
{
    ofstream g(gname); // ������� ������ ���� ��� ������
    string s, mins, z = ""; // s � ���������� � ����� f �����
    // mins � �����, ���� ���������
    // ���������
    // z - ��������� � ���� g �����
    int k; // - �����, �� � �� �����, �� ���
    // �������� � ���� g
    do // ���� ������ ����������� �����
    { // � ���, �� �� �� �������� � ���� g
        k = 0; // ��������� �������� �����, 
        // �� ��� ��������
        ifstream f(fname); // ������� ������ ���� ��� ����������
        // ����� ������ ������ ���� � �������
        // ���� ������� ������ ����������� �� �� �� ��������� �����
        while (getline(f, s)) // ���� ����� ��������� �����
        {
            if (s <= z) // ���� ��� ����� ��� ��������� � ���� g
                continue; // - ���������� ���� 
            mins = s; // ������� ������ �� �� ��������� �����
            // - ����������
            k++; // ������� �� �� ��������� �����
            // - �������� ��������
            break; // ������ � ����� ��������� ������
        } // mins ����������� ��������
        // ���� ������ ����������� �� �� �� ��������� �����
        while (getline(f, s)) // ���� ����� ��������� �����
        {
            if (s <= z) // ���� ��� ����� ��� ��������� � ���� g
                continue; // - ���������� ����
            if (s < mins) // ���� ���������� ����� ������
            { // �����������
                mins = s; // - ������� ���� ����������
                k++; // �������� �������� �� �� ���������
            } // �����
        }
        // ����� ����������� � �� ��������� ����� � ���� g
        z = mins; // ������ ���������� ���������
        // ���������� � �� ��������� �����
        if (k > 0) // ���� ���� �������� �� �� ��������
            g << z << endl; // ����� - �������� ���������� � ���
        f.close(); // ������� ������ ���� 
    } // ��� ���� ������ ���� � �������
    while (k > 0); // ����������, ���� � �� �������� �����
}
int main()
{
    // text files
    char fname[100]; // ��'� ������� �����
    cout << "enter file name 1: "; cin >> fname;
    CreateTXT(fname); // ����� ����� ����� � ���������
    PrintTXT(fname); // ������ ���� ������� ����� �� �����
    cout << "k(' ' 'b'=) = " << ProcessTXT1(fname) << endl;
    char gname[100]; // ��'� ������� �����
    cout << "enter file name 2: "; cin >> gname;
    SortTXT(fname, gname); // ����������� ����� ������� �����,
    // ��������� �������� � ������ ����
    PrintTXT(gname); // ������ ���� ������� ����� �� �����
    return 0;
}