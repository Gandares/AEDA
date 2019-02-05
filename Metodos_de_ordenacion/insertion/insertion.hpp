#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
class insertion{
        
    private:
    
        int demostrar;
    
    public:
    
        void set_demos(int n){
            
            demostrar=n;    
        }
        
        void insertion_sort(vector<T>& v){
    
            int aux, pos;
    
            for (int i = 0; i < v.size(); i++){
                
                pos=i;
                aux=v[i];
                
                while((pos > 0)&&(v[pos-1]>aux)){
                    v[pos]=v[pos-1];
                    pos--;
                }
                v[pos]=aux;
                if(demostrar==1){
                    write(cout,v);
                    cin.get();
                }
            }
        }

        ostream& write(ostream& os, vector<T>& v){
            for(int j=0;j<v.size();j++)
                cout << v[j] << ", ";
            cout << endl << endl;
        }
        
        ostream& write(ostream& os, vector<double>& v){
            for(int j=0;j<v.size();j++)
                cout << v[j] << fixed << setprecision(6) << ", ";
            cout << endl << endl;
        }
        
};