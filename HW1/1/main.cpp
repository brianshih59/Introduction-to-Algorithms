#include <bits/stdc++.h>
using namespace std;
class People{
public:
    char name[21];
    int score[4];
};
int k;
char O[4][4];
vector<vector<People>> group(4);
char c2i(char c){
    if(c == 'H')
        return '0';
    if(c == 'W')
        return '1';
    if(c == 'I')
        return '2';
    if(c == 'E')
        return '3';
    return 0;
}
bool mycompare(People& person1, People& person2){
    if(person1.score[O[k][0] - '0'] == person2.score[O[k][0] - '0'])
        if(person1.score[O[k][1] - '0'] == person2.score[O[k][1] - '0'])
            if(person1.score[O[k][2] - '0'] == person2.score[O[k][2] - '0'])
                if(person1.score[O[k][3] - '0'] == person2.score[O[k][3] - '0'])
                    return strcmp(person1.name, person2.name) < 0;
                else
                    return person1.score[O[k][3] - '0'] > person2.score[O[k][3] - '0'];
            else
                return person1.score[O[k][2] - '0'] > person2.score[O[k][2] - '0'];
        else
            return person1.score[O[k][1] - '0'] > person2.score[O[k][1] - '0'];
    else
        return person1.score[O[k][0] - '0'] > person2.score[O[k][0] - '0'];
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<4; i++){
        string s;
        cin >> s;
        for(int j=0; j<4; j++)
            O[i][j] = c2i(s[j]);
    }
    for(int i=0; i<n; i++){
        People person;
        cin >> person.name;
        int idx, M = -1;
        for(int j=0; j<4; j++){
            cin >> person.score[j];
            if(person.score[j] > M){
                idx = j;
                M = person.score[j];
            }
        }
        group[idx].push_back(person);
    }
    for(int i=0; i<4; i++){
        k = i;
        sort(group[i].begin(), group[i].end(), mycompare);
        cout << "Group " << char(i + 'A') << ":";
        if(group[i].empty())
            cout << " No Audience\n";
        else
            cout << "\n";
        for(int j=0; j<(int)group[i].size(); j++)
            cout << group[i][j].name << "\n";
    }
    return 0;
}
