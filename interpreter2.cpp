#include "iostream"
#include "cmath"
#include "algorithm"
using namespace std;
const bool KIRI = 0;
const bool KANAN = 1;
const char BLANK = '\0';
const char Y = '\2';
const char X = '\3';
struct matriks{
       bool arah;
       char ganti;
       int state;
       matriks(bool arah1, char ganti1, int state1){
            arah = arah1;
            ganti = ganti1;
            state = state1;
       }
};
matriks* s[45][128] = {};
void alokasi(int asal, int input, bool arah, char ganti, int state){
     matriks* news = new matriks(arah, ganti, state);
     s[asal][input] = news;
}
void seluruhcetak(int asal, int tujuan, char ganti, bool arah){
     for(int i = 32; i < 127; i++){
             if(ganti == '\1') alokasi(asal, i, arah, char(i), tujuan);
             else alokasi(asal, i, arah, ganti, tujuan);
     }
}
void bilangan(int asal, int tujuan, char ganti, bool arah){
     for(int i = 48; i < 58; i++){
             if(ganti == '\1') alokasi(asal, i, arah, char(i), tujuan);
             else alokasi(asal, i, arah, ganti, tujuan);
     }
}
void takur(int asal, int tujuan, char ganti, bool arah){
     for(int i = 43; i < 46; i += 2){
             if(ganti == '\1') alokasi(asal, i, arah, char(i), tujuan);
             else alokasi(asal, i, arah, ganti, tujuan);
     }
}
void kabataku(int asal, int tujuan, char ganti, bool arah){
     if(ganti == '\1') alokasi(asal, 42, arah, char(42), tujuan);
     else alokasi(asal, 42, arah, ganti, tujuan);
     for(int i = 43; i < 48; i+=2){
             if(ganti == '\1') alokasi(asal, i, arah, char(i), tujuan);
             else alokasi(asal, i, arah, ganti, tujuan);
     }
}
size_t hitung(size_t a, size_t b, char opt){
       if(opt == '*') return a*b;
       else if(opt == '/') return a/b;
       else if(opt == '+') return a+b;      
}
int main(){
    //selesai;
    string t = "selesai;";
    for(int i = 0; i < t.length(); i++){
            alokasi(i, t[i], KANAN, BLANK, i+1);
            alokasi(i, t[i], KANAN, BLANK, i+1);
    }
    //Cetak "";
    alokasi(0, 'c', KANAN, BLANK, 9);
    alokasi(0, 'C', KANAN, BLANK, 9);
    t = "etak ";
    for(int i = 0; i < t.length(); i++){
            alokasi(i+9,t[i], KANAN, BLANK, i+10);
            alokasi(i+9,toupper(t[i]), KANAN, BLANK, i+10);
    }
    alokasi(14, '\"', KANAN, BLANK, 15);    
    seluruhcetak(15, 15, '\1', KANAN);
    alokasi(15, BLANK, KIRI, BLANK, 16);
    alokasi(16, ';', KIRI, BLANK, 17);
    alokasi(17, '\"', KIRI, BLANK, 18);
    seluruhcetak(18, 18, '\1', KIRI);
    alokasi(18, BLANK, KANAN, BLANK, 19);
    seluruhcetak(19, 19, '\1', KANAN);
    alokasi(19, BLANK, KANAN, BLANK, 20);
    //aritmatika
    bilangan(14, 21, '\1', KANAN);
    takur(14, 22, '\1', KANAN);
    takur(22, 22, '\1', KANAN);
    bilangan(22, 21, '\1', KANAN);
    bilangan(21, 21, '\1', KANAN);
    kabataku(21, 21, '\1', KANAN);
    alokasi(21, ';', KANAN, ';', 21);
    alokasi(21, BLANK, KIRI, BLANK, 23);
    alokasi(23, ';', KIRI, BLANK, 24);
    bilangan(24, 25, '\1', KIRI);
    bilangan(25, 25, '\1', KIRI);
    kabataku(25, 25, '\1', KIRI);
    alokasi(25, BLANK, KANAN, BLANK, 26);
    bilangan(26, 26, '\1', KANAN);
    takur(26, 26, '\1', KANAN);
    alokasi(26, '*', KIRI, Y, 27);
    alokasi(26, '/', KIRI, Y, 27);
    bilangan(27, 28, '\1', KIRI);
    bilangan(28, 28, '\1', KIRI);
    takur(28, 29, '\1', KIRI);
    alokasi(28, BLANK, KANAN, BLANK, 30);
    takur(29, 29, '\1', KIRI);
    bilangan(29, 30, '\1', KANAN);
    alokasi(29, BLANK, KANAN, BLANK, 30);
    takur(30, 30, X, KANAN);
    bilangan(30, 30, X, KANAN);
    alokasi(30, Y, KANAN, Y, 31);
    takur(31, 32, X, KANAN);
    bilangan(31, 33, X, KANAN);
    takur(32, 32, X, KANAN);
    bilangan(32, 33, X, KANAN);
    bilangan(33, 33, X, KANAN);
    kabataku(33, 34, '\1', KIRI);
    alokasi(33, BLANK, KIRI, BLANK, 34);
    alokasi(34, X, KIRI, '\0', 34);
    alokasi(34, Y, KIRI, '\0', 34);
    bilangan(34, 35, '\1', KANAN);
    alokasi(34, BLANK, KANAN, BLANK, 35);
    alokasi(35, '0', KANAN, '\0', 26);
    
    alokasi(26, BLANK, KIRI, BLANK, 36);
    bilangan(36, 36,  '\1', KIRI);
    takur(36, 36,  '\1', KIRI);
    alokasi(36, BLANK, KANAN, BLANK, 37);
    takur(37, 38, X, KANAN);
    bilangan(37, 39, X, KANAN);
    takur(38, 38, X, KANAN);
    bilangan(38, 39, X,KANAN);
    bilangan(39, 39, X,KANAN);
    takur(39 ,40, X, KANAN);
    takur(40, 40, X, KANAN);
    bilangan(40, 41, X, KANAN);
    bilangan(41, 41, X, KANAN);
    takur(41, 42, '\1', KIRI);
    alokasi(41, BLANK, KIRI, BLANK, 42);
    alokasi(42,X,KIRI,'0',42);
    alokasi(42,BLANK,KANAN,BLANK,43);
    alokasi(43,'0',KIRI, '\0',36);
    alokasi(39,BLANK,KANAN,BLANK,44);
    
    
    
    int head = 1;
    int state = 0;
    string c, cetak;
    char opt;
    bool tanda1, tanda2, tandah;
    unsigned long long int op1, op2, hasil;
    while(state != 8){
       head = 1;
       state = 0;
       cetak = "";
       c = "";
       opt = '+';
       tanda1 = 0;
       tanda2 = 0;
       op1 = 0;
       op2 = 0;
       hasil = 0;
       cout<<"# ";
       getline(cin, c);
       c = '\0' + c + '\0';
       while(s[state][c[head]]){
            if(state == 19) cetak += c[head];
            else if(state == 30){
                 if(48 <= c[head] && c[head] <= 57) op1 = op1*10 + c[head]-48;
                 else if(c[head] == '-') tanda1 ^= 1;
                 else if(c[head] == '+') tanda1 ^= 0;
            }
            matriks* temp = s[state][c[head]];
            char ctemp = c[head];
            int tstate = state;
            state = temp->state;
            c[head] = temp->ganti;
            if(state == 27) opt = ctemp;
            else if(state == 32 || state == 40){
 	 	   		 if(ctemp == '-') tanda2 ^= 1;
                 else if(ctemp == '+') tanda2 ^= 0;
            }
            else if((tstate == 35 && state == 26) || (tstate == 43 && state == 36)){
            	if(tandah) c[head] = '-';
            	else c[head] = '+';
            	op1 = 0;
            	op2 = 0;
            	tanda1 = 0;
            	tanda2 = 0;
            }
            else if(state == 38){
                 if(ctemp == '-') tanda1 ^= 1;
                 else if(ctemp == '+') tanda1 ^= 0;
            }
            else if(state == 39){
                 op1 = op1*10 + ctemp - 48;     
            }
            else if(state == 33 || state == 41) op2 = op2*10+ctemp-48;
            else if((state == 34 && (ctemp == BLANK || ctemp == '*' || ctemp == '/' || ctemp == '-' || ctemp == '+')) || (state == 42 && (ctemp == '+' || ctemp == '-' || ctemp == BLANK))){
                  if(opt != '+'){
                  	hasil = hitung(op1, op2, opt);
                	tandah = tanda1^tanda2;
                  }
                  else{
                  	long long int temp1, temp2, temph;
                  	if(tanda1) temp1 = (long long int)op1*-1;
                  	else temp1 = op1;
                  	if(tanda2) temp2 = (long long int)op2*-1;
                  	else temp2 = op2;
                  	temph = temp1+temp2;
                  	hasil = abs(temph);
                  	if(temph >= 0) tandah = 0;
                  	else tandah = 1;
                  }
                  tanda1 = 0;
                  tanda2 = 0;
                  opt = '+';
            }
            else if(state == 34 || state == 42){
                 c[head] = hasil%10 + 48;
                 hasil /= 10;     
            }
            if(temp->arah) head++;
            else head--;
            //cout<<c<<"|chead = "<<int(c[head])<<"|state = "<<state<<"|op1 = "<<op1<<"|op2 = "<<op2<<"|hasil = "<<hasil<<endl;
       }
       if(state == 20) cout<<"> "<<cetak<<endl;
       else if(state == 44){
	   		cout<<"> ";
	   		if(tanda1) cout<<(long long int)op1*-1<<endl;
			else cout<<(long long int)op1<<endl;		
       }
       else if(state != 8) cout<<"> Kode tidak sesuai dengan peraturan."<<endl;
    }
    cout<<"> Terima kasih sudah menggunakan compiler ini."<<endl;
}
