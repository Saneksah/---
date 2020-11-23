#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(){
    double x1, y1, x2, y2;
    double a, b, c;
    setlocale(LC_ALL, "rus");
    ifstream INPUT("INPUT.txt");
    INPUT >> x1;
    INPUT >> y1;
    INPUT >> x2;
    INPUT >> y2;
    INPUT.close();
    cout << "Первая координата : " << x1 << " " << y1 << endl;
    cout << "Вторая координата : " << x2 << " " << y2 << endl;
        const float e = 10e-8;
        c = abs((y2 * x1 - x2 * y1) / sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        a = sqrt(pow(x1, 2) + pow(y1, 2));
        b = sqrt(pow(x2, 2) + pow(y2, 2));
        int rezultat = 0;
        if (x1!= x2 or y1 != y2){
            if ((2 * x1 * x1 - 2 * x1 * x2 + 2 * y1 * y1 - 2 * y1 * y2 < 0) or (2 * x2 * x2 - 2 * x1 * x2 + 2 * y2 * y2 - 2 * y1 * y2 < 0))
                rezultat = (int)(max(a, b) + e) - (int)(min(a, b) - e);
            else {
                rezultat = (int)(a + e) - (int)(c - e);
                rezultat = rezultat + (int)(b + e) - (int)(c - e);
                if ((abs(round(c) - c) < e) and (abs(c) > e)) {
                    rezultat--;
                }
            }
        }
        else {
            rezultat = 0;
        }
        cout << "Ответ(кол-во пересечений): " << rezultat;


    ofstream OUTPUT("OUTPUT.txt");
    OUTPUT << rezultat;
    OUTPUT.close();
    return 0;
}
