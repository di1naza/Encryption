#include <iostream>
using namespace std;

class Codec {
private:
    int W, H, S;
    const char C[71] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 .,-!?()";
    char M[70][70];
    bool used[70][70];
    char res[70];
public:

    void clear(){
        for (int i = 0; i < 70; ++i){
            for (int j = 0; j < 70; ++j){
                M[i][j] = '$';
                used[i][j] = false;
            }
        }
    }

    void upd(){
        clear();
        for (int i = 0; i < 70; ++i){
            for (int j = 0; j < 70; ++j) {
                if(i >= H || j >= W) used[i][j] = true;
            }
        }
        int idx = 0;
        int idy = -1;
        int move = 0; //0 - right, 1 - down, 2 - left, 3 - up
        for (int i = 0; i < 70; ++i){
            for (int j = 0; j < S + 1; ++j){
                if(move == 0){
                    if(idy + 1 < 70 && !used[idx][idy + 1]){
                        if(idy != -1) used[idx][idy] = true;
                        idy++;
                    }
                    else{
                        move = 1;
                        used[idx][idy] = true;
                        idx++;
                    }
                }
                else if(move == 1){
                    if(idx + 1 < 70 && !used[idx + 1][idy]){
                        used[idx][idy] = true;
                        idx++;
                    }
                    else{
                        move = 2;
                        used[idx][idy] = true;
                        idy--;
                    }
                }
                else if(move == 2){
                    if(idy > 0 && !used[idx][idy - 1]){
                        used[idx][idy] = true;
                        idy--;
                    }
                    else{
                        move = 3;
                        used[idx][idy] = true;
                        idx--;
                    }
                }
                else {
                    if(idx > 0 && !used[idx - 1][idy]){
                        used[idx][idy] = true;
                        idx--;
                    }
                    else{
                        move = 0;
                        used[idx][idy] = true;
                        idy++;
                    }
                }
            }
            M[idx][idy] = C[i];
        }
        int index = 0;
        for (int i = 0; i < W; ++i) {
            for (int j = 0; j < H; ++j) {
                if(M[j][i] != '$'){
                    res[index++] = M[j][i];
                }
            }
        }
    }

    Codec() {
        this->W = 70;
        this->H = 1;
        this->S = 0;
        upd();
    }
    Codec(int w, int h, int s) {
        this->W = w;
        this->H = h;
        this->S = s;
        upd();
    }
    void config(int w, int h, int s) {
        this->W = w;
        this->H = h;
        this->S = s;
        upd();
    }
    void showSetting() {
        cout << "W=" << W << ", H=" << H << ", S=" << S << endl;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if(M[i][j] == '$')cout << ' ';
                else cout << M[i][j];
            }
            cout << endl;
        }
        cout << "Seq: ";
        for (int i = 0; i < 70; ++i){
            cout << res[i];
        }
        cout << endl;
    }
    int get_pos_encode(char x){
        for (int i = 0; i < 70; ++i) {
            if(C[i] == x)return i;
        }
        return -1;
    }

    void encode(char in[], char out[]) {
        int index = 0;
        while(in[index] != '\0'){
            int pos = get_pos_encode(in[index]);
            if(pos == -1)out[index] = in[index];
            else out[index] = res[pos];
            index++;
        }
        out[index] = '\0';
    }

    int get_pos_decode(char x){
        for (int i = 0; i < 70; ++i){
            if(res[i] == x)return i;
        }
        return -1;
    }

    void decode(char in[], char out[]) {
        int index = 0;
        while(in[index] != '\0'){
            int pos = get_pos_decode(in[index]);
            if(pos == -1)out[index] = in[index];
            else out[index] = C[pos];
            index++;
        }
        out[index] = '\0';
    }
};

int main() {
    char cmd, inStr[1000], outStr[1000];
    bool fin=false;
    Codec C;

    while(!fin) {
        cout << "\nCommand: ";
        cmd = cin.get();
        switch(cmd) {
            case 'C':
                int w,h,s;
                cin>>w>>h>>s;
                C.config(w,h,s);
                cin.ignore(1000,'\n');
                break;
            case 'Q':
                cout << "Quit\n";
                cin.ignore(1000,'\n');
                fin=true;
                break;
            case 'S':
                C.showSetting();
                cin.ignore(1000,'\n');
                break;
            case 'E':
                cin.get();
                cin.getline(inStr,1000);
                C.encode(inStr,outStr);
                cout << outStr<<endl;
                break;
            case 'D':
                cin.get();
                cin.getline(inStr,1000);
                C.decode(inStr,outStr);
                cout << outStr<<endl;
                break;
        }
    }
    return 0;
}