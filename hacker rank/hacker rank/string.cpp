#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
int main() {
    string input;
    getline(cin, input);
    vector<bool> vect(26, false);
    for(int i = 0; i < input.length(); i++){
        if(input[i] - 'a' >= 0 && input[i] - 'a' < 26)
            vect[input[i] - 'a'] = true;
        else if(input[i] - 'A' >= 0 && input[i] - 'A' < 26)
            vect[input[i] - 'A'] = true;
        
    }
    
    bool isTrue = true;
    for(int i = 0; i < vect.size(); i++){
        if(vect[i] == false){
            isTrue = false;
            cout << "not pangram";
            break;
        }
        
    }
    if(isTrue)
        cout << "pangram";
    return 0;
}



            
            
            int main() {
                int n;
                cin >> n;
                string a;
                string b;
                getline(cin, a);
                for(int i = 0; i < n; i++){
                    bool isTrue = true;
                    vector<bool> vect(26, false);
                    getline(cin, a);
                    getline(cin, b);
                    for(int j = 0; j < a.length(); j++){
                        vect[a[j] - 'a'] = true;
                    }
                    for(int j = 0; j < b.length(); j++){
                        if(vect[b[j] - 'a'] == true){
                            cout << "YES" << endl;
                            isTrue = false;
                            break;
                        }
                    }
                    if(isTrue)
                        cout << "NO" << endl;
                    vect.clear();
                }
                
                return 0;
            }
*/

/*

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vect;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        vect.push_back(temp);
    }
    
    int pageNum = 0;
    int content = 0;
    int specialPage = 0;
    for(int i = 0; i < vect.size(); i++){
        for(int j = 0; j < vect[i]; j++){
            if(content >= k){
                pageNum++;
                content = 0;
            }
            if(j == pageNum){
                specialPage++;
            }
            content++;
            
        }
        pageNum++;
        content = 0;
    }
    cout << specialPage << endl;
    return 0;
}
*/


/*
int r;
int c;

bool isMatch(vector<string> largeVect, vector<string> smallVect, int row, int col){
    int count = 0;
    for(int i = row; i < row + r; i++){
        string temp = largeVect[i].substr(col, c);
        if(temp != smallVect[count])
            return false;
        count++;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
            cin >> G[G_i];
        }
        cin >> r >> c;
        vector<string> P(r);
        for(int i = 0; i < r; i++){
            cin >> P[i];
        }
        bool isTrue = false;
        for(int i = 0; i <= R - r; i++){
            for(int j = 0; j <= C - c; j++){
                if(isMatch(G, P, i, j))
                    isTrue = true;
                
            }
        }
        if(isTrue)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string addStrings(vector<string> vect){
    string result = "";
    int remainder = 0;
    for(int i = 0; i < vect[vect.size() - 1].length(); i++){
        int sum = 0;
        int digit = 0;
        for(int j = 0; j < vect.size(); j++){
            int temp = vect[j].length();
            temp -= i + 1;
            if(temp < 0){
                continue;
            }
            sum += vect[j][vect[j].length() - i - 1] - '0';
            
        }
        sum += remainder;
        digit = sum % 10;
        result.insert(0, to_string(digit));
        remainder = sum / 10;
        if(i == vect[vect.size() - 1].length() - 1 && remainder != 0){
            result.insert(0, to_string(remainder));
        }
    }
    return result;
    
}

string multStrings(string a, string b){
    int remainder = 0;
    int temp;
    int digit = 0;
    vector<string> vect;
    for(int j = b.length() - 1; j >= 0; j--){
        string tempStr = "";
        for(int i = a.length() - 1; i >= 0; i--){
            temp = (a[i] - '0') * (b[j] - '0');
            temp += remainder;
            digit = temp % 10;
            remainder = temp / 10;
            tempStr.insert(0, to_string(digit));
            if(i == 0 && remainder != 0){
                tempStr.insert(0, to_string(remainder));
            }
        }

        for(int k = j; k < b.length() - 1; k++){
            tempStr += '0';
        }
        vect.push_back(tempStr);
    }
    
    return addStrings(vect);
}


int main(){
    int n;
    cin >> n;
    string result, b;
    result = '1';
    for(int i = 2; i <= n; i++){
        b = to_string(i);
        result = multStrings(result, b);

    }
    cout << result;
    return 0;
}

