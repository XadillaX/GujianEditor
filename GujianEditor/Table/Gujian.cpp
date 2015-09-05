#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
#define ITEM "TaskItem"
#define ITEMFILE "CTaskItem.cpp"

int ID[1024];
string NAME[1024];
string DES[1024];

int main()
{
    ifstream fin("ListTask.txt");
    int i;
    for(i = 0; ; i++)
    {
        if(fin >> ID[i])
        {
            getline(fin, NAME[i]);
            DES[i] = "";
            while(NAME[i][0] == ' ') NAME[i].erase(0, 1);
            int pos = NAME[i].find("ги");
            if(pos != string::npos)
            {
                DES[i] = NAME[i].substr(pos + 2, NAME[i].length());
                NAME[i] = NAME[i].substr(0, pos);
                DES[i] = DES[i].substr(0, DES[i].length() - 2);
            }
            else
            {
                pos = NAME[i].find(" ");
                if(pos != string::npos)
                {
                    DES[i] = NAME[i].substr(pos + 1, NAME[i].length());
                    NAME[i] = NAME[i].substr(0, pos);
                    while(DES[i][0] == ' ') DES[i].erase(0, 1);
                }
            }
        }
        else break;
    }
    fin.close();

    ofstream fout(ITEMFILE);
    
    fout << "void CGujianEditorDlg::Init" << ITEM << "()\n{\n";
    for(int j = 0; j < i; j++)
    {
        //fprintf(fp, "    %s[%s].id = %d, %s[%s].des = %s;\n", ITEM, NAME[j], ID[j], ITEM, NAME[j], DES[j]);
        fout << "    " << ITEM << "[L\"" << NAME[j] << "\"].id = " << ID[j] << ", " << ITEM << "[L\"" << NAME[j] << "\"].des = L\"" << DES[j] << "\";\n";
    }
    
    fout << "}\n";
    fout.close();
    
    system("pause");
    return 0;
}
