#include <iostream>
#include <cmath>
#include <string>

using namespace std;
#define MIN(x,y) ((x) < (y) ? (x) : (y)) //calculate minimum between two values

int main() {
                int i, j, l1, l2, t, track;



                int dist[500][500];
                //take the strings as input
                string s1;
                string s2;
                //stores the lenght of strings s1 and s2
                while (getline(cin, s1))
                {
                                getline(cin, s2);
                                l1 = s1.length();
                                l2 = s2.length();
                                for (i = 0; i <= l1; i++)
                                {
                                                dist[0][i] = i;
                                }
                                for (j = 0; j <= l2; j++) {
                                                dist[j][0] = j;
                                }
                                for (j = 1; j <= l1; j++) {
                                                for (i = 1; i <= l2; i++) {
                                                                if (s1[j - 1] == s2[i - 1]) {
                                                                                track = 0;
                                                                }
                                                                else {
                                                                                track = 1;
                                                                }

                                                                t = MIN((dist[i - 1][j] + 1), (dist[i][j - 1] + 1));
                                                                dist[i][j] = MIN(t, (dist[i - 1][j - 1] + track));
                                                }
                                }
                                cout << dist[l2][l1]<<endl;
                                for (int i = 0; i < 500; i++)
                                {
                                                for (int j = 0; j < 500; j++)
                                                {
                                                                dist[i][j] = NULL;
                                                }
                                }
                }
                return 0;
}
