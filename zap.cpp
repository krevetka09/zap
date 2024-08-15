// zap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include "pch.h"
#include <iostream>

int StartDXF(FILE* file_stream)
{
    fprintf(file_stream, "%s\n", "0");
    fprintf(file_stream, "%s\n", "SECTION");
    fprintf(file_stream, "%s\n", "2");
    fprintf(file_stream, "%s\n", "ENTITIES");
    return 0;
}
int LineDXF(FILE* file_stream, double x1, double y1, double z1, double x2, double y2, double z2)
{
    fprintf(file_stream, "%s\n", "0");
    fprintf(file_stream, "%s\n", "LINE");
    fprintf(file_stream, "%s\n", "8");
    fprintf(file_stream, "%s\n", "0");
    fprintf(file_stream, "%s\n", "10");
    fprintf(file_stream, "%f\n", x1);
    fprintf(file_stream, "%s\n", "20");
    fprintf(file_stream, "%f\n", y1);
    fprintf(file_stream, "%s\n", "30");
    fprintf(file_stream, "%f\n", z1);
    fprintf(file_stream, "%s\n", "11");
    fprintf(file_stream, "%f\n", x2);
    fprintf(file_stream, "%s\n", "21");
    fprintf(file_stream, "%f\n", y2);
    fprintf(file_stream, "%s\n", "31");
    fprintf(file_stream, "%f\n", z2);
    return 0;
}
int SurfaceDXF(FILE* file_stream, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4)
{
    fprintf(file_stream, "%s\n", "0");
    fprintf(file_stream, "%s\n", "3DFACE");
    fprintf(file_stream, "%s\n", "   8");
    fprintf(file_stream, "%s\n", "0");
    fprintf(file_stream, "%s\n", "   10");
    fprintf(file_stream, "%f\n", x1);
    fprintf(file_stream, "%s\n", "20");
    fprintf(file_stream, "%f\n", y1);
    fprintf(file_stream, "%s\n", "30");
    fprintf(file_stream, "%f\n", z1);
    fprintf(file_stream, "%s\n", "11");
    fprintf(file_stream, "%f\n", x2);
    fprintf(file_stream, "%s\n", "21");
    fprintf(file_stream, "%f\n", y2);
    fprintf(file_stream, "%s\n", "31");
    fprintf(file_stream, "%f\n", z2);
    fprintf(file_stream, "%s\n", "12");
    fprintf(file_stream, "%f\n", x3);
    fprintf(file_stream, "%s\n", "22");
    fprintf(file_stream, "%f\n", y3);
    fprintf(file_stream, "%s\n", "32");
    fprintf(file_stream, "%f\n", z3);
    fprintf(file_stream, "%s\n", "13");
    fprintf(file_stream, "%f\n", x4);
    fprintf(file_stream, "%s\n", "23");
    fprintf(file_stream, "%f\n", y4);
    fprintf(file_stream, "%s\n", "33");
    fprintf(file_stream, "%f\n", z4);
    return 0;
}
int TextDXF(FILE* file_stream, double x, double y, double z, int height, char* text)
{   fprintf(file_stream, "%s\n", "0");
    fprintf(file_stream, "%s\n", "TEXT");
    fprintf(file_stream, "%s\n", "   8");
    fprintf(file_stream, "%s\n", "0");
    fprintf(file_stream, "%s\n", "   10");
    fprintf(file_stream, "%f\n", x);
    fprintf(file_stream, "%s\n", "20");
    fprintf(file_stream, "%f\n", y);
    fprintf(file_stream, "%s\n", "40");
    fprintf(file_stream, "%i\n", height);
    fprintf(file_stream, "%s\n", "   1");
    fprintf(file_stream, "%s\n", text);
    fprintf(file_stream, "%s\n", "   7");
    fprintf(file_stream, "%s\n", "ESKD");
    return 0;
}
int EndSection(FILE* file_stream)
{
    fprintf(file_stream, "%s\n", "  0");
    fprintf(file_stream, "%s\n", "ENDSEC");
    return 0;
}
int EndDXF(FILE* file_stream)
{
    fprintf(file_stream, "%s\n", "  0");
    fprintf(file_stream, "%s\n", "EOF");
    return 0;
}
int main()
{
    FILE* myfile;
    int i, j, n, m;
    int err;
    double carx1, cary1, carz1, carx2, cary2, carz2;
    double carx3, cary3, carz3, carx4, cary4, carz4;
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    double r1, s1, r2, s2, r3, s3, r4, s4;
    double rn, rk, sn, sk, dr, ds;
    double r, s;
    double ff1, ff2, ff3, ff4;
    //
    err = fopen_s(&myfile, "tst01.dxf", "w+"); // открываем текстовый фаил txt.dxf на запись
    // printf("\n");
    printf("\n  %s\n", "DXF-File recording"); // вывод сторки "Запись в DXF-файл" на экран   1135 на 3 - матрица
    StartDXF(myfile);
    //=====================================
    //========
    //=====================================
    n = 10;
    m = 15;
    rn = -1.;  rk = 1.;  dr = (rk - rn) / n;
    sn = -1.;  sk = 1.;  ds = (sk - sn) / n;
    // вершины билинейной поверхности
    carx1 = 0.;       cary1 = 0.;       carz1 = -200.;
    carx2 = 250.;     cary2 = 0.;       carz2 = 100.;
    carx3 = 400.;     cary3 = 400.;     carz3 = -200.;
    carx4 = 0.;       cary4 = 250.;     carz4 = 100.;
    //
    r1 = rn;
    for (i = 0; i < n; i++)
    {
        s1 = sn;
        for (j = 0; j < m; j++)
        {
            r2 = r1 + dr;   s2 = s1;
            r3 = r1 + dr;   s3 = s1 + ds;
            r4 = r1;        s4 = s1 + ds;

            r = r1;   s = s1;

            ff1 = 0.25 * (1. - r) * (1. - s);
            ff2 = 0.25 * (1. + r) * (1. - s);
            ff3 = 0.25 * (1. + r) * (1. + s);
            ff4 = 0.25 * (1. - r) * (1. + s);

            x1 = ff1 * carx1 + ff2 * carx2 + ff3 * carx3 + ff4 * carx4;
            y1 = ff1 * cary1 + ff2 * cary2 + ff3 * cary3 + ff4 * cary4;
            z1 = ff1 * carz1 + ff2 * carz2 + ff3 * carz3 + ff4 * carz4;

            r = r2; s = s2;
            ff1 = 0.25 * (1. - r) * (1. - s);
            ff2 = 0.25 * (1. + r) * (1. - s);
            ff3 = 0.25 * (1. + r) * (1. + s);
            ff4 = 0.25 * (1. - r) * (1. + s);

            x2 = ff1 * carx1 + ff2 * carx2 + ff3 * carx3 + ff4 * carx4;
            y2 = ff1 * cary1 + ff2 * cary2 + ff3 * cary3 + ff4 * cary4;
            z2 = ff1 * carz1 + ff2 * carz2 + ff3 * carz3 + ff4 * carz4;

            r = r3; s = s3;
            ff1 = 0.25 * (1. - r) * (1. - s);
            ff2 = 0.25 * (1. + r) * (1. - s);
            ff3 = 0.25 * (1. + r) * (1. + s);
            ff4 = 0.25 * (1. - r) * (1. + s);

            x3 = ff1 * carx1 + ff2 * carx2 + ff3 * carx3 + ff4 * carx4;
            y3 = ff1 * cary1 + ff2 * cary2 + ff3 * cary3 + ff4 * cary4;
            z3 = ff1 * carz1 + ff2 * carz2 + ff3 * carz3 + ff4 * carz4;

            r = r4; s = s4;
            ff1 = 0.25 * (1. - r) * (1. - s);
            ff2 = 0.25 * (1. + r) * (1. - s);
            ff3 = 0.25 * (1. + r) * (1. + s);
            ff4 = 0.25 * (1. - r) * (1. + s);

            x4 = ff1 * carx1 + ff2 * carx2 + ff3 * carx3 + ff4 * carx4;
            y4 = ff1 * cary1 + ff2 * cary2 + ff3 * cary3 + ff4 * cary4;
            z4 = ff1 * carz1 + ff2 * carz2 + ff3 * carz3 + ff4 * carz4;
            // 
            SurfaceDXF(myfile, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
            LineDXF(myfile, x1, y1, z1, x2, y2, z2);
            LineDXF(myfile, x2, y2, z2, x3, y3, z3);
            LineDXF(myfile, x3, y3, z3, x4, y4, z4);
            LineDXF(myfile, x4, y4, z4, x1, y1, z1);
            //
            s1 = s1 + ds;
        }
        r1 = r1 + dr;
    }
    //===============================================
    //==Завершение записи графических данных в файл==
    //===============================================
    EndSection(myfile);
    EndDXF(myfile);

    printf("\n %s \n", " End of DXF-file recording");
    //
    fclose(myfile);
}
    // Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
