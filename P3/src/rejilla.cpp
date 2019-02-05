#include "../include/rejilla.hpp"

rejilla::rejilla(int m, int n){
    
    m_=m;
    n_=n;
    
    M_.resize(m, vector<char>(n));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
                M_[i][j]=' ';

        }
    }
}

int rejilla::get_m(void) const{
    
    return m_;
}

int rejilla::get_n(void) const{
    
    return n_;
}

char rejilla::get_color(int i,int j) const{
    
    return M_[i][j];
}

void rejilla::set_color(int i,int j,char color){
    
    M_[i][j]=color;
}
